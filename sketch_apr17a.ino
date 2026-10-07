#include <Arduino.h>
#include <SPI.h>

// ---------------- ESP32 pins ----------------
static const int PIN_SCK  = 12;
static const int PIN_MISO = 13;
static const int PIN_MOSI = 11;

static const int CS1 = 10;   // Sensor 1
static const int CS2 = 9;    // Sensor 2

SPIClass spi(HSPI);

// ---------------- IIS3DWB registers ----------------
#define REG_WHO_AM_I  0x0F
#define REG_CTRL1_XL  0x10
#define REG_CTRL3_C   0x12
#define REG_OUTX_L_A  0x28

#define WHO_AM_I_EXPECTED 0x7B
#define CTRL3_C_IF_INC    0x04
#define CTRL1_XL_ENABLE_3AXIS 0xA0   // XL_EN[2:0]=101, FS default ±2g

// 10 k sample sets/s per sensor
#define SAMPLE_RATE_HZ 10000UL
#define SAMPLE_PERIOD_US 100UL

// Stream in blocks to reduce serial overhead
#define BLOCK_SAMPLES 100

typedef struct __attribute__((packed)) {
  int16_t s1x;
  int16_t s1y;
  int16_t s1z;
  int16_t s2x;
  int16_t s2y;
  int16_t s2z;
} SampleSet;

// frame header: 0xA5 0x5A + uint16 sample_count
typedef struct __attribute__((packed)) {
  uint8_t sync1;
  uint8_t sync2;
  uint16_t count;
} FrameHeader;

static SampleSet blockBuf[BLOCK_SAMPLES];
static volatile bool streaming = false;
static uint32_t blockIndex = 0;
static uint32_t nextSampleUs = 0;

// ---------------- SPI helpers ----------------
static inline uint8_t cmd_read(uint8_t reg)  { return 0x80 | (reg & 0x7F); }
static inline uint8_t cmd_write(uint8_t reg) { return (reg & 0x7F); }

static inline void csHighAll() {
  digitalWrite(CS1, HIGH);
  digitalWrite(CS2, HIGH);
}

void writeReg(int csPin, uint8_t reg, uint8_t value) {
  digitalWrite(csPin, LOW);
  spi.transfer(cmd_write(reg));
  spi.transfer(value);
  digitalWrite(csPin, HIGH);
}

uint8_t readReg(int csPin, uint8_t reg) {
  digitalWrite(csPin, LOW);
  spi.transfer(cmd_read(reg));
  uint8_t value = spi.transfer(0x00);
  digitalWrite(csPin, HIGH);
  return value;
}

void readXYZRaw(int csPin, int16_t &x, int16_t &y, int16_t &z) {
  uint8_t data[6];

  digitalWrite(csPin, LOW);
  spi.transfer(cmd_read(REG_OUTX_L_A));
  for (int i = 0; i < 6; i++) {
    data[i] = spi.transfer(0x00);
  }
  digitalWrite(csPin, HIGH);

  x = (int16_t)((data[1] << 8) | data[0]);
  y = (int16_t)((data[3] << 8) | data[2]);
  z = (int16_t)((data[5] << 8) | data[4]);
}

bool initSensor(int csPin, const char *name) {
  uint8_t who = readReg(csPin, REG_WHO_AM_I);
  Serial.print(name);
  Serial.print(" WHO_AM_I = 0x");
  Serial.println(who, HEX);

  if (who != WHO_AM_I_EXPECTED) {
    return false;
  }

  writeReg(csPin, REG_CTRL3_C, CTRL3_C_IF_INC);
  writeReg(csPin, REG_CTRL1_XL, CTRL1_XL_ENABLE_3AXIS);
  delay(20);

  return true;
}

void flushBlock() {
  if (blockIndex == 0) return;

  FrameHeader hdr;
  hdr.sync1 = 0xA5;
  hdr.sync2 = 0x5A;
  hdr.count = (uint16_t)blockIndex;

  Serial.write((const uint8_t *)&hdr, sizeof(hdr));
  Serial.write((const uint8_t *)blockBuf, blockIndex * sizeof(SampleSet));
  blockIndex = 0;
}

void startStreaming() {
  blockIndex = 0;
  streaming = true;
  nextSampleUs = micros();
  Serial.println("STATE:STARTED");
}

void stopStreaming() {
  streaming = false;
  flushBlock();
  Serial.println("STATE:STOPPED");
}

void handleCommand(const String &cmdIn) {
  String cmd = cmdIn;
  cmd.trim();
  cmd.toUpperCase();

  if (cmd == "START") {
    startStreaming();
  } else if (cmd == "STOP") {
    stopStreaming();
  } else if (cmd == "PING") {
    Serial.println("STATE:READY");
  }
}

void pollSerialCommands() {
  static String cmd;
  while (Serial.available() > 0) {
    char c = (char)Serial.read();
    if (c == '\n' || c == '\r') {
      if (cmd.length() > 0) {
        handleCommand(cmd);
        cmd = "";
      }
    } else {
      cmd += c;
    }
  }
}

void setup() {
  Serial.begin(3000000);
  delay(1000);

  pinMode(CS1, OUTPUT);
  pinMode(CS2, OUTPUT);
  csHighAll();

  spi.begin(PIN_SCK, PIN_MISO, PIN_MOSI, -1);
  spi.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0));

  Serial.println("BOOT:INIT");

  if (!initSensor(CS1, "Sensor1")) {
    Serial.println("ERROR: Sensor1 not detected");
    while (1) delay(1000);
  }

  if (!initSensor(CS2, "Sensor2")) {
    Serial.println("ERROR: Sensor2 not detected");
    while (1) delay(1000);
  }

  Serial.println("STATE:READY");
}

void loop() {
  pollSerialCommands();

  if (!streaming) {
    delay(1);
    return;
  }

  uint32_t now = micros();
  if ((int32_t)(now - nextSampleUs) >= 0) {
    nextSampleUs += SAMPLE_PERIOD_US;

    int16_t s1x, s1y, s1z;
    int16_t s2x, s2y, s2z;

    readXYZRaw(CS1, s1x, s1y, s1z);
    readXYZRaw(CS2, s2x, s2y, s2z);

    blockBuf[blockIndex].s1x = s1x;
    blockBuf[blockIndex].s1y = s1y;
    blockBuf[blockIndex].s1z = s1z;

    blockBuf[blockIndex].s2x = s2x;
    blockBuf[blockIndex].s2y = s2y;
    blockBuf[blockIndex].s2z = s2z;

    blockIndex++;

    if (blockIndex >= BLOCK_SAMPLES) {
      flushBlock();
    }
  }
}
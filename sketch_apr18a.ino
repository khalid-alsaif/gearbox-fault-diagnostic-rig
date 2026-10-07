#include <ModbusMaster.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// -------------------- VFD / RS485 --------------------
HardwareSerial VFDSerial(1);
ModbusMaster node;

const int TXD1 = 17;
const int RXD1 = 18;
const int REDE = 16;

const float MAX_FREQ_HZ = 50.0;
const uint16_t REG_FREQ_CMD = 0x1000;
const uint16_t REG_RUN_CMD  = 0x2000;

// -------------------- DS18B20 --------------------
const int TEMP_PIN = 4;
OneWire oneWire(TEMP_PIN);
DallasTemperature sensors(&oneWire);

// -------------------- Temperature thresholds --------------------
const float TEMP_TRIP_C  = 32.0;
const float TEMP_CLEAR_C = 30.0;

// -------------------- Timing --------------------
unsigned long lastTempReportMs = 0;
const unsigned long TEMP_REPORT_INTERVAL_MS = 1000;

// -------------------- State --------------------
String inputLine = "";
bool thermalTrip = false;
float currentTempC = -127.0;

// ------------------------------------------------

void preTransmission() {
  digitalWrite(REDE, HIGH);
}

void postTransmission() {
  digitalWrite(REDE, LOW);
}

bool writeHolding(uint16_t reg, uint16_t val) {
  uint8_t result = node.writeSingleRegister(reg, val);
  return result == node.ku8MBSuccess;
}

uint16_t hzToPercentX100(float hz) {
  if (hz < 0) hz = 0;
  if (hz > MAX_FREQ_HZ) hz = MAX_FREQ_HZ;
  float pct = (hz / MAX_FREQ_HZ) * 100.0;
  return (uint16_t)(pct * 100.0 + 0.5);
}

bool vfdRun() {
  return writeHolding(REG_RUN_CMD, 1);
}

bool vfdStop() {
  return writeHolding(REG_RUN_CMD, 6);
}

void sendLine(const String &s) {
  Serial.println(s);
  Serial.flush();
}

void reportTemperature() {
  unsigned long now = millis();
  if (now - lastTempReportMs < TEMP_REPORT_INTERVAL_MS) return;
  lastTempReportMs = now;

  sensors.requestTemperatures();
  float t = sensors.getTempCByIndex(0);
  currentTempC = t;

  if (t == DEVICE_DISCONNECTED_C || t < -100 || t > 150) {
    sendLine("ERR TEMP_SENSOR");
    return;
  }

  sendLine("TEMP " + String(t, 2));

  if (!thermalTrip && t >= TEMP_TRIP_C) {
    thermalTrip = true;

    bool stopOk = vfdStop();

    sendLine("ALARM OVERTEMP " + String(t, 2));
    sendLine(String("ALARM_ACTION STOP=") + (stopOk ? "OK" : "FAIL"));
  }
  else if (thermalTrip && t <= TEMP_CLEAR_C) {
    thermalTrip = false;
    sendLine("ALARM_CLEAR " + String(t, 2));
  }
}

void handleSetCommand(float targetHz) {
  if (thermalTrip) {
    sendLine("ERR OVERTEMP " + String(currentTempC, 2));
    return;
  }

  uint16_t cmd = hzToPercentX100(targetHz);
  unsigned long t0 = millis();

  bool ok = writeHolding(REG_FREQ_CMD, cmd);
  unsigned long tWrite = millis() - t0;

  if (!ok) {
    sendLine("ERR WRITE_FREQ");
    return;
  }

  Serial.print("ACK SET ");
  Serial.print(targetHz, 2);
  Serial.print(" ");
  Serial.println(tWrite);
  Serial.flush();
}

void handleRunCommand() {
  if (thermalTrip) {
    sendLine("ERR OVERTEMP " + String(currentTempC, 2));
    return;
  }

  unsigned long t0 = millis();
  bool ok = vfdRun();
  unsigned long tWrite = millis() - t0;

  if (!ok) {
    sendLine("ERR WRITE_RUN");
    return;
  }

  Serial.print("ACK RUN ");
  Serial.println(tWrite);
  Serial.flush();
}

void handleStopCommand() {
  unsigned long t0 = millis();
  bool ok = vfdStop();
  unsigned long tWrite = millis() - t0;

  if (!ok) {
    sendLine("ERR WRITE_STOP");
    return;
  }

  Serial.print("ACK STOP ");
  Serial.println(tWrite);
  Serial.flush();
}

void handleCommand(String line) {
  line.trim();

  if (line.startsWith("SET ")) {
    float targetHz = line.substring(4).toFloat();
    handleSetCommand(targetHz);
    return;
  }

  if (line == "RUN") {
    handleRunCommand();
    return;
  }

  if (line == "STOP") {
    handleStopCommand();
    return;
  }

  sendLine("ERR BAD_CMD");
}

void setup() {
  Serial.begin(115200);

  pinMode(REDE, OUTPUT);
  digitalWrite(REDE, LOW);

  VFDSerial.begin(9600, SERIAL_8N2, RXD1, TXD1);
  node.begin(1, VFDSerial);
  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);

  sensors.begin();

  sendLine("READY");
}

void loop() {
  reportTemperature();

  while (Serial.available()) {
    char c = (char)Serial.read();

    if (c == '\n') {
      handleCommand(inputLine);
      inputLine = "";
    } else if (c != '\r') {
      inputLine += c;
    }
  }
}
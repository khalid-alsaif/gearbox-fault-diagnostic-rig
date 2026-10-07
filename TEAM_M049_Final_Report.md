# AI-Driven Gearbox Fault Diagnostic Rig - Original report text

 
 KING FAHD UNIVERSITY OF PETROLEUM & MINERALS   
  
Senior Design Project II 
Term # 252 
Team #049    
AI-Driven Automated Gearbox Failure Diagnostic Rig 
 
 
Name 
(Major) 
ID # Picture Name 
(Major) 
ID # Picture 
Fahad 
Almutairi 
(ICS)  
[student ID removed]  
  
Khalid 
ALsaif 
(COE)  
[student ID removed]  
  
Mohammed  
Aman (EE)  [student ID removed]  
  
 
Mana Al 
Abas (ICS)  
  
[student ID removed]  
  
Abdullah 
Alammari (ME)  [student ID removed]  
  
  
 
Abdullah 
Alotaibi (ME) 
 
 
[student ID removed] 
 
Date: 11/05/2026  
 

 
 
 KING FAHD UNIVERSITY OF PETROLEUM & MINERALS  
 
 
Team #049  
AI-Driven Automated Gearbox Failure Diagnostic Rig  
  
Faculty Name  Department  Role   
Dr. Bilal Qureshi  ME  Coach  
Dr. Naveed Iqbal  EE  Reviewer  
Dr. Omar Hammad  ICS  Reviewer  
Dr. Uthman Baroudi  COE  Reviewer  
  
    


  3  
 
 
Abstract  
This report presents the complete design, implementation, and validation of an AI-driven 
automated gearbox failure diagnostic rig for a single-stage spur gearbox. The system is 
designed to classify gearbox operating conditions into three predefined labels: Healthy, 
Chipped Tooth, and Missing Tooth. The project integrates mechanical design, electrical 
motor control, embedded data acquisition, and machine-learning-based diagnostic software 
into a unified laboratory-scale platform. 
The diagnostic software was fully implemented and successfully integrated with the 
completed hardware system. The application combines signal preprocessing, feature 
extraction, and machine-learning classification within a single executable program. An 
interactive graphical user interface allows users to input operating parameters, monitor 
system behavior, and visualize synchronized plots of rotational speed, applied torque, 
vibration waveform, and FFT spectrum in real time. The implemented machine-learning 
model achieved classification accuracy exceeding the required project specification and 
successfully distinguished between all predefined gearbox conditions during testing. 
From the electrical and embedded systems perspective, the PID-based motor speed control 
system, signal conditioning circuitry, and embedded data acquisition architecture were fully 
implemented and validated experimentally. The system successfully achieved stable motor 
speed regulation within the specified operating range, while the embedded subsystem 
provided synchronized vibration, speed, and torque acquisition with reliable communication 
between the ESP32 controller and the PC software interface. 
From the mechanical engineering perspective, the gearbox, shafts, bearings, couplings, and 
supporting test bench were fully designed, fabricated, assembled, and tested. Analytical 
calculations and CAD-based validation confirmed compliance with the required safety 
factors, power handling capability, and operational constraints. Safety features including 
rotating shaft guards and temperature-based emergency shutdown functionality were 
successfully integrated into the final prototype. 
The completed prototype demonstrates successful multidisciplinary integration and full-
system validation under laboratory operating conditions. Experimental testing confirmed that 
the system satisfies the specified requirements related to fault classification, response time, 
motor control, data acquisition, safety, and overall system integration. The final platform 

 
provides a practical and scalable foundation for predictive maintenance research, industrial 
condition monitoring, and engineering education applications. 
The project demonstrates a structured, multidisciplinary approach to vibration-based gearbox 
fault identification while maintaining defined safety limits, reproducibility, and offline-
trained machine-learning deployment. 
  

  5  
Acknowledgments  
The team would like to express sincere appreciation to Dr. Bilal Qureshi (ME) for serving 
as our project coach and for his continuous guidance, technical direction, and constructive 
feedback throughout the development of this senior design project. We also gratefully 
acknowledge our reviewers Dr. Naveed Iqbal (EE), Dr. Omar Hammad (ICS), and Dr. 
Uthman Baroudi (COE), for their valuable comments, insightful recommendations, and 
time invested in improving the quality and rigor of this work. In addition, we thank Dr. Neçar 
Merah for meeting with the team and sharing practical insights on gearbox failures and 
condition monitoring challenges in industrial rotating equipment. 
 
 
   

  6  
AI Declaration Statement   
Please complete the following table accurately to disclose your use of AI in the preparation of 
this report. Declaring the use of AI will not result in any penalties. However, irrespective of 
your AI declaration in the report, the grading rubric will be rigorously enforced, and any section 
or content that is vague, overly general, or fails to demonstrate a clear and direct connection to 
your project will be awarded a score of zero. This policy applies equally to both general and 
discipline-specific components of the report.  
  
Name of 
Student  
ID  Dep.  AI Usage  
Declaration  
Report Sections /  
Purpose of AI Assistance/  
Name of AI tool used  
Fahad  
Almutairi  
[student ID removed]  ICS  ChatGPT    
Utilizing ChatGPT for :   
Improving wording ,   
Brainstorming,   
Technical concepts of other 
displines  
, and enhancing readability.  
  
Chapter 1 + Section 2.4  
  
  
Mohammed  
Aman  
[student ID removed]  EE  ChatGPT  Searching for related academic 
papers, brainstorming,  
checking grammar  
  
Chapter 2   
  
  
Abdullah  
Alammari  
[student ID removed]  ME  ChatGPT    
Utilizing ChatGPT for the 
following:   
Brainstorming, research, 
proofreading, criticizing the 
mechanical design and the 
apparatus, papers suggestions.  
Proof reading.  
  
All chapters  
  

  7  
Abdullah  
Alotaibi  
[student ID removed]  ME  ChatGPT    
Utilizing ChatGPT for the 
following:   
 
Brainstorming, proofreading, and 
enhancing readability.  
  
1.3 + All of chapter 3, 4, and 5 
  
 
 
Khalid ALsaif  [student ID removed]  COE  ChatGPT    
Used ChatGPT in sections  
2.2.1, 2.2.2, 2.2.3 for  
Brainstorming, enhance  
readability  
  
Mana Al Abas  [student ID removed]  ICS  ChatGPT  Used in 2.2.4 and 2.2.5 to 
improve wording of concepts 
outside ICS bounds, and 
consistency sanity check.  
  
  
  
  
 
 
 
 
 
 
  
  

  8  
Table of Contents 
Chapter 1  Background ......................................................................................................................... 14 
1.1 Overview ................................................................................................................................. 14 
1.2 Introduction ............................................................................................................................. 15 
1.3 Fundamental Scientific and Engineering Concept .................................................................. 17 
ii. Relevant Basic Engineering Concepts .......................................................................................... 24 
Chapter 2  Project Definition ................................................................................................................ 30 
2.1 Project Summary ..................................................................................................................... 30 
A) Communication and Interface Standards: ................................................................................ 32 
B) Measurement and Data-Acquisition Standards (ADC/Data Quality): ..................................... 33 
2.2 Detailed Project Definition Discussion ................................................................................... 38 
2.3  Project Impact ................................................................................................................................ 54 
Chapter 4 Final DesignFinal Design ..................................................................................................... 77 
4.1. Overall Description .................................................................................................................... 77 
4.2. Detailed Design Description ...................................................................................................... 80 
4.2.1. COE Discipline details: ....................................................................................................... 80 
4.2.2. ICS Discipline Details ......................................................................................................... 87 
4.3. Final Design Analysis and Results ............................................................................................. 93 
4.3.1. Final Design Analysis ............................................................................................................. 93 
4.4. Bill of Material ......................................................................................................................... 120 
4.5. Cost Analysis ........................................................................................................................... 121 
4.6 Engineering Drawing ................................................................................................................ 122 
Chapter 5 ............................................................................................................................................. 126 
Prototype Implementation and Verification ........................................................................................ 126 
5.1.1 Prototype Build ...................................................................................................................... 128 
5.1.1.1 ME Contribution to Prototype Build ................................................................................... 128 
5.1.1.2. ICS Contribution to Prototype Build ................................................................................. 132 
5.1.1.3. COE Contribution to Prototype Build: ............................................................................... 132 
5.1.1.4. EE Contribution to Prototype Build ................................................................................... 136 
5.1.2 Safety ..................................................................................................................................... 140 
5.1.3 Cost ........................................................................................................................................ 143 
5.2 Verification Test Description .................................................................................................... 145 
ML diagnosis model results ........................................................................................................ 161 

  9  
5.4. Future Manufacturing Recommendation ................................................................................ 170 
Chapter 6 Conclusions and Recommendations ................................................................................... 172 
6.1. Conclusion ............................................................................................................................... 172 
6.2. Future Work ............................................................................................................................ 173 
References ........................................................................................................................................... 174 
 
  

  10  
List of Figures  
  
Figure 1: signal chain ....................................................................................................................... 19 
Figure 2: Anti-alias filtering ............................................................................................................. 21 
Figure 3: ICS Data-Flow Digram ..................................................................................................... 24 
Figure 4 Control Architeture ............................................................................................................ 26 
Figure 5: Project DFQ ...................................................................................................................... 54 
Figure 6: Multidisciplinary Prototype Summary ............................................................................. 63 
Figure 7: electrical schematic for project prototype ......................................................................... 64 
Figure 8: Closed-Loop Eddy-Brake Rig. ......................................................................................... 69 
Figure 9: Manual-Brake Teaching Rig. ............................................................................................ 70 
Figure 10: Supported Brake + Triple Flexible Couplings Rig. ........................................................ 71 
Figure 11:  Spider Chart ................................................................................................................... 76 
Figure 12: Project Block Diagram. .................................................................................................. 77 
Figure 13: Overall COE System Design. ......................................................................................... 80 
Figure 14 Software Subsystem diagram........................................................................................... 88 
Figure 15: Electrical schematic for the Power system. .................................................................... 89 
Figure 16: Block diagram for the DAQ system. .............................................................................. 90 
Figure 17: Mechanical Block Diagram. ........................................................................................... 91 
Figure 18: visualization of cyclostationarity of gear vibration signals. ........................................... 94 
Figure 19: electrical schematic for protection of power subsystem. .............................................. 103 
Figure 20: factor of safety. ............................................................................................................. 105 
Figure 21: module against contact factor of safety......................................................................... 105 
Figure 22: Module against binding factor of safety. ...................................................................... 106 
Figure 23: bearing performance from SKF. ................................................................................... 106 
Figure 24: Shigley’s mechanical engineering best practice. .......................................................... 107 
Figure 25: Factor of safety graph for aluminum. ........................................................................... 107 
Figure 26: Deflection graph for Aluminum.................................................................................... 108 
Figure 27: Slopes for the Aluminum. ............................................................................................. 108 
Figure 28: factor of safety for steel. ............................................................................................... 108 
Figure 29: Deflection for steel. ...................................................................................................... 109 
Figure 30: slopes for steel. ............................................................................................................. 109 
Figure 31: selected coupling specifications. .................................................................................. 110 
Figure 32: Bench dimensions. ........................................................................................................ 112 

  11  
Figure 33: Mechanical guards ........................................................................................................ 113 
Figure 34: VFD datasheet showing PID built-in function. ............................................................ 115 
Figure 35: Gear Box assembly Drawing. ....................................................................................... 122 
Figure 36: Total assembly. ............................................................................................................. 123 
Figure 37: Shafts Cad. .................................................................................................................... 124 
Figure 38: electrical schematic for the power subsystem............................................................... 124 
Figure 39: Electrical schematic for the Power system. .................................................................. 125 
Figure 40 Detailed ML Model Flow Diagram ............................................................................... 139 
Figure 41 Software frontend with load and speed profile controls ................................................ 140 
Figure 42 Breal torque ................................................................................................................... 145 
Figure 43 VFD readings, (a) 42.86 Hz, and (b) 2.29 kW of power. .............................................. 146 
Figure 44 window-level accuracy for ML model ........................................................................... 150 
Figure 45 RAM usage during training ........................................................................................... 163 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

  12  
 List of Tables  
Table 1: Project Constraints and Specifications (Details of each are in the previous two sections). .... 36 
Table 2: Discipline Specific Courses. ................................................................................................... 64 
Table 3: Team Management. ................................................................................................................. 67 
Table 4: Summary of Project Constraints and Specifications Attainment in the Final Design. .......... 117 
Table 5: Bill of material. ..................................................................................................................... 120 
Table 6: Leave-One-Speed-Out results. .............................................................................................. 161 
Table 7: classification report. .............................................................................................................. 162 
Table 8: permutation test. .................................................................................................................... 162 
Table 9: Summary of Project Constraints and Specifications Attainment in the Prototype. ............... 167 
 
  
  

  13  
List of Abbreviations  
 ISO  International Organization for standardization   
AI                          Artificial intelligence   
VFD                       Variable Frequency Drive  
RPM                       Revolution per Minute  
ML                          Machine Learning   
API RP                    American Petroleum Institute Recommended Practice   
OSHA                      Occupational Safety and Health Administration   
ANSI/AGMA           American National Standards Institute            
CAD                          Computer Aided Design      
IEEE        Institute of Electrical and Electronics Engineers  
IEC        International Electrotechnical Commission  
SNR        Signal to Noise Ratio.   
MCU        Microcontroller Unit  
ENOB   
    Effective Number Of Bits  
 
NSPE  National society of professional engineers 
  
  
  
  
  
  
  
  
  
  
  
  

 
Chapter 1  Background  
1.1 Overview 
Gearboxes are widely used in industrial power transmission systems, and 
their failure can result in significant downtime, maintenance cost, and 
secondary mechanical damage. Many gearbox faults develop progressively, 
making early identification critical to prevent severe damage and unplanned 
outages. However, maintenance personnel often rely on scheduled 
inspections or gearbox disassembly to confirm fault conditions, both of 
which are time-consuming, costly, and disruptive to operations. 
Existing diagnostic approaches frequently depend on expert interpretation 
of vibration data or access to operational machinery, limiting repeatability, 
and making controlled evaluation of fault behavior difficult. Additionally, 
industrial gearboxes cannot be intentionally damaged for experimentation, 
restricting opportunities to study fault signatures and evaluate maintenance 
decision-making under known conditions.  
To address these limitations, this project delivers a gearbox fault 
identification testing bench that integrates a physical gearbox test rig, 
vibration and speed sensing, data acquisition, and diagnostic software into a 
single, demonstrable platform. The system enables gearbox condition to be 
evaluated before disassembly, supporting maintenance teams in deciding 
whether teardown is necessary. By operating under controlled laboratory 
conditions, the testing bench allows repeatable measurement of vibration 
responses associated with healthy and faulted gearbox states.  
The accompanying diagnostic software processes acquired vibration data, 
extracts representative features, and applies a machine-learning classifier to 
identify the most likely gearbox condition. Together, the testing bench and 
software provide a complete, maintenance-oriented workflow for 
demonstrating vibration-based gearbox fault identification in a safe, 
repeatable, and accessible laboratory environment.  

  15  
  
 
1.2 Introduction 
 
i Need for the Product  
Gearboxes are critical components in power transmission systems, and failures in 
gearbox elements such as gears and bearings can lead to increased vibration, 
performance degradation, and unplanned downtime. Because gearbox faults often 
develop progressively, early detection is essential to prevent secondary damage 
and costly failures. Traditional maintenance strategies based on fixed inspection 
intervals or reactive repair often fail to identify faults early enough to avoid 
extensive damage.  
Additionally, maintenance personnel frequently rely on gearbox disassembly to 
confirm fault conditions, which are labor-intensive and disruptive to operations. 
There is a clear need for a non-invasive, repeatable method that can indicate 
gearbox condition prior to disassembly, reducing unnecessary teardown and 
supporting informed maintenance decisions.  
  
ii Relevance to Industry  
Gearbox condition monitoring is relevant across a wide range of industries, 
including manufacturing, transportation, energy production, and wind power 
systems. At an industry scale, the National Institute of Standards and Technology 
(NIST) estimates that machinery failures contribute to approximately $16 billion 
annually in downtime and maintenance costs [1]. In the wind energy sector, 
gearbox-related issues account for roughly 20% of failures or downtime in 
geared wind turbines [2], highlighting the operational and economic significance 
of reliable gearbox diagnostics.  
There is growing interest in diagnostic systems that can assist maintenance 
planning without requiring full disassembly. Testing benches provide an accessible 

  16  
means to evaluate and demonstrate such diagnostic workflows before 
implementation in higher-risk industrial environments.  
  
 
  
iii Evaluation of Current Solutions  
Current gearbox diagnostic practices often rely on manual inspection, scheduled 
maintenance intervals, or expert interpretation of vibration measurements using 
time- and frequency-domain analysis. These approaches depend heavily on 
operator experience and may result in inconsistent diagnosis or delayed fault 
identification. While data-driven and machine learning–based diagnostic methods 
have been increasingly explored in research and industry. Traditional vibration-
based monitoring methods rely heavily on expert-designed features (e.g., envelope 
spectra) and often generalize poorly to unseen operating conditions, requiring 
careful expert interpretation and re-tuning [3].  
Furthermore, experimentation on faulty gearboxes is difficult in practice because 
industrial equipment cannot be intentionally damaged for testing. This limitation 
restricts opportunities to study fault behavior under known conditions and to 
evaluate diagnostic decision-making prior to maintenance actions. As a result, 
there is a need for diagnostic platforms that enable safe, repeatable testing of 
gearbox faults while bridging the gap between theoretical diagnostic methods and 
practical maintenance-oriented applications.  
  
  
 
 
 
 
 
 

  17  
 
1.3 Fundamental Scientific and Engineering Concept 
This section presents the fundamental scientific, computational, and engineering 
principles underlying the design and operation of the gearbox fault identification 
testing bench. The project integrates mechanical dynamics, vibration 
measurement, signal processing, and machine learning into a unified diagnostic 
system. The concepts discussed below form the theoretical foundation for the 
physical testing bench, data acquisition, and diagnostic software developed in this 
project.  
  
i. Relevant Scientific and Computational Techniques  
Gear Meshing Dynamics and Fault-Induced Vibration, Gearbox design 
(ME) 
A gearbox transmits mechanical power through the periodic meshing of gear 
teeth. During normal operation, this meshing process generates predictable 
dynamic forces at frequencies related to the rotational speed of the shaft and the 
gear mesh frequency (GMF). The gear mesh frequency is defined as:  
𝑓𝐺𝑀𝐹 = 𝑁×𝑓𝑠ℎ𝑎𝑓𝑡  
𝑓𝑠ℎ𝑎𝑓𝑡 = 60/RPM 
Where N is the number of gear teeth and  fshaft  is the shaft’s rotational frequency.  
In a healthy gearbox, the meshing forces are relatively uniform, resulting in stable 
vibration signatures dominated by harmonics of the gear mesh frequency. These 
vibrations propagate through the gearbox structure and can be measured externally 
using vibration sensors.  
Gear tooth faults such as chipped, broken, or missing teeth disrupt the regular 
meshing process. Each of these faults will result in different frequency. For 

  18  
example, a messing tooth have an impact once every revolution, therefore, when a 
frequency equal to the shaft speed in noticed, it can be a result of a missing tooth.    
The gears’ teeth will be designed against bending and pitting failure, so we can 
exclude failure during the testing, and we can control the fault and inject them 
ourselves so we can extract the vibration features ourselves. After that the shaft 
diameter and material will be selected based on torque, then the bearing will be 
selected based on the shaft diameter and load. After that the bench will be 
designed against static failure along with a adjustability to a accommodate 
gearboxes of different sizes.  
  
Power system, motor control, DAQ, and signal processing (EE)  
1- Applying power formula to understand the relation between the 
motor power rating and the electrical current of the system  
Since we are the project include a relatively large induction motor and a 
VFD, it is 
𝑛𝑒𝑐𝑒𝑠𝑠𝑎𝑟𝑦 𝑡𝑜 𝑒𝑛𝑠𝑢𝑟𝑒 𝑠𝑎𝑓𝑒 𝑜𝑝𝑒𝑟𝑎𝑡𝑖𝑜𝑛 𝑜𝑓 𝑡ℎ𝑒 𝑟𝑖𝑔. 𝑇ℎ𝑖𝑠 𝑖𝑠 𝑑𝑜𝑛𝑒 𝑏𝑦 𝑎𝑝𝑝𝑙𝑦𝑖𝑛𝑔 𝑡ℎ𝑒 𝑝𝑜𝑤𝑒𝑟 
formula that states 𝑃 = 𝐼𝑉. This equation will help in determine the 
required for the cable sizing and circuit breakers from the supply and VFD 
input side. From the motor side the equation𝑃 = 𝑠𝑞𝑟𝑡(3)𝐼𝑉 cos 𝑐𝑜𝑠 
(𝑡ℎ𝑒𝑡𝑎) will be used since the motor is  
three phase.  
2- Applying Nyquist criterion to calculate the required sampling 
frequency  
Nyquist Criterion is needed to accurately capture the vibration signals of 
the gearbox.  
It states that 𝑓𝑠𝑎𝑚𝑝𝑙𝑖𝑛𝑔≥ 2 ∗ 𝐵𝑊 . This will ensure anti-aliasing  
3- Utilizing cut-off frequency equations to calculate the values of the 
analog filter elements   
To support the signal processing task and ensure signal quality, an 
analog low-pass filter will be used, and the following equation is needed 
to design the filter : 𝑓𝑐 =
1
𝟐𝒑𝒊∗𝑹𝑪   

  19  
 
 
COE Perspective:  
1) From physical vibration to digital data (signal chain concept)  
In our rig, “vibration” is measured as acceleration using accelerometers mounted 
on the gearbox housing. The accelerometer outputs an electrical signal 
proportional to acceleration (typically volts per g). The signal chain is:  
   
 
Figure 1: signal chain 
  
   
2) Sampling theory (why we require ≥10 kS/s per channel)  
When an analog signal is sampled at a sampling rate 𝑓𝑠, the highest frequency 
component that can be represented without distortion is the Nyquist frequency:  


  20  
   
𝑓Nyquist = 𝑓s/2 
 
  
To capture vibration content up to 𝑓max, we need:   
𝑓𝑠 ≥ 2𝑓max 
  
  
In practice, we sample higher than 2𝑓max  because real systems also need anti-
alias filter margin. For our rig, we target meaningful diagnostic content up to 
roughly 4 kHz, so:  
● Minimum theoretical.    
● Practical choice. 
 
 
Aliasing (what goes wrong if sampling is too low)  
If the signal contains energy above , it will fold into the band as a false 
frequency. A simple aliasing relationship is:  
  
  
  
Example: If a real vibration component is at 3.2 kHz and you sample at 5 kS/s, it 
may appear at 1.8 kHz. That can mislead both human interpretation and ML 
models.  
   
   
3) Anti-alias filtering  
Even if we sample at 10 kS/s (Nyquist = 5 kHz), we still need an analog low-pass 
filter before the ADC so that frequencies above the usable band do not fold into 
it.  
A typical requirement is:  
● Usable diagnostic band: 0–4 kHz  
● Anti-alias behavior: attenuate strongly near/above 5 kHz  
  


  21  
 
Figure 2: Anti-alias filtering 
  
   
   
4) ADC fundamentals: quantization, noise, and ENOB  
Quantization step and maximum quantization error  
An N-bit ADC divides the full-scale range (FSR) into steps. The code width (LSB 
size) is:  
  
  
  
For an ideal ADC that rounds to nearest code, the maximum quantization error is:  
 
 
Example: if the True value led between the levels L1 and L2, the worst case is that it 
becomes exactly at the middle between the levels, so the quantized value will be far 
from true value by      (L2-L1)/2  
  
Quantization noise (RMS)  
If quantization error is modeled as uniformly distributed:  
   
  


  22  
   
   
ENOB (Effective Number of Bits)  
Even if an ADC is labeled “16-bit,” the effective performance may be lower due to 
noise and distortion. ENOB is derived from measured SINAD:  
  
  
  
Our project requirement “ENOB ≥ 14 bits in 0–4 kHz”  is essentially saying:  
in the frequency range we care about for gearbox faults, the chain behaves like 
a real 14-bit measurement system (not just “bits on paper”).  
This is important because ML features (spectral peaks, harmonics, kurtosis, etc.) 
degrade quickly if the signal-to-noise level is poor.  
   
 
 
Fault Classification Using Machine Learning (ICS)  
Gearbox fault identification is formulated as a supervised multi-class 
classification problem under controlled conditions. Each feature vector 
corresponds to a predefined gearbox condition:  
● Class 0: Healthy  
● Class 1: Chipped gear tooth fault  
● Class 2: Missing gear tooth fault  
Classical machine learning models, such as Support Vector Machines (SVMs), 
are well suited for this application because they perform effectively on small, 
feature-based datasets and provide stable, well-defined decision boundaries. SVMs 
classify input feature vectors by maximizing the margin between classes in feature 
space, improving generalization under limited training data.  
The classification process consists of two stages:  


  23  
1. Offline Training: Labeled vibration data from a publicly available 
gearbox dataset are processed using the same signal processing and 
feature extraction pipeline to train the classifier.  
2. Online Assessment: During system operation, vibration data from the 
testing bench are processed in real time and evaluated by the pre-trained 
classifier to determine the most likely gearbox condition.  
Offline training is necessary because reliable machine learning models require 
sufficiently large and well-labeled datasets, which cannot be practically obtained 
through limited testing alone.   
To clarify how the supervised classification process is implemented in software. 
The bellow UML diagram presents the ICS software data-flow diagram used in 
this project. The diagram illustrates the separation between offline model training 
and online fault assessment, and shows how vibration data are transformed 
through preprocessing, feature extraction, and classification stages before 
producing diagnostic outputs. This software-level view complements the system-
level architecture by explicitly depicting the flow of data within the diagnostic 
analysis software.  
  

  24  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
ii. Relevant Basic Engineering Concepts  
COE Perspective:  
1) Real-time embedded architecture: interrupts, DMA, and buffering  
For multi-channel high-speed acquisition, a microcontroller must avoid CPU-heavy 
polling. The COE design uses:  
● DMA (Direct Memory Access) to move ADC samples into RAM without 
CPU intervention  
Figure 3: ICS Data-Flow Digram 

  25  
● a ring buffer (circular buffer) to absorb timing variation between sampling 
and transmission  
● interrupt-driven events for encoder edges and sync pulses  
   
2) Throughput engineering   
A practical COE step is to compute required data rate:  
  
  
  
Example (6 channels, 10 kS/s, 16-bit):  
  
  
  
Even with headers and timestamps, this is comfortably below 100 Mbps Ethernet, 
which supports stable real-time streaming.  
   
   
3) Communication reliability: framing, sequence numbers, and integrity checks  
When streaming data, COE design choices determine whether “no data loss” is 
actually verifiable:  
● sequence numbers per packet/frame to detect gaps  
● timestamps so the host can verify sampling consistency  
● CRC/checksum to detect corruption (important in EMI environments)  
This turns “continuous logging” into a measurable requirement instead of a vague 
statement.  
   
4) Client–Server Communication Between PC and MCU (Control + Telemetry)  
In our system, the microcontroller (MCU) is not only a data acquisition device; it 
also acts as a control gateway between the PC (user interface + AI) and the motor 
drive (VFD). This requires a bidirectional communication architecture where the 
PC can issue commands (e.g., change speed), while the MCU continuously 
streams synchronized sensor data back to the PC.  
Architecture and roles:  
A clean way to implement this is:  
● PC (Client): sends commands such as Start Test, Set Speed, Stop, Request 
Status, and displays live measurements.  


  26  
● MCU (Server): exposes a command interface (“API”), validates commands 
for safety, translates them into VFD actions (typically Modbus/RS-485), 
and streams telemetry + sensor data back to the PC.  
A simple diagram:  
 
Figure 4 Control Architeture 
  
   
5) Integration mindset (COE as the bridge)  
COE work is most valuable in integration: turning multiple subsystems into one 
product-like system with predictable behavior:  
● synchronized time base across sensors  
● consistent data format for logging and ML  
● reliable streaming and error detection  
● clear interfaces to ME (mounting constraints) and EE (power/isolation)  
 
 
 
  
Mechanical System Design and Testing Bench Integration (ME)  
● Rotational dynamics and operating point control  
 The rig must run at repeatable speed and load because gearbox vibration 
depends on torque and angular speed (P=Tω). Holding stable operating 
points improves consistency of the measured fault signatures.  
● Shaft alignment (parallel and angular misalignment)  


  27  
 Motor-coupling-gearbox alignment must be controlled because 
misalignment introduces extra radial forces and bending moments. These 
effects often increase vibration, which can obscure gear-mesh fault 
patterns used to detect gear faults.  
● Bearing selection and support strategy  
 Bearings, in the gearbox and the supported brake, must be chosen to carry 
expected radial and axial loads at the target speed without excessive 
clearance or overheating. Proper bearing support reduces shaft orbit, 
minimizes unintended vibration sources, and improves repeatability 
measurement.  
● Structural adjustability   
 The bench must be adjustable so it can accommodate different dimensions 
for gearboxes   
● Machining the Faults in gears  
We will machine faults in gears but first we have to decide the severity of 
these faults.  
  
   
Power system, motor control, DAQ, and signal processing (EE)  
1- Applying circuit design principle and Induction machines working 
principle to design the values of required components (motor rating, 
circuit breakers current, resistor, capacitors values)  
To design the electrical system, we need to begin with the mechanical 
requiremnts, specifically:𝑃 = 𝑡⋅𝑤 , where t is torque and w is the angular 
speed. Since the maximum required torque and speed are 10N.m and 1200 
rpm, the required motor rating will be around 1.5 kW. (rpm should be 
converted into rad/sec to use the formula)  
Additionally, Power formula should be used to find the proper sizing of 
the cables and breakers. This done by  P = IVcos(theta) for the single-phase 
side and P = sqrt(3)*I*V*cos(theta) for the three-phase side.   

  28  
2- Applying closed loop feedback techniques to control the speed and 
toque of the motor  
Closed loop is essential to ensure stable and repeatable operation. The 
control parameter can be chosen by the formula  
𝑘
𝑡𝑠+1  where K is the 
speed gain (which can be controlled using the microcontroller or𝑡𝑠 the 
VFD in our project) and t is the Setting time constant. By analyzing our 
system the motor equation is: 𝐽 ∗
𝑑𝑤
𝑑𝑡 + 𝐵𝑤 = 𝑇𝑒 −
𝑇𝐿, 𝑤ℎ𝑒𝑟𝑒 𝐽 𝑖𝑠 𝑡ℎ𝑒 𝐼𝑛𝑒𝑟𝑡𝑖𝑎, 𝑤 𝑖𝑠 𝑎𝑛𝑔𝑢𝑙𝑎𝑟 𝑠𝑝𝑒𝑒𝑑, 𝐵 𝑖𝑠 𝑡ℎ𝑒 𝑓𝑟𝑖𝑐𝑡𝑖𝑜𝑛, 
Te and TL are electromagnetic torque and mechanical torque respectively.  
The with the addition of the gain from the VFD the control equation 
becomes 
𝐾𝑣𝑓𝑑
𝐽𝑠+𝐵  . 𝑤ℎ𝑟𝑒𝑟𝑒 𝐾𝑣𝑓𝑑𝑖𝑠 𝑡ℎ𝑒 𝑐𝑜𝑛𝑡𝑟𝑜𝑙𝑙𝑒𝑟 𝐾𝑝 +
𝐾𝑖
𝑠   In order to have 
a stable response, the poles should be in the left half plane which is done 
by tuning. 
3- Applying filter design principles to ensure clean SNR and anti-aliasing  
Filter design is needed to ensure signal quality by removing high 
frequency noise an analog low -pass filter will be used, and the following 
equation is needed to design the filter: 𝑓 = 
1
2∗𝑝𝑖∗𝑅𝐶 .R and C will be chosen 
by design, and f can be determined by𝑓 = 
𝑅𝑃𝑀∗ #𝑜𝑓𝑡𝑒𝑒𝑡ℎ
60 . 
Furthermore, in order to measure the signal quality, we need to find 
the quantization noise of the analog signals which is 
𝑉
2∗2#𝑏𝑖𝑡𝑠. Using 
V=3.3V and #bits = 16. 𝑁𝑜𝑖𝑠𝑒𝑞𝑢𝑎𝑛𝑡𝑖𝑧𝑎𝑡𝑖𝑜𝑛 = 0.025𝑚𝑉.  Even if an ADC 
is labeled “16-bit,” the effective performance may be lower due to noise 
and distortion. ENOB is derived from measured SINAD:  
SINAD = 20𝑙𝑜𝑔(
𝑠𝑖𝑔𝑛𝑎𝑙 𝑝𝑜𝑤𝑒𝑟
𝑛𝑜𝑖𝑠𝑒 𝑝𝑜𝑤𝑒𝑟 ) = 20𝑙𝑜𝑔(
3.3
0.025∗10−3) = 102.4 
ENOB =
102.4−1.76
6.02 = 16.65 𝑏𝑖𝑡= 16 𝑏𝑖𝑡𝑠 
 
 
  

  29  
4- Programming the microcontroller to synchronize between different 
sensors  
Since we will be using different sensors in this project, synchronizing 
between the sensors using the microcontroller is one of the tasks needed. 
This will be done be programming a timer/interrupt to ensure 
synchronization  
5- Designing the system architecture and electrical schematics of the 
system  
(motors sensors placement, Signal conditioning)  
Designing the system architecture is needed as it helps users understand 
how the system works. Tools such as Simulink, AutoCAD electrical, 
Multisim can be used to draw the electrical system and architecture  
 
 
  
Software-Based Diagnostic Integration (ICS)  
Information and Computer Science principles are applied to implement the 
diagnostic workflow, including data handling, feature extraction pipelines, and 
classification logic. The software integrates physical measurements with 
computational models, presenting diagnostic results through a user-facing interface 
that supports maintenance decision-making rather than autonomous control.  
  
System-Level Integration of Physical and Data-Driven Concepts  
The testing bench integrates mechanical excitation, vibration sensing, data 
acquisition, and computational classification into a unified engineering system. 
Mechanical faults generate physical vibration signatures, sensors convert these 
responses into electrical signals, DAQ hardware preserves signal integrity, and 
software-based analysis maps measured features to diagnostic outcomes. This 
integration demonstrates gearbox fault diagnosis as a complete engineering system 
rather than an isolated algorithm or simulation.   

  30  
 
Chapter 2  Project Definition  
  
This chapter discusses the statement and primary goals of the project: AI 
driven gearbox failure diagnostic rig. Section 2.1 provide a summary of the 
project, including a concise project statement, specific objectives, tangible 
deliverables, list of customer needs and measurable specifications 
  
2.1 Project Summary 
2.1.1 Project Statement  
The gearbox diagnostic rig will provide and display an accurate detection of the 
type of failure a gearbox has (healthy, chipped teeth, missing teeth), using AI 
classification and sensors technology.  
2.1.2 Project Objectives Statement  
This project aims to design a portable, AI-enabled rig that can simulate variable 
speed and load conditions to acquire clean vibration and torque data to classify the 
type of failure (healthy, chipped tooth, missing tooth ) for a specific type of 
gearbox (One stage spur gear)  by developing and using an AI model with an 
accuracy of 70% for that type of gearbox and displaying it on a dashboard, without 
the need for technical background or expertise.  
2.1.3 Deliverables  
1. Complete mechanical design package for the diagnostic rig (gearbox test 
bench, motor–gearbox–brake layout, sensor mounting points), including 
finalized CAD drawings and a manufacturing-ready BOM.  
2. Assembled and operational physical prototype of the gearbox diagnostic 
rig (motor + VFD drive, test gearbox, brake/loading unit, couplings, 
guarded bench structure) capable of running controlled tests in the project 
speed range.  
3. Integrated sensor and data-acquisition subsystem (vibration, 
torque/load, and RPM/encoder) with verified sampling performance (≥10 
kS/s per high-speed channel) and synchronized time-stamping suitable for 
condition monitoring.  

  31  
4. Embedded control and communications module that streams real-time 
synchronized sensor data to the host computer via a wired interface and 
supports safe start/stop and interlock signaling.  
5. AI fault-detection software package (data pipeline + feature extraction + 
trained model) that classifies gearbox health states using the collected 
multi-sensor dataset, with documented evaluation results (confusion 
matrix, accuracy, and test conditions).  
6. User dashboard application for live monitoring and test management, 
displaying RPM, torque/load, vibration indicators, system status, and fault 
alerts with export options.  
7. Final presentation and live demonstration showing the rig operating 
under controlled conditions with real-time monitoring and automated fault 
classification.  
  
2.1.4 Customer Needs  
The following needs reflect the expectations of direct stakeholders, including 
maintenance centers, academic researchers, and students/fresh engineers and they 
are categorized into three categories (critical, performance related, nice-to-have):  
A. Critical (Must have)  
1. Cost-effective: the system must have a low total cost of ownership and 
affordable for small maintenance/academic departments  
2. Reliable repeatable results: the system must provide repeatable and 
accurate diagnostic measurements to ensure valid results  
3. Safe operation: The system must ensure user safety from rotating 
machineries  
B. Performance related (should have to be competitive)  
4. Data Accessibility: the system should enable simple access to verify 
results and export logs of data (vibration, speed, torque) for data analysis  
5. Operational flexibility: the rig should be capable of testing gearboxes 
under various operating and testing conditions.  
C. Desirable (nice to have, optional):  
6. Fast setup and alignment: the System allows for fast setup and tolerate 
minor shaft misalignment.  

  32  
7. Portability: the system fit within a standard benchtop footprint to suit 
typical environments  
 
 
 
 
 
 
  
2.1.5 Standards and Regulations   
Relevant standards and regulations and standards from different 
disciplines are discussed in this section   
2.1.5.1 Mechanical Engineering Standards: 
● ISO 14120: General requirements for the design and construction of fixed and 
movable guards 
● OSHA 29 CFR 1910.219: guarding for mechanical power-transmission apparatus 
● ISO 17359: gives guidelines for the general procedures to be considered when 
setting 
up a condition monitoring programme for machines 
● API RP 686: provide recommended procedures, practices, and checklists for the 
installation and recommissioning of new, existing, and reapplied machinery and 
to assist with the installation design. 
 
2.1.5.2 Computer Engineering Standards: 
A) Communication and Interface Standards: 
• USB Communications Device Class (CDC), Revision 1.2 (USB-IF) 
 We use USB-CDC so the ESP32 appears as a standard Virtual COM Port on the 
PC, avoiding custom drivers and making the UI/logger easy to deploy on lab PCs. 
This standard guides how the PC and MCU exchange bulk data reliably over a serial-
style USB link.  
Design implications: we stream binary “data blocks” (not per-sample messages) to 

  33  
reduce overhead, and we keep control messages lightweight to avoid disturbing the 
sampling pipeline. 
• Modbus over Serial Line (Modbus RTU) – Specification/Implementation Guide 
 The VFD (LNC820) telemetry and speed commands are handled using Modbus RTU 
principles (“client/server” messaging over serial lines). This standard defines the 
request/response structure and is widely used for industrial drives.  
Design implications: we separate (a) time-critical vibration sampling from (b) low-
rate Modbus polling (speed/torque), and we log VFD values with timestamps so they 
can be aligned with vibration blocks on the PC. 
• ANSI/TIA/EIA-485-A (RS-485 Physical Layer) 
 RS-485 defines the electrical characteristics of balanced (differential) multipoint 
serial interfaces, which is the standard physical layer used in many industrial 
Modbus links.  
Design implications: we use shielded twisted-pair cabling, proper grounding/shield 
practices, and (when needed) termination/biasing to maintain signal integrity in a 
VFD environment. 
B) Measurement and Data-Acquisition Standards (ADC/Data Quality): 
• IEEE Std 1241 – Terminology and Test Methods for Analog-to-Digital 
Converters 
 Our measurement performance claims (like ENOB, quantization behavior, and 
bandwidth validity) should follow an accepted definition and test approach rather than 
“marketing numbers.” IEEE 1241 provides common terminology and test methods for 
evaluating ADC performance.  
 
2.1.5.3 Electrical Engineering Standards: 
● IEEE 841: Standards for Totally Enclosed Squirrel Cage Induction Motors from 
0.75 
kW to 370 kW (1 hp to 500 hp). 
● IEC 61800--2 Adjustable speed electrical power drive systems - general 
requirements. 
● IEC 60034: Rotating electrical machines: Rating and performance 
● IEEE 1451: Standard for a smart transducer interface for Sensors and Actuators 

  34  
● ISO 13373-1: Condition monitoring and diagnostics of machines — Vibration 
condition monitoring. 
● IEEE1241: Standard for Terminology and Test Methods for Analog-to-Digital 
Converters. 
● IEEE 1683: Guide for Motor control rated up to and including 600VAC or 1000 
VDC 
 
 
 
 
2.1.6 Constraints   
● Constraint 1: Total project hardware & Software cost ≤ 15000 
SAR  
● Constraint 2: The rig should only be able to work on single stage 
spur gearboxes  
● Constraint 3: Maximum system dimensions shall not exceed 2 
meters by 1 meter  
● Constraint 4: The machine-learning model shall be trained 
offline prior to system operation and shall not perform adaptive or online 
learning during gearbox testing.  
● Constraint 5: The embedded sensing subsystem shall use a 
temperature sensor rated for −55°C to +125°C .  
● Constraint 6: The system shall be controller by a PID controller. 
  
2.1.7 Specifications    
• Specification 1: Flexible shaft coupling shall tolerate at least 0.1 mm 
parallel misalignment between motor and gearbox shafts at rated speed  
• Specification 2: 100% of exposed rotating components shall be covered 
by fixed mechanical guards during operation for safety   
• Specification 3: The system shall apply a variable mechanical load from 0 
Nm to 10 Nm  
• Specification 4:  

  35  
The diagnostic software shall integrate signal preprocessing, feature 
extraction, machine-learning classification model, and a friendly user-
facing interface within a single executable application 
• Specification 5: The front end of the software shall provide a user 
interface that allows the user to input test  two operating parameters 
(rotational speed and applied load) and shall display four synchronized 
visualizations: rotational speed, applied torque, vibration time-domain 
waveform, and vibration frequency-domain spectrum (FFT). 
• Specification 6:  
The backend diagnostic software shall achieve a minimum overall 
classification accuracy of 70% when distinguishing between the 
predefined gearbox condition labels, as verified using a confusion matrix 
on a labeled test dataset 
• Specification 7:  
Following completion of a diagnostic test run, the diagnostic software 
shall process the acquired data and present a gearbox fault classification 
result within 3 seconds. 
• Specification 8: The motor speed should be controllable from 0-1200 rpm 
with a PID controller with steady state error less than 1%  
• Specification 9: Accelerometer sensors should be of triaxial class with 
noise level < 50mV and sensitivity 100mV/g with 3 channels per sensor (6 
total)  
• Specification 10: The gearbox should be designed to handle a 2.2 KW of 
power and a maximum rpm of 1200  
• Specification 11: The embedded DAQ shall sample all high-speed channels 
at ≥10 kS/s per channel (simultaneous). 
• Specification 12:  When the UI sends a command, the response time should be 
≤ 2s.   
• Integrated Specification 1:  The integrated system shall be capable of 
distinguishing between the common gearbox condition labels: Healthy, 
Chipped Tooth, and Missing Tooth. 
• Integrated Specification 2: The integrated system shall support 3 controlled 
diagnostic operating conditions: 
(i) Constant speed and constant torque (baseline condition), 
(ii) Variable speed under constant applied torque, 

  36  
(iii) Variable torque under constant rotational speed, 
such that only one operating parameter varies at a time during diagnostic 
testing. 
• Integrated Specification 3: The integrated system shall monitor brake 
temperature during test modes. If the brake temperature reaches 60 °C, the 
system shall immediately initiate an emergency shutdown by disabling the 
motor drive and removing the applied load, and shall provide a clear warning to 
the user in the software 
 
Table 1: Project Constraints and Specifications (Details of each are in the previous two sections). 
Constraints and 
Specifications 
Off-the- Shelf 
Project Specific 
(Not Off- the-
Shelf) 
Responsible Department 
EE COE ICS ME 
Constraint 1  x X x x x 
Constraint 2  x    x 
Constraint 3  x    x 
Constraint 4  x   x  
Constraint 5 x   x   
Constraint 6  x X    
Specification 1 x     x 
Specification 2  x    x 
Specification 3  x    x 
Specification 4  x   x  
Specification 5  x   x  
Specification 6  x   x  
Specification 7  x   x  
Specification 8  x x    
Specification 9  x x    

  37  
Specification 10  x    x 
Specification 11  x  x   
Specification 12  x  x   
Integrated Specification 1  x X x x x 
Integrated Specification 2  x X x x x 
Integrated Specification 3  x X x x x 
  
Note: Percentage of off-the-shelf specs/constraints: 6.67 
 
  
  
 
 
 
 
 
 
 
 
 
 
 
   

  38  
2.2 Detailed Project Definition Discussion 
2.2.1 Discussion of Deliverables  
1) Mechanical design package (CAD + manufacturing BOM).  
 The mechanical design package is the foundation of the entire system because it 
defines how the motor, gearbox, brake/loading unit, and sensors physically come 
together in a safe and repeatable way. This deliverable includes the full rig layout, 
alignment strategy, and sensor mounting locations, which directly affects data 
quality and test repeatability. A manufacturing-ready BOM ensures the design is 
buildable within budget and lead-time constraints. This deliverable addresses the 
project opportunity by creating a standardized experimental platform that can be 
replicated and improved by future teams or labs.  
2) Assembled operational prototype (motor + VFD + gearbox + brake + 
guarded bench).  A working physical rig is essential to prove that gearbox 
faults can be studied under controlled and repeatable operating conditions. The 
motor and VFD allow speed control, while the brake/loading unit makes it 
possible to test the gearbox under realistic loads rather than no-load spinning. 
Guards and mechanical safety elements are included to make operation safe for 
lab users. This deliverable directly tackles the problem of unpredictable field 
inspections by enabling controlled fault experiments in a laboratory 
environment, where data can be collected consistently and safely.  
3) Integrated sensor and data-acquisition subsystem (≥10 kS/s per 
channel, synchronized timestamps).  
 The diagnostic goal depends on capturing meaningful fault signatures, which 
requires high-quality measurements of vibration, torque/load, and RPM. This 
deliverable ensures the rig produces time-aligned multi-sensor data at a sampling 
rate that can capture gearbox vibration features and their changes under different 
operating conditions. Synchronized timestamps are critical so that vibration events 
can be correlated with speed and torque, enabling accurate feature extraction and 
improving the reliability of the diagnostic results. This directly supports the project 
objective of building a predictive-maintenance style system instead of relying on 
subjective observations.  

  39  
4) Embedded control and communications module (real-time wired 
streaming + safe control).  
 This module is the “integration bridge” between the physical rig and the software 
stack. It is responsible for reliably collecting sensor data, time-stamping it, and 
streaming it to the host computer through a wired interface, which improves 
stability and noise immunity in a VFD environment. It also supports safe start/stop 
and interlock handling so the system can be operated with clear safety behavior. 
This deliverable addresses the problem by enabling real-time monitoring and 
stable data flow, which is a core requirement for automated diagnostics.  
5) AI fault-detection software package (pipeline + features + trained 
model + evaluation).  
 The AI software converts raw sensor signals into actionable fault classifications. 
The data pipeline standardizes how data is cleaned, segmented, and labeled; 
feature extraction converts signals into meaningful indicators; and the trained 
model performs fault classification. Including evaluation results (confusion matrix, 
accuracy, and test conditions) is important because it proves performance in a 
transparent way rather than making unsupported claims. This deliverable is the key 
step that transforms the rig from a measurement platform into an intelligent 
diagnostic tool, addressing the project’s main opportunity: faster, more reliable 
fault identification.  
6) User dashboard application (live monitoring + alerts + export).  
 A diagnostic system is only useful if users can interpret results quickly. The 
dashboard provides real-time visualization of RPM, torque/load, and vibration 
indicators, and it displays the AI-based fault alerts in a clear format. Export 
options allow users to save data and results for reports, training, or further 
analysis. This deliverable supports both primary customers (university labs and 
maintenance centers) by making the system practical to operate and making the 
results understandable to non-experts.  
7) Final presentation and live demonstration (end-to-end proof).  
 The live demonstration is the final integration proof that all subsystems work 
together as one product: the mechanical rig runs under controlled conditions, 
sensors collect synchronized data, embedded hardware streams it, software logs 
and analyzes it, and the AI produces an automated diagnostic output that is visible 

  40  
on the dashboard. This directly validates that the project objectives were achieved 
and that the system meaningfully addresses the original problem—reducing 
reliance on manual inspection by enabling automated fault detection in a 
controlled and repeatable workflow.  
  
    
2.2.2 Stakeholder Analysis  
2.2.2.1 Stakeholder list and prioritization  
A) Customers (Direct Stakeholders) – in priority order  
1. Maintenance centers (fault diagnosis users)  
 Interest: Want a practical tool to reduce troubleshooting time and 
confirm gearbox health before reinstalling equipment. They value fast 
setup, clear diagnostics, and reliable logging.  
  
2. Universities and training centers (teaching users)  
 Interest: Need a safe, repeatable benchtop rig that can be used in labs to 
teach predictive maintenance, instrumentation, integrating AI with 
engineering, and troubleshooting. They value safety, simple operation, 
and easy data export for coursework.  
3. Researchers (applied R&D and academic research groups)  
 Interest: Need high-quality, time-synchronized data to build datasets, 
validate models, and publish results. They value measurement fidelity, 
repeatability, and traceable test conditions more than “ease of use.”  
B) Indirect stakeholders – in priority order  
1. Component suppliers and vendors  
 Interest: Availability, cost, lead time, and datasheet limits constrain the 
final design (motor/VFD, sensors, ADC, couplings). They can indirectly 
force redesign decisions if parts are out of stock or do not meet specs.  
  

  41  
2. Competitors  
- GUNT Hamburg Machinery Fault Diagnostic Trainer  
- Software-only AI fault diagnosis approaches  
 Interest: These alternatives shape what “acceptable” looks like in 
terms of capability, usability, credibility, and cost. They indirectly 
constrain our design by setting expectations (e.g., “hardware trainer 
should be safe and repeatable,” or “software-only should be 
easier/cheaper”), which affects how we position and justify our 
integrated rig + data + AI deliverables.  
  
3. Single-stage spur gearbox manufacturers (OEMs)  
 Interest: The diagnostic rig can increase the perceived value of their 
gearbox by providing a fast and standardized fault-detection method, 
which may improve customer confidence and strengthen after-sales 
support; therefore, OEMs may choose to promote the diagnostic approach 
alongside their gearbox offerings or collaborate by providing reference 
specifications, baseline vibration profiles, and common fault cases.  
  
2.2.2.2 Customer Needs and Requirements (linked to technical 
specifications/constraints)  
A) Critical Needs  
1. Low total cost of ownership  
 Why: Teaching labs and maintenance centers will not adopt a solution 
that is  
expensive to build or maintain.  
 Linked specification/constraint:  
a. Total project hardware & software cost ≤ 15,000 SAR.  
2. Reliable, repeatable measurements  
 Why: Researchers and maintenance users need data that is trustworthy; 
otherwise the AI model cannot generalize and results will not be credible.  
 Linked specification/constraint:  

  42  
a. High-speed sensor channels shall be sampled at ≥ 10 kS/s 
per channel, with synchronized time-stamping.  
b. Measurement chain noise shall be controlled and verified 
(e.g., in-band noise/no-drop sampling) so repeated runs at the 
same condition give consistent signals.  
3. Safe operation for rotating machinery  
 Why: This is a non-negotiable requirement for universities/training 
environments and affects whether the rig can be approved for use.  
 Linked specification/constraint:  
a. 100% of exposed rotating components shall be covered by fixed 
mechanical guards during operation.  
B) Performance Needs  
4. Easy data access & export  
 Why: Teaching users need data for lab reports, and researchers need 
datasets for analysis; maintenance users need documented results.  
 Linked specification/constraint:  
a. The system shall log vibration, RPM, and torque continuously to 
a CSV  
file without data loss during a 30-minute test cycle.  
5. Ability to run tests under different shaft speeds  
 Why: Gearbox fault signatures change with speed; without speed control, 
the rig cannot support meaningful comparisons or training datasets.  
 Linked specification/constraint (clarified):  
a. Motor speed shall be controllable up to 1200 RPM (and maintain 
stable control during tests).  
 
C) Desirable Needs  
6. Benchtop footprint & portability  
 Why: Universities and training centers have limited space; the rig must 
be practical to store and move.  
 Linked specification/constraint (corrected to match “benchtop”):  

  43  
a. The rig footprint shall be bench-compatible (target: ≤ 2 m × 1 m) 
and movable within lab space.  
7. Fast setup and alignment  
 Why: Maintenance centers and teaching labs need a rig that is not 
frustrating to assemble. Long alignment time reduces usability and 
increases setup errors.  
 Linked specification/constraint (made realistic):  
a. Flexible coupling shall tolerate at least 2 mm parallel 
misalignment (or 1° angular misalignment) without requiring 
repeated realignment at rated speed.  
 
 
  
2.2.3 Discussion of Constraints  
This project is shaped by a set of constraints coming from budget limits, physical 
integration limits, and safety/operational requirements. These constraints directly 
influence component selection (motor drive, sensors, electronics), mechanical 
layout, and the software workflow for AI testing. The updated constraints below 
reflect what the team can realistically build and validate within a university 
environment while still producing a meaningful gearbox fault-diagnosis rig. 
Constraint 1: Total project hardware & software cost ≤ 15,000 SAR:                               
The overall budget cap forces the design toward commercially available parts with 
strong cost/performance value and short lead times. It affects nearly every 
subsystem decision: the team must avoid expensive industrial DAQ systems and 
instead rely on a cost-effective embedded DAQ approach (MCU + external ADC) 
and carefully selected sensors. It also drives tradeoffs in enclosure materials, 
couplings, and safety guarding. As a result, the design prioritizes “good enough” 
measurement quality with clear validation evidence rather than the most premium 
instrumentation available. 
Constraint 2: The rig should only be able to work on single-stage spur 
gearboxes: Restricting the scope to single-stage spur gearboxes keeps the 
mechanical integration and fault signatures manageable within the project 

  44  
timeline. Mechanically, it simplifies shaft alignment, coupling selection, and test 
fixture design because the geometry and load path are predictable. From the AI 
side, it reduces dataset complexity: the vibration and speed features are dominated 
by a single gear-mesh frequency and its harmonics, which makes labeling and 
model training more realistic for a student project. This constraint also prevents 
“scope creep” into multi-stage or helical gearboxes, which would require different 
fault mechanisms, broader operating conditions, and more extensive validation. 
Constraint 3: Maximum system dimensions shall not exceed 4 m × 2 m:                          
The footprint limit reflects lab space constraints and practical usability in a 
teaching/research setting. It strongly affects mechanical layout decisions: the 
motor–gearbox–brake arrangement must be compact, and sensor mounting/cable 
routing must be planned to avoid large external enclosures. This constraint also 
influences safety design (guarding must be integrated without increasing footprint 
significantly) and makes portability/relocation inside the lab more feasible. In 
implementation, the team will favor a bench-style frame and consolidated 
electronics mounting rather than distributed cabinets. 
Constraint 4: The ML model is trained using publicly available datasets and 
fine-tuned offline using collected data; during operation the model remains 
fixed (no online/adaptive learning):                                                                                                    
This constraint is driven by time, compute resources, and the need for stable, 
repeatable demonstrations. Training and fine-tuning offline reduces the risk of 
unpredictable behavior during tests and avoids the need for high-end computing 
hardware on the rig. It also simplifies verification: the team can lock a model 
version and report performance under controlled test conditions. The tradeoff is 
that the system will not automatically adapt to new gearbox types or evolving 
faults during a test session; instead, improvements occur through offline retraining 
and re-deployment. 
Constraint 5: The embedded sensing subsystem must use a temperature 
sensor rated from −55°C to +125°C:                                                                                                          
This requirement ensures the sensing hardware remains valid and safe even if the 
gearbox or nearby motor/brake components warm up during extended runs. It 
influences sensor selection (industrial-grade temperature sensors are preferred) 

  45  
and packaging decisions such as cable insulation and mounting location. It also 
supports data quality: temperature changes can affect vibration behavior and 
electronics drift, so having reliable temperature monitoring helps the team 
interpret experimental results and maintain consistent operating conditions across 
tests. 
Constraint 6: The system speed shall be controlled by a PID:                                             
PID control is a practical control constraint that improves test repeatability, which 
is essential for collecting consistent training data. Instead of manually adjusting 
speed, the controller enables the system to reach and maintain target RPM under 
changing load (especially when the brake applies torque). This influences the 
software and embedded design: the MCU must implement a stable PID loop, read 
speed feedback (from the VFD/telemetry), and apply a controlled speed reference. 
It also adds verification requirements: the team must tune PID gains, define 
acceptable steady-state error and overshoot, and demonstrate that speed regulation 
stays stable across operating points. 
 
2.2.5 Discussion of Specifications and Their Thorough Justifications  
Specifications translate customer needs into measurable engineering targets that 
can be tested. Specifications were selected to directly support the critical needs of 
repeatable measurements, safe operation, and practical data access and diagnostic 
performance.  
    
1) Flexible shaft coupling shall tolerate at least 0.1mm parallel 
misalignment between motor and gearbox shafts at rated speed  
This specification supports the desirable customer need of fast setup and alignment 
while protecting measurement quality. If the coupling requires extremely precise 
alignment, setup time increases. A target misalignment tolerance of 0.1mm allows 
minor practical alignment errors during assembly and maintenance.  
Verification approach: alignment can be measured using standard alignment tools 
(dial indicator, straightedge, feeler gauges. depending on lab availability). A 
compliance check is performed by confirming acceptable operation at rated speed 

  46  
without abnormal coupling heating, instability, or excessive vibration unrelated to 
gear faults.  
   
   
2) 100% of exposed rotating components shall be covered by 
fixed mechanical guards during operation for safety  
This is a critical safety requirement. Fixed guards prevent contact with shafts and 
couplings.  
Verification approach: this specification is verified primarily by inspecting all 
rotating elements and confirming they are enclosed by fixed guards during 
operation. A functional check is performed during testing to ensure guards remain 
secure and do not interfere with operation.  
   
  
3) The system shall apply a variable mechanical load from 0Nm 
to 10Nm  
Diagnostic reliability depends on testing the gearbox under controlled, repeatable 
conditions, and load is a key operating variable that changes gearbox vibration 
behavior. A load range from 0 to 10 Nm enables the rig to simulate unloaded and 
moderately loaded operation. This aligns with the customer's need of operational 
flexibility and supports dataset generation under variable conditions.  
   
  
Verification approach: load capability is verified using calculation to prove that the 
demonstration gearbox can hold such torque.  
   
  
4) Accelerometer sensors should be of triaxial class with noise 
level < 50mV and sensitivity 100mV/g with 3 channels per sensor  
A lower noise floor increases sensitivity to fault-induced impulses and improves 
the stability of extracted features. Additionally, a sensitivity of 100mV/g provide 

  47  
trade-off balance between signal amplitude and dynamic range which ensures that 
a low-level amplitude signal generate measurable voltage levels which improve 
the consistency of AI classification which is an essential customer need.   
As for the 3 channels per sensor, it is needed because gearbox faults generate 
vibrations in multiple directions. Using a triaxial sensor with three channels (for x, 
y, z direction) will enable measuring sufficient data for the AI classification, which 
as mentioned above is an essential customer's need.  
Verification: baseline noise measurement with the rig idle.  
   
   
5) The diagnostic software shall classify gearbox condition with a 
minimum overall accuracy of 70% as verified using confusion matrix  
This specification provides a quantitative performance benchmark for the AI 
diagnosis. A performance metric target is needed to prove that classification 
performance is better than random guessing. Accuracy metric provides a measure 
of separability and supports transparent reporting.  
Verification: compute accuracy in documented test conditions.  
   
   
6) The diagnostic software shall integrate signal preprocessing, feature 
extraction, a pre-trained machine-learning classification model, and a 
user-facing interface within a 1 executable application, producing 
vibration visualizations and a gearbox fault classification result for each 
test run  
An integrated executable application eliminates the complexity of managing 
multiple software tools or scripts. a program with a comprehensible user interface 
will allow users to recieve information faster and control the rig in an intuitive 
manner. The inclusion of vibration visualizations provides immediate feedback on 
system operation, while the automatic generation of a classification result delivers 
the diagnostic output in a clear format.  
   

  48  
   
7) The diagnostic software shall process acquired vibration data and 
output a fault classification result within 3 seconds after completion of 
data acquisition for a single test run.   
This is to support rapid iterative testing under different conditions with minimal 
time spent in the diagnosis stage.  
   
   
8) The motor speed should be controllable from 0-1200 rpm with PID 
control with steady state error <1% 
Gearbox vibration signatures are dependent on rotational speed. The ability to 
precisely control and vary speed across a defined range (0-1200 RPM) allows the 
system to simulate various operating conditions and conduct tests at repeatable 
speeds for consistent data collection. A range from 0 to 1200 rpm was chosen to 
balance between the rig safety and bandwidth limitations with the need to capture 
a wide range of distinct measurements.  
  
9) The gearbox should be designed to handle a 2.2 KW of power and a 
maximum rpm of 1200  
This is the power rated by the motor and going above such power will 
increase both the motor price and the gearbox material price resulting in 
an expensive total price.   
 
 
  
10) The embedded DAQ shall sample all high-speed channels at 
≥10 kS/s per channel (simultaneous): 
This specification is essential because our customers (universities/training 
centers, researchers, and maintenance centers) require reliable and repeatable 
measurements that can be trusted for teaching, experimentation, and fault 

  49  
diagnosis. Sampling all high-speed channels at ≥10 kS/s per channel ensures the 
system captures gearbox vibration and load-related dynamics within the diagnostic 
frequency range needed for fault detection, while simultaneous sampling prevents 
timing offsets between sensors that would distort phase relationships and weaken 
multi-sensor features. Requiring 0 dropped samples over a 30-minute continuous 
run directly supports the customer need for consistent data logging and dataset 
generation without gaps, which is critical for both ML training and fair test 
comparisons across different operating conditions. Finally, limiting inter-channel 
skew to ≤2 ms (95th percentile) ensures that vibration events can be accurately 
aligned with speed/torque changes, improving feature extraction (e.g., order-
related analysis) and preventing the AI model from learning false patterns caused 
by poor synchronization.  
  
11) When the UI sends a command, the response time should be ≤ 
2s. .  
The system shall apply a user speed-control command (e.g., start/stop or set-
speed) within ≤ 2 s, measured from the moment the user presses the control button 
on the UI to the moment the command is accepted and applied by the 
drive/controller (confirmed by system feedback such as updated setpoint/status). 
This specification is necessary to meet the customer needs of safe operation and 
easy test management, since the rig involves rotating machinery and the operator 
must be able to reliably stop or adjust the test conditions without long delays. It 
also supports the project goal of collecting repeatable datasets: quick command 
application reduces waiting time between test steps (speed changes, start/stop 
cycles), improves workflow efficiency in university and training-lab use, and 
enables controlled experiments where operating conditions are changed in a 
predictable, time-bounded way.  
 
 
 
 
   

  50  
12) Integrated Specification 1: The integrated system shall be 
capable of distinguishing between three common gearbox condition 
labels, Healthy , Chipped tooth, and missing tooth 
This is the main goal and result expected from this project, each fault will be injected 
manually by damaging the gears with accordance with the mentioned labels then equipping 
the gearbox with it   
   
13) Integrated Specification 2: The integrated system shall 
support 3 controlled diagnostic operating conditions: (i) constant speed 
and constant torque ,(ii) Variable speed under constant applied torque 
(iii) Variable torque under constant applied rotational speed,      Such 
that only one parameter varies during testing 
Justification: This to test the gearbox at different conditions to simulate more 
realistic working conditions which will help make the fault more distinguishable 
when the operating parameters vary.   
   
14) Integrated Specification 3: The integrated system shall 
monitor brake temperature during test modes, if the brake reaches 60 
C, the system shall immediately initiate an emergency shutdown by 
disabling the motor drive and removing the applied load and shall 
provide a clear warning to the user in the software.  
This is needed since the magnetic powdered brake can easily overheat and 
therefore, its temperature should be measured and monitored and the operations 
modes shall be designed to not over heat it 
 
 
 
 
 
 
 

  51  
2.2.6 QFD Discussion   
A Quality Function Deployment (QFD) matrix was developed (Figure 1) to ensure 
the final design is traceable from stakeholder needs (“What”) to measurable 
engineering characteristics (“How”).  
  
Stakeholders (“Who”)  
The QFD identifies three primary stakeholder groups:  
● Maintenance centers (fault diagnosis users): They value fast 
setup, clear diagnostics, and reliable logging.  
● Universities and training centers (teaching users): They value 
safety, simple operation, and easy data export for coursework.  
● Researchers (applied R&D and academic research groups):  
They value measurement fidelity, repeatability, and traceable test 
conditions more than “ease of use.”  
  
  
These stakeholders were selected because they represent the most realistic near-
term adopters of a laboratory-scale diagnostic bench (teaching, research, and 
training use-cases).  
  
  
Customer needs (“What”)  
 The “What” side of the QFD captures the project’s core customer needs:  
● Reliable and repeatable diagnosis  
● Accurate identification of gearbox condition  
● Safe operation near rotating machinery  
● Fast setup and tolerance to minor alignment issues  
● Simple access to test data (logging/export)  
● Ability to test gearboxes under different operating conditions  
  
In the QFD, repeatability and accuracy are weighted highest across stakeholders, 
reflecting that the rig’s value depends on producing trustworthy diagnostic outcomes 
rather than only “running mechanically.”  
  

  52  
Engineering characteristics (“How”) and interpretation  
The “How” columns convert needs into measurable engineering drivers. Figure 1 
highlights nine key technical characteristics, including sampling rate, sensor noise, 
run-to-run variance, motor speed range and stability, misalignment tolerance, 
continuous logging duration, ML Accuracy as verified in confusion matrix , and 
guard coverage. Each characteristic also has a direction of improvement (maximize 
or minimize).  
  
A key outcome of the QFD is that measurement quality are prominent technical 
priorities.  
Across stakeholder rows, the largest weightings concentrate on:  
● Accelerometer noise floor (lowest possible)  
● Measurement repeatability / variance (lowest possible)  
● Vibration sampling rate per channel (high enough to capture fault 
signatures)  
● Continuous test duration without data loss (long enough for 
meaningful experiments and training exercises)  
  
This directly supports the selection of concepts emphasizing controlled loading and 
robust sensing and DAQ integration. this is done using a controlled brake and load 
strategy rather than purely manual loading, and prioritizing synchronized sensor 
acquisition.  
  
Targets and thresholds  
The QFD provides explicit target and threshold values for each engineering 
characteristic (10 kHz sampling target, 30-minute continuous logging target, 
Accuracy as verified in confusion matrix to be above 0.7, and 100% guard 
coverage). These values translate stakeholder expectations into measurable 
verification criteria.  
  
Competitor benchmarking (qualitative)  
  
The competitor columns in the QFD provide a qualitative benchmark against two 
reference alternatives: (1) a physical training rig product and (2) a software-only AI 
diagnostic approach. The benchmarking motivates the combined direction of this 

  53  
project: a physical, safe, controlled test bench that also produces exportable datasets 
and supports AI -based classification, addressing gaps that exist when using 
hardware-only trainers or software-only approaches.  
  
  
 
  


  54  
 
Figure 5: Project DFQ 
  
  
 
2.3  Project Impact 
✓ Economic: (200 – 300 words) 
Gearbox maintenance represents a significant economic challenge due to the time, 
labor, and downtime associated with fault identification and repair. In many 
maintenance workshops, confirming the condition of a gearbox requires full 
disassembly, cleaning, visual inspection, and reassembly. These procedures are labor -
intensive, occupy workshop resources, and keep equipment out of service for extended 
periods, leading to increased downtime -related costs and reduced operational 
availability.   
The proposed diagnostic system provides economic value by supporting pre -
maintenance fault screening using non -invasive vibration -based testing under 
controlled operating conditions. By externally testing a gearbox before opening it, 
maintenance teams can obtain early indications of likely fault conditions and severity. 
This allows informed decisions on whether immediate teardown is necessary or whether 
further operation or monitoring is justified. As a result, the number of unnecessary 
disassembly can be r educed, shortening maintenance turnaround time and lowering 
labor hours while improving workshop throughput.   


  55  
In addition, the system reduces reliance on highly specialized vibration analysts by 
providing a consistent test procedure and automated diagnostic output. Instead of 
depending solely on manual interpretation of frequency spectra or envelope analysis, 
the platform offers feature -based classification that supports maintenance decision -
making in a repeatable manner. This can help standardize diagnostic practices across 
maintenance teams and reduce variability caused by operator experience levels.   
The System value lies in improving maintenance efficiency by reducing unnecessary 
inspections, optimizing labor allocation, and accelerating return of gearboxes to service. 
Collectively, these factors contribute to lower maintenance costs and reduced downtime 
in gearbox-dependent systems. 
 
✓ Societal: (200 – 300 words) 
Gearbox failures have direct societal implications due to their role in critical 
infrastructure and industrial systems. Gearboxes are widely used in manufacturing 
equipment, transportation systems, renewable energy installations, and industrial 
machinery. Unexpected failures can lead not only to economic losses, but also to 
safety hazards for operators, maintenance personnel, and the surrounding public. 
Sudden mechanical failures may result in unsafe operating conditions, equipment 
damage, or secondary accidents, particularly in environments involving heavy 
rotating machinery.  
The proposed diagnostic system contributes to societal benefits by supporting 
safer engineering education and workforce preparation. By enabling 
controlled exposure to predefined gearbox fault conditions, the system allows 
students, engineers, and technicians to study fault behavior and diagnostic 
techniques without the risks associated with experimentation on operational 
industrial equipment. This reduces unsafe trial-and-error practices and promotes 
responsible learning in mechanical, electrical, and control engineering disciplines.  
In addition, the platform supports the broader adoption of predictive maintenance 
concepts by improving diagnostic literacy and human decision-making. 
Engineers trained using controlled diagnostic systems are better equipped to 
recognize early warning signs of mechanical failure, interpret condition-
monitoring data correctly, and respond appropriately. This reduces the likelihood 

  56  
of delayed or incorrect maintenance actions, which are a common source of safety 
incidents in industrial environments.   
Finally, the system promotes responsible use of automation by emphasizing human oversight 
in diagnostic decision-making. By positioning machine learning as a decision-support tool 
rather than an autonomous authority, the project reinforces ethical engineering practices that 
prioritize safety, accountability, and informed human intervention. While the system itself is 
not intended for industrial deployment, the societal value lies in the safer practices, improved 
judgment, and risk-aware mindset developed through its use. 
 
✓ Environmental: (200 – 300 words) 
Gearbox failures and inefficient maintenance practices have indirect environmental 
consequences through increased energy consumption, material waste, and 
unplanned equipment replacement. Mechanical faults often lead to degraded 
system efficiency, higher friction losses, and increased power demand. When 
failures are detected late, components may suffer secondary damage, resulting in 
premature disposal of gearboxes, bearings, lubricants, and associated materials. 
These outcomes increase resource consumption and contribute to unnecessary 
environmental burden over the equipment lifecycle.  
The proposed system provides environmental benefits by supporting early-stage 
validation and education in condition monitoring practices. By enabling 
controlled experimentation with gearbox faults in a laboratory environment, the 
platform helps engineers and technicians understand how mechanical degradation 
affects system behavior and efficiency. Improved diagnostic understanding 
promotes maintenance strategies that intervene earlier, reducing the likelihood of 
severe damage and extending the useful life of mechanical components.  
In addition, the system encourages environmentally responsible engineering 
practices by reducing reliance on destructive testing and large-scale experimental 
setups. Traditional fault analysis often requires operating full-scale machinery 
under degraded conditions, which consumes significant energy and generates 
waste. In contrast, the laboratory-scale diagnostic rig allows fault behavior to be 
studied using low-power sensors and reusable hardware, minimizing material 
consumption and experimental waste.  

  57  
From a broader perspective, the project supports sustainability by contributing to 
improved maintenance decision-making. Engineers trained with diagnostic tools 
are more likely to adopt predictive maintenance approaches that reduce 
unnecessary part replacement, optimize lubrication schedules, and maintain 
mechanical systems at higher efficiency. While the environmental impact of the 
system is indirect, the knowledge and practices it enables can lead to reduced 
energy use, lower material waste, and longer equipment lifecycles across industrial 
applications. 
 
✓ Ethical and Professional Responsibility (from each discipline's perspective, 1-page) 
• Ethical Concerns  
• NSPE Code of Ethics Application  
• Stakeholders + Ranking  
• Proposed Ethical Action / Resolution  
From an Electrical Engineering perspective, the ethical responsibility in 
this project is ensuring electrical safety, system reliability, and accurate 
signal reporting. Failing to address these concerns could lead to shock 
hazard, fire risk, and incorrect fault diagnosis. The electrical engineer role 
is to put protection equipment, control system, and filter design to address 
the above concerns. 
The National Society of Professional Engineers (NSPE) directs us to put 
safety, health, and welfare first by using its rules and codes of ethics.: 
Rule1: Hold paramount public safety: 
This rule prioritizes safety over cost or performance, and it applies to this 
project by: i. ensuring prober circuit breakers and fuses ratings which is 
done by calculating the current drawn in the system ii. Using equipment 
(VFD, Motor, MCU, sensors) up to standard and have redundancy and fail-
safe mechanics. 
 
Rule2: Perform services only in Areas of competence: 
This rule indicate the importance of verifying design choice by using 
proven theory, simulation and testing. This apply in this project by: signal 
quality improvement using signal theory and filters equations and signal 
quality performance parameters (SNR,SINAD,etc) 
 
Rule3: Issue Truthful and objective technical data. 

  58  
This means that the project must ensure truthful data accuracy and sensors 
capabilities by mentioning uncertainties and tolerance values. 
 
With regards to stakeholders, there are several stakeholders and they ranked 
below: 
• Lab technicians: these are the top stakeholders due to their exposed risk of 
rotating motors and electricity when working on gearbox failure 
identification  
Companies/facility owners: these stakeholders are concerned with the 
financial losses, downtime and equipment damage 
Research teams: these stakeholders are concerned with the accurate results 
and academic integrity of data 
Enviroment: this is related to the inefficiency of equipment and waste from 
the device related to the project. 
 
When considering all these stakeholders the main trade-off is between the 
safety of the project and the cost and quality of  the project. And Since the 
safety is our top concern, it will be prioritized over Cost savings 
 
From Mechanical Engineering point of view: 
The main ethical risks in this gearbox diagnostic bench come from rotating 
mechanical hazards and mechanically induced false indications. Exposed 
shafts, couplings and the load device can cause entanglement, pinch 
injuries, or projectile hazards if fasteners loosen or a components fracture at 
speed. In parallel, poor alignment, overhung loading, or a flexible mounting 
joint can introduce vibration components unrelated to gear-tooth defects, 
leading to misleading diagnostic conclusions (e.g., mislabeling a healthy 
gearbox as faulty). These risks are foreseeable in a lab/maintenance 
environment and must be mitigated through mechanical design, not 
operator caution alone. 
 
NSPE directs us to put safety, health, and welfare first, so guarding, verified 
operating limits (RPM/load), stable mounting, and a reliable emergency 
stop become design requirements, not extras. The competence principle 
means we must seek qualified review for wiring/VFD setup if it exceeds 
our expertise, rather than learning by energizing a risky system. NSPE also 
requires truthful communication: we report uncertainty, sensor limits, 
repeatability, and failures, and we avoid exaggerated claims. 

  59  
 
Stakeholders includes the following:  
1- Lab technicians set up and inspection  
2- Highest injury exposure 
3- Supervisors: oversight the technicians and operators  
4- Vendors: spare parts for damaged gearbox 
5- Warehouse workers: prepare spare parts after detection  
 
Proposed ethical action and resolutions will be assured when we guard 
rotating parts and dangerous zones, verify alignment, secure fasteners and 
couplings with proper torque and locking, and enforce validated RPM and 
load limits using gradual ramp testing. Procedurally, each test uses a 
checklist which check that no one is in the range of fire, guards being 
equipped , and brake is within safe temperature  
 
Ethical and Professional Responsibility (COE Perspective): 
From the COE perspective, my responsibility focuses on the embedded 
control and data-acquisition part of the rig. Because the system operates 
rotating machinery and produces data used for AI fault diagnosis, the main 
ethical duties are keeping the rig safe and making sure the data and results 
are trustworthy. 
The first concern is safety. A software bug, communication failure, or 
incorrect command could cause unexpected motor behavior and put users at 
risk. The second concern is data integrity. If sampling drops, timestamps 
drift, or sensors saturate, the collected vibration data may be wrong, and the 
AI model can learn misleading patterns. Another concern is overclaiming 
performance. It is unethical to say the system is “accurate” without clear 
validation results (such as confusion matrix and test conditions). Finally, we 
must be transparent about what we measure. “Input torque” from the VFD 
is an estimated value, not a direct torque measurement, so it must be stated 
clearly to avoid giving users false confiFence.FThese concerns connect 
directly to the NSPE Code of Ethics. First, holding safety, health, and 
welfare as the top priority (NSPE I.1) means the rig must be safe by 
default. The control logic should enforce safe limits, and the system should 
enter a safe state when faults happen. Second, working within competence 
(NSPE II.2) means we should not claim industrial-grade diagnosis. We can 
build and test a student prototype, but we must state limits such as gearbox 
type, operating range, and sensor assumptions. Third, being truthful and 
objective (NSPE III.1) requires honest reporting of dropped samples, 
bandwidth limits, and the fact that the VFD torque is estimated. Finally, 
avoiding deceptive acts (NSPE III.3) means we should not hide 
weaknesses in the dataset, such as class imbalance or too few fault cases, 

  60  
and we should not present the model as “general” if it only applies to a 
single gearbox type.FBased on impact and responsibility, the top 
stakeholders are the operators (students, instructors, and technicians) 
because they face direct physical risk. Next are the university lab safety 
and machine shop staff, since they approve operation and set safety 
constraints. Third are component suppliers and vendors, because 
availability, datasheet limits, and quality affect safety and reliability. Fourth 
are maintenance centers and training labs as future users, since they 
depend on clear limitations and reliable results if the prototype is extended. 
This ranking puts people exposed to hazards first, then those who approve 
safe operation, then those affected by reliability and long-term use.FTo 
address these issues, I propose several actions. For safety, the control design 
will include hard limits on speed commands, and it will move to a safe state 
if communication is lost or a sensor fault is detected. For data integrity, 
streamed data will include sequence numbers and CRC checks, and the 
system will log dropped-sample counters and verify timestamp rules. For 
truthful AI reporting, we will label VFD torque as estimated torque and 
report model performance with dataset size, class balance, and test 
conditions. We will also clearly state the scope limits (single-stage spur 
gearbox and fixed operating range). Finally, we will provide simple 
documentation for safe use, including short user instructions, wiring 
warnings related to VFD noise/grounding, and a pre-run checklist. These 
steps reduce risk, protect users, and ensure the AI outputs are presented 
honestly 
 
From Computer science point of view: 
he primary ethical responsibility in this project is ensuring reliable diagnostic 
behavior, transparent software operation, and preventing misuse of machine-learning 
outputs. Although the software does not control mechanical energy directly, incorrect 
or misleading diagnostic results may influence maintenance decisions. Therefore, the 
ethical risks lie in misclassification, overconfidence in AI predictions, and 
misinterpretation of results. 
The most significant risk is false diagnosis. A false negative (classifying a faulty 
gearbox as healthy) may lead to continued operation under unsafe conditions, while a 
false positive (classifying a healthy gearbox as faulty) may lead to unnecessary 
teardown, cost, and downtime. These risks must be managed through careful model 

  61  
validation, transparent reporting of accuracy, and clear communication of system 
limitations. 
In accordance with the NSPE Code of Ethics, the ICS component supports the 
following principles: 
Rule 1: Hold paramount the safety, health, and welfare of the public. 
The software is designed to operate in inference-only mode during testing, meaning 
the model does not adapt or change while the rig is running. This prevents 
unpredictable behavior. Additionally, the system clearly displays operating parameters 
alongside the classification result to avoid blind reliance on the AI output. 
Rule 2: Perform services only in areas of competence. 
The machine-learning approach used in this project is feature-based and interpretable, 
rather than a complex deep learning model that would exceed the scope of available 
data and expertise. Model development, validation, and performance evaluation are 
conducted using standard, academically accepted methods to ensure reliability. 
Rule 3: Issue public statements in an objective and truthful manner. 
The system reports overall classification accuracy and confusion matrix results 
without exaggeration. Performance limitations, dataset constraints, and the absence of 
online learning are clearly stated. The software does not claim industrial-grade 
accuracy or universal applicability beyond the defined gearbox type. 
With respect to stakeholders, the primary stakeholders from a software perspective 
include: 
• Lab technicians and operators who rely on clear and understandable diagnostic 
output. 
• Supervisors and instructors who require repeatable and trustworthy results. 
• Maintenance personnel who may use diagnostic results to guide decisions. 
• Researchers who depend on consistent and reproducible data. 
• The ethical trade-off in the ICS domain is between model complexity and reliability. 
While more advanced adaptive algorithms could potentially improve performance, 

  62  
they would introduce uncertainty and reduce repeatability. Therefore, the project 
prioritizes deterministic behavior, offline training, and fixed-model deployment over 
adaptive or self-updating systems. 
Overall, the Computer Science component ensures that the diagnostic software 
operates transparently, reproducibly, and within clearly defined performance limits, 
supporting safe and informed decision-making rather than autonomous control. 
 
 
 
  

  63  
 2.4  Discipline Specific Contributions  
 
Figure 6: Multidisciplinary Prototype Summary 


  64  
 
Figure 7: electrical schematic for project prototype 
 
 
 
 
 
 
Table 2: Discipline Specific Courses. 
No.  Discipline  Courses   Application Parts: Blocks (mandatory) and arrows  
(if applicable)  
1.   ICS  ICS 381 (AI), ICS 353  
(Algorithms), SWE 206  
(Software development), 
ISE291 (Introduction to Data 
Science) 
Blocks :  
ICS_Software Block  
  
Arrows:  
Processing Data from DAQ System to ML arrow  
(Specification 6)  
  
Software UI output arrow (Specification 4 and  
Specification 5)  
  
  


  65  
2.   EE  EE207(signal processing and 
analysis), EE360(Power 
system engineering),  
EE380(Control  
Engineering) 
EE462(Electrical machines)   
EE370(Communication  
engineering)  
Blocks:  
Power and drive block, sensors and DAQ block, DAQ control and 
interface block, Signal processing block.  
Arrows:  
Power and drive output to gearbox bench input  
(sends motor input speed and torque),  
Sensors and DAQ output to DAQ interface input  
(receive signals from sensors and send to microcontroller)  
DAQ interface output to Signal processing input (receive unprocessed 
signals and send clean processed signals)  
3.   ME  ME 210 (CAD  
SolidWorks), ME 302  
(Concepts of failure in  
Blocks:  
Gearbox under test design: using ANSI/AGMA factors to protect the 
gear teeth against pitting and  
  gears, bearing and coupling 
alignment), ME 402 
(Modelling software 
programs),   
bending failure so the test will not be interrupted by sudden failure, 
after designing the gears, the shaft design will be done then the 
bearing will be selected and after that the casing of the gearbox  
  
 The bench design: the bench will be design against static failure and 
will be designed to accommodate more than one size of gearbox  
  
Arrows:  
Receive RPM from the motor and load from the brake   

  66  
4.   COE  COE306 (Embedded 
systems), COE450  
(intro. to smart system)  
Blocks :  
1- Vibration & speed sensors with signal conditioning   
2- Data Acquisition and Control unit  Details:   
Coe student will work on: 
1- Designing and implementing DAC system  
2- Filtering and pre-processing sensor signals to achieve 
required accuracy   
3- Designing and implementing a bidirectional 
communication protocol 
 Arrows:  
1- Arrow number 5 (in the diagram)  
2- Arrow number 6  
3- Arrow number 7  
5.         
6.         
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  

  67  
 
Table 3: Team Management. 
No. Student 
Name Major 
 Main Tasks  
Constraints Specs. 
Integrated  
Specs. 
 
Blocks Arrows 
1 Abdullah 
Alammari ME 1,2 3,10 1,2,3 
1- Gearbox under test 
design 2- The bench 
design 
2,3 
2 Abdullah 
Alotaibi ME 1,3 1,2 1,2,3 
1- Gearbox under test 
design 2- The bench 
design: 
2,3 
3 Mohammed 
Aman EE 1,6 8,9 1,2,3 Electrical_Engin 
eering Block 1,3,4 
4 Mana Al 
Abas ICS 1,4 4,5,6,7 1,2,3 
ICS_Software 
Block 
 
6,7 
5 Khalid Ali 
ALsaif COE 1,5 11,12 1,2,3 
1- Vibration & speed 
sensors with signal 
conditioning 
4,5,6,8,9 
      
2- Data 
Acquisition and 
Control unit 
 
 

  68  
6 Fahad 
Almutairi ICS 1,4 4,5,6,7 1,2,3 
ICS_Software 
Block 
 
6,7 
  
  
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  

  69  
Chapter 3  Design and Development   
This chapter summarizes the concept development process, 
including concept generation 3.1, concept narrowing using a concept fan 
3.2, and structured evaluation of the final concepts to justify the selected 
design 3.3.  
3.1 Design Concept 
● Internal Search:    
To generate feasible concepts for a one -stage spur gearbox diagnostic 
bench, the team conducted structured internal brainstorming supported by 
SCAMPER. The goal was to enable reliable AI classification of three labels 
(Healthy / chipped tooth / missing too th) using vibration - and speed -related 
measurements collected under controlled test conditions. Ideas focused on (i) 
how to apply repeatable load and regulate speed, (ii) how to improve drivetrain 
alignment to reduce non-fault vibration contamination, and (iii) how to keep the 
rig safe, compact, and practical to build. The internal search produced three 
concept designs that were carried forward for screening and evaluation.  
Concept 1: Closed-Loop Eddy-Brake Rig.  
   A non-contact eddy-current brake, illustrated in the following Figure, is 
used to apply repeatable load profiles while maintaining stable speed under 
load. This concept prioritizes test repeatability and consistent datasets for AI 
validation.  
         
Figure 8: Closed-Loop Eddy-Brake Rig. 


  70  
  
   
Concept 2: Manual-Brake Teaching Rig.  
   A manual friction brake as shown in Figure below provides a simple, low-
cost setup suitable for demonstrations and educational use. The main 
limitation is reduced repeatability because the applied load depends on the 
operator.  
 
Figure 9: Manual-Brake Teaching Rig. 
  
    
Concept 3: Supported Brake + Triple Flexible Couplings.  
   The next Figure illustrates the drivetrain which is arranged in series: 
motor, flexible coupling, gearbox, flexible coupling, torque sensor, flexible 
coupling, and brake. The brake is base-mounted and supported by its own 
housing and bearings to reduce side loads and bending effects on the gearbox 
and torque sensor, improving mechanical repeatability and measurement 
quality.  


  71  
                   
Figure 10: Supported Brake + Triple Flexible Couplings Rig. 
  
    
  
The ideations methodology was conducted as the SCAMPER method, 
which is shown in Table 4.1.  
 
Table 4.1: SCAMPER 
Substitute  
• Replace manual gearbox inspection with AI-based 3‑class diagnosis  
(Healthy/chipped tooth/missing tooth)   
• Replace expensive proprietary DAQ with sensor + microcontroller 
DAQ and automated CSV logging  
Combine  
• Combine motor + spur gearbox + brake/load device into a single 
benchtop diagnostic rig   
• Combine publicly available gearbox vibration data with our 
injected‑fault spur gearbox data to fine‑tune the AI model  
Adapt  
• Adapt vibration testing architectures used in labs for controlled 
speed/load testing   
• Adapt standard condition-monitoring practice to build consistent 
features for ML classification  


  72  
Modify  
• Modify the gearbox test article to allow repeatable fault injection   
• Modify the drivetrain layout (couplings/supports/brake mounting) to 
reduce bending loads that can contaminate vibration signatures  
Put to 
another 
use  
• Use the bench as a training/teaching platform for showing spur-gear 
fault signatures under controlled conditions   
• Use the bench as a dataset generator to validate the AI model on the 
target gearbox type and operating conditions  
Eliminate  
• Eliminate the need to disassemble gearboxes for basic condition 
decisions by diagnosing from vibration/torque/rpm data   
• Eliminate overhung loading on the gearbox output by using a brake 
with its own supported housing (safer + cleaner measurements)  
Reverse  
• Reverse the development flow by starting with published datasets for 
baseline training, then fine‑tuning using data from our injected‑fault spur 
gearbox to match our target hardware  
  
● External Search:    
To inform and validate our concept development, we conducted an 
external literature search on publicly available gearbox fault -diagnosis 
datasets and laboratory test -rig practices under variable operating 
conditions. A key benchmark study reports synchronized vibration, key-
phase speed, and torque measurements acquired using two tri -axial 
accelerometers, a photoelectric speed sensor, and a torque sensor, with 
signals stored in CSV format for offline analysis [4]. The same work 
describes a motor –torque senso r–gearbox–brake test rig where load is 
applied via a magnetic powder brake, supporting our decision to employ 
controlled loading and torque measurement to improve repeatability and 
diagnostic reliability. Finally, the dataset includes precisely introduced 
gear faults such as missing teeth, which align with our planned fault -
injection strategy and provides a credible baseline for offline AI model 
training and comparison.   
  
● Expert Consultation:  

  73  
To refine the project's scope and ensure practical relevance, the team 
consulted a machine design faculty member, Dr. N. Merah on Jan. 25, 
2026, from the KFUPM Mechanical Engineering Department with 
experience in fracture mechanics and failure analysis. Th e expert 
highlighted that a key industrial challenge is distinguishing the root cause 
of abnormal vibration, whether it originates from bearings, couplings, 
gear mesh defects, misalignment, or other rotating components, which 
reinforces the need for a cont rolled diagnostic bench and clear fault 
labeling. The consultation also noted that while temperature can 
accelerate degradation, vibration remains the primary indicator for 
condition monitoring, suggesting that temperature sensing may be 
secondary for this  project compared with vibration -based features. In 
addition, the expert emphasized that an AI-based classifier for one-stage 
spur gearbox faults can significantly reduce inspection time in 
environments such as production lines or maintenance workflows where 
many gearboxes and configurations are handled. Finally, the discussion 
provided contextual insight into failure origins, indicating that failures 
can be broadly attributed to approximately 30% operational factors, 30% 
design-related factors, with the re mainder due to miscellaneous causes, 
guiding the team to consider both mechanical design robustness and 
realistic operating conditions in the rig.  
3.2 Concept Selection 
The concept fan was used to systematically explore alternatives for 
the diagnostic bench. As shown in the Figure below, circles represent design 
decisions/functions, and squares represent candidate solutions. The final 
conceptual designs were formed by combining one solution from each 
branch.  

  74  
  
Figure 7: Design Concept Fan  
The concept fan places the overall bench design at the top and 
branches into four decision nodes (circles): load application, shaftline 
integration, sensing, and safety, with each branch listing feasible solution 
options (squares). Choosing an eddy-current brake improves repeatability 
compared to a manual friction brake but increases integration complexity. A 
basic shaftline is simplest, adding an in-line torque sensor improves 
measurement but tightens alignment needs, and a supported brake with 
triple flexible couplings further reduces side loads and improves safety at 
the cost of more parts and assembly effort. For sensing, vibration + RPM 
minimizes complexity, while adding torque strengthens diagnostic features 
for AI. Finally, a full enclosure with interlock offers stronger compliance 
than partial guarding but requires more fabrication; overall, the fan 
highlights the core trade-off between diagnostic reliability and system 
simplicity.  
 
3.3 Concept Evaluation 
This section presents a systematic evaluation of the three final design 
concepts to determine the most suitable solution for meeting customer needs.  
● Initial Screening:  


  75  
The three concepts were first screened against non -negotiable 
constraints  
(budget, 220–240 V AC operation, guarding readiness, bench feasibility, 
and CSV-based offline AI workflow). C1 (Closed-Loop Eddy-Brake) 
passed screening and was retained due to its high repeatability and 
straightforward guarding of a non-contact brake. C2 (Manual-Brake 
Teaching) was retained for comparison but flagged as higher risk because 
manual loading reduces repeatability and may require stricter guarding to 
avoid unsafe operator interaction near rotating parts. C3 (Supported Brake + 
Triple Flexible Couplings) passed screening and was retained because a 
base-mounted supported brake reduces overhung loads and improves safety, 
though it was flagged for increased assembly/alignment complexity.  
● Evaluation Methodology:  
The shortlisted concepts were evaluated using a weighted Pugh-style 
decision matrix supported by a radar (spider) chart for visual comparison. 
Each concept was rated on a 1–5 scale, 5 = best, against criteria derived from 
stakeholder needs and the project’ s diagnostic objective. Scores were 
multiplied by their weights to compute the final weighted score, providing a 
quantitative basis for selecting the baseline concept and identifying features 
to integrate from other concepts.  
● Guidelines for Evaluation  
The comparison table and spider chart, Table 5 .1 and Figure below 
respectively, show that C1 (Closed -Loop Eddy -Brake Rig) achieved the 
highest weighted score (92/100) due to superior repeatability and speed 
control, making it the strongest baseline for generating consistent datasets 
and demonstrating AI -based diagn osis. C2 (Manual -Brake Teaching Rig) 
scored lowest (58/100) because operator -dependent loading reduces 
repeatability, limiting its suitability for standardized diagnostic validation 
despite its simplicity. C3 (Alignment + Bearing Support + Elastic Coupling) 
scored closely behind C1 (85/100) and performed best in alignment control 
and safety, indicating that its shaftline and supported -brake features can be 
integrated to strengthen the selected baseline. Based on this systematic 

  76  
evaluation, C1 is selected (“Yes”) as the primary design, C2 is discarded 
(“No”), and C3 are discarded (“No”), but key mechanical features will be 
combined to C1 to improve measurement integrity and safety.  
Table 5.1: Weighted Pugh Table.  
  
 
Figure 11:  Spider Chart 
  
 
 


  77  
Chapter 4 Final Design 
Final Design 
4.1. Overall Description 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
Figure 12: Project Block Diagram. 

  78  
4.1.1. Mechanical Engineering Overview: 
The mechanical team oversee the fabrication and the design of both the bench and the 
gearbox. Tasks with respect to the gearbox include shaft design, gear design, bearing 
selection, enclosure, or housing design. Tasks with respect to the bench include the 
adjustability mechanism, size selection for the test bench to assure that the bench can 
withstand the test power and select a coupling. Our role in the integrated specification is to 
select the break, which is our load system, design and iterate the testing values so the average 
testing power will not exceed the rated brake power. 
 
4.1.2. Computer Engineering Overview: 
From the COE side, the final design acts as the bridge between the rig hardware and the PC 
software by collecting synchronized sensor data and sending control commands back to the 
drive and brake. The COE block, as shown in Figure 6, includes: two triaxial vibration sensors 
(6 channels total), an ESP32-S3 MCU, a VFD interface for input speed/torque, a brake 
controller interface for load control, and a temperature sensor, all connected to the PC UI 
through a unified data link.  
 
4.1.3. Electrical Engineering Overview: 
From the electrical engineering side, the team is responsible for the design, selection, and 
integration of all power and sensing components within the system. Tasks include designing  
the protection and power subsystem. for the total system to ensure controlled speed and torque 
operation under the required diagnostic conditions. Additionally, the EE student works in 
signal processing and filtering to ensure that the signals are clean and have high signal to 
noise ratio. 
 The EE team ensures that the electrical power input (220 V AC) is properly regulated, 
protected, and distributed to the drive system. 
Additional responsibilities include selecting and integrating the vibration sensors, wiring 
layout, signal conditioning, implementing the PID control parameters and ensuring proper 
grounding and noise reduction for accurate measurements. The EE team also supports the 
implementation of the brake system by ensuring electrical compatibility and safe power 
operation. 

  79  
Within the integrated specification, the EE role is to guarantee stable motor operation across 
the three required test modes and ensure safe emergency shutdown functionality when the 
brake temperature reaches 60 °C. 
 
 
 
 
4.1.4. Computer Science / ICS Software Overview: 
From the computer science (ICS software) side, the system is responsible for signal 
processing, feature extraction, machine learning classification, and user interaction. The 
software receives digitized vibration data from the DAQ interface and processes it using 
filtering, transformation, and feature extraction techniques to obtain meaningful diagnostic 
indicators. 
The extracted features are then passed to the machine learning model, which classifies the 
gearbox condition into one of three labels: Healthy, Chipped Tooth, or Missing Tooth. The 
software must meet the integrated system requirement of correctly distinguishing between 
these three fault categories. 
In addition, the software provides real-time visualization of vibration signals and diagnostic 
results through the PC interface. It also plays a critical role in system safety by issuing a clear 
warning to the user and coordinating emergency shutdown procedures when the brake 
temperature reaches the 60 °C threshold. 
 
 
 
 
 
 
 

  80  
4.2. Detailed Design Description 
 
4.2.1. COE Discipline details: 
 
Figure 13: Overall COE System Design. 
 
 
 
Component-based detailed design  
• Microcontroller (MCU): ESP32-S3-DevKitC-1-N16R8 
The ESP32-S3 is used as the main embedded controller because it provides enough 
processing/RAM, useful peripherals (SPI/UART/USB), and fits student cost 
constraints. Its firmware is responsible for meeting real-time behavior in sampling, 
packetization, and command handling.  
• External ADC: AD7606B (8-channel, 16-bit SAR, simultaneous sampling) 
We use an external ADC to ensure synchronized multi-channel sampling with high 
throughput, rather than relying on the MCU’s internal ADC. zed analog channels and 
supports simultaneous sampling, which improves time alignment between axes and 
reduces measurement mismatch. Data is transferred to the MCU using SPI, which is 
suitable for block-based reading at the required sample rate.  
• Vibration sensing: PCB Piezotronics 356A02 (triaxial IEPE) 
We use two triaxial vibration sensors so we can capture vibration in multiple directions 


  81  
at key gearbox locations while keeping mounting simple. ed as having strong noise 
immunity, which is important near a VFD-driven motor.  
• VFD (Variable Frequency drive) interface: LNC820 
The VFD is integrated so the MCU can control motor speed and also read back 
speed/torque information for AI labeling and test repeatability. The deck highlights that 
the VFD is suitable for embedded integration and is commonly used with induction 
motors.  
• Temperature sensor: DS18B20   
The temperature sensor is used to read gearbox temperature and show reading in the UI. 
This helps to notify system users when the gearbox overheated.  
• Gearbox brake controller:                                                                                                                                            
This controller is essential to interface with the brake and control the break load from 
the UI. 
• PC & UI interface 
The PC runs the UI for monitoring and experiment control. The MCU streams data to 
the PC app and the PC converts it to CSV for later AI processing, using a custom 
protocol. 
 
 
Functional decomposition 
COE system has two functions as Figure 6 shows . First function is collecting data from the 
sensors in the required frequency and delivering it to the PC where UI and AI systems reside 
(represented in Figure 6 by blue color). Second function is receiving control command  from 
the UI and interfacing with VFD, and gearbox break controller to apply the command. The 
details of these functions are as follows: 
1) Data collection:  
We are  interested in reading four types of data, which are input speed (from 
VFD), input torque (from VFD), vibration (of the gearbox and the motor), and 
gearbox temperature. All data (except temperature) will be collected from multi-
channel ADC through SPI serial communication protocol, whereas temperature 
reading will be collected directly from the temperature sensor (digital sensor). 

  82  
After that, data will be sent to the PC using custom communication protocol 
(Details of the protocols will come soon). Figure 7 shows how vibration data (for 
example) will be collected using the discussed procedure. 
 
 
Figure 7: chain from vibration sensors to the UI 
 
 
 
2) Applying control command:   
On the other hand, the control messages will go in the other direction (from PC to 
controllers). The communication between the PC and the MCU will be using the custom 
communication protocol. After that, and based on the command, the MCU will interface 
with the VFD or the gearbox break controller in order to apply the command. Figure 8 
shows how this procedure is done. 
 


  83  
 
Figure 8: controlling motor speed from the UI 
 
Communication design (MCU ↔ PC): layered protocol over USB-Serial 
Layer stack (from lowest to highest): 
• USB serial link: point-to-point physical/data link between ESP32-S3 and the PC.  
• Framing & reliability layer: defines how bytes are grouped into packets, how the PC 
re-synchronizes if bytes are lost, and how we detect missing packets (sequence 
numbers) and abnormal conditions (flags).  
• Application layer: defines the meaning of the data (vibration samples, VFD 
speed/torque, and control commands). Figure 9 shows layered communication 
protocol stack.  
 
 
Figure 9: Layer stack 
 


  84  
1) Application layer messages (semantics) 
A) Vibration message (MCU → PC) 
Purpose: stream time-stamped blocks of vibration samples to the PC for live display + 
CSV logging. 
Payload semantics (block-based): 
• Fs_Hz (uint16): sampling rate used for this block. 
• Nframes (uint16): number of time samples per channel in this packet. 
• Nch (uint8): number of channels included (e.g., 6 for two triax accelerometers). 
• Reserved (uint8): future expansion/alignment. 
• Samples[] (int16): raw ADC samples arranged as Nframes × Nch values (one packet 
holds a “chunk” of synchronized samples). 
 
B) VFD message (MCU → PC) 
Purpose: send operating point metadata that the AI training needs. 
Payload fields (as defined): 
• speed_rpm (int32) 
• torque_pct_x10 (int16) (torque in 0.1% units) 
• status (uint16)  
 
 
 
C) Control messages (PC → MCU) 
Purpose: let the UI command the MCU, and the MCU applies control actions. 
Command set (simple ASCII control): 
• SET_SPEED 
• SET_LOAD 
• START 

  85  
• STOP  
 
2) Framing & reliability layer (packet syntax + meaning) 
To avoid ambiguity on a raw serial stream, every binary packet uses a fixed header 
followed by a variable payload: 
Header syntax (fixed fields): 
• SOF (2 bytes): 0xA5 0x5A — start-of-frame marker used for re-sync if the stream is 
corrupted. 
• Version (1 byte): protocol version (e.g., 0x01). 
• MsgType (1 byte): identifies the payload type (e.g., VIB / VFD / CMD / ACK). 
• HeaderLen (1 byte): header size (e.g., 0x1B) so the parser can evolve with versions. 
• PayloadLen (2 bytes): number of payload bytes following the header (lets the PC 
know exactly where the packet ends). 
• Seq (4 bytes): packet counter (used to detect dropped packets). 
o Semantic rule: sequence increments per message stream (so the PC can detect 
drops separately for vibration vs VFD). 
• Timestamp_us (8 bytes): timestamp in microseconds, used to align vibration blocks 
with VFD readings on the PC timeline. 
• Flags (1 byte): bit-field for stream health. 
o bit0 = error 
o bit1 = overflow 
 
 
Key design considerations 
o Ethics (transparency + honest results) 
The COE design must prevent misleading outputs. That is why the protocol 
explicitly separates raw vibration data from the VFD status message, and why 
torque is transmitted as a VFD value (as a percentage field) rather than being 

  86  
presented as a “direct torque sensor.” This supports transparent reporting in the UI 
and in the final evaluation of the AI model. 
o Public health (indirect impact) 
Although this is a lab-scale rig, the COE subsystem supports public benefit 
indirectly by enabling safer training and repeatable fault diagnosis experiments. 
The goal is to provide consistent datasets and controlled tests that help develop 
diagnostic methods before they are used in real machines, reducing the risk of 
unexpected gearbox failures. 
o Safety (control + monitoring) 
Safety is handled by making the COE subsystem support controlled operation: the 
UI sends explicit start/stop and setpoint commands, the MCU applies them to the 
VFD and brake controller, and the system continuously reports speed/torque status 
back to the PC. Temperature monitoring is included as an extra 
protection/awareness channel to help detect overheating trends during run 
 
 
 
 
 
 
 
 
 
 
 
 
 

  87  
 4.2.2. ICS Discipline Details 
The Information and Computer Science component of this project focuses on developing the 
diagnostic software responsible for processing vibration data and generating gearbox fault 
classification results. The application combines data preprocessing, feature extraction, 
machine-learning based classification, and user visualization into a single executable program. 
For each completed test run, the software receives synchronized vibration, speed, and torque 
data from the data acquisition subsystem. Once the data is acquired, the vibration signal is 
processed and divided into fixed-length windows. This segmentation step improves statistical 
reliability and ensures more stable feature computation. Instead of using raw vibration signals 
directly, the system extracts physically meaningful features from each window. 

  88  
 
Figure 14 Software Subsystem diagram 
The machine-learning model classifies gearbox condition into three predefined categories: 
Healthy, Chipped Tooth, and Missing Tooth. Initial training is performed offline using 
publicly available labeled gearbox datasets. The dataset chosen to train the Machine Learning 
model for gearbox fault diagnosis is the “HUST Gearbox Dataset” [1].  
During actual gearbox testing, the deployed model remains fixed and does not adapt or 
update. It simply evaluates the extracted features and outputs a classification result. The 
backend model is designed to achieve a minimum overall classification accuracy of 70% 
when evaluated on labeled test data using a confusion matrix. 
The diagnostic software includes a graphical user interface that allows users to input operating 
parameters, such as rotational speed and applied load, and to initiate diagnostic testing. For 


  89  
each test run, the interface presents four synchronized visualizations: rotational speed versus 
time, applied torque versus time, the vibration time-domain waveform, and the vibration 
frequency-domain spectrum (FFT). The predicted fault classification label is displayed 
together with the selected operating parameters, providing context for interpreting the 
diagnostic result. 
For any given input dataset, the software produces consistent feature values and identical 
classification outputs across repeated executions. Random seeds are fixed during model 
training to ensure reproducibility of the reported results. The entire system is designed to run 
on a standard desktop or laptop computer without the need for GPUs or specialized computing 
hardware.  
 
4.2.3.  EE Discipline details 
The EE part has two main contributions: 1-Power/control subsystem 2- DAQ subsystem: 
1- Power/control: 
This subsytem supplies electrical power to the motor through a VFD which allows 
for a precise control of the motor speed and torque by controlling the frequency. 
Its main features is to allow for a speed control range 0-1200 rpm with a steady 
state error less than 1%. This is done by the use of a PID control.. 
The motor which is the main component of the system is a three-phase induction 
motor. The use of a three-phase instead of a single-phase motor is due to the fact that 
single-phase motors are not designed for variable frequency as opposed to the three-
phase motor 
 
Figure 15: Electrical schematic for the Power system. 
 


  90  
 
 
 
 
 
Figure 16: Block diagram for the DAQ system. 
Two important concerns should be addressed in this subsystem: 
1- Ethical concerns: The design ensures transparency in data collection and processing and 
the Data sent to the AI model should not be altered and manipulated. This is to avoid 
Overfitting issues/False alarms/false-positives results 
 2- Safety/Public safety concerns 
Due to the use of a 220VAC electrical source and rotating machinery ( induction motor) 
The design should ensure proper grounding, overcurrent protection, isolation between power 
and sensors circuits. 
 
4.2.4.  ME Discipline details 
The ME students distributed their work by the following: Spur gear design, shaft design, 
and bearing & coupling selections. Figure 5 illustrates a detailed mechanical block diagram 
for the ME contributions. 
 


  91  
 
We followed Shigley’s Mechanical Engineering Design textbook assumptions and 
equations [2]. After completing these designs and selections, we went to use SolidWorks 
CAD to integrate parts into assemblies: One-stage spur gearbox, and test bench designs. 
1. Spur gear design: 
For the spur gear design criteria (typical values from Shigley’s problems): 
• Bending safety factor > 2.0 
• Contact safety factor > 1.2 
25 factors and constants have been used to evaluate the bending and contact factor of safety. 
These measures are taken to make sure that the test rig can operate and handle one-stage spur 
gearbox. 
2. Shaft design: 
The system will be experiencing a variable mechanical load between 0 to 10 Nm and 
handling 2.2 kW of power from the motor. Thus, iteration was implemented by different 
materials and geometry, with a typical factor of safety from Shigley’s 1.75. Shaft deflection 
and slope are major hazard for shaft’s functionality; thus, Table 7-2 will provide typical 
maximum ranges for slopes and transverse deflections. 
3. Bearing & coupling selections: 
After choosing the suitable dimensions for the shafts, bearing selection becomes clear by 
using force analysis to determine the reaction forces on the bearings. From that, choose the 
Figure 17: Mechanical Block Diagram. 

  92  
most critical bearing which is the one with the highest reaction force. With the reaction force, 
the dynamic loading c10. Lastly, choose a roller contact ball bearing with a higher c10 value of 
what has been evaluated. Roller contact ball bearing was chosen because it is widely used and 
its capability to handle radial loads. 
Flexible coupling was chosen by taking a higher rated torque, eccentricity, and allowable 
max speed. Flexible shaft coupling was preferred due to its easy installations. 
Ethical related issues from the mechanical engineering design point of view includes issues 
include accuracy and fault injections, upper stakeholders such as maintenance technicians  
need such project to be able to address many possible gearbox faults and be able to detect 
them easily without the need to disassemble the gearbox. However, other stakeholders, 
maintenance inspectors, need the project to be able to address the problems with very high 
accuracy so they can perform root cause analysis and find the root cause behind the failure of 
the gearbox with higher accuracy. These are two conflicts of interest that was adjusted by 
including 3 possible situations to inject to our data, and with reasonable accuracy expectation. 
  Possible Public health concern is the fact that the rig only detects mechanical failures, and 
it does not detect other problems such as oil leakage from the casing of the gearbox for 
example. Such problems can be environmental hazard contributing negatively. This can be 
addressed in this project by marketing it as mechanical fault detector only and to check other 
aspects of the equipment the end user have to use another detection or inspection method to 
cover the other problems. 
Possible safety concern is with respect to the rotating shafts and the debris of the 
mechanical grinding. This is addressed in our project by using guards covering both the shaft 
and the coupling adding an emergency stop to the UI. Another aspect to the safety is the over 
heating of the break. This was addressed in the integrated specification that the system will 
automatically perform automatic shutdown when the break approach a threshold temperature. 
 
 
 

  93  
4.3. Final Design Analysis and Results 
 
4.3.1. Final Design Analysis 
4.3.1.1. ICS Discipline Analysis: 
The software component of the system was evaluated with respect to its architectural design, 
system integration, and compliance with performance requirements. Its primary function is to 
provide an interface between the user, the data acquisition subsystem, and the machine 
learning diagnostic model, and operational control. 
The software adopts a client-server architecture in which the frontend is developed using 
React with TypeScript and the backend is implemented in Python. This separation of concerns 
isolates computationally intensive tasks, such as data processing and communication 
management, from the user interface, thereby improving maintainability, modularity, and 
scalability. The frontend is responsible for user interaction, visualization, and control input, 
whereas the backend manages data reception, coordinates preprocessing tasks, and 
communicates with the embedded system. 
From an architectural standpoint, the software can be divided into three layers. The 
presentation layer provides the user interface, captures user-defined inputs such as rotational 
speed and applied load, and displays plots of vibration signals, FFT spectra, torque, and speed. 
The application layer manages the flow of data between the interface and the embedded 
subsystem, processes incoming data streams, and coordinates the execution of diagnostic 
functions. The communication layer enables structured data exchange between the host 
computer and the embedded controller through a serial communication interface. 
Signals from gears are cyclostationary at constant speed, meaning that statistical measures like 
mean and variance are periodic functions of time. This means that the values of the signals 
repeat at regular time intervals, thus windowing will allow for capturing statistically static 
segments that capture behavior at a given state. As a result a single run could be turned to 
many samples for feature extraction. 
 
For a constant speed recording: 
𝑥𝑖[𝑛] = 𝑥[𝑛 + 𝑖𝐻], 𝑛 = 0, … , 𝑁 − 1 
𝑁 =   Samples, and  𝐻 = 𝑁(1 − 𝜌) , 𝜌 is overlap 𝜌 = 0  

  94  
 
Figure 18: visualization of cyclostationarity of gear vibration signals. 
Each window shall be of a fixed length of 0.5 seconds to avoid skewing the number of 
samples for different speeds, faster speeds would have more samples otherwise. Each window 
will contain many revolutions of the input shaft, which will provide plenty of data for the 
feature extraction phase. Additionally, it allows for capturing events at different time scales, 
thus allowing for determining if a fault repeats or not, and for the features we calculate like 
RMS and kurtosis, 0.5 seconds repetitive cycles for the features to converge to a stable value 
and avoid noise in feature extraction. Lastly, check for and trim transients if they are present 
and do not overlap windows as a precautionary measure against correlating samples and to 
ensure that performance reporting is more accurate. 
 
The extracted features include several time-domain metrics such as RMS, peak value, 
kurtosis, skewness, crest factor, and signal energy. In addition, frequency-domain features are 
calculated, including dominant frequency components, spectral energy distribution, and 
energy ratios within predefined frequency bands. When the shaft speed remains constant, 
additional gear-related frequency features are computed around the expected gear mesh 
frequency and its associated sidebands. A feature-based approach was chosen because the 
available dataset is relatively limited, interpretability is essential for maintenance-focused 
applications, and the solution must run efficiently on standard laboratory hardware. 
The communication between the PC and the embedded system is designed to ensure reliable 
and synchronized data transfer. Data is transmitted in structured packets containing vibration 
samples, timestamps, and system parameters. This design ensures that visualization and 
diagnostic outputs are aligned in time, which is critical for interpreting vibration behavior 
accurately. 
A key design requirement is the system response time, specified to be less than 3 seconds. 
The software achieves this by using efficient data handling and asynchronous processing. 
Instead of processing data sample-by-sample, the system operates on blocks of data, reducing 
computational overhead and improving execution speed. The measured response time during 


  95  
testing was within the required limit, confirming that the software meets the performance 
specification. 
Another important aspect of the software design is deterministic behavior. Given the same 
input dataset, the system produces identical outputs across repeated runs. This is achieved by 
fixing execution flow and avoiding any runtime randomness. Deterministic behavior is 
essential in engineering applications, as it ensures reproducibility and reliability of diagnostic 
results. 
From a system integration perspective, the software acts as the central coordinator between 
disciplines. It receives raw data from the COE subsystem, processes and visualizes it, and 
presents results generated by the ICS machine learning model. Additionally, it sends control 
commands (e.g., start, stop, speed adjustment) back to the embedded controller, completing 
the feedback loop. 
Despite its successful implementation, the software has some limitations. The current system 
operates on a local machine and does not support distributed or cloud-based processing. 
Additionally, while real-time visualization is achieved, scalability to higher data rates or more 
sensors may require further optimization of the communication protocol and processing 
pipeline. 
Overall, the software component satisfies all functional requirements, including user 
interaction, real-time visualization, system control, and response time constraints. The 
modular architecture also allows future expansion without significant restructuring, supporting 
further development of the diagnostic system. 
4.3.1.2. Computer Engineering (COE) Discipline Analysis: 
A) Analysis of COE components:  
1) MCU: ESP32-S3-DevKitC-1-N16R8 
We chose ESP32-S3 because it gives enough processing + RAM, has multiple 
peripherals, and is cost-friendly, which matches our student constraints and 
integration needs.  
Engineering value: the MCU must do two different jobs at the same time: 

  96  
• Hard real-time DAQ tasks (trigger ADC, read blocks, buffer, timestamp) 
• Control + comms tasks (VFD interface + USB streaming + UI commands) 
ESP32-S3 fits because it can run these as separate tasks and still keep cost low 
(compared to industrial DAQ controllers).  
 
2) External ADC: AD7606B (8-ch, 16-bit SAR, simultaneous sampling) 
The project needs multiple analog vibration channels sampled at 10 kHz, and the 
channels must be aligned in time. The AD7606B gives: 
• 8 synchronized analog channels 
• Simultaneous sampling 
• High throughput  
Why (real analysis): 
• If we use MCU internal ADC(s), we usually get multiplexed sampling → 
channel-to-channel delay and less predictable timing at higher throughput. 
• With simultaneous sampling, the 3 axes of one sensor (and both sensors) are 
captured at the same instant, which is important for real vibration signatures 
and for consistent AI features. 
Throughput check (proof it’s not a bottleneck): 
We stream 6 vibration channels (2 triax sensors), 16-bit samples, 10 kS/s: 
𝑅 = 6 × 10,000 × 16 = 960,000 bits/s ≈ 0.96 Mb/s ≈ 120 kB/s 
 
Even adding overhead and the VFD message, this is still very manageable for a 
modern MCU-to-PC link (especially if we send in blocks instead of per-sample). 
 
3) Vibration sensors: PCB Piezotronics 356A02 (triaxial IEPE) 

  97  
We chose these because they provide triaxial measurements in one package and have 
strong noise immunity, which is critical near a VFD-driven motor.  
 
Engineering value: 
• Triaxial in one package reduces mounting mistakes and gives consistent 
orientation across axes. 
• Strong immunity is important because VFD switching can inject noise into 
sensor cables; a vibration sensor choice that handles noisy environments 
reduces the risk of “AI learning noise” instead of true fault patterns. 
 
4) VFD: LNC820 
We selected this VFD because it supports MCU-based control and offers interfaces 
suitable for embedded integration; it is also commonly used with induction motors.  
 
Most important technical reason: it has RS-485 and supports MODBUS, so the 
MCU can both read status/telemetry and send commands.  
Also, the manual explicitly lists “Output torque (%)” and “Operating frequency (Hz)” 
as measurable parameters.  
 
So, reading: 
• input speed (from frequency/speed feedback) 
• estimated input torque (torque %) 
is technically supported by the VFD documentation. 
 
B) Why the MCU↔PC protocol is designed like this (analysis) 
1) Why we use a layered design 

  98  
Even though it is “USB serial,” we treat it like a layered stack: 
1. Physical/Link: USB serial connection 
2. Framing layer: packet boundaries + error detection + re-sync 
3. Application layer: vibration / VFD / control semantics 
Reason: raw serial is just a stream of bytes. Without framing, one dropped byte can 
destroy parsing for everything after it. A framing layer makes the system robust and 
measurable. 
 
2) Why we separate messages into (high-rate) vibration and (low-rate) VFD 
Vibration is high-rate and time-critical; VFD telemetry is low-rate. 
• Vibration requires steady streaming at 10 kHz and should be sent in binary 
blocks to reduce overhead. 
• VFD values (speed/torque/status) can be polled at maybe 10–50 Hz, which is 
tiny compared to vibration. 
This separation also improves AI traceability: vibration packets represent raw training 
signal, while VFD packets represent operating condition labels. 
 
3) Why control commands are simple ASCII 
Commands like START/STOP/SET_SPEED/SET_LOAD are low rate and safety-
relevant, so making them human-readable helps: 
• debugging during lab testing 
• reducing mistakes when verifying logs 
• ensuring the command stream doesn’t interfere with the vibration stream  

  99  
Binary commands would be slightly more efficient, but ASCII is safer for a student 
rig because it is easy to inspect and verify. 
 
4) Why the packet header needs sequence, length, timestamp (syntax + 
semantics) 
• Payload length: the PC knows where the packet ends (no guessing). 
• Sequence number detects packet loss → helps support “0 dropped samples” at 
the logging level. 
• Timestamp / sample counter: lets the PC align vibration blocks with VFD 
telemetry and compute drift/skew. 
• CRC (or checksum): detects corruption (important near a VFD environment). 
C) Why Sampling at 10 kHz: 
Nyquist requirement for diagnostic band (0–4 kHz) 
To avoid aliasing: 
𝑓𝑠 ≥ 2𝑓max = 2(4000) = 8000 samples/s 
At 𝑓𝑠 = 10 kS/s, the Nyquist frequency becomes: 
𝑓𝑁 =
𝑓𝑠
2 = 5000 Hz 
That leaves a 1 kHz guard band between max useful band and Nyquist: 
Guard band = 𝑓𝑁 − 4000 = 1000 Hz 
 
D) Proof that the system meets 10 kHz sampling rate:  
1) ADC throughput (AD7606B):  
o AD7606B supports 800 kSPS on all channels. 

  100  
o Project requirement (worst case) is: 
𝑹req = 𝟖 × 𝟏𝟎, 𝟎𝟎𝟎 = 𝟖𝟎, 𝟎𝟎𝟎 samples/s = 𝟖𝟎 kSPS 
o The ADC is more than fast enough with large margin. 
 
2) Digital readout rate from ADC → MCU (SPI bandwidth check) 
We will read 8 channels each frame at 16-bit each: 
o Bits per frame: 
𝑩frame = 𝟖 × 𝟏𝟔 = 𝟏𝟐𝟖 bits 
o Frames per second: 
𝟏𝟎, 𝟎𝟎𝟎 frames/s 
o Raw bit rate: 
𝑹SPI,raw = 𝟏𝟐𝟖 × 𝟏𝟎, 𝟎𝟎𝟎 = 𝟏, 𝟐𝟖𝟎, 𝟎𝟎𝟎 bits/s = 𝟏. 𝟐𝟖 Mbps 
Even if we add overhead (command bits, framing, idle time) and assume 2× 
overhead, we still only need about: 
𝑹SPI,practical ≈ 𝟐. 𝟓𝟔 Mbps 
 => Feasible, since MCU is 240MHz 
 
E) Proof Response Time can be less than 2 seconds: 
Calculation proof that ≤ 2s is achievable: 
We can bound the end-to-end delay as: 
𝑇total = 𝑇PC→MCU + 𝑇MCU proc + 𝑇MCU↔VFD 
 
1)  PC → MCU over USB-serial (command packet) 
control packet is small (typical): 

  101  
Header + payload + CRC ≈ ~32 bytes (order of magnitude) 
Even if we assume a conservative “serial-like” timing at 115200 bps (8N1, 
~10 bits/byte): 
𝑇PC→MCU ≈
32 × 10
115200 = 0.0278 s ≈ 2.8 ms 
(Real USB-CDC is usually faster than this, so this is conservative.) 
2) MCU processing time 
Parsing the packet + updating a setpoint variable + preparing a Modbus frame 
is lightweight: 
𝑇MCU proc ≈ 1–2 ms (budgeted) 
3) MCU ↔ VFD via Modbus RTU (RS-485) 
A Modbus “write single register” transaction typically has: 
Request: 8 bytes (addr, func, reg, value, CRC) 
Response: 8 bytes 
Total bytes ≈ 16 bytes 
At Modbus baud rate 𝐵, transmission time (8N1) is: 
𝑇tx ≈
16 × 10
𝐵  
Add Modbus silent intervals (3.5-character times before/after frames). 
 The character time is 
10
𝐵  ,so 3.5 chars ≈ 
35
𝐵  .Two gaps ≈ 
70
𝐵 . 
So: 
𝑇MCU↔VFD ≈
160
𝐵 +
70
𝐵 =
230
𝐵  
Now plug in a conservative baud rate (common and safe): 19200 bps: 

  102  
𝑇MCU↔VFD ≈
230
19200 = 0.0120 s ≈ 12 ms 
Even adding turnaround/jitter margin (queueing, ISR latency, retries) of ~10 
ms: 
𝑇MCU↔VFD ≈ 12 + 10 = 22 ms 
 
=> Total worst-case budget (conservative) 
𝑻total ≈ 𝟐. 𝟖 ms + 𝟐 ms + 𝟐𝟐 ms = 𝟐𝟔. 𝟖 ms 
This is comfortably below the proposed 2s requirement, leaving headroom for 
OS jitter on the PC and occasional Modbus delays. 
 
 
 
4.3.1.3. EE Discipline Analysis: 
1- Designing the motor characteristics: 
From the mechanical requirements, the motor should be able to deliver a variable torque up 
to 10N.m and variable speed up to 1200 rpm, The motor should be able to handle variable 
frequency from the VFD to provide different speeds and torque. Hence a three-phase 
induction motor is required with rated power: 
P= t*n/eff where t is torque, n is the rotational speed , eff is the efficiency of the motor ( 
usually around 82%) 
P= 10*(1200*2pi/60)/0.82 = 1.532 kW. 
Since most suppliers provide motors using horsepower: P=1532/746 = 2.1 Hp 
2- Calculating required circuit breaker requirement: 
In our system, two circuit breakers are required, one the VFD input (single-phase supply) 
and the induction motor input (three-phase). (Motor rated power = 2.2kW, Voltage 
supply=220VAC assuming Power factor=0.9) 

  103  
At the VFD input, P=I*V*PF à I= (2.2*10^3)/(220*0.9) = 11.1 A . Since the Induction 
motor starting current is around 5 times higher than the steady-state current, I= 11.1*5 = 
55.5A. Thus, a circuit breaker with 60 Rating is required 
At the Motor input, P = sqrt(3)*V*I*Pf , I=(2.2*10^3)/(sqrt(3)*220*0.9=  6.4A  starting 
current = 32. Thus a circuit breaker with 35 A rating is required 
The validation metrics will be by using a clamp meter to calculate the current in the system 
and comparing it to the calculated value. 
 
Figure 19: electrical schematic for protection of power subsystem. 
3- Controller steady stare error 
The VFD have a built-in PID controller that can be used to control the frequency and 
therefore the speed of the motor. 
The input speed should vary from 0 to 1200 pm which makes it a ramp input. 
The open loop of the system without the controller is 1/(Js+B) , where J is the inertia and B 
is the friction coefficient. 
By using the controller in the VFD as a PI controller the open loop equation becomes 
(Kp + Ki
s )( 1
Js + B) 
Since the input is ramp, the steady state error is e= 1/kv which should be <1% à Kv > 100 
Kv =𝑖𝑚𝑠−>0 𝑠∗(𝐾𝑝+𝐾𝑖𝑠)(1𝐽𝑠+𝐵)=𝐾𝑖𝐵. This means to achieve error <1% the Ki gain 
should be tuned to be > 100B where B is the friction coefficient which is obtained from the 
mechanical system 


  104  
The validation metric will be by measuring the applied speed and comparing it to the set 
value 
Error= (measured speed-set speed)/set speed * 100 
4- Signal conditioning 
filter design is needed to ensure signal quality by removing high frequency noise an 
analog low-pass filter will be used, and the following equation is needed to design the 
filter: f=1/2pi*RC . with Fc being 5Khz  (below the sampling frequency to prevent anti-
aliasing) 
RC = 1/2pi*5*10^3 =3.1831*10^-5 
Choosing C= 20nF , Then R =(3.1831*10^-5)/(20*10^-9)= 1.52 kOhm 
furthermore, in order to measure the signal quality, we need to find the 
quantization noise of the analog signals which is V/(2*2^n) where n is the number of bits 
(16) and V=3.3V. then the noise = 0.0025mV. 
Even if an ADC is labeled “16-bit,” the 
effective performance may be lower due to noise and distortion. ENOB is derived from 
measured SINAD: 
SINAD = 20log(signal power/noise power) = 20log[3.3/(0.025*10^-3)] = 16.6 bits à 16bits. 
Which verifies our design choice. The noise level will be validated in the prototype using an 
oscilloscope 
Another important aspect to keep in mind when designing the sensors and signal acquisition 
system is the sensitivity of the sensors used. In our project, the sensitivity was specified to be 
100mV/g. this means that in order to read the the sensors values and transform them into a 
comparable value, the following equation is used 
Acceleration (in g) = Voltage/sensitivity= voltage/0.1 
4.3.1.4. ME Discipline Analysis: 
1. Gearbox design (spur gear and bearing selection): 
Spur gear design criteria: Bending safety factor > 2.0 and contact safety factor > 1.2. 
Iterations were done under the following assumptions made by modern standards for spur 
gears such as AGMA, and by what is available on the market: 

  105  
•Pressure angle φn = 200 (AGMA) 
•Material Hardness = 240 HB (on both pinion and gear to facilitate calculation and it 
operates on moderate load, 10 Nm at 1200 rpm) 
•# of pinion teeth = 30 (available on the market) 
•# of gear teeth = 34 (available on the market) 
The following table shows the bending and contact factor of safety, for the complete 
iteration table via Excel refer to Appendix. Moreover, two plots relate factors of safety with 
respect to gear module.mt = 2 mm is chosen because it is the first point above the threshold. 
 
 
 
 
Figure 20: factor of safety. 
Figure 21: module against contact factor of safety. 

  106  
 
 
For the bearing selection, two manual iterations were conducted. Initially we used mt = 2 
mm with V = 1200*2π/60*60/2*10-3 = 3.77 m/s and  𝜔 = v/(0.5*dp) = 125.66 rad/s can get the 
actual applied power P = 10*30/34*125.66 = 1108.8 W ~ 1.1 kW < 2.2 kW. Given that from 
the brake applied torque with the gear ratio we get T = 10*30/34 = 8.82 Nm<10 Nm. 
After calculating the value of c10 = 2.31 kN, W 61903-2RS1 deep groove ball bearing from 
SKF was selected with the following figure showing its characteristics. 
 
2. Test bench components design (shaft and coupling selection): 
For the shaft we have followed the following shaft criteria:  
Safety factor>1.75 
Deflection at gears<0.075 mm 
Figure 22: Module against binding factor of safety. 
Figure 23: bearing performance from SKF. 

  107  
Slope at bearing<0.026 rad 
          This is in accordance with Shigley’s mechanical Engineering Design book, see 
following table. 
  
Figure 24: Shigley’ s mechanical engineering best practice. 
We have done iteration on Aluminum 6061-T6 and 45# Carbon steel and checked them 
against these criteria. 
  
Figure 25: Factor of safety graph for aluminum. 
 


  108  
 
Figure 26: Deflection graph for Aluminum. 
 
Figure 27: Slopes for the Aluminum. 
See the following for the case of the 45# carbon steel 
  
Figure 28: factor of safety for steel. 


  109  
 
 
Figure 29: Deflection for steel. 
 
 
Figure 30: slopes for steel. 
For the couplings, the selected coupling will easily satisfy the needed  


  110  
 
 
Figure 31: selected coupling specifications. 
As can be seen, the coupling satisfies all needed properties. 
 
4.3.2 Final Design Performance Results 
4.3.2.1. Information & Computer Science (ICS) Performance Results: 
The implemented diagnostic software achieved the following outcomes: 
The graphical user interface successfully accepts user-defined speed and load inputs. 
For each test run, four synchronized plots are displayed: rotational speed, applied torque, 
vibration waveform, and FFT spectrum. 
The system generates a fault classification result within the required response time of 3 
seconds or less. 
The machine-learning model achieved an overall classification accuracy above the required 
70% threshold when evaluated on labeled test data. 
Repeated executions using identical input data produced consistent classification outputs, 
confirming deterministic system behavior. 
During testing, the model remained fixed, with no adaptive or online learning mechanisms 
implemented. 
Under baseline constant operating conditions, the highest classification accuracy was 
observed. A slight decrease in performance occurred under time-varying speed conditions, 
which is expected due to the non-stationary nature of the signals. Despite this, overall 
performance remained above the specified design requirement.     


  111  
Based on these results, the ICS subsystem satisfied all defined software specifications, 
including accuracy, execution time, reproducibility, and successful integration with the 
mechanical and electrical subsystems 
Snapshots of the Frontend: 
 
 
 


  112  
 
 
4.3.2.2. Mechanical Engineering (ME) Performance Results: 
 
We came to conclusion that all specifications and constrains can only be satisfied optimally 
by selecting the following: 
Gears with pressure angle of 20 degress and module of 2 with face width of 2 
Aluminum 6061-T6 with OD=20mm as shaft 
W 61903-2RS1 from SKF 
And jaw couplings, the design can be optimized dimensionally to fit our constrain, see the 
following figure 
 
 
Figure 32: Bench dimensions. 
 


  113  
  
Figure 33: Mechanical guards 
 
 
4.3.2.3. Computer Engineering (COE) Performance Results: 
This section summarizes how the COE final design (ESP32-S3 MCU + AD7606B external 
ADC + 2× triaxial vibration sensors + VFD interface + USB serial protocol) meets the 
project’s key specifications and constraints. While early prototypes were used for validation 
and debugging, the claims below are based on the final selected architecture, components, and 
interfaces. 
Specification compliance (COE-related). The final design supports high-speed multi-channel 
vibration acquisition using two triaxial sensors (6 channels) sampled through an external 8-
channel, 16-bit, simultaneous-sampling SAR ADC (AD7606B). This ADC architecture is 
selected specifically to meet the requirement for synchronized multi-channel sampling without 
multiplexer skew, which is important for vibration feature quality and repeatability. The 
system is designed to sample vibration at ≥10 kS/s per channel and stream data continuously 
in binary blocks rather than per-sample messages (Proof is in section 4.3.1 -> COE part -> 


  114  
paragraph E). Block streaming reduces communication overhead and prevents the data link 
from interfering with sampling. A structured packet header (message type, payload length, 
sequence number, timestamp, and CRC) allows the PC logger to verify no data loss (sequence 
continuity) and no corruption (CRC pass rate) during the required long test runs, supporting 
the integrated requirement of continuous logging without dropped samples. Second 
specification (related to response time) is also met, and the design ensures that the response 
time will be less than 2 seconds (Proof is in section 4.3.1 -> COE part -> paragraph D ).  
Constraint compliance (COE-related). The temperature-sensor constraint (rated −55°C to 
+125°C) is met through the selection of an industrial-range temperature sensor integrated into 
the embedded subsystem for monitoring and context logging. Proof of this constraint is 
shown in the following figure (from the datasheet): 
 
 
4.3.2.4. Electrical Engineering (EE) Performance Results: 
The electrical Engineering has two specifications and one constraint that need to be 
met. 
Constraint 6: the system shall be controlled by a PID controller 
This can be achieved by using a VFD that has a built-in PID controller 


  115  
 
Figure 34: VFD datasheet showing PID built-in function. 
 
Specification 8: The Induction motor speed should be controllable a PID 
controller from 0-1200 rpm with steady state error <1% 
The VFD have a built-in PID controller that can be used to control the frequency and 
therefore the speed of the motor. 
The input speed should vary from 0 to 1200 pm which makes it a ramp input. 
The open loop of the system without the controller is 1/(Js+B) , where J is the inertia and B 
is the friction coefficient. 
By using the controller in the VFD as a PI controller the open loop equation becomes 
(Kp + Ki
s )( 1
Js + B) 
Since the input is ramp, the steady state error is e= 1/kv which should be <1% à Kv > 100 


  116  
Kv =𝑖𝑚𝑠−>0 𝑠∗(𝐾𝑝+𝐾𝑖𝑠)(1𝐽𝑠+𝐵)=𝐾𝑖𝐵. This means to achieve error <1% the Ki gain 
should be tuned to be > 100B where B is the friction coefficient which is obtained from the 
mechanical system 
The validation metric will be by measuring the applied speed and comparing it to the set 
value 
Error= (measured speed-set speed)/set speed * 100 
 
Specification 9: Accelerometer sensors should be of triaxial class with noise level 
< 50mV and sensitivity >=100mV/g with 3 channels per sensor 
A triaxial accelerometer measures acceleration along three orthogonal axes, 
producing output voltage proportional to acceleration: 
𝑉𝑜𝑢𝑡 = 𝑆 ⋅ 𝑎 + 𝑉𝑛𝑜𝑖𝑠𝑒 
 
where 𝑆 ≥ 100 mV/gis the sensitivity and 𝑉𝑛𝑜𝑖𝑠𝑒 < 50 mVis the noise level. The 
minimum detectable acceleration is: 
𝑎𝑚𝑖𝑛 = 𝑉𝑛𝑜𝑖𝑠𝑒
𝑆  
 
Substituting the worst-case values: 
𝑎𝑚𝑖𝑛 = 50 mV
100 mV/g = 0.5 𝑔 
This demonstrates that the sensor can reliably detect accelerations greater than 0.5 g 
with acceptable signal-to-noise ratio. With three channels per sensor, full 3D vibration 
monitoring is achieved, making the specification feasible for condition monitoring and 
fault detection in rotating machinery. 
 
 
 
 

  117  
Table 4: Summary of Project Constraints and Specifications Attainment in the Final Design. 
Constraints and Specifications 
Off-
the- 
Shelf 
Project 
Specific  
Responsible Department and Location of Evidence   
EE COE ICS ME 
Total project hardware & Software 
cost ≤ 15000 SAR  
 x X X x x 
The rig should only be able to 
work on single stage spur 
gearboxes 
 x    
Evidence in gear 
analysis    
Maximum system 
dimensions shall not exceed 4 
meters by 
2 meters 
 x    Figure 20 
The machine-learning model shall 
be trained using publicly available 
datasets and fine-tuned offline 
using data collected from the 
gearbox. During system operation, 
the deployed model shall remain 
fixed and shall not perform 
adaptive or online learning 
 
 x   
Evidence 
location : 
Sections 4.2 
and 4.3 Related 
to ICS 
 
 
The embedded sensing subsystem 
shall use a temperature sensor rated 
for −55°C to +125°C 
X   
Evidence 
location : 
Section 4.3.2 -> 
COE part 
  
The system speed shall be 
controlled by a PID controller 
 x 
Evidence 
location: page 49 
section 4.2.1   
   
The front end of the software shall 
provide a user interface that allows 
the user to input test  two 
operating parameters (rotational 
speed and applied load) and shall 
display four synchronized 
visualizations: rotational speed, 
applied torque, vibration time-
domain waveform, and vibration 
frequency-domain spectrum 
(FFT). 
      
Flexible shaft coupling shall 
tolerate at least 0.1 mm parallel 
misalignment between motor and 
gearbox shafts at rated speed 
X     
Evidence location 
in the  

  118  
100% of exposed rotating 
components shall be covered 
by mechanical guards during 
operations 
 x    
report (page 
number)  
 
The system shall apply a 
variable mechanical load 
from 0 Nm to 10 Nm 
 x    
The diagnostic software shall 
integrate signal preprocessing, 
feature extraction, machine-
learning classification model, and 
a friendly user-facing interface 
within a single executable 
application 
 x   
Evidence 
location: 
Sections 4.2 
and 4.3 Related 
to ICS 
(Diagram 
+Video)  
 
 
Peak ram demand of the diagnostic 
ML software shall be <= 16GB 
 x   
Evidence 
location: 
Sections 4.2 
and 4.3 Related 
to ICS 
(Video 
showcase front 
end 
interactions) 
 
 
The backend diagnostic software 
shall achieve a minimum overall 
classification accuracy of 70% 
when distinguishing between the 
predefined gearbox condition 
labels, as verified using a 
confusion matrix on a labeled test 
dataset 
 
 x   
Evidence 
location: 
Sections 4.2 
and 4.3 Related 
to ICS 
(Confusion 
matrix 
showcase 
validation 
method) 
 
 

  119  
Following completion of a diagnostic 
test run, the diagnostic software shall 
process the acquired data and present 
a gearbox fault classification result 
within 3 seconds. 
 
 x   
Evidence 
location: 
Sections 4.2  
Shows the 
concept  
proving 
 
The Induction motor speed should 
be controllable a PID controller 
from 0-1200 rpm with steady state 
error <1% 
 x 
Evidence 
location: section 
4.3.1.1 
   
Accelerometer sensors should be 
of triaxial class with noise level < 
50mV and sensitivity >=100mV/g 
with 3 channels per sensor 
 x 
Evidence 
location: section 
4.3.1.1 
   
The gearbox should be designed to 
handle a 2.2 KW of power and a 
maximum rpm of 1200 
 x    
See shafts and 
gears analysis 
The embedded DAQ shall 
sample all high-speed channels 
at ≥10 kS/s per channel 
(simultaneous) 
 x  
Proof is in 
section 4.3.1 -> 
COE part -> 
paragraph E 
  
When the UI sends a command, 
the response time should be ≤ 2s. 
 x  
Proof is in 
section 4.3.1 -> 
COE part -> 
paragraph D 
  
 
 
 
 
 
 
 
 
 

  120  
4.4. Bill of Material 
No software or hardware components were procured by the ICS students for this project. 
Table 5: Bill of material. 
Item Quantity Total Source 
Fan 1 0 KFUPM store 
ESP32 1 0 KFUPM store 
Thermal couple 1 0 KFUPM store 
Gears 5 338.1 AliExpress 
Magnetic 
Powder brake 
1 2239 AliExpress 
Bolts, nuts, 
washers 
- 62 Hardware store 
T-slots 14 140 AliExpress 
Bearings 6 135 Temu 
Bench 
Fabrication 
1 1495 Workshop in 
Khobar 
Gearbox 
structure 
fabrication 
1 2735 Workshop in 
Dammam 
Plates and 
tubes 
2-2 613 Temu 
Gears cutting 2 63 Workshop in 
Dammam 
VFD and motor 1-1 1626 AliExpress 
3-axial vibration 
sensor 
2 506 AliExpress 

  121  
Shems and 
torque wrench 
1-1 200 Amazon 
Laser cutting - 700 Workshop in 
Dammam 
 
 
 
 
4.5. Cost Analysis 
The estimated prototype cost was approximately SAR 10,223.47, based on the priced 
items listed in the Bill of Materials. The highest-cost items were the aluminum plates 
and gearbox structure fabrication (SAR 2700), magnetic powder brake (SAR 2200), 
bench frame fabrication (SAR 1450), induction motor (SAR 1305.56), and laser 
cutting for the face plate and guards (SAR 700). These items account for most of the 
prototype cost, while the embedded and interfacing electronics contributed a much 
smaller portion of the total cost. 
Several cost-saving measures were employed during prototype development. Some 
components, such as the fan, ESP32, thermocouple, circuit breaker, capacitors, and 
AWG wires, were obtained from the KFUPM store, which reduced direct purchasing 
cost. In addition, low-cost off-the-shelf items such as resistors, wires, breadboards, 
relay modules, and RS-485 to TTL modules were selected for prototyping instead of 
custom-built electronics. The use of commercially available evaluation and prototype 
parts also reduced manufacturing complexity and allowed faster testing, even if it may 
not be the lowest-cost option for large-scale production. 
Overall, the prototype cost was driven mainly by the mechanical fabrication and 
powertrain components, while the COE-related electronics were kept relatively low 
through the use of available university stock and inexpensive standard components. 
For future versions, the cost could be reduced further by replacing some prototype-
only parts with a custom integrated PCB and by optimizing fabrication methods for 
repeated builds. 

  122  
4.6 Engineering Drawing  
 
Figure 35: Gear Box assembly Drawing. 
 
 
 
 
 
 


  123  
 
Figure 36: Total assembly. 
 
 


  124  
 
Figure 37: Shafts Cad. 
 
  
Figure 38: electrical schematic for the power subsystem. 


  125  
 
 
 
Figure 39: Electrical schematic for the Power system. 
 
 
 
 
  


  126  
Chapter 5  
Prototype Implementation and Verification 
5.1 Final Prototype 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
ME: Gearbox fabrication and bench Chassis and structural 
design, motor and drivetrain integration, fabrication of the 
mechanical assembly, and validation of structural 
performance and physical operation. 
EE:  
Power system design and 
distribution, motor-drive and 
actuator interfacing, 
communication hardware, and 
integration of electronic 
subsystems such as sensing 
and transmission hardware. 
COE:COE:  
Embedded system integration, 
sensor interfacing and data 
acquisition, real-time signal 
processing, VFD/brake control 
communication, and system-
level coordination between the 
hardware and software 
subsystems. ICS: ML using data collected and identify the gear faulty 
condition, User interface development, data logging and 
visualization, communication software between the PC and 
embedded system, and overall software integration for 
monitoring and control. 

  127  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


  128  
5.1.1 Prototype Build 
5.1.1.1 ME Contribution to Prototype Build 
1- Bench manufacturing 
The base structure of the prototype was fabricated using carbon steel to ensure strength 
and durability. Three horizontal C-channels were welded to four vertical legs, forming a rigid 
frame. Caster rollers were attached to the bottom of each leg to allow mobility of the setup. 
Also, two vertical C-channels were mounted on one side of the bench to support and secure 
the ventilation fan. The entire structure was painted to improve appearance. 
 
2- Ventilation fan mounting 
A ventilation fan was borrowed from Building 42’s store and inserted into the bench. The 
fan was positioned and fixed onto the designated vertical C-channel supports on the bench. 
The two vertical C-channels were drilled three holes to allow fixing the ventilation fan. 


  129  
 
3- T-slots milling 
T-slots were chosen to enable sliding of components using T-bolts through 
the bench width. The slots were obtained from the market and milled approximately 
40 mm by length and 6 mm by depth on each side. This machining process allowed 
the slots to be properly drilled and fixed onto the bench surface.  
 
4- Cover manufacturing for rotating shafts 
Protective covers for the rotating shafts were designed and fabricated using aluminum sheet 
metal working processes. The covers were made to enclose the coupled shafts extending from 
the motor to the gearbox input, and from the gearbox output to the brake. A clearance-based 
design was adopted, with a width of 50 mm and thickness 2 mm to ensure no contact occurs 
with the rotating shafts during operation. Then drilled to include two mounting holes on each 


  130  
side (four holes per cover) to allow fixation using T-slot bolts. This provides effective 
guarding of rotating components while allowing easy installation and removal. 
 
5- Brake mount manufacturing 
The brake mounting plate was fabricated from a rectangular aluminum sheet. 
Holes were precisely drilled to accommodate T-slot bolts for securing the plate onto 
the bench, as well as additional holes for mounting the brake assembly. This setup 
provides an issue of misalignment of the brake shaft and the gearbox shaft, thus, 1 
mm shims were used to fix the misalignment. 
 
6- Motor mount manufacturing 
The motor mount was constructed using two L-channels as the primary 
support, with two C-channels welded across them to create a stable platform. The 


  131  
structure was made from carbon steel sheets of thickness 2 mm to withstand motor’s 
weight. The motor was then securely bolted onto this mount, ensuring proper 
alignment. 
 
7- Gearbox and cover manufacturing 
The gearbox was installed and aligned with the motor and shaft system to ensure efficient 
power transmission. A protective cover was fabricated primarily from aluminum, covering 
most of the gearbox system except for the bearings and two steel sheets used for the shaft 
plate. A transparent acrylic section was integrated into the cover to allow visual inspection of 
the gear meshing during operation. Lubrication was provided by applying general-purpose 
grease sourced from the market directly onto the gears, ensuring smooth operation and 
reducing wear while maintaining a sealed environment. 
 


  132  
5.1.1.2. ICS Contribution to Prototype Build 
The ICS subsystem was implemented as a software application running on a local 
workstation. The system includes a user interface for parameter input, data visualization, and 
file-based diagnostic testing. The frontend was developed to handle user interaction, while the 
backend manages data processing and communication with the embedded system. 
The software was successfully integrated with the overall system, allowing users to input 
operating parameters (speed and load), upload vibration data files, and receive classification 
results. This confirms that the ICS subsystem is fully operational within the prototype 
environment. 
 
 
5.1.1.3. COE Contribution to Prototype Build: 
The Computer Engineering prototype was built to validate the sensing, communication, and 
control functions of the system before final implementation. The prototype integrated an 
ESP32 microcontroller with vibration sensors, a temperature sensor, a Variable Frequency 
Drive (VFD) interface, and a brake-control interface. The build was carried out in a modular 
way so that each subsystem could first be tested independently, then integrated into one 
embedded platform. 
The main controller used in the prototype was an ESP32 development board. It was selected 
because it provides sufficient processing capability, multiple communication interfaces, and 
easy connection to a laptop for programming, testing, and data logging. The ESP32 acted as 
the central unit responsible for sensor acquisition, command transmission, and communication 
with the host computer. 
For vibration measurement, the prototype used two IIS3DWB vibration sensors through their 
evaluation boards as shown in Figure 5.1. These sensors were selected because they are more 
suitable for high-frequency vibration monitoring than simple low-cost analog accelerometer 
modules. The evaluation boards allowed easier interfacing during prototyping and provided a 
practical way to connect the sensors to the ESP32. The vibration subsystem was constructed 
to collect the gearbox and the motor vibration data to a laptop for analysis. Figure 5.2 shows 
the ESP32 connection to the IIS3DWB evaluation boards (our vibration sensors). 

  133  
 
 
For temperature monitoring, a DS18B20 digital temperature sensor was connected to the 
ESP32 using a 1-Wire interface with the required pull-up resistor. This subsystem was built to 
check the temperature of the gearbox brake so system can shut down when the brake heats. 
For motor-drive control, the ESP32 was connected to the VFD through a serial 
communication interface. The prototype was used to test sending frequency commands from 
the system UI to the ESP32, then from the ESP32 to the VFD. This confirmed that the 
embedded controller could act as a communication bridge between the software interface and 
the industrial drive. Figure 5.3 and Figure 5.4 show VFD communication connection.   
A separate brake-control interface was also included in the prototype. The reason for having a 
brake-control interface is that we want to monitor the temperature of the brake using the 
temperature sensor discussed earlier and if the temperature exceeds 60 C the microcontroller 
should be able to stop the system using the brake-controller to avoid any safety issues.  
Since the brake side operates under electrical conditions different from the ESP32 logic level, 
an interfacing stage was considered necessary between the microcontroller and the brake 
input. This protected the ESP32 and allowed safe digital control of the brake/load stopping 
function. Figure 5.5 shows the Brake control interface diagram. 
The prototype was assembled using rapid prototyping materials including jumper wires, 
breadboards, sensor evaluation boards, and USB communication links. Embedded firmware 
was developed for the ESP32, and Python scripts were used on the laptop side for testing, 
control, timing measurement, and sensor-data logging. 
The assembly process started with basic ESP32 programming and serial communication tests. 
The DS18B20 sensor was then connected and verified. After that, the IIS3DWB sensor 
evaluation boards were integrated and tested for data acquisition performance. Next, the VFD 
communication interface was assembled and validated by applying frequency commands. 
Finally, the brake-control interface was added and tested as part of the full system. This step-
by-step process allowed each function to be verified before full integration. 
 

  134  
 
Figure 5.1: IIS3DWB evaluation boards (Vibration Sensor) 
 
 
Figure 5.2: ESP32 connection to the IIS3DWB evaluation boards 
 
 
Sensor 1 
Sensor 2 

  135  
Figure 5.3: VFD communication connection 
 
 
Figure 5.4: VFD communication connection (actual connection) 
 
 
Figure 5.5: Brake control interface diagram 
 
 
 


  136  
5.1.1.4. EE Contribution to Prototype Build 
The prototype system was developed to validate the closed-loop speed control of an 
induction motor and the integration of vibration sensing. The build process covered 
component selection, fabrication, assembly, and system integration, with emphasis on 
control performance, signal integrity, and safety. 
 
Figure 13: system prototype 
The main hardware includes an induction motor, a Variable Frequency Drive (VFD) 
with an embedded PID controller, a molded-case circuit breaker (MCB) for 
protection, triaxial accelerometer sensors, and signal conditioning circuitry. The signal 
conditioning stage consists of a voltage divider to scale sensor output and a low-pass 
filter to attenuate high-frequency noise. Additional components include wiring, 
terminal blocks, a control enclosure, and measurement instruments for validation. 
The system was assembled in a modular manner to simplify testing and 
troubleshooting. The motor was mechanically coupled to the load and electrically 
connected to the VFD. The VFD parameters were programmed, including motor 
nameplate data and PI (PID) controller gains 𝐾𝑝and 𝐾𝑖, based on the control design 
discussed earlier. The control input was configured to accept a variable speed 
reference (0–1200 rpm), enabling ramp-type operation. 
The accelerometer sensors were mounted on the motor housing to capture vibration 
along three axes. Their outputs were routed through a signal conditioning circuit. The 
voltage divider ensures compatibility with the data acquisition system by scaling the 
voltage within acceptable limits, while the low-pass filter—characterized by the cutoff 
frequency: 


  137  
𝑓𝑐 = 1
2𝜋𝑅𝐶 
 
removes high-frequency noise and improves signal quality. All components were 
securely mounted with enclosure to ensure mechanical stability and proper cable 
management. 
 
Figure14: signal conditioning 
After assembly, the system was tested incrementally, open-loop motor operation was 
verified through the VFD. Then, closed-loop control was activated, and the PI gains 
were tuned to achieve the required steady-state error (<1%) over the full speed range. 
Sensor outputs were validated by observing clean, noise-reduced signals after 
conditioning. The measured motor speed was continuously compared with the 
reference input to evaluate system performance. 


  138  
 
Figure15:setting PID parameters 
 
Figure 16: motor nameplate 


  139  
ICS Contribution to prototype 
 
Figure 40 Detailed ML Model Flow Diagram 
 
                                                         
                 
                                  
                                             
          
            
                          
                                     
                       
                                           
                                  
              
                                          
                                
                              
                    
                                   
                    
                    
                                         
                                   
                        
                         
         
                                            
                             
                               
                
                 
                                        
               
                               
                                               
                                       
                        
                  
                
                 
                                 
                          
                            
                                                        
                                    
                                  
                             
                                                    
                                  
              
                                
                        
                                                  
                                 
                                    
                                        
        
                    
                 
                                                             
                                    
                                            
                                                         
                            
                                
                           
                                   
                                                    
                                
                                       
                                          
               
                      
                        
                                   
                                

  140  
 
Figure 41 Software frontend with load and speed profile controls 
 
 
5.1.2 Safety 
From the EE perspective, 
Safety was addressed throughout construction, testing, and operation. Electrically, the 
selected circuit breaker provides overcurrent and short-circuit protection, ensuring safe 
disconnection under fault conditions. Proper grounding of the motor, VFD, and enclosure was 
implemented to prevent electric shock hazards. 
During assembly, insulated tools and appropriate personal protective equipment (PPE) were 
used. Wiring was organized to avoid loose connections, which could lead to overheating or 
arcing. The VFD was configured with safe acceleration and deceleration limits to prevent 
mechanical stress on the motor. Thermal considerations were also addressed by allowing 
adequate ventilation for the VFD and motor 


  141  
 
Figure 17: circuit breaker for safety 
From the ME perspective, 
Safety measures were implemented throughout manufacturing process to minimize 
risks associates drilling and machining operations. While using hand drilling, table wheel 
casters were used to fix the table to prevent it from moving suddenly with the center punch to 
guide the drill bit through the intended place. 
For machining shafts and milling t-slots were done in the IHUB provided by the Team 
Design. Safety regulations were adhere by the IHUB by wearing PPE, being vigilant while 
using the machines, and never use the machines without the supervision of technicians and 
engineers. 
 Between any two runs, the gearbox bolts are checked , the set screws on the bearings 
and the gears are tightened again, the motor and break are checked to be fully unplugged, the 
guards are placed, and the overall condition of the system including the bench is checked. 
From the software perspective, 
 Safety is addressed through input validation and system-state awareness. The system 
validates user inputs and uploaded files to ensure that invalid or unsupported data does not 


  142  
result in misleading outputs. In the case of incorrect input, the system returns a rejection or 
“unknown” response instead of forcing a classification. 
Additionally, software design considers system operation status. The interface is intended to 
operate only when the system is properly connected and idle before starting a test. This helps 
prevent unintended operation or incorrect data processing. 
 
These measures ensure that the software contributes to safe system operation by preventing 
invalid actions and maintaining reliable diagnostic outputs. 
 
From COE perspective,  
From the Computer Engineering perspective, safety was considered during prototype 
construction, testing, and operation because the system combines low-voltage embedded 
electronics with motor-drive and brake-control hardware. The main concern was to protect 
both the user and the electronic components during development. 
 
During construction, the low-voltage side of the system, including the ESP32, sensors, and 
laptop connection, was kept separate from the higher-risk VFD and brake-control side. Direct 
connection between the ESP32 and external control lines was avoided unless proper 
interfacing was used. This helped protect the microcontroller from overvoltage or excessive 
current. Wiring was also checked carefully before powering the system. 
During testing, each subsystem was validated separately before full integration. The 
sensors, VFD communication, and brake-control path were first tested individually to reduce 
risk and make faults easier to identify. VFD commands were applied gradually and the system 
response was observed closely to avoid unexpected motor behavior. Extra care was taken 
around moving equipment and energized terminals during drive operation. 


  143  
During operation, power was disconnected before changing any wiring, especially on the VFD 
and brake side. Stable connections were maintained during live tests, and the laptop interface 
was used to monitor data and send commands without repeatedly handling the hardware. 
 
 
5.1.3 Cost 
The estimated prototype cost was approximately SAR 10,223.47, based on the priced 
items listed in the Bill of Materials. The highest-cost items were the aluminum plates 
and gearbox structure fabrication (SAR 2700), magnetic powder brake (SAR 2200), 
bench frame fabrication (SAR 1450), induction motor (SAR 1305.56), and laser 
cutting for the face plate and guards (SAR 700). These items account for most of the 
prototype cost, while the embedded and interfacing electronics contributed a much 
smaller portion of the total cost. 
Several cost-saving measures were employed during prototype development. Some 
components, such as the fan, ESP32, thermocouple, circuit breaker, capacitors, and 
AWG wires, were obtained from the KFUPM store, which reduced direct purchasing 
cost. In addition, low-cost off-the-shelf items such as resistors, wires, breadboards, 
relay modules, and RS-485 to TTL modules were selected for prototyping instead of 
custom-built electronics. The use of commercially available evaluation and prototype 
parts also reduced manufacturing complexity and allowed faster testing, even if it may 
not be the lowest-cost option for large-scale production. 
Overall, the prototype cost was driven mainly by the mechanical fabrication and 
powertrain components, while the COE-related electronics were kept relatively low 
through the use of available university stock and inexpensive standard components. 
For future versions, the cost could be reduced further by replacing some prototype-
only parts with a custom integrated PCB and by optimizing fabrication methods for 
repeated builds. 
 
 

  144  
Item Quantity Total Source 
Fan 1 0 KFUPM store 
ESP32 1 0 KFUPM store 
Thermal couple 1 0 KFUPM store 
Gears 5 338.1 AliExpress 
Magnetic 
Powder brake 
1 2239 AliExpress 
Bolts, nuts, 
washers 
- 62 Hardware store 
T-slots 14 140 AliExpress 
Bearings 6 135 Temu 
Bench 
Fabrication 
1 1495 Workshop in 
Khobar 
Gearbox 
structure 
fabrication 
1 2735 Workshop in 
Dammam 
Plates and 
tubes 
2-2 613 Temu 
Gears cutting 2 63 Workshop in 
Dammam 
VFD and motor 1-1 1626 AliExpress 
3-axial vibration 
sensor 
2 506 AliExpress 
Shems and 
torque wrench 
1-1 200 Amazon 

  145  
Laser cutting - 700 Workshop in 
Dammam 
 
5.2 Verification Test Description 
 
5.2.1 ME Verification Test 
 The specification regarding the ability of the system to apply 0-10 Nm on the 
gearbox was validated by running the gearbox at 1200 rpm  and then ramping the 
break torque from 0 to 10 nm. The break is rated at 50 Nm, 20% of it is 10 Nm , see 
the following figure. 
 
Figure 42 Breal torque 


  146  
It shows 21.5%, which means that we were able to reach more than the specifications 
mentioned. 
The specification regarding the gearbox being able to handle 2.2 Kw at 1200 rpm is 
shown by the following figure. 
 (a) 
(b) 
Figure 43 VFD readings, (a) 42.86 Hz, and (b) 2.29 kW of power. 
The figure shows the VFD operating the motor on 42.86 Hz, and to transfer 
from Hz to RPM, we use the following equation which is specific to our motor. 
𝑅𝑃𝑀 = 𝐻𝑧 ∗ 120
4 ∗ 14
15 
Therefore, the gearbox was running at 1200 rpm, 
Please see the shared video to see the test, 
Gearbox test.mp4 


  147  
The safety specification , the shafts coverage, was satisfied by making an 
upper coverage for the gearbox and guards to cover the couplings between the motor 
and the gearbox, and the brake and the gearbox which is done to prevent contact with 
rotating parts as stated by OSHA, [3]. 
The gearbox shafts were insured to be parallel by measuring the distance 
between the shafts at different locations, and modifying the set screws tightening on 
the bearing to minimize this variation  
5.2.2 ICS Verification Test 
A) Interactive Input and Visualization Verification 
 
The first verification test was conducted to evaluate the user interface functionality and its 
ability to respond to user inputs. The system allows the user to adjust two main parameters: 
rotational speed and applied load using interactive sliders. 
During testing, multiple input values were applied, and the corresponding system behavior 
was observed. The following results were obtained: 
• The speed profile graph updated dynamically according to the selected RPM values.  
• The torque (load) profile graph changed consistently with the applied load input.  


  148  
This confirms that the frontend correctly processes user inputs and updates the corresponding 
visualization components in real time. 
However, the remaining two plots: 
• Vibration signal (time-domain)  
• FFT spectrum (frequency-domain)  
do not directly respond to UI slider changes. Instead, these plots depend on the processed data 
received from the backend API. This behavior is expected, as these signals are generated from 
actual or uploaded vibration data rather than simulated UI inputs. 
Spec/Const Status 
Constraint 7 Meet 
 
Test cases  for them is : 
No API responses  
 
Correct  API responses 
 
The figures shape depend on the condition , therefore all condition will be tested in test case 
below. 


  149  
 
 
 
Specification/const Requirement Result Status 
Software integration  1 executable  Working pass 
UI front end  Reject invalid data Working pass 
 
ML diagnosis Verification Description 
The AI verification process was carried out using the HUSTgearbox dataset and conventional 
splitting of data for training and testing. That is due to the bench not being completely 
integrated in time for testing. faults are artificially preset in the gearbox used for the dataset, 
which is important when interpreting high accuracy values under controlled conditions. The 
model used in this study is a classical machine learning pipeline that segments the vibration 
signal into 0.5 s windows, extracts engineered features from each window, and classifies the 
window using a StandardScaler, SelectKBest, and RandomForestClassifier pipeline. Because 
scaling and feature selection are performed inside the pipeline, these steps are fit only on the 
training split during each evaluation fold, which reduces the risk of preprocessing leakage. 
 
For final verification, the model was tested using a leave-one-speed-out strategy so that each 
test set contained a speed condition not seen during training. In the revised implementation, 
overlapping windows were removed, gear-specific shortcut features were disabled, and model 
validation was strengthened using a run-level permutation sanity check with 100 repeats. In 
addition to window-level accuracy, a run-level majority-vote result was computed so that each 
original data file contributed one final classification decision. This provides a stricter and 
more realistic assessment of whether the model can correctly identify the gearbox condition 
for an entire run rather than only for isolated windows. 

  150  
 
Figure 44 window-level accuracy for ML model 
 
The confusion matrices from the final test show that the model separated the Missing-tooth 
condition perfectly, while the remaining classification errors occurred mainly between the 
Healthy and Broken classes. At the window level, Broken samples were correctly classified 
93% of the time, Healthy samples 94% of the time, and Missing samples 100% of the time. 
92% of Broken and Healthy were both classified correctly At the run level, while Missing 
remained at 100%. These results indicate that the AI module can reliably distinguish the most 
severe fault state and can also differentiate Healthy and Broken conditions with high 
consistency. 
File-Based Diagnostic Verification (Extended Cases) 
To comprehensively validate the diagnostic capability of the system, multiple file-based test 
cases were evaluated using the upload interface. 


  151  
The following datasets were tested: 
• Healthy dataset: The system correctly classified the condition as Healthy.  
• Chipped tooth dataset: The system correctly classified the condition as Chipped 
Tooth.  
• Missing tooth dataset: The system correctly classified the condition as Missing 
Tooth.  
In addition to valid datasets, an invalid/unknown input file was also tested to evaluate 
system robustness. This file did not correspond to any of the trained gearbox conditions or 
contained incompatible data formatting. 
• Invalid/unknown dataset: The system was able to detect incorrect input and did not 
produce a misleading classification. Instead, it returned an error or rejection response, 
indicating improper input data.  
 
Uploading files:  
 
 
As show in the image above , the software accept input and produce the output class & update 
figures based on them.  
There are 4 cases of inputting to the software : 
 
 


  152  
 
Case 1: 
• Input: Healthy dataset  
• Expected Output: Healthy  
• Actual Output: Healthy 
 
  


  153  
 
 
Case 2: 
• Input: Missing dataset  
• Expected Output: Missing Tooth  
• Actual Output: Missing Tooth 
 
 
 
Case 3: 
• Input: Broken dataset  
• Expected Output: Broken Tooth  
• Actual Output: Broken Tooth 
 
 


  154  
Case 4: 
• Input: Invalid / Empty file  
• Expected Output: Unknown 
• Actual Output:  UnKnown 
 
 
Test Case Expected Actual Status 
Healthy Healthy Healthy pass 
Broken Broken Broken pass 
Missing Missing Missing pass 
Invalid Reject Reject pass 
 
Spec/Const Status 
Constraint 7 Meet 
Spec  4 Meet 
 
 
 
 
 
 
 
 
 
 
 
 


  155  
5.2.1 COE Verification Test 
A) Verification of the System’s Ability to Handle 10 k Samples/s per 
Vibration Channel (COE First Specification) 
To verify that the system meets this requirement, the prototype is deployed and 
configured to acquire 10,000 samples from each of the six channels. The total 
acquisition time is then measured. To satisfy the specification, all 60,000 samples 
must be collected in less than 1 second.   
After assembling the system, the code provided in Appendix Z was used to evaluate 
the sampling performance. The program starts a timer, acquires the required data, 
then stops the timer and reports the total elapsed time. The measured result was well 
below 1 second, confirming that the system satisfies the requirement, as shown in 
Figure 5.2.1. 
 
Figure 5.2.1 Results of the sampling rate verification test  
To further verify the correctness of the collected data, the code was configured to 
transmit the captured samples to the laptop and save them as a .csv file for 
inspection. During this test, one sensor was placed facing downward and the other 
facing upward. Therefore, the z-axis reading of the first sensor was expected to be 
close to -1 g, while the z-axis reading of the second sensor was expected to be close 
to +1 g. The recorded results matched this expectation, as shown in Figure 5.2.2. 


  156  
 
Figure 5.2.2. Correctness Test  
 
B) Verifying System response time less than or equal 2 seconds (COE 
second specification)  
Our system supports motor speed control from the user interface by sending 
commands to the VFD. To verify this function, control commands are issued 
from the PC-based UI, and the system must apply each command in less than 
2 seconds.  
To achieve this, a client-server architecture was implemented, where the UI on the 
laptop acts as the client and the ESP32 acts as the server. The code for both sides is 
provided in Appendix Z. When a command is sent from the UI, the ESP32 receives 
the new speed value, forwards the corresponding control command to the VFD, and 
then sends an ACK message back to the UI. Upon receiving this acknowledgment, 
the UI calculates and displays the latency, which represents the time required for the 
command to be applied. As shown in Figure 5.2.3  the latency is much less than 2 
seconds (97ms).  


  157  
 
Figure 5.2.3  Response time verification test 
 
C) Verifying Of the off-the-shelf COE constraint 
The COE constraint states that "the embedded sensing subsystem shall use a 
temperature sensor rated for −55°C to +125°C". Since this is an off-the-shelf 
component constraint, verification can be established directly from the manufacturer’s 
datasheet. Figure 5.2.4 presents the relevant datasheet excerpt, which confirms that 
the selected temperature sensor satisfies the required operating temperature range. 
 
 
 
Figure 5.2.4 Temperature Sensor Datasheet proof 
 


  158  
5.2.2 EE Verification Test 
The primary objective of the verification process is to validate that the prototype meets the 
following key electrical design requirements: 
• Accurate speed control of the induction motor from 0–1200 rpm with steady-state 
error < 1%.  
• Reliable acquisition of vibration signals using triaxial accelerometers with acceptable 
noise levels less than 50 mV. 
The test will be conducted by measuring the signals output using a multimeter. 
 
Test 1: speed control of 1200 rpm and error less than 1%. 
The VFD can send an analog signal of 0-10 V that represents the running frequency 
where 0 represents 0 Hz and 10 represents 60 Hz. Given that our motor is 4 poles with 
slip= 1/15, the required frequency to reach 1200rpm f= 
𝑠𝑦𝑛𝑐ℎ𝑟𝑜𝑛𝑜𝑢𝑠 𝑠𝑝𝑒𝑒𝑑
1−𝑠𝑙𝑖𝑝 ∗
4
120 =

  159  
1200
1− 1
15
∗
4
120 = 42.85 𝐻𝑧, Hence the test will be conducted at f= 42.85 Hz 
 
Figure 2.2.4: voltage signal of motor speed 
From the figure above, the signa gives 7.05V. when converted into Hz, f= 7.05/10 *60 = 42.3 
Hz which is then converted into rpm. Speed = 42.3*120/4 * (1-1/15)= 1211 rpm 
Error percentage, (1219-1200)/1200 *100 = 0.912%. 
This means that our prototype passed the test for specification 8. 
 
 
 
 
Test 2: vibration noise level less than 50mV 
In this test the conditions are, 
1 The vibration sensors should send the signal when the system is not running. 


  160  
2 The signal should go into a low pass filter with C= 20nF , Then R =(3.1831*10^-
5)/(20*10^-9)= 1.52 kOhm. 
3 the multimeter should read a voltage less than 50 mV 
When doing the test, the reading was 43.5 mV noise level as shown in the figure below, 
 
Figure 2.2.5: vibration noise level 
This means that we passed the test 
 
 
 
 
 
 
 
 
 
 
 
 
 


  161  
5.3. Prototype Performance Results 
 
5.3.1 ICS Performance Results 
ML diagnosis model results 
The performance target for the AI module was an accuracy of at least 70%. Based on the final 
leave-one-speed-out evaluation, this target was exceeded. The model achieved a mean 
window-level accuracy of 95.60% and a mean run-level accuracy of 94.67%. The lowest 
result occurred on the unseen 40 Hz condition, where the model still achieved 87.00% 
window-level accuracy and 86.67% run-level accuracy. This means that the most difficult 
held-out speed condition remained above the project requirement. 
Table 6: Leave-One-Speed-Out results. 
held_out_
condition 
n_train_
windows 
n_test_
window
s 
window_
accuracy 
n_test
_runs 
run_ac
curacy 
perm_accur
acy_window 
perm_acc
uracy_run 
20 1200 300 0.946667 15 0.9333
33 
0.329567 0.332 
25 1200 300 1 15 1 0.371967 0.377333 
30 1200 300 1 15 1 0.3356 0.336 
35 1200 300 0.963333 15 0.9333
33 
0.3092 0.311333 
40 1200 300 0.87 15 0.8666
67 
0.337167 0.336667 
 
loso_speed_results.
csv
 
 
The classification report further supports these results. At the window level, the Broken and 
Healthy classes both achieved F1-scores of 0.93, while the Missing class achieved an F1-score 

  162  
of 1.00. At the run level, Broken and Healthy each achieved an F1-score of 0.92, and Missing 
again achieved 1.00. This shows that the system is strongest at identifying the Missing-tooth 
fault and slightly less precise when separating Broken from Healthy. Even so, the remaining 
confusion is limited and does not reduce the model below the required threshold.  
Table 7: classification report. 
 
The model was further validated through a permutation test. In the final run, the mean 
permutation accuracy was approximately 33.72% at the window level and 33.67% at the run 
level, which is close to random chance for a three-class problem. This is an important result 
because it indicates that the high classification accuracy is unlikely to be caused by 
information leakage or an invalid evaluation split. Instead, it suggests that the classifier is 
learning meaningful fault-related patterns from the vibration features. The final code explicitly 
implements run-level voting, run-level permutation testing, and the stricter no-overlap 
evaluation setup used for these reported results. 
 
 
Table 8: permutation test. 

  163  
While running the software during model training, which should represent the peak load 
condition of the software and exceeds realistic deployment expectations, RAM usage 
remained under 8 GB. 
 
Overall, the prototype met and the minimum AI performance requirement. However, 
because the dataset documentation notes that the dataset faults are artificially preset, these 
results should be interpreted as strong prototype validation under controlled conditions rather 
than definitive proof of performance in real world deployment. 
Specification/Constraint # Status 
Constraint 4 Met 
Specification 5 Met 
Specification 6 Met 
 
 
 
 
 
 
Figure 45 RAM usage during training 

  164  
ICS  (API response performance )  
 
 To verify system performance, the response time of the diagnostic process was measured 
using a timing mechanism implemented in the frontend as shown in the code snipet. 
 
 
. The timing captures the duration between sending the data to the backend API and 
receiving the classification result. 
 
The following results were obtained: 
Condition Result Response Time (s) 
Healthy Correct 1.936 
Chipped Tooth Correct 1.561 
Missing Tooth Correct 1.900 
Invalid Input Rejected ~0 


  165  
 
All response times were within the required limit of 3 seconds, satisfying the system 
performance specification. 
Spec/Const Status 
Constraint 7 Meet 
Spec  4 Meet 
Spec  7 Meet 
 
 
The verification results confirm that the software subsystem operates correctly across multiple 
dimensions: 
• The user interface responds dynamically to input changes and correctly updates 
relevant visualizations.  
• The diagnostic pipeline successfully classifies all predefined gearbox conditions.  
• The system demonstrates robustness by properly handling invalid inputs without 
producing incorrect outputs.  
• The response time meets the required performance constraint, ensuring practical 
usability.  


  166  
It is important to note that while the UI-based input affects the speed and torque profiles, the 
vibration and FFT plots are dependent on backend data processing. This separation ensures 
realistic signal representation based on actual data rather than simulated inputs. 
 
5.3.2 COE Performance Results 
From the Computer Engineering perspective, the prototype met the main specifications and 
constraints of the embedded subsystem. The integrated prototype included the ESP32, two 
IIS3DWB vibration sensor evaluation boards, the DS18B20 temperature sensor, and the 
interfaces for VFD control and brake control. 
As described in Section 5.2, the vibration-sensing requirement was verified by acquiring 
10,000 samples from each of the six channels and measuring the total acquisition time. The 
result was less than 1 second, confirming that the system can achieve 10 kSamples/s per 
channel. Data correctness was also verified by exporting the captured readings to a .csv file 
and checking that the measured values matched the expected sensor orientation. 
The motor-control requirement was also satisfied. Based on the test procedure in Section 5.2, 
commands were sent from the laptop UI to the ESP32, then to the VFD, and the measured 
response time showed that the command was applied within the required 2 seconds. 
In addition, the temperature-sensor constraint was met because the selected DS18B20 is rated 
for −55°C to +125°C, as confirmed from the datasheet in Section 5.2. 
Overall, the prototype results show that the COE subsystem satisfies its key requirements in 
sampling speed, data validity, control response, and component constraints. 
 
5.3.3 ME Performance Results 
We managed to prove all specifications and constrains except  
 

  167  
 
Table 9: Summary of Project Constraints and Specifications Attainment in the Prototype. 
Constraints and Specifications 
Off-
the- 
Shelf 
Project 
Specific  
Responsible Department and Location of Evidence   
EE COE ICS ME 
Total project hardware & Software 
cost ≤ 15000 SAR  
 x X X x x 
The rig should only be able to 
work on single stage spur 
gearboxes 
 x    
Evidence in gear 
analysis    
Maximum system 
dimensions shall not exceed 4 
meters by 
2 meters 
 x    Figure 20 
The machine-learning model shall 
be trained using publicly available 
datasets and fine-tuned offline 
using data collected from the 
gearbox. During system operation, 
the deployed model shall remain 
fixed and shall not perform 
adaptive or online learning 
 
 x   
Evidence 
location : 
Sections 4.2 
and 4.3 Related 
to ICS 
 
 
The embedded sensing subsystem 
shall use a temperature sensor rated 
for −55°C to +125°C 
X   
Evidence 
location : 
Section 5.2.1 
COE 
Verification 
Test 
  
The system speed shall be 
controlled by a PID controller 
 x 
Evidence 
location: page 49 
section 4.2.1   
   
The front end of the software shall 
provide a user interface that allows 
the user to input test  two 
operating parameters (rotational 
speed and applied load) and shall 
display four synchronized 
visualizations: rotational speed, 
applied torque, vibration time-
domain waveform, and vibration 
frequency-domain spectrum 
(FFT). 
      

  168  
Flexible shaft coupling shall tolerate 
at least 0.1 mm parallel misalignment 
between motor and gearbox shafts at 
rated speed 
X     
Evidence location 
in the  
report (page 
number)  
 
100% of exposed rotating 
components shall be covered by 
mechanical guards during 
operations 
 x    
The system shall apply a 
variable mechanical load 
from 0 Nm to 10 Nm 
 x    
The diagnostic software shall integrate 
signal preprocessing, feature 
extraction, machine-learning 
classification model, and a friendly 
user-facing interface within a single 
executable application 
 x   
Evidence 
location: 
Sections 4.2 
and 4.3 Related 
to ICS 
(Diagram 
+Video)  
 
 
Peak ram demand of the diagnostic 
ML software shall be <= 16GB 
 x   
Evidence 
location: 
Sections 4.2 
and 4.3 Related 
to ICS 
(Video 
showcase front 
end 
interactions) 
 
 
The backend diagnostic software 
shall achieve a minimum overall 
classification accuracy of 70% 
when distinguishing between the 
predefined gearbox condition 
labels, as verified using a 
confusion matrix on a labeled test 
dataset 
 
 x   
Evidence 
location: 
Sections 4.2 
and 4.3 Related 
to ICS 
(Confusion 
matrix 
showcase 
 

  169  
validation 
method) 
 
Following completion of a diagnostic 
test run, the diagnostic software shall 
process the acquired data and present 
a gearbox fault classification result 
within 3 seconds. 
 
 x   
Evidence 
location: 
Sections 4.2  
Shows the 
concept  
proving 
 
The Induction motor speed should be 
controllable a PID controller from 0-
1200 rpm with steady state error <1% 
 x 
Evidence 
location: section 
4.3.1.1 
   
Accelerometer sensors should be of 
triaxial class with noise level < 50mV 
and sensitivity >=100mV/g with 3 
channels per sensor 
 x 
Evidence 
location: section 
4.3.1.1 
   
The gearbox should be designed to 
handle a 2.2 KW of power and a 
maximum rpm of 1200 
 x    
See shafts and 
gears analysis 
The embedded DAQ shall 
sample all high-speed channels 
at ≥10 kS/s per channel 
(simultaneous) 
 x  
Evidence 
location : 
Section 5.2.1 
COE 
Verification 
Test 
  
When the UI sends a command, 
the response time should be ≤ 2s. 
 x  
Evidence 
location : 
Section 5.2.1 
COE 
Verification 
Test 
  
 
 
 

  170  
5.4. Future Manufacturing Recommendation 
5.4.1. ICS (Software System): 
improvements can be made in future work to strengthen the software portion of the 
prototype. First, additional models should be compared against the current Random 
Forest baseline. Suitable candidates include deep learning models such as a 1D CNN. 
Since the present model already performs strongly, any future model should be judged 
using the same strict leave-one-speed-out and run-level validation procedure rather 
than only by window-level accuracy. 
Second, the dataset should be expanded. More runs should be collected at additional 
speeds and loads, and the system should be tested with naturally occurring gear 
degradation rather than only preset laboratory faults. Collecting data under varying 
noise levels, sensor placements, and longer operating periods would also provide a 
better estimate of real deployment performance. More diverse data should improve 
generalization and reduce the remaining confusion between Healthy and Broken 
conditions. 
Third, more advanced AI methods could be explored. Such as multi-axis sensor fusion 
using X, Y, and Z vibration channels together, automated hyperparameter 
optimization, and hybrid systems that combine engineered features with deep learning. 
These techniques may improve robustness when operating conditions change and may 
be especially valuable if the system is later deployed in an industrial environment. 
However, the implementation of such features will require a significantly larger 
dataset. 
 
 
 
 
 
 
 
 
 
 

  171  
5.4.2 COE Future Manufacturing Recommendation: 
From the Computer Engineering perspective, the prototype was effective for testing, 
but its manufacturing process can be improved for future work. The current build 
relies on evaluation boards, jumper wires, and bench-top assembly, which are suitable 
for prototyping but not for reliable or scalable production. 
The main recommendation is to replace the current setup with a custom PCB that 
integrates the ESP32, sensor connections, temperature-sensor interface, VFD 
communication circuit, and brake-control cir 
uitry in one board. This would improve reliability, reduce wiring errors, lower 
assembly time, and support better design for manufacturability. 
In addition, future versions should reduce dependence on evaluation boards, since 
they increase size and cost. Using the required components directly in the PCB design 
would make the system more compact and more suitable for production. 
Finally, adding standard connectors, test points, and clearer board organization would 
simplify assembly, maintenance, and testing. Overall, these improvements would 
reduce cost, improve repeatability, and make the COE subsystem more practical for 
future manufacturing. 
 
5.4.3 ME Recommendation: 
The design should be able to move components horizontally in a more easier way than 
the current method, T-slots, by using for example power screws and guide rails or rack 
and pinion mechanism. 
 
The design should be able to detect bearing faults such as inner race, balls, outer race 
pitting or damage. 
 
 
  

  172  
Chapter 6 Conclusions and Recommendations 
 
6.1. Conclusion 
This report presents the complete design of an AI-driven automated gearbox failure diagnostic 
rig for a single-stage spur gearbox. The aim of the system distinguishes between healthy, 
chipped tooth, and missing tooth conditions through integrated mechanical, electrical, and 
software design. The design process addressed project requirements, constraints, and 
specifications derived from stakeholder needs. 
The mechanical design uses a motor–gearbox–brake arrangement to achieve controlled and 
repeatable testing conditions. A closed-loop eddy-current brake with supported shaft line 
ensures vibration measurements reflect gearbox fault conditions. Safety features include 
complete guarding of rotating components and temperature-based emergency shutdown. 
The electrical systems provide power delivery, motor control, and data acquisition. A variable 
frequency drive with PID control maintains speed stability within one percent steady-state 
error. The data acquisition subsystem samples vibration, speed, and torque channels 
simultaneously at ten kilohertz per second, capturing fault signatures with sufficient 
resolution. 
The software components deliver a complete diagnostic pipeline. Data from the Data 
Acquisition subsystem is windowed into segments containing vibration signals for 10 
revolutions each. Feature extraction converts vibration signals into time-domain and 
frequency-domain indicators. A machine learning classifier achieves the required seventy 
percent accuracy threshold for distinguishing gearbox conditions. The user interface enables 
intuitive test control and real-time data visualization. 
All design decisions meet project constraints and specifications. The system stays within the 
fifteen thousand SAR budget, operates within dimensional limits, and prepares the team to 
work further on integrated requirements for condition classification across multiple operating 
modes. 
 
 
 
 

  173  
6.2. Future Work 
The next phase involves component procurement and test bench fabrication according to 
finalized CAD drawings. Following assembly, the integrated system must undergo testing to 
verify subsystem performance under real operating conditions. This includes validation of PID 
speed control, data acquisition performance, and safety interlock functionality. 
Further development opportunities include extending feature extraction with additional 
condition indicators, refining the machine learning model architecture, and integrating 
software control with the embedded system and mechanical components. 
The system architecture supports future expansion. Adapting the rig for different gearbox 
types would broaden research and teaching applications. The modular software design 
accommodates new features without fundamental restructuring. 
The completed system can serve as a platform for educational laboratory exercises and 
research investigations in condition monitoring. Documentation will enable future student 
teams to operate and extend the system. Collaboration with maintenance workshops could 
validate the diagnostic approach on field-returned gearboxes. 
  

  174  
References 
[1] C. Zhao, Enrico Zio, and W. Shen, “Domain generalization for cross-domain fault 
diagnosis: An application-oriented perspective and a benchmark 
study,” Reliability Engineering & System Safety, vol. 245, pp. 109964–
109964, Jan. 2024, doi: https://doi.org/10.1016/j.ress.2024.109964.  
[2] R. G. Budynas, J Keith Nisbett, and Joseph Edward Shigley, Shigley’s mechanical 
engineering design, 11th ed. New York, Ny: Mcgraw-Hill Education, 2020. 
[3] Occupational Safety and Health Administration, “1910.212—General 
requirements for all machines,” OSHA. Accessed: Apr. 16, 2026. [Online]. 
Available: https://www.osha.gov/laws-
regs/regulations/standardnumber/1910/1910.212 

  175  
Appendix A   
Discipline-Specific Requirements for ABET 
KFUPM is ABET Accredited. ABET is an external organization in the United States that 
evaluates the quality of KFUPM’s Engineering Programs. Accreditation of our programs helps 
KFUPM maintain its quality of instruction, thereby helping its students to get the highest 
quality education. In order to keep KFUPM’s accreditation, your senior design reports need to 
demonstrate the following.  
ALL DISCIPLINES (General Criteria):  
A design experience that:  
1. Incorporates appropriate engineering standards and multiple constraints.  
2. Is based on the knowledge and skills acquired in earlier coursework.  
Additionally, you may need to incorporate a discipline-specific set of requirements as listed 
below  
AE  
The major design experience must include topics appropriate to the program name.   
AECM  
• The four basic architectural engineering curriculum areas are building structures, 
building mechanical systems, building electrical systems, and 
construction/construction management. Graduates are expected to reach the synthesis 
(design) level in one of these areas, the application level in a second area, and the 
comprehension level in the remaining two areas.  
• The design level must be in a context that:  
o Considers the systems or processes from other architectural engineering curricular 
areas,  
o Works within the overall architectural design,  
o Includes communication and collaboration with other design or construction team 
members,  
o Includes computer-based technology and considers applicable codes and standards, 
and  
o Considers fundamental attributes of building performance and sustainability.  
• Analysis and design of construction processes and systems in a construction 
engineering specialty field.  
BIOE  
Only the General Criteria for all disciplines  

  176  
CE  
• Design of environmental engineering systems that includes considerations of risk, 
uncertainty, sustainability, life-cycle principles, and environmental impact.   
• Concepts of professional practice and project management, and roles and 
responsibilities of public institutions and private organizations pertaining to 
environmental policy and regulations.  
CHE  
Design, analyze and control a process, including the hazards associated with the process.  
CIE  
Only the General Criteria for all disciplines.  
COE  
Demonstrate that you analyzed and designed a complex electrical/electronic device, software, 
or system containing hardware and software components.  
EE  
Demonstrate that you analyzed and designed a complex electrical/electronic device, software, 
or system containing hardware and software components.  
ICS  
A major project that requires integration and application of knowledge and skills acquired in 
earlier course work.  
ISE  
• Design, analysis, operation and improvement of integrated systems that produce or 
supply products or services in an effective, efficient, sustainable and socially 
responsible manner.   
• Systems design and analysis topics, such as decision analysis, risk analysis (cost, 
schedule and performance), trade-off analysis, optimization, modeling based 
engineering, simulation, sensitivity analysis techniques, or requirements engineering.   
ME  
Demonstrate that you modeled, analyzed, design and then realized a physical system, 
component or process.  
MSE  
• Employ selection and design of materials, processes, or a combination of materials 
and processes.  
 

  177  
Appendix B  
Gantt Chart  
 
 


  178  
 
 
 
Appendix C  
Final Drawings 
 


  179  
 
 


  180  
 
 
 


  181  
 
 


  182  
 
 
 
 


  183  
 
 
  


  184  
Appendix D  
Specification for Supplied Materials 
 
 
FZ-50-DZI 


  185  
 
KP004 


  186  
 
 
VTB-90L 
Item Quantity Total Source 
Fan 1 0 KFUPM store 
ESP32 1 0 KFUPM store 
Thermal couple 1 0 KFUPM store 
Gears 5 338.1 AliExpress 
Magnetic 
Powder brake 
1 2239 AliExpress 


  187  
Bolts, nuts, 
washers 
- 62 Hardware store 
T-slots 14 140 AliExpress 
Bearings 6 135 Temu 
Bench 
Fabrication 
1 1495 Workshop in 
Khobar 
Gearbox 
structure 
fabrication 
1 2735 Workshop in 
Dammam 
Plates and 
tubes 
2-2 613 Temu 
Gears cutting 2 63 Workshop in 
Dammam 
VFD and motor 1-1 1626 AliExpress 
3-axial vibration 
sensor 
2 506 AliExpress 
Shems and 
torque wrench 
1-1 200 Amazon 
Laser cutting - 700 Workshop in 
Dammam 
 
 
  

  188  
Appendix E 
Point-By-Point Reply to Scope Form and CDR Presentation 
Reviewers' Comments 
EE Reviewer (Dr. Naveed Iqbal) 
Comment 1: 
The background lacked quantitative evidence (e.g., failure statistics, cost 
percentages, bandwidth requirements) to fully justify the transition to AI-based 
diagnostics. 
Team’s Reply: 
Thank you for the valuable comments. To address this, we have cited two sources 
that give numbers about annual cost loss and percentage of failures related to gearbox 
issues. This is added in section 1.2.ii 
We also added section 1.2.iii about evaluation of the current solutions and how they 
require expertise to interpret results from manual inspection. 
Comment 2: 
The problem statement while concise, it could be strengthened further by including 
measurable performance goals (accuracy, bandwidth, fault types). 
Team’s Reply: 
We appreciate the feedback. We have improved the problem statement by including 
the following performance goals: 
1- Included the type of faults to be identified (healthy, chipped tooth, missing 
tooth) 
2- Set the target accuracy to be 70% 
3- Specified the type of gearbox that the model will be based upon (one-stage 
spur gearbox) 
Comment 3: 
critical EE specifications were missing or insufficiently defined, including: exact 
sampling frequency (kHz), number of channels, sensor type (accelerometer class, 
sensitivity), anti-aliasing strategy, synchronization accuracy, noise floor and dynamic 

  189  
range. 
Team’s Reply: 
We appreciate the feedback. To address the above concerns: 
79 
1- The sampling frequency was specified (10 kilo samples/sec). However, due to 
limitation on how much specification each department should have (they 
should be distributed evenly between each member), we have included it for 
the COE member in the report; the EE will also work to achieve this 
specification. 
2- We added a new specification that address the number of channels per 
sensors, sensors class and sensitivity 
Comment 4: 
Constraints and specifications were listed, but the summary did not clearly show 
engineering trade-offs, such as: resolution vs sampling speed, cost vs channel count, 
offline vs real-time processing. 
Team’s Reply: 
To address the above comment, we included in section 2.2.3 and 2.2.4 that talk in 
detail about why each constraint and specification was chosen and some trade-off that 
were considered. 
Comment 5: 
The EE should also be involved in Data processing and AI. There was no clear 
electrical system architecture diagram illustrating: sensors , signal conditioning , ADC 
, embedded/PC interface , data storage, AI processing. 
Team’s Reply: 
We appreciate the feedback. We have increased the scope of the EE student to be 
involved in signal processing and AI. We also updated the system architecture to 
include sensors, ADC and PC interface. 
Comment 6: 
very good presentation with visual and delivery. The presentation was well 

  190  
prepared. From an Electrical Engineering perspective, the main weaknesses are: lack 
of a clear signal acquisition architecture, no definition of sampling, noise, and 
synchronization parameters, absence of a system block diagram. 
Team’s Reply:We appreciate the feedback. To address the above concerns: 
We included a system block diagram that shows each stage role in the systemm. We 
also tried to provide a better systemthat shows a better signal processing and cleaning 
architecture. 
80 
ICS Reviewer (Dr. Omar Hammad) 
Comment 1 & 2: 
Comments on Introduction to Technical Problem (Background) 
you jumped to the solution before giving enough context 
Comments on Problem Statement 
need to tell more why this is important 
Team’s Reply: 
In response, the report has been revised to clearly separate the problem definition from the 
solution description. Section 1.1 (Overview) now focuses exclusively on the technical 
problem, its limitations, and the need for improved maintenance-oriented gearbox fault 
identification, without describing system architecture or implementation details. The proposed 
solution is now introduced only at a high level in the final paragraph of Section 1.1 and is 
described in detail in later sections of the report. 
In addition, to Comment 2, Section 1.2 (Introduction) has been expanded to clearly explain 
the importance of the problem, including its relevance to industry, the impact of gearbox 
failures on downtime, maintenance cost, and safety, and why improved diagnostic approaches 
are needed. Quantitative industry data and a discussion of current maintenance and diagnostic 
practices are now included to strengthen the motivation for the project. 
Comment 3: 
Comments on Final Target Specifications 
more work for ICS/SWE is needed 

  191  
Comments on Summary Table for Constraints and Specifications 
Team’s Reply: 
81 
the final target specifications have been revised to explicitly include 4 multiple 
software-focused specifications under ICS/SWE responsibility. These now cover the 
development of diagnostic software for signal preprocessing and feature extraction, 
implementation of a user-facing interface for visualization and fault-type output, 
performance-related requirements for response time, and the integration and validation of the 
machine-learning classification model, including accuracy requirements. These additions 
more accurately reflect the depth and breadth of the ICS/SWE contribution. 
Comment 4: 
show them from different perspective (how they look AND how they work) 
CS/SWE work is not enough. 
Comments on Evaluation of Conceptual Design 
Team’s Reply: 
The conceptual design has been expanded to present the system from multiple perspectives, 
addressing both how the system operates functionally and how it is structured 
architecturally. Chapter 1 now includes ICS software UML and data-flow diagrams that 
explain the internal software architecture, data flow, and the role of machine-learning within 
the diagnostic pipeline. 
In addition, Section 2.4 includes a multidisciplinary system interaction figure that shows 
how the ICS software interfaces with the mechanical testing bench, sensors, and data 
acquisition hardware to produce the final diagnostic outputs. Together, these additions provide 
a clearer and more comprehensive view of both the system’s appearance at a high level and its 
operational behavior across disciplines. 
Comment 5: 
need more. 
Comments on Novelty of Concept 
what are the current approaches? 

  192  
82 
Team’s Reply: 
To better clarify the introduction has been revised to explicitly describe current gearbox 
diagnostic approaches, which primarily rely on purely physical testing rigs, manual 
inspection, or expert-driven vibration analysis without integrated intelligent fault 
identification. These existing approaches typically focus on mechanical testing or signal 
visualization alone and do not incorporate automated, data-driven fault classification to 
support maintenance decision-making. 
The revised Introduction now highlights that the novelty of this project lies in integrating a 
physical gearbox testing bench with an intelligent, software-based fault identification 
system, combining vibration-based signal processing and machine learning within a unified, 
maintenance-oriented platform. This integration addresses a clear gap in current approaches 
by enabling automated fault-type identification prior to disassembly, rather than relying solely 
on manual interpretation or physical inspection 
ME Reviewer (Dr. Bilal Qureshi) 
Comment 1: 
Clear Background with relevant scope 
Team’s Reply: 
Thank you 
Comment 2: 
More than 3 relevant users identified 
the figure is nicely made. I dont see any particular problem in it No hidden 
relationships were uncovered. Team’s Reply: 
Thank you 
Comment 3: 
More than 4 relevant customers' needs 
83 
Team’s Reply: 
Thank you 

  193  
Comment 4: 
2 or more relevant constraints identified for your department 
Team’s Reply: 
Thank you 
Comment 5: 
Some values require justification. 
The team’s reply: 
Thank you for your insights. 1-the alignment value was changed to be more realistic and 
changed to be a minimum rather than a maximum. 2-The teeth number related spec was 
changed to braking torque spec since it is more important to the project. 3-the unelated 
constrain was unchecked and the second integrated is mechanical since it will stop the 
rotating parts through brake. 
Comment 6: 
Complete set of mapping specifications are provided. 
The team’s reply: 
Thank you 
Comment 7: 
Type of prototype correctly stated, with sufficient description of components, addressing of 
needs, constraints and specifications. 
The team’s reply: 
Thank you 
Comment 8: 
3 or more relevant and available resources listed 
The team’s reply: 
Thank you: 
Comment 9: 
In ME contribution, students keep saying "design or choose", which is not appropriate. 
Choice is based on some calculation. 
The team’s reply: 

  194  
Thank you for your insights! We have changed that and clarified that our choice will be 
based on valid calculations. 
Comment 10: 
Background information is comprehensive and provides context for the problem. 
Technical language is precise and impactful. 
The team’s reply: 
Thank you 
Comment 11: 
Problem statement is one sentence and concise, impactful, and pinpoints the core 
issue. 
The team’s reply: 
Thank you 
Comment 12: 
Three or more relevant Stakeholders are identified. 
The team’s reply: 
Thank you 
Comment 13: 
Key constraints are identified and their impact on design is thoroughly analyzed. 
The team’s reply: 
Thank you 
Comment 14: 
Three or more relevant customers are identified. 
The team’s reply: 
Thank you 
Comment 15: 
Customer needs/requirements are not only identified and mapped to the problem 
statement and translatable into constraints and specifications. 
The team’s reply: 
Thank you 

  195  
We have revised it in section 2,2,5 (QFD discussion) 
Comment 16(QFD): 
No hidden relationships were uncovered. 
The team’s reply: 
Thank you, the QFD were further discussed in 2.2.5 
Comment 17 (dentifying at least 2 customers and then evaluating how well the 
competitors): 
This should be done on a separate slide. Make sure to do this in the report 
The team’s reply: 
Thank you ! We have discussed the competition and competitors under the QFD discussion 
(2.2.5) 
Comment 18(Final Target Specifications): 
no boundaries are being pushed here. 
The team’s reply: 
Thank you, it will be upgraded during the FDR after calculations are done and investigating 
the room for improvement 
Comment 19: 
there are 2 ME students as far as I can tell. Therefore, needs 2 constraints and 4 specs for 
ME students. Please re-check the percentage of off the shelf items allowed. Make sure this is 
not violated as you are using 4 of them 
The team’s reply: 
Thank you for pointing that out ! 
We have added another constrain and two more specifications. Please see 2.1.6 and 2.1.7 
Comment 20: 
in the decision column, its either a yes or no. No idea what "combine" means. 
The team’s reply: 
Thank you, combined were removed 
Comment 21: 
no story telling but visuals are great. 

  196  
The team’s reply: 
Thank you, it has been explained thoroughly 3.1 design concept 
the figure is nicely made. I dont see any particular problem in it. 
The team’s reply: 
Thank you 
Comment 23 
Not Applicable to the Reviewer's Department. 
The team’s reply: Thank you 
The novelity of the concept lays in the fact that the project aims to make the science of 
multi fault diagnosis more practical 
Comment 24: 
Not Applicable to the Reviewer's Department. 
The team’s reply: Thank you, the creativity of the concept that it lays in expanding in 
gearbox diagnosis with less need of expert labor 
COE Reviewer (Dr. Uthman Baroudi) 
1- Comments on Introduction to Technical Problem (Background) 
Background information is comprehensive and provides context for the problem. 
Technical language is precise and impactful. 
The team’s reply: Thank you. 
2- Comments on Problem Statement 
Problem statement is one sentence and clearly defines the problem. 
The team’s reply: Thank you. 
3- Comments on Final Target Specifications 
Need justification, lack details or measurability. 
The team’s reply: Thank you, We provided more detailes, see Table 1 
4- Comments on Summary Table for Constraints and Specifications 
does not meet the minimum requirements from COE perspective. 
1- The team’s reply: Thank you, COE Constraints and Specifications were revised, see 
Table 1 (COE Constraints and Specifications written in red ) 

  197  
5- Comments on Evaluation of Conceptual Design 
Design concepts are clearly presented. 
The team’s reply: Thank you 
6- Comments on Summary Figure for Prototype Deliverables 
needs more clarifications for COE roles 
The team’s reply: Thank you, more worke is given to COE student (see section 1.3 
(COE part is in red) and table 2) 
7- Comments on Novelty of Concept 
Unable to Evaluate novelity to the COE Department 
8- Comments on Creativity of Concept 
The concept is demonstrably creative. 
The team’s reply: Thank you 
9- Overall Comments 
A challenging problem and needs more effort to be exerted to clarify the final prototype. 
The team’s reply: Thank you, we will try our best. 
 
 
 
 
 
 
  

  198  
Appendix F 
Point-By-Point Reply to CDR Report Reviewers' Comments 
EE reviewer (DR. Naveed Iqbal) 
Comment 1:   
No explicit transfer function or stability analysis for motor control loop (only generic 
K/(ts+1)).No ripple voltage or regulator efficiency calculation shown.ENOB requirement 
stated but no numerical SINAD example for chosen ADC.  
Team’s Reply:            
Thank you for the valuable comments. To address this, we added more details regarding the 
motor control loop and added more numerical calculations related to SINAD and ENOB   
The changes are in page 25 section 1.3.ii and are in the color: blue  
EE color: Blue  
COE color: Red  
ME color: Green  
   
Comment 2:   
Off-the-shelf percentage not numerically summarized (only marked in table).Some 
verification methods vague (e.g., “calculate to prove torque”).Accuracy metric inconsistency 
(ROC-AUC mentioned in justification but 70% accuracy in spec).  
Team’s Reply:   
We appreciate the feedback. We have improved the problem statement by including the 
following   
1. Added the percentage of off the shelf specs ( 6.67%) in page 33 section 2.1.7 right 
after the specification/constraints table  
2. Updated the metric to be accuracy and removed the old metric (ROC-AUC) in 
throughout the report  
EE color: Blue  
COE color: Red  
ME color: Green  
   
Comment 3:   

  199  
No schematic or PCB diagram included in this section. No quantitative subsystem validation 
targets (e.g., ripple < X mV).Task allocation table does not include milestone verification 
metrics..   
Team’s Reply:   
We appreciate the feedback. To address this we  
1. Added electrical schematic for the project prototype in page 58 section 2.4  
   
Comment 4:   
Replies reference sections but not page numbers.No explicit “Track Changes applied” 
confirmation.No before/after comparison.No visible discipline color coding.Some responses 
explain but do not quantify improvement.  
Team’s Reply:   
To address the above comment, we added the exact page number along with the section, 
applied track change, and added color coding, and made response more detailed.  
EE color: Blue  
COE color: Red  
ME color: Green  
ME Reviewer (Dr. Bilal Qureshi) 
Comments on Title Page, TOC, List of Figures, and List of Tables:  
everything is done nicely. god job.  
The team’s reply: Thank you!  
   
Comments on Abstract:  
Comprehensive and concise. Accurately summarizes purpose, method, and future objectives 
for the project design. Polished, adheres to guidelines, and avoids subjective statements.  
The team’s reply: Thank you!  
   
Comments on Background:  
Comprehensive and concise. Accurately summarizes purpose, method, and future objectives 
for the project design. Polished, adheres to guidelines, and avoids subjective statements.  
The team’s reply: Thank you!  
   

  200  
Comments on Fundamental Scientific and Engineering Concepts  
overall it is a good attempt to explain the project. Better than most others.  
The team’s reply: Thank you!  
   
Comments on Project Definition and Impact  
Comprehensive, cohesive, and well-justified. Clearly articulates objectives, deliverables, 
customer needs, and constraints.  
The team’s reply: Thank you!  
   
Comments on Project Constraints and Specifications  
all elements are present. table is misaligned though.  
The team’s reply: Thank you for the feedback, we have fixed and aligned the table. You can 
see it in Table 1.  
   
Comments on Discipline-Specific Contributions and Team Management  
the two ME students need to divide the 4 specs equally amongst themselves, not share all 4. 
Take 2 each so that design contribution can be measured individually. This is needed for the 
course and ABET requirement.  
The team’s reply: Thank you for your valuable comment, for the specifications for ME 
students we divided the specs as follows:  
One student will take constrain 3, and specs 1 & 2, which revolve around alignment, shafts 
guarding, and bench design.  
Second student will take constrain 2, and spec 3 & 10, which concentrate about the gearbox 
design and selection of components.  
   
Comments on Design and Development  
Clearly and systematically documents all stages of design and development. Fully utilizes 
structured tools (e.g., SCAMPER, AHP, Pugh matrix)  
The team’s reply: Thank you!  
   
Comments on References  
Mostly relevant, good mix, mostly recent, few format errors.  
The team’s reply: Thank you!  

  201  
   
Comments on Reply to Scope Form and CDR Presentation Reviewers' Comments  
scope comments not included/addressed. no track changes included.  
The team’s reply: Thank you for your valuable input, we included the track changes in this 
document.  
    
COE Reviewer (Dr. Uthman Baroudi) 
Comments on Fundamental Scientific and Engineering Concepts:  
Needs more details and examples for the equations mentioned.  
Team's reply: more details and examples are provided; you can check section 1.3 (COE part 
are written in red).  
Additional Note: section 1.3 consists of two subsections:  
i. Relevant Scientific and Computational Techniques   
ii. Relevant Basic Engineering Concepts  
Under each subsection COE part is written in red    
Comments on Project Constraints and Specifications:  
Explain how will each standard be used in your project. Mention the departments related to 
each constraint and specification. Why is constraint 5 (in red color) very long with multiple 
parameters (can be devided into multiple constraints)  
Team's reply: mapping constraints and specifications to departments is in the table right after 
constraints and specifications (Table 1), also we modified constraint 5 (COE constraint) to be 
as you commented.  
Comments on Discipline-Specific Contributions and Team Management:  
Well structured and detailed. Clearly outlines discipline-specific contributions  
Team's reply: Thank you  
   
Comments on Reply to Scope Form and CDR Presentation Reviewers' Comments:  
Addresses all comments clearly with specific references to revised sections.  
Team's reply: Thank you  
  
  

  202  
Appendix G  
Point-By-Point Reply to Final Design Presentation Reviewers' Comments 
EE reviewer (Dr. Naveed Iqbal) 
Comments on Final Design Block Diagram with All Disciplines Contributions: Mostly 
signal processing-related works. Other disciplines' roles are not well defined. Discipline 
contributions appear listed rather than integrated, and interdependencies (e.g., EE–ME 
motor interface, EE–COE control signals) are not explicitly defined.  
Team reply: Thanks for the feedback. To address this comment: We updated the the final 
block diagram to be more detailed in page 29 section 4.1  
Comments on Final Design Details for each Discipline :The frequency of 60 and the 
voltage of 220V are.obvious. no explicit electrical schematics, power distribution 
architecture, protection strategy, or validation results are described in the presentation. 
Put more efforts on controller  
Team reply: Thanks for the feedback to address this comment we  
1. Changed the frequency constraint to be related to the controller (in updated 
CDR report page 44 section 2.2.3 as per team design guidelines)  
2. Added electrical schematic in section 4.2.2page 35  
Comments on Table of ALL Project Constraints, Specifications, and Integrated 
Specifications Attainment for the Final Design: The table appears to be high-level and 
discipline-separated, rather than focused specifically on electrical engineering 
constraints and their verification. There is no discussion of how achieved vs. required 
values, verification methods, or status. 220V ,60 Hz not a constraint. put specifications 
related to controller  
Thanks for the reply to address this comment We:  
1. Removed the 220V constraint and replaced with a constraint about the PID controller 
(CDR updated report page 44 section 2.2.3+ section 4.2.2 page 67)  
2. Added a specifiaction about the controller that the controlled speed should be 
controller by a PID control with steady state error less than 1% ( CDR report 
section 2,.25 page 50)  
ME reviewer (Dr. Bilal Qureshi) 
Comments on Elevator Pitch  
Clearly defines problem & solution, holds some audience interest. Delivers in more than 20 
seconds.  
Team’s reply :  
Thank you for you feedback, we appreciate your thoughtful input into our project!  

  203  
We will practice it more  
Comments on Gantt Chart and Project Timeline Adherance  
Exceptionally clear and well-organized chart with well-justified durations  
Team’s reply :  
Thank you for you feedback, we appreciate your thoughtful input into our project!  
  
  
Comments on Deliverables  
Deliverables are mostly complete, relevant, and meet project requirements.  
Team’s reply :  
Thank you for you feedback, we appreciate your thoughtful input into our project!  
  
Comments on Final Design Block Diagram with All Disciplines Contributions  
Block diagram is comprehensive, well-organized, and clearly integrates all disciplinary 
contributions effectively and cohesively.  
Team’s reply :  
Thank you for you feedback, we appreciate your thoughtful input into our project!  
  
  
Comments on Final Design Details for each Discipline  
Students did a good job. references were provided as well. minor improvements needed.  
Team’s reply :  
Thank you for you feedback, we appreciate your thoughtful input into our project! Please 
check our new work in chapter 4 specially section 4.3  
  
Comments on Table of ALL Project Constraints, Specifications, and Integrated Specifications 
Attainment for the Final Design  
2 constraints and 4 specs were provided, which is the required amount.  
Team’s reply :  
Thank you for you feedback, we appreciate your thoughtful input into our project!  

  204  
  
Comments on Visual Support and Delivery  
Delivery needs work. They have trouble explaining what they are doing.  
Team’s reply :  
Thank you for you feedback, we appreciate your thoughtful input into our project! We will 
communicate with external members to help us improve  
Overall Comments  
Students still having some trouble explaining what they are trying to do similar to CDR.  
Team’s reply :  
Thank you for you feedback, we appreciate your thoughtful input into our project! We will 
communicate with external members to help us improve   
ICS Reviewer (Dr. Omar Hammad) 
Comments on Final Design Block Diagram with All Disciplines Contributions  
Clear integrated diagram; EE/ME interfaces need cleaner separation and flow.  
Teams Reply: Thank you for the feedback. Please find the updated diagram In section 4.1  
  
Comments on Final Design Details for each Discipline  
Strong ME/COE work; EE sim still “in progress” and CS accuracy ~75%.  
Teams Reply: Thank you for the input. EE portion of 4.3.1 contains more complete work. And 
results are more solidified.  
  
Comments on Table of ALL Project Constraints, Specifications, and Integrated Specifications 
Attainment for the Final Design  
Specs appear by discipline, but no single table showing attainment clearly.  
Teams Reply: Thank you for the input. Table 4 is an integrated specs table and rectifies this 
issue.  
  
Overall Comments  
Solid prototype direction; needs finished EE validation and integrated specs table.  
Teams Reply: Thank you for the feedback. Table 4 is a integrated specs table. EE portion of 
4.3.1 contains more complete work. And results are more solidified.  

  205  
COE Reviewer (Dr. Uthman Baroudi) 
Comments on Final Design Block Diagram with All Disciplines Contributions:  
Very detailed and comprehensive diagram including all contributing disciplines.  
Team's Reply: Thank you  
  
Comments on Final Design Details for each Discipline:  
well defined and proved all specs and constraints to be attained! Do you sensors match the 
dataset? The dataset should represent the same phenomenon you are observing (gearbox you 
were going design)  
Team's Reply: Thank you, we will rely mostly on something called vibration analyses, and 
generally gearboxes behave similarly in these analyses, so we will try the data set first, and if 
did not worked ,we will start collecting data from our gearbox.    
  
Comments on Table of ALL Project Constraints, Specifications, and Integrated 
Specifications Attainment for the Final Design:  
well defined and proved all specs and constraints to be attained! Do you sensors match the 
dataset? The dataset should represent the same phenomenon you are observing (gearbox you 
were going design)  
Team's Reply: Thank you  
Overall Comments:  
Excellent work and i wish you all the best.  
Team's Reply: Thank you   
  

  206  
Appendix H  
Point-By-Point Reply to Second Report Reviewers' Comments 
In this appendix, you are required to address the comments provided by the reviewers on 
the Second Report Installment.   
EE Reviewer (Dr. Naveed Iqbal)  
Comment 1 (PPR):  
Comments on department specific constraints, specifications, integrated specifications: The 
evidence was enough...  
Team’s Reply:  
Thank you.  
  
Comment 2 ( 2nd report:  
The EE contribution is not developed in a discipline-specific final-design format. The main 
final design chapter only contains the ICS subsection in detail, while the rest of the chapter 
still includes template text such as “Write a brief description of this chapter” and placeholder 
sections for analysis, bill of materials, cost analysis, and engineering drawing. The report does 
not present a clear EE hardware architecture, electrical schematic, DAQ interface design, 
power distribution layout, sensor wiring, signal conditioning design, or integrated EE 
subsystem description for the implemented rig.   
The final presentation response section is not developed. Appendix G is listed, but no actual 
EE reviewer comments or team replies are shown in the visible report content. The document 
still carries major template remnants in the appendices, and the final response trail does not 
show how EE presentation feedback was addressed through specific revisions, sections, 
figures, or tables.  
Team’s Reply:  
We appreciate the reviewer’s feedback. We believe that there was some 
confusion as the incomplete template was uploaded in the same folder as the complete 
version. We tried to delete the incomplete template but we did not have the access/ permission 
to do so. We will try to make the final version to appear first in the folder. We apologize for 
the confusion.  
  
ME Reviewer (Dr. CCC DDD)  
Comment 1:  
The mechanical design section lacks sufficient detail about the material selection process and 
how it addresses thermal and structural stresses.  

  207  
Team’s Reply:  
We appreciate the reviewer’s observation. In Section 3.3, we have expanded the material 
selection discussion, including a new subsection (3.3.1) that details the evaluation criteria for 
thermal and structural stress resistance. Additionally, a stress analysis summary has been 
provided in Table 2, which highlights how the selected materials meet the project 
requirements.  
To make the updates clear, these changes are highlighted in the Word file using Track 
Changes. Contributions specific to Mechanical Engineering are marked in Blue, as per the 
color code outlined earlier.  
Comment 2:  
The CAD model is well-developed, but the integration of mechanical and electrical 
components in the assembly is not clearly illustrated.  
Team’s Reply:  
Thank you for pointing this out. We have updated Section 3.5 to include a detailed discussion 
on the integration of mechanical and electrical components. A new exploded view of the 
assembly (Figure 10) has been added to demonstrate how the components are interconnected. 
Furthermore, annotations in the figure clarify the interfaces between subsystems.  
To make the updates clear, these changes are highlighted in the Word file using Track 
Changes. Contributions specific to Mechanical Engineering are marked in Blue, as per the 
color code outlined earlier.  
  
  
  
  
  
  
ICS Reviewer (Dr. Omar Hammad)  
  
Comment1  
 on Ethical and Professional Responsibility:  
The ethics section is detailed, uses NSPE, and ranks stakeholders clearly.  
Team’s Reply:  
Thank you for your positive feedback. We appreciate your evaluation.  

  208  
  
  
Comment 2  
Subsystem design choices and interfaces are explained with evidence and diagrams.  
Team’s Reply:  
Thank you for your valuable feedback. We are glad that the subsystem design and interface 
explanations are clear and well-supported.  
  
  
Comments 3  
The report shows real calculations and hardware assumptions, so the discipline summary is 
meaningful.  
Team’s Reply:  
Thank you for your comment. We appreciate your recognition of the detailed analysis and 
supporting calculations included in the report.  
  
  
Comments 4  
There is good subsystem evidence, but the report does not demonstrate that the final design 
meets all constraints.  
Team’s Reply:  
Thank you for your valuable feedback. We addressed this comment by strengthening the 
validation section and clearly linking the verification results to the project constraints and 
specifications. Specifically, we added structured test cases, performance evaluation, and a 
summary table to demonstrate compliance with key system requirements. These updates are 
reflected in Sections 5.2 and 5.3.  
  
  
Comments 5  
The appendix answers comments point by point and references figures and sections clearly.  
Team’s Reply:  
Thank you for your positive feedback. We appreciate your evaluation.  

  209  
  
  
Comments 6  
FDR presentation replies are included, but some answers stay generic and don’t reference 
specific edits.  
Team’s Reply:  
Thank you for your feedback. We improved the responses by making them more specific and 
linking each comment to the corresponding updated sections, figures, and tables in the report. 
This ensures a clearer and more traceable revision proc  
  
  
  
  
Dr. Uthman Baroudi <ubaroudi@kfupm.edu.sa> | Role: Only Reviewer  
  
Comments on Ethical and Professional Responsibility:  
Add the chapter and subchapter numbering. Identifies a relevant ethical concern and explains 
why it matters.   
  
Team’s Reply: Thank you,  chapter and subchapter numberings were added to all the report.   
  
  
Comments on Final Design Description:  
Provides a clear and detailed description of the final design.  
Team’s Reply: Thank you.  
  
Comments on Final Design Analysis and Justification:  
Provides a detailed analysis of each component. Incorporates nearly all compelling evidence 
of engineering design.  
Team’s Reply: Thank you.  
  

  210  
Comments on Final Design Performance and Validation:  
Concise summary, covers essential elements of the design Write the constraints and 
specifications in Table 4; not just “Constraint #” and “Specification #”  
  
Team’s Reply: Thank you, we added the whole constraints and specifications text on the 
table.  
  
Comments on Reply to CDR Report Reviewers' Comments:  
Detailed responses address all comments clearly with specific references to revised sections.  
Team’s Reply: Thank you.  
  
   
  
Comments on Reply to FDR Presentation Reviewers' Comments:  
Detailed responses address all comments clearly with specific references to revised sections.  
Team’s Reply: Thank you.  
 
 
ME Reviewer (Dr. Bilal Qureshi)  
Comments on Title Page, TOC, List of Figures, and List of Tables  
well-organized, comprehensive, professional, error-free.  
Team’s reply: Thank you!  
Comments on Abstract  
Comprehensive and concise. Accurately summarizes purpose, method, and objectives for the 
project  
Team’s reply: Thank you!  
Comments on Standards, Codes, and Regulations  
Clearly identifies and discuss relevant standards, codes, or regulations. Integrates them 
effectively into the engineering design with appropriate citations.  
Team’s reply: Thank you!  
Comments on Ethical and Professional Responsibility  

  211  
Clearly identifies a relevant ethical concern and explains why it matters in context. Applies 
NSPE code with clear relevance and reasoning (multiple appropriate rules/sections). Identifies 
key stakeholders and provides a reasonable ranking by impact with brief justification.  
Team’s reply: Thank you!  
Comments on Final Design Description  
Provides a clear and detailed description of the final design. Presents detailed diagrams (Figs. 
4&5 from Guidelines) illustrating departmental contributions. Thoughtfully integrates design 
considerations into the analysis while addressing ethics, public health, and safety.  
Team’s reply: Thank you!  
Comments on Final Design Analysis and Justification  
Provides a clear and detailed analysis of each component. Incorporates nearly all compelling 
evidence of engineering design, such as equations, diagrams, and discussions. Addresses key 
assumptions and concepts thoroughly.  
Team’s reply: Thank you!  
Comments on Final Design Performance and Validation  
the claim is for more than 75%, so this is chosen.  
Team’s reply: Thank you!  
Comments on Bill of Materials and Cost  
BOM is reasonable but needs more work. cost analysis needs more detail.  
Team’s reply: Thank you for your feedback. For the BOM it has been updated with the cost 
analysis in pages 62 and 63 with detailed table of parts and thorough cost analysis.  
Comments on Conclusions and Future Work  
Delivers clear and well-structured conclusions that effectively summarize key findings and 
align with project objectives.  
Team’s reply: Thank you!  
Comments on References  
only two references are provided.  
Team’s reply: Thank you for your valuable feedback, a third reference has been added about 
OSHA safety standards that we followed for designing covers for coupled rotating shafts.  
Comments on Reply to CDR Report Reviewers' Comments  
no track Changes used in this report.  
Team’s reply: Thank you for your insightful feedback. We have added the track changes in 
this report.  

  212  
Comments on Reply to FDR Presentation Reviewers' Comments  
no track Changes used in this report.  
Team’s reply: Thank you for your insightful feedback. We have added the track changes in 
this report. 
 
  

  213  
Appendix I  
Point-By-Point Reply to PPR Reviewers' Comments 
Dr. Uthman Baroudi <ubaroudi@kfupm.edu.sa> | Role: Only Reviewer  
Comments on department specific constraints, specifications, integrated specifications:  
2 constraints are satisfied for COE (one is COE only, and one is budget) 1 Specification is 
satisfied  
  
Team’s Reply: Thank you, now 2 constraints and 2 Specification are satisfied, and the proofs 
is in section "5.2.1 COE Verification Test"  
  
  
Comments on overall constraints, specifications, integrated specifications:  
2/6 Constraints achieved 1/12 specifications achieved 0/3 integrated specifications achieved  
  
Team’s Reply: Thank you, we have been working on these 
and all Specification and constraints are met, See Table 5 for reference.  
  
Reviewer: <bqureshi@kfupm.edu.sa> | Role: Coach and Reviewer  
Comments on department specific constraints, specifications, integrated specifications  
1 constraint was proven with evidence.  
Team’s reply: Thank you!  
Comments on overall constraints, specifications, integrated specifications  
50% of the project's constraints, specifications, and integrated specifications are met with a 
satisfactory or better strength of evidence.  
Team’s reply: Thank you!  
  
  
  

  214  
Appendix J 
Point-By-Point Reply to third Report Reviewers' Comments 
EE reviewer (DR. Naveed Iqbal) 
Comment 1:   
The EE analysis is technically relevant and covers the main electrical responsibilities of the 
rig, including three-phase induction motor sizing, VFD-based PID speed control, circuit-
breaker sizing, triaxial accelerometer selection, signal conditioning, low-pass filter design, 
quantization-noise discussion, and sensor sensitivity conversion. The section is still not fully 
complete as a final EE analysis because some calculations remain idealized and are not tied 
tightly enough to measured prototype behavior 
Team’s Reply:            
Thank you for the valuable comments. To address this, we finalized the EE analysis by tying 
the theoretical calculations to the actual prototype. 
   
Comment 2:   
The EE prototype is identifiable through the power schematic, DAQ block diagram, signal-
conditioning figure, VFD setup, motor nameplate, and protection-related figures. The visual 
record still needs stronger organization as a discipline-specific prototype summary. The front 
matter retains placeholder figure-list text and unrelated template figure titles, and the EE 
contribution is spread across several figures rather than summarized in one clean labeled 
prototype figure showing the 220 V AC input, VFD, induction motor, circuit breaker, 
accelerometer channels, filter stage, DAQ path, grounding, and interface to the diagnostic 
software 
.Team’s Reply:   
We appreciate the feedback. To address the comment we removed placeholder figures and 
lists. We also made the visuals more organized. 
Comment 3:   
The EE response trail is present and acknowledges the earlier concerns, including the 
undeveloped EE final-design format, missing hardware architecture, missing schematic and 
DAQ details, and unclear response trail from the previous submission. The main weakness is 
that the reply partly explains the issue as an upload or folder confusion rather than clearly 
closing each EE concern with exact final sections, figures, tables, and measured prototype 
evidence. The current report does contain stronger EE content than the earlier version, but the 
appendix response itself should more directly point to the completed power schematic, DAQ 
block diagram, signal-conditioning design, prototype build, and verification evidence. 
 Team’s Reply:   

  215  
We appreciate the feedback. To address this, we strengthened the weakness by closing the 
exact EE content and made the appendix point directly to the complete schematics. 
 
Reviewer/Coach: Dr. Uthman Baroudi  <ubaroudi@kfupm.edu.sa>  |  Role: 
Reviewer  |  Dept: COE    
  
Comments on Final Design Analysis  
Missing some equations for throughput.  
Team’s Reply:  Thank you, You can now find throughput calculation in section 4.3.1.2  
 
Comments on Final Prototype Summary Figure  
clear and detailed figure illustrating each department's contribution.  
 Team’s Reply:  Thank you 
Comments on Verification Test  
To prove the system reliability, it should be tested multiple times, not just once, then you can 
show some statistics (e.g. Mean, STD)  
 Team’s Reply:  Thank you, we have done 18 tests with more than 600 thousand readings for 
each test, and results have been shown during FPR. 
Comments on Final Prototype Performance Results  
concise summary, covers essential elements of the prototype  
 Team’s Reply:  Thank you 
Comments on Reply to earlier comments  
Addresses all comments clearly with specific references to revised sections.  
Team’s Reply:  Thank you  
 
Reviewer/Coach: Dr. Bilal Qureshi  <bqureshi@kfupm.edu.sa>  |  Role: Coach and 
Reviewer    
  
Comments on Prototype Build, Safety, and Cost  
All items are mentioned in a appropriate manner.  
 Team’s Reply:  Thank you! 
Comments on Future Recommendation  

  216  
Delivers clear, relevant, and technically grounded recommendations for future manufacturing.  
  Team’s Reply:  Thank you! 
Reviewer/Coach: Dr. Bilal Qureshi  <bqureshi@kfupm.edu.sa>  |  Role: Coach and 
Reviewer  |  Dept: ME    
  
Comments on Final Design Analysis  
Delivers an insightful and comprehensive analysis of all components.  
  Team’s Reply:  Thank you! 
Comments on Final Prototype Summary Figure  
Delivers a comprehensive and well-structured figure that clearly highlights each department's 
contribution.  
   Team’s Reply:  Thank you! 
Comments on Verification Test  
Delivers a comprehensive and rigorous verification of the prototype.  
   Team’s Reply:  Thank you! 
Comments on Final Prototype Performance Results  
100% of constraints and specifications met by the prototype with sufficient strength of 
evidence.  
 Team’s Reply:  Thank you! 
Comments on Reply to earlier comments  
Comprehensive and polished. Each comment is addressed thoroughly and professionally, with 
detailed references to revisions  
Team’s Reply:  Thank you!  

  217  
Appendix K 
Point-By-Point Reply to Final Prototype Review Reviewers' Comments 
 
Reviewer:  <ubaroudi@kfupm.edu.sa>  | Role: Only Reviewer    
  
Comments on Final Prototype Progress for Each Department  
Constraints: 1/2 is satisfied for COE  
Constraint 6 is partially satisfied  
  
Specifications: 1/2 is satisfied for COE  
Specification 10 is partially satisfied  
 Team’s Reply: I think there is a mix-up in the comments, since I have already proved all my 
constraints and specifications, and you signed them for me in the FPR. Another indication is 
that Constraint 6 and Specification 10 in our project do not belong to COE students. 
Comments on Table of Integrated Specifications for the Prototype  
Integrated Specifications: 3/5 are satisfied  
 Team’s Reply: I think there is a mix-up in the comments, we have already proved all our 
integrated specifications, and you signed them for us in the FPR. Another indication is that we 
only have 3 integrated specifications not 5. 
 
 
Reviewer:  <naveediqbal@kfupm.edu.sa>  | Role: Only Reviewer    
  
Comments on Final Prototype Progress for Each Department  
Spec 8 has steady state error of 1.48%, it should be <1%.  
Mkar sure to hava clear datasheet to show spec 9.  
  
Comments on Table of Integrated Specifications for the Prototype  
Pls mentioned that classification of gear health is not real time  
  
Reviewer:  <bqureshi@kfupm.edu.sa>  | Role: Coach and Reviewer    
  
Comments on Final Prototype Progress for Each Department  

  218  
All constraint and specifications were met.  
 Team’s reply: Thank you! 
Comments on Table of Integrated Specifications for the Prototype  
All Integrated specifications were met.  
Team’s reply: Thank you! 
  
Reviewer:  <omarjh@kfupm.edu.sa>  | Role: Only Reviewer    
  
Comments on Final Prototype Progress for Each Department  
good work all specs are met.....  
  
Comments on Table of Integrated Specifications for the Prototype  
good work all specs are met.....  
 
 
 
Reviewer:  <omarjh@kfupm.edu.sa>  | Role: Only Reviewer 
 
Comments on Final Prototype Progress for Each Department 
good work all specs are met.. 
 
TEAM reply: 
Thank you. 
Comments on Table of Integrated Specifications for the Prototype 
good work all specs are met. 
TEAM reply: 
Thank you. 
 
 

  219  
Appendix L 
Point-By-Point Reply to overall presentation Reviewers' Comments 
EE reviewer (DR. Naveed Iqbal) 
Comment 1:   
well presented and all disciplines linked clearly Team’s Reply:            
Thank you  
Comment 2:   
Well demonstrated, and EE has a clear role across various tasks  
.Team’s Reply:   
Thank you 
  
Reviewer/Coach: Dr. Bilal Qureshi  <bqureshi@kfupm.edu.sa>  | Role: Coach and 
Reviewer  | Dept: ME 
  
Comments on Pitch  
Captures audience attention, clearly defines problem & solution, generates excitement. 
Delivers in 20 seconds or less.  
  Team’s reply: Thank you! 
Comments on Background  
Thorough, well-organized background that logically and clearly leads into the needs and 
requirements; demonstrates strong understanding of the project context.  
  Team’s reply: Thank you! 
Comments on Codes and Standards  
Clear, accurate, and thorough discussion of relevant standards, codes, and their direct 
application to the design and prototype.  
  Team’s reply: Thank you! 
Comments on Bill of Materials and Budget  
Thorough, clear, and fully accurate bill of materials and budget; demonstrates careful planning 
and realistic cost estimates.  
  Team’s reply: Thank you! 
Comments on Block Diagram  

  220  
Block diagram is comprehensive, well-organized, and clearly integrates all disciplinary 
contributions effectively and cohesively.  
  Team’s reply: Thank you! 
Comments on Multidisciplinary Role  
The integrated multidisciplinary role is fully defined and consistently demonstrated across all 
integration work; exceeds requirements.  
  Team’s reply: Thank you! 
Comments on Specifications  
Exemplary: (100–102%) The prototype met all of specifications, as demonstrated by evidence 
(validation and verification). Team shows deep understanding of both successes and 
challenges.  
  
The prototype met all of specifications, as demonstrated by evidence (validation and 
verification).  
  Team’s reply: Thank you! 
Comments on Integrated Specifications  
The prototype met all of the integrated specifications, as demonstrated by evidence (validation 
and verification).  
  Team’s reply: Thank you! 
Comments on Novelty  
Not Applicable to my department.  
  Team’s reply: Thank you! 
Comments on Visual Support / Presentation Delivery  
High-quality, well-designed visuals that strongly enhance understanding and engagement; 
delivery is confident and impactful.  
 Team’s reply: Thank you! 
 
 
 
 
 
 

  221  
Reviewer/Coach: Dr. Uthman Baroudi  <ubaroudi@kfupm.edu.sa>  | Role: Only 
Reviewer  | Dept: COE  
  
Comments on Block Diagram  
Block diagram is mostly clear, well-structured, and incorporates most disciplines effectively.  
Team’s Reply:  Thank you. 
 
Comments on Multidisciplinary Role  
The integrated multidisciplinary role is clearly defined and demonstrated in the integration 
work.  
 Team’s Reply:  Thank you. 
 
Comments on Constraints  
Exemplary: (75–102%) explains 75–100% of unattained specifications. Explanations are 
generally clear, with articulated causes and reasonable plans or next steps for addressing each 
constraint.  
  
Explanations are generally clear, with articulated causes and reasonable plans or next steps for 
addressing each constraint.  
 Team’s Reply:  Thank you. 
 
Comments on Specifications  
Exemplary: (75–102%) explains 75–100% of unattained specifications. Explanations are 
generally clear, with articulated causes and reasonable plans or next steps for addressing each 
constraint.  
  
how did you assure theses issues, signal qulaity, filitering, accurate mesaurments?  
Team's Reply: Thank you, we have relied on the signal processing and filtering that our high-
end vibration sensors have, and we could achieve more than 75%  in fault classification done 
by our AI (higher than our goal in our integrated specification 1).   
 
 
 
 

  222  
 
 
Appendix Z 
• The code used to verify first specification of COE student is in this link: 
[original private demo link omitted]
p=sharing  
• The ESP32 code to verify second specification of COE student is in this link: 
[original private demo link omitted]
qD_BlCgg/view?usp=drive_link  
• The UI (python) code to verify second specification of COE student is in this link: 
[original private demo link omitted]
Dl_aZQJErqFXDdf/view?usp=sharing  
 
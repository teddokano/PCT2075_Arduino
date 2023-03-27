# TempSensor_NXP_Arduino
Temperature sensor device operation sample with Arduino
![Boards](https://github.com/teddokano/additional_files/blob/main/TempSensor_NXP_Arduino/TempSensors.jpg)  

# What is this?
A Arduino library for I²C temperature sensors with sample code.  
The I²C temperature sensors can measure temoperature and output comparator or interrupt signals by threshold settings. 

With `TempSensor_NXP_Arduino` library, the temperature measurement and showing it in Celsius can be done very simple as follwoing. 
```cpp
#include <TempSensor.h>

I2C i2c;
PCT2075 sensor(i2c);

void setup() {
  Serial.begin(115200);
  Serial.println("\r***** Hello, PCT2075! *****");
}

void loop() {
  float t = sensor.temp();

  Serial.println(t);
  delay(1000);
}
```

# Supported devices
Type#|Features|Accuracy|Resolution|Interface|Evaluation board
---|---|---|---|---|---
[LM75B](https://www.nxp.jp/products/sensors/ic-digital-temperature-sensors/digital-temperature-sensor-and-thermal-watchdog:LM75B)											|An industrial standard Digital Temperature Sensor				|±2℃		|0.125℃ (11bit)	|I²C Fast-mode (400KHz)			|---
[PCT2075](https://www.nxp.jp/products/sensors/ic-digital-temperature-sensors/ic-bus-fm-plus-1-degree-c-accuracy-digital-temperature-sensor-and-thermal-watchdog:PCT2075)	|I²C-Bus Fm+, 1 Degree C Accuracy, Digital Temperature Sensor	|±1℃		|0.125℃ (11bit)	|I²C Fast-mode Plus (1MHz)		|[PCT2075DP-ARD Arduino® Shield - Temperature Sensors](https://www.nxp.jp/design/development-boards/analog-toolbox/arduino-shields-solutions/pct2075dp-ard-arduino-shield-temperature-sensors:PCT2075DP-ARD)
[P3T1085](https://www.nxp.jp/products/sensors/ic-digital-temperature-sensors/i3c-ic-bus-0-5-c-accurate-digital-temperature-sensor:P3T1085UK)								|I3C/I²C-Bus ±0.5 °C Accurate Digital Temperature Sensor		|±0.5℃	|0.0625℃ (12bit)	|I3C / I²C Fast-mode (400KHz)	|[P3T1085UK Arduino® Shield Evaluation Board](https://www.nxp.com/design/development-boards/analog-toolbox/arduino-shields-solutions/p3t1085uk-arduino-shield-evaluation-board:P3T1085UK-ARD?_gl=1*up6muo*_ga*NTA5NDE1NDA0LjE2NzgzNDYyNzA.*_ga_WM5LE0KMSH*MTY3OTk0MzEzOS4yMS4xLjE2Nzk5NDQ1NjMuMC4wLjA.)

# Getting started

1. Get a .zip file by downloading
1. Adding the library into your Arduino IDE, follow instruction of **Importing a .zip Library** part of [Add libraries to Arduino IDE](https://support.arduino.cc/hc/en-us/articles/5145457742236-Add-libraries-to-Arduino-IDE). 
1. Try **Using installed libraries** part of [same guide page above](https://support.arduino.cc/hc/en-us/articles/5145457742236-Add-libraries-to-Arduino-IDE)

_Downloading a .zip file_  
![Download](https://github.com/teddokano/additional_files/blob/main/TempSensor_NXP_Arduino/download.png)

_Choosing an example file after library import_  
![Choosing an example](https://github.com/teddokano/additional_files/blob/main/TempSensor_NXP_Arduino/examples.png)

# References
[I²C Digital Temperature Sensors](https://www.nxp.com/products/sensors/ic-digital-temperature-sensors:MC_31128)

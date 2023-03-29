# TempSensor_NXP_Arduino
Temperature sensor device operation sample code for [Arduino](https://www.arduino.cc) 

> **Note**
This library works with [`I2C_device`](https://github.com/teddokano/I2C_device_Arduino) library together. Please be sure the `I2C_device` library is imported in your environment before trying to build. 

![Boards](https://github.com/teddokano/additional_files/blob/main/TempSensor_NXP_Arduino/TempSensors.jpg)  
_P3T1085UK-ARD and PCT2075DP-ARD : Arduino® Shield Evaluation Board for temperature sensors_

# What is this?
An Arduino library for I²C temperature sensors with sample code.  
The I²C temperature sensors can measure temoperature and output comparator or interrupt signals by threshold settings. 

With `TempSensor_NXP_Arduino` library, the temperature measurement and showing it in Celsius can be done very simple as follwoing. 
```cpp
#include <TempSensor.h>

PCT2075 sensor;

void setup() {
  Wire.begin();
  Serial.begin(9600);
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
## 3 steps to start
- **STEP 1**: Get a **.zip file** by "Download ZIP" in this page  
![Download](https://github.com/teddokano/additional_files/blob/main/TempSensor_NXP_Arduino/download.png)  

- **STEP 2**: Adding the **library into your Arduino IDE**, follow instruction of **Importing a .zip Library** part of [Add libraries to Arduino IDE](https://support.arduino.cc/hc/en-us/articles/5145457742236-Add-libraries-to-Arduino-IDE)  
![AddingZip](https://github.com/teddokano/additional_files/blob/main/TempSensor_NXP_Arduino/add_zip.png)  

- **STEP 3**: Try **Using installed libraries** part of [same guide page above](https://support.arduino.cc/hc/en-us/articles/5145457742236-Add-libraries-to-Arduino-IDE)  
![Choosing an example](https://github.com/teddokano/additional_files/blob/main/TempSensor_NXP_Arduino/examples.png)  

# What's inside?
## Temperature sensor library
`LM75B`, `PCT2075` and `P3T1085` class libraries are included. Those libraries can be used by just making an instance from those class.  
Those libraries have common methods to get/set device information.

Method|Role
---|---
temp()					|Get temperature in Celsius
thresholds( v0, v1 )	|Set high and low temperature threshold for OS output. `v0` and `v1` are needed to be given by Celsius value. Order of the arguments doesn't care
os_mode( mode )			|Set OS pin mode. It can be set comparator or interrupt mode. The argument needs to be given as a class constant like `PCT2075::COMPARATOR` or `PCT2075::INTERRUPT`. The class name can be `LM75B`, `PCT2075`, `P3T1085` or a generic name of `TempSensor`.

## Examples
Example code is provided as scketch files.  
For a quick access to those sketch, **refer to STEP 3** of **"Getting started" section** of this document. 

Sketch|Feature
---|---
PCT2075_simple							|Simple sample for just reading temperature fro PCT2075 in every second
PCT2075DP-ARD_interrupt_by_Tos_Thyst	|Demo to use interrupt. The sketch sets thresholds +2℃ and +1℃ of temperature when starting. The sketch controls **on-board heater** to keep the temperature withon those thresholds.
P3T1085_simple							|Simple sample for just reading temperature fro P3T1085 in every second (Similar to `PCT2075_simple`)
P3T1085_interrupt						|Demo for interrupt behavior. On the **P3T1085UK-ARD evaluation board**, the D8 pin is used for interrupt output but it cannot be used on most of Arduino boards. The D2 pin is used for interrupt input on this sketch. So to perform the interrupt correctly, **short D8 and D2 pins**. 

# Document
For details of the library, please find descriptions in [this document](https://teddokano.github.io/TempSensor_NXP_Arduino/annotated.html).

# References
[I²C Digital Temperature Sensors](https://www.nxp.com/products/sensors/ic-digital-temperature-sensors:MC_31128)

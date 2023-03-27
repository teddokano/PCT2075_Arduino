# TempSensor_NXP_Arduino
Temperature sensor device operation sample with Arduino

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
Type#|Features|Accuracy|Resolution|Interface
---|---|---|---|---
[LM75B](https://www.nxp.jp/products/sensors/ic-digital-temperature-sensors/digital-temperature-sensor-and-thermal-watchdog:LM75B)											|An industrial standard Digital Temperature Sensor				|±2℃		|0.125℃ (11bit)	|I²C Fast-mode (400KHz)
[PCT2075](https://www.nxp.jp/products/sensors/ic-digital-temperature-sensors/ic-bus-fm-plus-1-degree-c-accuracy-digital-temperature-sensor-and-thermal-watchdog:PCT2075)	|I2C-Bus Fm+, 1 Degree C Accuracy, Digital Temperature Sensor	|±1℃		|0.125℃ (11bit)	|I²C Fast-mode Plus (1MHz)
[P3T1085](https://www.nxp.jp/products/sensors/ic-digital-temperature-sensors/i3c-ic-bus-0-5-c-accurate-digital-temperature-sensor:P3T1085UK)								|I3C/I2C-Bus ±0.5 °C Accurate Digital Temperature Sensor		|±0.5℃	|0.0625℃ (12bit)	|I3C / I²C Fast-mode (400KHz)

<!--
# Getting started
# What is inside?
-->
# References

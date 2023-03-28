/** PCT2075 temperature sensor operation sample
 *  
 *  This sample code is showing PCT2075 temperature sensor operation with interrupt.
 *  "Tos" and "Thyst" are set to generate interrupt.   
 *
 *  @author  Tedd OKANO
 *  @version 0.2
 *  @date    29-Mar-2023
 *
 *  Released under the MIT license License
 *
 *  About PCT2075:
 *    https://www.nxp.jp/products/sensors/ic-digital-temperature-sensors/ic-bus-fm-plus-1-degree-c-accuracy-digital-temperature-sensor-and-thermal-watchdog:PCT2075
 */


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

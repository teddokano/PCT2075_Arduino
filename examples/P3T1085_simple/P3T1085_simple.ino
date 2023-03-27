/** PCT2075 temperature sensor operation sample
 *  
 *  This sample code is showing P3T1085 temperature sensor operation with interrupt.
 *  "Tos" and "Thyst" are set to generate interrupt.   
 *
 *  @author  Tedd OKANO
 *  @version 0.1
 *  @date    27-Mar-2023
 *
 *  Released under the MIT license License
 *
 *  About P3T1085:
 *    https://www.nxp.jp/products/sensors/ic-digital-temperature-sensors/i3c-ic-bus-0-5-c-accurate-digital-temperature-sensor:P3T1085UK
 */

#include <TempSensor.h>

I2C i2c;
P3T1085 sensor(i2c);

void setup() {
  Serial.begin(115200);
  Serial.println("\n***** Hello, P3T1085! *****");
}

void loop() {
  float t = sensor.temp();

  Serial.println(t);
  delay(1000);
}

/** PCT2075 temperature sensor operation sample
 *  
 *  This sample code is showing PCT2075 temperature sensor operation with interrupt.
 *  "Tos" and "Thyst" are set to generate interrupt.   
 *
 *  @author  Tedd OKANO
 *  @version 0.1
 *  @date    26-Mar-2023
 *
 *  Released under the MIT license License
 *
 *  About PCT2075:
 *    https://www.nxp.jp/products/sensors/ic-digital-temperature-sensors/ic-bus-fm-plus-1-degree-c-accuracy-digital-temperature-sensor-and-thermal-watchdog:PCT2075
 */


#include "PCT2075.h"

const uint8_t interruptPin  = 2;
const uint8_t heaterPin  = 3;
uint8_t heater  = HIGH;

I2C     i2c;
PCT2075 sensor( i2c );

void setup() {
  Serial.begin(115200);
  
  pinMode( heaterPin, OUTPUT );
  
  pinMode( interruptPin, INPUT_PULLUP );
  attachInterrupt( digitalPinToInterrupt( interruptPin ), callback, FALLING );

  float temp  = sensor.temp();

  sensor.thresholds( temp + 1, temp + 2 );
  sensor.os_mode( PCT2075::INTERRUPT );

  Serial.print( "Temperature at start: " );
  Serial.println( temp );
}

void callback() {
  heater  = ! heater;
}

void loop() {
  Serial.print( "heater: " );
  Serial.print( heater ? "ON   " : "OFF  " );

  Serial.println( sensor.temp() );
 
  digitalWrite( heaterPin, heater );
  delay(1000);
}

/** P3T1035 temperature sensor operation sample
 *  
 *  This sample code is showing P3T1755 temperature sensor operation.
 *
 *  @author  Tedd OKANO
 *
 *  Released under the MIT license License
 *
 *  About P3T1035:
 *    https://www.nxp.com/products/sensors/i3c-ic-digital-temp-sensors/i3c-ic-bus-0-5-c-accuracy-digital-temperature-sensor:P3T1035xUK
 */

#include <P3T1035.h>

P3T1035 sensors[] = {
  P3T1035( 0xE0 >> 1 );
  P3T1035( 0xE2 >> 1 );
  P3T1035( 0xE4 >> 1 );
  P3T1035( 0xE6 >> 1 );
  P3T1035( 0xE8 >> 1 );
  P3T1035( 0xEA >> 1 );
  P3T1035( 0xEC >> 1 );
  P3T1035( 0xEE >> 1 );
};

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Wire.begin();

  Serial.println("\n***** Hello, P3T1035! *****");
}

void loop() {
  for ( int i = 0; i < 8; i++ )
    zprintf( " %7.3f,", sensors[ i ].temp() );
  
    zprintf( "\n" );
  
  delay(1000);
}

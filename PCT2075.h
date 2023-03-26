/** PCT2075 temperature sensor operation library for Arduino
 *
 *  @class   PCT2075
 *  @author  Akifumi (Tedd) OKANO, NXP Semiconductors
 *  @version 0.1
 *  @date    26-Mar-2023
 *
 *  Released under the MIT license License
 *
 *  About PCT2075:
 *    https://www.nxp.jp/products/sensors/ic-digital-temperature-sensors/ic-bus-fm-plus-1-degree-c-accuracy-digital-temperature-sensor-and-thermal-watchdog:PCT2075
 */

#ifndef ARDUINO_PCT2075_H
#define ARDUINO_PCT2075_H

#include "src/lib_i2c/I2C.h"
#include "src/lib_i2c/I2C_device.h"

class PCT2075 : public I2C_device
{
public:
	/** Name of the PCT2075 registers */
	enum reg_num {
		Temp,	/**< Temp register	*/
		Conf,	/**< Conf register	*/
		Thyst,	/**< Thyst register	*/
		Tos,	/**< Tos registe	*/
		Tidle,	/**< Tidle register	*/
	};
	enum mode {
		COMPARATOR,	/**< Comparator mode	*/
		INTERRUPT,	/**< Interrupt mode	*/
	};

    /** Create a PCT2075 instance connected to specified I2C pins with specified address
     *
     * @param i2c_address I2C-bus address (default: (0x90>>1))
     */
    PCT2075( I2C &i2c_, char i2c_address = (0x90 >> 1) );

    /** Destructor of PCT2075
     */
    ~PCT2075();
	
    /** Get temperature value in degree Celsius [°C] 
     *
     * @return temperature value in degree Celsius [°C] 
     */
	float		temp( void );
	
    /** Set Overtemperature shutdown threshold (Tos) and hysteresis (Thyst) in degree Celsius [°C] 
     *
     *	This method takes 2 values and higher value will set as the threshold (Tos) and 
     *. another will be the hysteresis (Thyst)
     *
     * @param v0 a value in degree Celsius
     * @param v1 a value in degree Celsius
     */	
	void		thresholds( float v0, float v1 );

    /** Set OS operation mode 
     *
     * @param flag use PCT2075::COMPARATOR or PCT2075::INTERRUPT values
     */	
	void		os_mode( mode flag );
};

#endif //	ARDUINO_PCT2075_H

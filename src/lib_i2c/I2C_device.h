/** I2C device abstracting class
 *
 *	This class provides common methods for all I2C devices
 *
 *  @class   I2C_device
 *  @author  Tedd OKANO
 *  @version 0.1
 *  @date    26-Mar-2023
 *
 *  Released under the MIT license License
 */

#ifndef ARDUINO_I2C_DEVICE_H
#define ARDUINO_I2C_DEVICE_H

#include "I2C.h"

class I2C_device
{
public:
    /** Create a I2C_device instance with specified address
     *
	 * @param i2c_ I2C instance
	 * @param i2c_address I2C-bus address
     */
	I2C_device( I2C &i2c_, char i2c_address );

    /** Destructor of I2C_device
     */
    ~I2C_device();
	
	/** Register write, 8 bit
	 *
	 * @param reg register index/address/pointer
	 * @param val data value
	 */
	void write_r8( uint8_t reg, uint8_t val );

	/** Register write, 16 bit
	 * 
	 *	This 16 bit access may ot be common but it's useful for sensor devices
	 *
	 * @param reg register index/address/pointer
	 * @param val data value
	 */
	void write_r16( uint8_t reg, uint16_t val );

	/** Register read, 8 bit
	 *
	 * @param reg register index/address/pointer
	 * @return data value
	 */
	uint8_t read_r8( uint8_t reg );

	/** Register read, 16 bit
	 *	
	 *This 16 bit access may ot be common but it's useful for sensor devices
	 *
	 * @param reg register index/address/pointer
	 * @return data value
	 */
	uint16_t read_r16( uint8_t reg );
	
private:
	I2C     &i2c;
	char    i2c_addr;
};

#endif //	ARDUINO_I2C_DEVICE_H

/** I2C abstracting class
 *
 *	This class provides higher level transfer interface
 *
 *  @class   I2C
 *  @author  Tedd OKANO
 *  @version 0.1
 *  @date    26-Mar-2023
 *
 *  Released under the MIT license License
 */

#ifndef ARDUINO_I2C_H
#define ARDUINO_I2C_H

#include "Wire.h"

class I2C
{
public:
	/** Create an I2C instance	 */
	I2C();

	/** Destructor of I2C
	 */
	~I2C();

	/** Send data
	 * 
	 * @param addr I2C target address
	 * @param data pointer to data buffer
	 * @param size data size
	 * @return transferred data size
	 */
	uint16_t	tx( uint8_t addr, uint8_t *data, uint16_t size );

	/** Receive data
	 * 
	 * @param addr I2C target address
	 * @param data pointer to data buffer
	 * @param size data size
	 * @return transferred data size
	 */
	uint16_t	rx( uint8_t addr, uint8_t *data, uint16_t size );
	
	/** Multiple register write
	 * 
	 * @param addr I2C target address
	 * @param reg register index/address/pointer
	 * @param data pointer to data buffer
	 * @param size data size
	 * @return transferred data size
	 */
	uint8_t		reg_w( uint8_t addr, uint8_t reg_adr, uint8_t *data, uint16_t size );

	/** Single register write
	 * 
	 * @param addr I2C target address
	 * @param reg register index/address/pointer
	 * @param data pointer to data buffer
	 * @param size data size
	 * @return transferred data size
	 */
	uint8_t		reg_w( uint8_t addr, uint8_t reg_adr, uint8_t data );

	/** Multiple register read
	 * 
	 * @param addr I2C target address
	 * @param reg register index/address/pointer
	 * @param data pointer to data buffer
	 * @param size data size
	 * @return transferred data size
	 */
	uint8_t		reg_r( uint8_t addr, uint8_t reg_adr, uint8_t *data, uint16_t size );

	/** Single register read
	 * 
	 * @param addr I2C target address
	 * @param reg register index/address/pointer
	 * @return read data
	 */
	uint8_t		reg_r( uint8_t addr, uint8_t reg_adr );

private:
};

#endif //	ARDUINO_I2C_H

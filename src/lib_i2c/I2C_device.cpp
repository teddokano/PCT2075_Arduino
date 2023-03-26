#include "I2C_device.h"

I2C_device::I2C_device( I2C &i2c_, char i2c_address ) : i2c( i2c_ ), i2c_addr( i2c_address )
{
	//  do nothing.
	//  leave it in default state.
}

I2C_device::~I2C_device()
{
}

void I2C_device::write_r8( uint8_t reg, uint8_t val )
{
	i2c.reg_w( i2c_addr, reg, val );
}

void I2C_device::write_r16( uint8_t reg, uint16_t val )
{
	uint8_t	buff[ 2 ];
	
	buff[ 0 ]	= val >> 8;
	buff[ 1 ]	= val & 0xFF;
	
	i2c.reg_w( i2c_addr, reg, buff, sizeof( buff ) );
}

uint8_t I2C_device::read_r8( uint8_t reg )
{
	return i2c.reg_r( i2c_addr, reg );	
}

uint16_t I2C_device::read_r16( uint8_t reg )
{
	uint8_t	buff[ 2 ];

	i2c.reg_r( i2c_addr, reg, buff, sizeof( buff ) );
	
	return (buff[ 0 ] << 8) | buff[ 1 ];
}

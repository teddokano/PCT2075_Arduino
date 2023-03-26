#include "Arduino.h"
#include "Wire.h"
#include "I2C.h"

I2C::I2C()
{
	Wire.begin();
}

I2C::~I2C()
{
}

uint16_t I2C::tx( uint8_t addr, uint8_t *data, uint16_t size )
{
	Wire.beginTransmission( addr );
	size		= Wire.write( data, size );
	uint8_t rtn = Wire.endTransmission();

	if (rtn)
		Serial.println( "i2c_tx: ERROR" );

	return size;
}

uint16_t I2C::rx( uint8_t addr, uint8_t *data, uint16_t size )
{
	uint16_t r_size = Wire.requestFrom( addr, size );

	if (r_size != size)
		Serial.println( "i2c_rx: received size was shorter than specified" );

	for ( uint16_t i = 0; i < size; i++ ) {
		while ( !Wire.available() )
			;
		data[ i ] = Wire.read();
	}
	return r_size;
}

uint8_t I2C::reg_w( uint8_t addr, uint8_t reg_adr, uint8_t *data, uint16_t size )
{
	uint8_t buffer[ size + 1 ];
	
	buffer[ 0 ]	= reg_adr;
	for ( uint16_t i = 0; i < size; i++)
		buffer[ i + 1 ]	= data[ i ];
	
	return tx( addr, buffer, sizeof( buffer ) );
}

uint8_t I2C::reg_w( uint8_t addr, uint8_t reg_adr, uint8_t data )
{
	uint8_t buffer[ 2 ];
	
	buffer[ 0 ]	= reg_adr;
	buffer[ 1 ]	= data;
	
	return tx( addr, buffer, sizeof( buffer ) );
}

uint8_t I2C::reg_r( uint8_t addr, uint8_t reg_adr, uint8_t *data, uint16_t size )
{
	tx( addr, &reg_adr, 1 );
	return rx( addr, data, size );
}

uint8_t I2C::reg_r( uint8_t addr, uint8_t reg_adr )
{
	uint8_t	buffer;
	
	tx( addr, &reg_adr, 1 );
	rx( addr, &buffer, 1 );
	return buffer;
}

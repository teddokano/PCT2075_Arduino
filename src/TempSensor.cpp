#include "TempSensor.h"

/* TempSensor class ******************************************/

TempSensor::TempSensor( uint8_t i2c_address ) : I2C_device( i2c_address )
{
	//  do nothing.
	//  leave it in default state.
}

TempSensor::~TempSensor()
{
}

/* LM75B class ******************************************/

LM75B::LM75B( uint8_t i2c_address ) : TempSensor( i2c_address )
{
	//  do nothing.
	//  leave it in default state.
}

LM75B::~LM75B()
{
}

float LM75B::temp()
{
	return read_r16( Temp ) / 256.0;
}

void LM75B::thresholds( float v0, float v1 )
{
	float higher	= (v0 < v1) ? v1 : v0;
	float lower		= (v0 < v1) ? v0 : v1;
	
	write_r16( Tos,   ((uint16_t)(higher * 256.0)) & 0xFF80 );
	write_r16( Thyst, ((uint16_t)(lower  * 256.0)) & 0xFF80 );
}

void LM75B::os_mode( mode flag )
{
	uint8_t	v;
	
	v	 = read_r8( Conf );
	v	&= ~0x02;
	v	|= flag << 1;
	
	write_r8( Conf, v );
}


/* PCT2075 class ******************************************/
PCT2075::PCT2075( uint8_t i2c_address ) : LM75B( i2c_address )
{
	//  do nothing.
	//  leave it in default state.
}

PCT2075::~PCT2075()
{
}

/* P3T1085 class ******************************************/

P3T1085::P3T1085( uint8_t i2c_address ) : LM75B( i2c_address )
{
	//  do nothing.
	//  leave it in default state.
}

P3T1085::~P3T1085()
{
}

void P3T1085::thresholds( float v0, float v1 )
{
	float higher	= (v0 < v1) ? v1 : v0;
	float lower		= (v0 < v1) ? v0 : v1;
	
	write_r16( T_HIGH, ((uint16_t)(higher * 256.0)) & 0xFFF0 );
	write_r16( T_LOW,  ((uint16_t)(lower  * 256.0)) & 0xFFF0 );

	Serial.println( read_r16( T_HIGH ) / 256.0 );
	Serial.println( read_r16( T_LOW  ) / 256.0 );
}

void P3T1085::os_mode( mode flag )
{
	uint16_t	v;
	
	v	 = read_r16( Conf );
	v	&= ~0x0400;
	v	|= flag << 10;
	
	write_r16( Conf, v );
}

bool P3T1085::clear( void )
{
	return (read_r16( Conf ) & 0x1000) ? true : false;
}


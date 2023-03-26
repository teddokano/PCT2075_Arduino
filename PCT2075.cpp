#include "PCT2075.h"

PCT2075::PCT2075( I2C &i2c_, char i2c_address ) : I2C_device( i2c_, i2c_address )
{
	//  do nothing.
	//  leave it in default state.
}

PCT2075::~PCT2075()
{
}

float PCT2075::temp()
{
	return read_r16( Temp ) / 256.0;
}

void PCT2075::thresholds( float v0, float v1 )
{
	float higher	= (v0 < v1) ? v1 : v0;
	float lower		= (v0 < v1) ? v0 : v1;
	
	write_r16( Tos,   ((uint16_t)(higher * 256.0)) & 0xFF80 );
	write_r16( Thyst, ((uint16_t)(lower  * 256.0)) & 0xFF80 );
}

void PCT2075::os_mode( mode flag )
{
	uint16_t	v;
	
	v	 = read_r8( Conf );
	v	&= ~0x02;
	v	|= flag << 1;
	
	write_r8( Conf, v );
}

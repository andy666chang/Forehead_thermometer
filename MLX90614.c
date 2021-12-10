

#include "MLX90614.h"

uint8_t buffer[42] = {0} ;


void MLX90614_Write_Byte( uint8_t data_addr , uint8_t data )
{
	I2C_Write_Byte( MLX90614_I2CADDR , data_addr , data ) ;
}

uint8_t MLX90614_Read_Byte( uint8_t data_addr )
{
	return I2C_Read_Byte( MLX90614_I2CADDR , data_addr ) ;
}

void MLX90614_Write_Bytes( uint8_t data_addr , uint8_t data[] , uint16_t len )
{
	I2C_Write_Bytes( MLX90614_I2CADDR , data_addr , data , len ) ;
}

void MLX90614_Read_Bytes( uint8_t data_addr , uint8_t data[] , uint16_t len )
{
	I2C_Read_Bytes( MLX90614_I2CADDR , data_addr , data , len ) ;
}

uint16_t read2Byte(uint8_t a) 
{
	uint8_t data[3] = {0} ;	
	uint16_t ret;

	MLX90614_Read_Bytes( a , data , 3 );

	ret = (uint16_t)data[1]<<8 | data[0] ;

	return ret;
}

float readTemp(uint8_t reg) {
	float temp;

	temp = read2Byte(reg);
//	temp *= .02;
//	temp  -= 273.15;
    temp = (int)temp*2 - 27315 ;// XX.XX
	return temp;
}



float MLX90614_readObjectTempC(void)
{
	return readTemp(MLX90614_TOBJ1);
}
float MLX90614_readAmbientTempC(void)
{
	return readTemp(MLX90614_TA);
}

float MLX90614_readObjectTempF(void)
{
	return (readTemp(MLX90614_TOBJ1) * 9 / 5) + 32;
}
float MLX90614_readAmbientTempF(void)
{
	return (readTemp(MLX90614_TA) * 9 / 5) + 32;
}
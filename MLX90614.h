

#ifndef _MLX90614_H
#define _MLX90614_H

#define  TRUE 1
#define FALSE 0

#define  ON 1
#define OFF 0

#define MLX90614_I2CADDR 0x5A

// RAM
#define MLX90614_RAWIR1 0x04
#define MLX90614_RAWIR2 0x05
#define MLX90614_TA 0x06
#define MLX90614_TOBJ1 0x07
#define MLX90614_TOBJ2 0x08
// EEPROM
#define MLX90614_TOMAX 0x20
#define MLX90614_TOMIN 0x21
#define MLX90614_PWMCTRL 0x22
#define MLX90614_TARANGE 0x23
#define MLX90614_EMISS 0x24
#define MLX90614_CONFIG 0x25
#define MLX90614_ADDR 0x0E
#define MLX90614_ID1 0x3C
#define MLX90614_ID2 0x3D
#define MLX90614_ID3 0x3E
#define MLX90614_ID4 0x3F


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "I2C.h"


void MLX90614_Write_Byte( uint8_t data_addr , uint8_t data );
uint8_t MLX90614_Read_Byte( uint8_t data_addr );
void MLX90614_Write_Bytes( uint8_t data_addr , uint8_t data[] , uint16_t len );
void MLX90614_Read_Bytes( uint8_t data_addr , uint8_t data[] , uint16_t len );


float MLX90614_readObjectTempC(void);
float MLX90614_readAmbientTempC(void);

float MLX90614_readObjectTempF(void);
float MLX90614_readAmbientTempF(void);

#endif

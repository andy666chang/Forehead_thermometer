
#ifndef _I2C_h
#define _I2C_h

#define  ACK 1
#define NACK 0

#include "mcc_generated_files/mcc.h"
#include <stdlib.h>
#include <string.h>

void I2C_Write_Byte( uint8_t Slave_addr , uint8_t Data_addr , uint8_t data) ;
uint8_t I2C_Read_Byte( uint8_t Slave_addr , uint8_t Data_addr ) ;
void I2C_Write_Bytes( uint8_t Slave_addr , uint8_t Data_addr , uint8_t data[] , uint16_t n) ;
void I2C_Read_Bytes( uint8_t Slave_addr , uint8_t Data_addr , uint8_t data[] , uint16_t n) ;


void I2C_Start( void );
void I2C_ReStart( void ) ;
void I2C_Write( uint8_t data );
uint8_t I2C_Read( bool keep );
void I2C_Stop ( void );


#endif
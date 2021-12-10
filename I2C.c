
#include "I2C.h"


#define WAIT_IRQ_FINISH		while ( !mssp1_IRQisSet() );	\
							mssp1_clearIRQ()



void I2C_Write_Byte( uint8_t Slave_addr , uint8_t Data_addr , uint8_t data) {

	// start I2c
	I2C_Start() ;

	// send slave address & W/R
    I2C_Write(  (Slave_addr << 1) | 0  ) ;

    // send Data address
    I2C_Write( Data_addr );
    // send data
    I2C_Write( data );

    // stop I2C
    I2C_Stop () ;
}

uint8_t I2C_Read_Byte( uint8_t Slave_addr , uint8_t Data_addr ) {
	uint8_t temp = 0 ;
    
	// start I2c
	I2C_Start() ;
	// send slave address & W/R
    I2C_Write(  (Slave_addr << 1) | 0  ) ;

    // send Data address
    I2C_Write( Data_addr );
    
    // restart I2c
    I2C_ReStart() ;

    // send slave address & W/R
    I2C_Write(  (Slave_addr << 1) | 1  ) ;

    // read data
    temp = I2C_Read ( NACK ) ;
    
    // stop I2C
    I2C_Stop () ;
    
    return temp ;
}

void I2C_Write_Bytes( uint8_t Slave_addr , uint8_t Data_addr , uint8_t data[] , uint16_t n) {

	// start I2c
	I2C_Start() ;

	// send slave address & W/R
    I2C_Write(  (Slave_addr << 1) | 0  ) ;

    // send Data address
    I2C_Write( Data_addr );
    // send data
    for ( uint16_t i = 0 ; i < n ; i++ )
    	I2C_Write( data[i] );

    // stop I2C
    I2C_Stop () ;

}

void I2C_Read_Bytes( uint8_t Slave_addr , uint8_t Data_addr , uint8_t data[] , uint16_t n) {

	// start I2c
	I2C_Start() ;
	// send slave address & W/R
    I2C_Write(  (Slave_addr << 1) | 0  ) ;

    // send Data address
    I2C_Write( Data_addr );
    
    // restart I2c
    I2C_ReStart() ;

    // send slave address & W/R
    I2C_Write(  (Slave_addr << 1) | 1  ) ;
    
    // read data
    for( uint16_t i = 0 ; i < n-1 ; i++ )
    	data[i] = I2C_Read ( ACK ) ;

    data[n-1] = I2C_Read ( NACK ) ;

    // stop I2C
    I2C_Stop () ;
    
}


////////////////////////////////////////////////////////////////////////////////////

void I2C_Start( void ) {
	i2c1_driver_start();
	while ( !i2c1_driver_isStart() );
    WAIT_IRQ_FINISH ;
}

void I2C_ReStart( void ) {
	i2c1_driver_restart() ;
    WAIT_IRQ_FINISH ;
}

void I2C_Write( uint8_t data ) {
	i2c1_driver_TXData( data );
    WAIT_IRQ_FINISH ;
}

uint8_t I2C_Read( bool keep ) {
	uint8_t temp = 0 ;

	i2c1_driver_startRX() ;
	while ( !mssp1_IRQisSet() || !i2c1_driver_isBufferFull() ) ;
	mssp1_clearIRQ();

	temp = i2c1_driver_getRXData() ;

	// send ACK / NACK
	( keep ) ?  i2c1_driver_sendACK() : i2c1_driver_sendNACK() ;
    WAIT_IRQ_FINISH ;

	return temp ;
}

void I2C_Stop ( void ) {
	// stop I2C
	i2c1_driver_stop();
    WAIT_IRQ_FINISH ;
}

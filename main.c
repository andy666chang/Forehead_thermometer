/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F18313
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

#include "I2C.h"
#include "SSD1306.h"
#include "MLX90614.h"
//#include "glcd_library_1_0.h"
/*
                         Main application
 */

void INT_EVENT(void);

void main(void)
{
    int temperature = 0 ;
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    INT_SetInterruptHandler( INT_EVENT );
    
    i2c1_driver_open();
    
    __delay_ms( 1000 ) ;
    
    OLED_initial();
    OLED_clear();
    OLED_display(1);

    while (1)
    {
        // Add your application code
//        OLED_display(1);
        temperature = MLX90614_readObjectTempC();
        uint8_t x = 25 , y = 3 ;
        
//        OLED_setXY(x,y);
//        OLED_write_num( temperature/1000 );
//        
//        x += 11 ;
//        OLED_setXY(x,y);
//        OLED_write_num( temperature/100%10 );
//        OLED_write_num( 12 );
//        OLED_write_num( temperature/10%10 );
//        OLED_write_num( temperature%10 );
//        OLED_write_num_16( 10 , 64 , 3 );
        
        OLED_write_num_16( temperature/1000%10 , x , y );
        x += 15 ;
        OLED_write_num_16( temperature/100%10 , x , y );
        x += 15 ;
        OLED_setXY( x , y+1 );
        OLED_write_num( 0 );
        x += 8 ;
        OLED_write_num_16( temperature/10%10 , x , y );
        x += 15 ;
        OLED_write_num_16( temperature%10 , x , y );
        x += 15 ;
        OLED_setXY( x , y );
        OLED_write_num( 1 );
        x += 8 ;
        OLED_write_num_16( 10 , x , y );
//        temperature ++ ;
        
        __delay_ms(2000);
//        OLED_display(0);
//        SLEEP();
    }
}

void INT_EVENT(void)
{
    
}

/**
 End of File
*/
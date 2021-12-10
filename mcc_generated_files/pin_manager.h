/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F18313
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SDA1 aliases
#define SDA1_TRIS                 TRISAbits.TRISA0
#define SDA1_LAT                  LATAbits.LATA0
#define SDA1_PORT                 PORTAbits.RA0
#define SDA1_WPU                  WPUAbits.WPUA0
#define SDA1_OD                   ODCONAbits.ODCA0
#define SDA1_ANS                  ANSELAbits.ANSA0
#define SDA1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SDA1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SDA1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SDA1_GetValue()           PORTAbits.RA0
#define SDA1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define SDA1_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define SDA1_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set SCL1 aliases
#define SCL1_TRIS                 TRISAbits.TRISA1
#define SCL1_LAT                  LATAbits.LATA1
#define SCL1_PORT                 PORTAbits.RA1
#define SCL1_WPU                  WPUAbits.WPUA1
#define SCL1_OD                   ODCONAbits.ODCA1
#define SCL1_ANS                  ANSELAbits.ANSA1
#define SCL1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define SCL1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define SCL1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define SCL1_GetValue()           PORTAbits.RA1
#define SCL1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define SCL1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define SCL1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/
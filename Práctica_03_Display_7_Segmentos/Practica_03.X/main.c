/*
 * File:   main.c
 * Author: Pedro Fernando Flores Palmeros
 * Objective: Generate a binary addition and subtraction
 * Created on January 24, 2024, 6:28 PM
 */

#include <xc.h>
#include "config.h"

#define _XTAL_FREQ   20000000 // Crystal of 20 MHz

/*
 *  REPASO
 *  LAT -> escribe en el puerto o en el pin
 *  TRIS -> declara si es entrada o salida
 *  PORT -> lectura del puerto
 * 
 * 
 */

#define time_blink  10
int value = 0;

                     // 0  1   2   3   4    5    6   7    8    9   A    b    C   d    e   F
                     // 0  1   2   3   4    5    6   7    8    9   10   11   12  13  14   15
int display_array[] = {63, 6, 91, 79, 102, 109, 124, 71, 127, 103, 119, 124, 57, 94, 121, 113};



void main(void) {
    
    int units = 0;
    int tens = 0;
    ADCON1 = 0B00001111;
        
    TRISD = 0;  // Todo el puerto D se configura como salida 
    
    TRISEbits.RE0 = 0;
    TRISEbits.RE1 = 0;
    
    
    for(tens = 0; tens <= 9; tens++){
        
        for(units = 0; units <=9; units++){
            LATD = display_array[units];
            LATEbits.LATE0 = 1;
            LATEbits.LATE1 = 0;
            
            __delay_ms(time_blink);
            LATD = display_array[tens];
            LATEbits.LATE0 = 0;
            LATEbits.LATE1 = 1;
            __delay_ms(time_blink);
        }
    }
  
    return;
}

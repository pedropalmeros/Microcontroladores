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
 */

                     // 0  1   2   3   4    5    6   7    8    9   A    b    C   d    e   F
                     // 0  1   2   3   4    5    6   7    8    9   10   11   12  13  14   15
int display_array[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103, 119, 124, 57, 94, 121, 113};
void main(void) {
       
    ADCON1 = 0B00001111;
        
    TRISD = 0;  // Todo el puerto D se configura como salida 
    TRISEbits.RE0 = 0; // RE0 como salida
    TRISEbits.RE1 = 0; // RE1 como salida
   
    for(int i = 0; i <= 15; i++){
        LATD = display_array[i];
        if (i%2 == 0){
            LATEbits.LE0 = 0;
            LATEbits.LE1 = 1;
        }else{
            LATEbits.LE0 = 1;
            LATEbits.LE1 = 0;
        }
        
        
        __delay_ms(500);
    }
  
    return;
}

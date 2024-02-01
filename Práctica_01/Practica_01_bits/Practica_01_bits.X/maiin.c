/*
 * File:   maiin.c
 * Author: Pedro Fernando Flores Palmeros
 *
 * Created on January 24, 2024, 6:12 PM
 */


#include <xc.h>
#include "config.h"

#define _XTAL_FREQ 20000000 // Definimos la frecuencia de 20 Mhz

void main(void) {
    ADCON1 = 0x0F;
    
    TRISAbits.RA0 = 0; // 0 -> OUTPUT // 1 -> INPUT
    
    while(1){
        LATAbits.LA0 = 1; 
        __delay_ms(1000);
        LATAbits.LA0 = 0;
        __delay_ms(1000);
    }
    
    
    
    return;
}

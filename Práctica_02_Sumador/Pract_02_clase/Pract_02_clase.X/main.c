/*
 * File:   main.c
 * Author: pedro
 *
 * Created on January 25, 2024, 8:07 AM
 */


#include <xc.h>
#include "config.h"

#define _XTAL_FREQ 20000000 // Frecuencia del cristal de 20 MHz

#define btnSum  PORTAbits.RA0 // 

int sumValue = 0;


void main(void) {
    ADCON1 = 0X0F; // CONFIGURA EL MICRO A DIGITAL
    TRISB = 0; // TODO el puerto B es salida TODO
    TRISAbits.RA0 = 1;  // Bit RA0 se configura como entrada.
    
    
    while(1){
        if(btnSum == 1){
            sumValue += 1; // sumValue = sumValue + 1
            while(btnSum == 1);
        }
        
        LATB = sumValue; // MANDA el valor de sumValue a la salida del micro
        
    }
    
    
    
    
    
    
    
    return;
}

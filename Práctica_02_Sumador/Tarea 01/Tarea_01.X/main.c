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

#define btnSum PORTAbits.RA0   //bit de suma
#define btnRes PORTAbits.RA1   //bit de resta
#define btnReset PORTAbits.RA2  //bit de reseteo

int count = 0;

void main(void) {
    ADCON1 = 0B00001111;
    
    TRISAbits.RA0 = 1; // RA0 se configura como entrada
    TRISAbits.RA1 = 1; // RA1 se configura como entrada
    TRISAbits.RA2 = 1; // RA2 se configura como entrada
    
    TRISD = 0;  // Todo el puerto B se configura como salida 
    
    while(1){
        if(btnSum == 1){
            count+=1;  // count = count + 1            
            __delay_ms(100); // rutina anti rebote 
            while(btnSum == 1); // rutina ante rebote 
        }
        
        if(btnRes == 1){
            count -= 1;   // count = count - 1
            while(btnRes == 1);
        }
        
        if(btnReset == 1){
            count = 0;
            while(btnReset == 0);
        }
        
        if(count > 255){
            count = 0;
        }
        
        if( count < 0){
            count = 255;
        }
        
        LATD = count;
        __delay_ms(100);
    }
    
    
    
    
    return;
}

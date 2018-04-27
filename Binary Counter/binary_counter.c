#include <p18F252.h>

void delay(void){
	// set the Timer2 to produce a certain delay
	// by loading T2CON and PR2 registers
	
	T2CON = 0x49;
	PR2 = 0x7c;
	
	T2CONbits.TMR2ON = 1;			// START Timer2
	
	while(!PIR1bits.TMR2IF);		// wait for the timer flag
		T2CONbits.TMR2ON	= 0;	// STOP the TIMER2
		PIR1bits.TMR2IF		= 0;	// clear the timer flag
}
	
void main(void){
	TRISB = 0x00; 				// Configure portb as output
	while(1){
//0
		PORTBbits.RB0 = 0;
		PORTBbits.RB1 = 0;
		delay();
//1
		PORTBbits.RB0 = 1;
		delay();
//2
		PORTBbits.RB0 = 0;
		PORTBbits.RB1 = 1;
		delay();
//3
		PORTBbits.RB0 = 1;
		PORTBbits.RB1 = 1;
		delay();
//4
		PORTBbits.RB2 = 1;
		PORTBbits.RB1 = 0;
		PORTBbits.RB0 = 0;
		delay();
//5
		PORTBbits.RB0 = 1;
		delay()
		
//6
		PORTBbits.RB0 = 0;
		PORTBbits.RB1 = 1;
delay();
	}
}

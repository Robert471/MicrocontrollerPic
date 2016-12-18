#include "servomotor.h"

unsigned int16 i = 0;
unsigned int16 angle = 300;

#INT_TIMER2
void TMR2_isr( ){
   // 300 - 2100
   output_high(PIN_CTRL);
   angle  = 300 + i*100;
   delay_us( angle );
   output_low(PIN_CTRL);
}

void init_servomotor(){
   set_tris_c(0b10000000);
   setup_timer_2( PRESCALER, PR2 , POSTSCALER );
   enable_interrupts( INT_TIMER2 ); 
   enable_interrupts(GLOBAL);
}

/*

*GENERAR 100ms 

TEMPORIZACION = 4*TOSC *VALORTIMER1*PRESCALER

TEMPORIZACION = 4*(1/FOSC)*VALORTIMER1*PRESCALER
TEMPORIZACION = (1us)*VALORTIMER1*PRESCALER

100ms = (1us)*VALORTIMER0*PRESCALER

VALORTIMER1*PRESCALER = 100000

PRESCALER = 8

VALORTIMER1 = 12500  

65536 - N = 12500

N = 53036

*/

#INCLUDE <16F877A.h>
#FUSES XT
#USE DELAY( CLOCK = 4M)
#DEFINE CARGA_TIMER1 53036 
#INCLUDE <lcd.c>

int i = 0;
int ss = 0,mm = 0, hh = 0;

//100ms
#INT_TIMER1
void TMR1_isr( ){
   output_toggle(PIN_B0);
   i++;
   if( i>= 10){
      i = 0;
      ss++;
      if(ss>=60){       ss = 0;mm++;
         if(mm>=60){    mm = 0;hh++;
            if(hh>=24){ hh = 0;
            }
         }
      }
      lcd_putc('\f');
      printf(lcd_putc,"hh:%u-mm:%u-ss:%u",hh,mm,ss);
   }

   set_timer1( CARGA_TIMER1 );
}
void main ( ){   
   
   setup_timer_1( T1_INTERNAL|T1_DIV_BY_8 );
   set_timer1( CARGA_TIMER1 );
   enable_interrupts( INT_TIMER1 ); 
   enable_interrupts(GLOBAL);
   set_tris_b(0);
   lcd_init();
   while (TRUE){
   }
}





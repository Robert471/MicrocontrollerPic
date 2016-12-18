#include <16f877a.h>
#fuses   XT
#use     delay(clock=4M)
#include <lcd.c>
int a = 0;
#INT_EXT 
void EXT_isr(){
   a = 1; 
}
void main(){
   unsigned int16  i = 0;
   lcd_init();
   ext_int_edge(L_TO_H);
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
   for(;;){
      for(i = 0; i <= 100; i++){
         printf(lcd_putc,"\fConteo:%Lu",i);
         delay_ms(500);
         if(a == 1){
            printf(lcd_putc,"\fInterrupcion");
            delay_ms(100);
            a = 0;
         }
      }
   }
}



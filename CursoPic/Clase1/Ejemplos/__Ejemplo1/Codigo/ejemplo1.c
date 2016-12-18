#include <16f877a.h>    
#use delay(clock=4Mhz) 

void main(void){        

   set_tris_b(0x00);    
   output_b(0);         
    
   for(;;){
      output_high(PIN_B7); 
      delay_ms(500);       
      output_low(PIN_B7); 
   }
}








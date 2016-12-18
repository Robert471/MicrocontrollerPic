#include <16f877a.h> 
#fuses XT
#use delay(clock=4Mhz) 

void main(void){

   set_tris_b(0b00000001); 

   for(;;){
      if(input(PIN_B0)==1){      
         output_high( PIN_B7 );   
      }else{
         output_low( PIN_B7 );  
      }
   }
}









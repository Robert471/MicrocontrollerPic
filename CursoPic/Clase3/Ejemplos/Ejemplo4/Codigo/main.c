#include <16f877a.h>
#fuses   xt
#use     delay(clock=4M)
#include "servomotor.c"


void main ( ){  
   init_servomotor();

   for(;;){
      for(i=0;i<=17;i++){
         delay_ms(500);
      }
   }
}



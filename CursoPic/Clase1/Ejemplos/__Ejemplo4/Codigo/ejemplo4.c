#include <16f877a.h> 
#fuses XT
#use delay(clock=4Mhz) 

void main(void){ 
   int valores[10]={ 0x03F,0x06,0x5B,0x4F,0x66,
                     0x6D,0x7D,0x47,0x7F,0x67   };
   int i=0;        
   int bucle=0;
   set_tris_b(0x00);
   set_tris_d(0xFF); 
   output_b(0);      
    
   for(;;){
      if( input(PIN_D0) == 1 ){ bucle = 1; }  
      if( bucle == 1 ){
         for( i=0; i < 10; i++){
            output_b( valores[i] ); delay_ms( 300 );
            if( input(PIN_D0) == 1 ){      
               delay_ms(300);
               bucle = 0; 
               break;  
            }
         }
      }
   }
}









#include <16f877a.h>
#fuses   xt
#use     delay(clock=4M)
#use rs232(BAUD=9600,XMIT=PIN_C6,RCV=PIN_C7)
#include "ultrasonico.c"

void main(){

   unsigned int16 tiempo = 0;
   float distancia;
   
   init_ultrasonico();
   
   for(;;){
      tiempo = read_time_ultrasonico();
      distancia = calcular_distancia(tiempo);
      printf("tiempo = %Lu - distancia: %f\n",tiempo,distancia);
      delay_ms(300);    
   }
}





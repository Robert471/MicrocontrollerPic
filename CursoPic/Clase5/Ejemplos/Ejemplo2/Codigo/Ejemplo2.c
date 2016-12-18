#include <16f877a.h>
#device  adc=10
#fuses   XT
#use     delay(clock=4M)
#use     rs232(BAUD = 9600,XMIT = PIN_C6, RCV = PIN_C7)   

void main(){
   int16 adc1,adc2;
   
   setup_adc(  ADC_CLOCK_INTERNAL );
   setup_adc_ports(  AN0_AN1_AN3  );   

   for(;;){
      set_adc_channel( 0 );
      delay_us(20);
      adc1 = read_adc();  
      
      set_adc_channel( 1 );
      delay_us(20);
      adc2 = read_adc(); 
      
      printf("x:%Lu - y:%Lu \r\n",adc1,adc2);

   }
}



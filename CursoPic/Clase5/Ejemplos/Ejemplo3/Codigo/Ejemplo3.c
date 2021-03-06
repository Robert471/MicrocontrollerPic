#include <16f877a.h>
#fuses   XT
#use     delay(clock=4M)
#use     rs232(BAUD = 9600,XMIT = PIN_C6, RCV = PIN_C7)   
#define  MOTOR1A  PIN_C0
#define  MOTOR1B  PIN_C1
#define  MOTOR2A  PIN_C2
#define  MOTOR2B  PIN_C3

char data;
#INT_RDA
void RDA_isr(){
   data = getc();      
}

void main(){

   set_tris_c(0b1000000);
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
   
   output_low(MOTOR1A); output_low(MOTOR1B);
   output_low(MOTOR2A); output_low(MOTOR2B);

   for(;;){
      if ( data == 'A'){   printf("Adelante\r\n");
         output_high(MOTOR1A); output_low(MOTOR1B);
         output_high(MOTOR2A); output_low(MOTOR2B);
         delay_ms(300);
      }
      if ( data == 'B'){   printf("ATRAS\r\n");
         output_low(MOTOR1A); output_high(MOTOR1B);
         output_low(MOTOR2A); output_high(MOTOR2B);
         delay_ms(300);
      }
      if ( data == 'c'){   printf("DERECHA\r\n");
         output_low(MOTOR1A); output_low(MOTOR1B);
         output_high(MOTOR2A); output_low(MOTOR2B);
         delay_ms(100);
         output_high(MOTOR1A); output_low(MOTOR1B);
         output_high(MOTOR2A); output_low(MOTOR2B);
      }
      if ( data == 'D'){   printf("IZQUIERDA\r\n");
         output_high(MOTOR1A); output_low(MOTOR1B);
         output_low(MOTOR2A); output_low(MOTOR2B);
         delay_ms(100);
         output_high(MOTOR1A); output_low(MOTOR1B);
         output_high(MOTOR2A); output_low(MOTOR2B);
      }    
      if ( data == 'E'){  printf("APAGAR\r\n");
         output_low(MOTOR1A); output_low(MOTOR1B);
         output_low(MOTOR2A); output_low(MOTOR2B);
      }
   }
}



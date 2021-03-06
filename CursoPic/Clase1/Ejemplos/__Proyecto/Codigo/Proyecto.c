#include <18F4550.h>       // PIC DE GAMA ALTA 
#fuses   HS,CPUDIV1        // FUSES PARA EL PIC
#use delay(clock=20Mhz)    // FRECUENCIA DE TRABAJO PARA EL PIC
#define CLOCK     PIN_B0
#define DATA      PIN_B1
#define MOSTRAR   PIN_B2
                       
void main(void){
   /*
      data    14:       envio datos de manera serial
      shift clock 11:   desplaza los datos
      latch clock 12:   escribe datos
   */


   int i=0,x=0;   // variables de conteo
   
   /* se le envia a las filas */
   int datos[8]={ // defino datos a mostrar en la matriz de led
                0b11111111,0b11111111,0b00110011,0b00110011,
                0b01001111,0b10001111,0b11000111,0b00000000
                };
   /* se le envia a las columnas */             
   int col[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
   /* inicializado los puertos del PIC*/
   set_tris_d(0); // CONFIGURO EL PUERTO D COMO SALIDA
   output_d(0);   // LIMPIO EL PUERTOD
   set_tris_b(0); // CONFIGURO EL PUERTO B COMO SALIDA
   output_b(0);   // LIMPIO EL PUERTOB
   
   for(;;){
      
      for(x=0;x<8;x++){    // para enviar los datos definidos en el arreglo
         output_d(col[x]); // HABILITA LAS COLUMNAS     
         for(i=0;i<8;i++){
            if(bit_test(~datos[x],7-i)==1){
               output_high(DATA);   //
            }else{
               output_low(DATA);
            }
            /* GRABAR EL BIT ENVIADO EN EL REGISTRO*/
            output_high(CLOCK);
            delay_us(10);
            output_low(CLOCK);      
         }
         output_high(MOSTRAR);
         delay_ms(5);
         output_low(MOSTRAR);
      }
   }  
}



#include <16f877a.h>
#use delay(clock=4M) 
#fuses XT 
#include <lcd.c>     
           
void main(void){

   lcd_init();    
   printf(lcd_putc,"Hola LaboTEC");
   for(;;){ 

   }
}




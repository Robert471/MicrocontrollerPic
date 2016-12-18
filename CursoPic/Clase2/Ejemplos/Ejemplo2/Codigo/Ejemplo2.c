#include <16f877a.h>
#use delay(clock=4M) 
#fuses XT 
#include <lcd.c>     
           
void main(void){
   
   long i=0;    
   lcd_init(); 
   for(;;){   
      for(i=0;i<=100;i++){   
         lcd_putc('\f');
         printf(lcd_putc,"Ejemplo2"); 
         lcd_gotoxy(1,2);  
         printf(lcd_putc,"conteo: %lu",i);
         delay_ms(50);      
      }
   }
}



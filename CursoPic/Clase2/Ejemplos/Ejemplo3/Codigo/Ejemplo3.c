#include <16f877a.h> 
#use delay(clock=4M)
#fuses XT 
#include <lcd.c>    
           
void main(void){
   
   int x=0,y=0;   
   lcd_init();
   while(1){   
      for(y=1;y<=2;y++){
         for(x=1;x<=16;x++){
            lcd_putc('\f');
            lcd_gotoxy(x,y);
            printf(lcd_putc,"LaboTEC");
            delay_ms(300);      
         }
      }
   }
}




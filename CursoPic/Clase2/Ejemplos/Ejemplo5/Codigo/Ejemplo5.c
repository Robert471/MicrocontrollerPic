#include <16f877a.h> 
#use delay(clock=4M) 
#fuses XT 
#include <lcd.c>    
#include "keypad.c" 

void main(void){  
   char c;     
   lcd_init(); 
   kbd_init(); 
   port_b_pullups(True);  
   lcd_gotoxy(1,1);
   printf(lcd_putc,"Presionar");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"Una tecla");  
   for(;;){         
      c=kbd_getc();  
      if(c != 0){
         lcd_putc('\f');
         printf(lcd_putc,"letra: %c",c);        
      }
   }
}




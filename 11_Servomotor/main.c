#include <16f877a.h>
#fuses XT
#use delay(clock=4M)
#define LCD_DATA_PORT getenv("SFR:PORTD")
#define LCD_ENABLE_PIN  PIN_A3                                  
#define LCD_RS_PIN      PIN_A5                                  
#define LCD_RW_PIN      PIN_A2                                   
#define LCD_DATA4       PIN_D4
#define LCD_DATA5       PIN_D5                                   
#define LCD_DATA6       PIN_D6                                    
#define LCD_DATA7       PIN_D7 
#include <lcd.c>
#include "..\_Library\keypad.c"
#include "..\_Library\servomotor.c"

void main(){
   char data;
   servomotor_init();
   kbd_init();
   lcd_init();
   printf(lcd_putc,"LaboTEC");
   for(;;){
      data = kbd_getc();
      if(data!=0){
         if(data == 'A'){
            i++;
            lcd_putc('\f');
            printf(lcd_putc,"Pulse(us)=%Lu",angle);
         }
         if(data == 'B'){
            i--;
            lcd_putc('\f');
            printf(lcd_putc,"Pulse(us)=%Lu",angle);
         }
      }
   }
}

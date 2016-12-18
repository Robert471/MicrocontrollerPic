#include <16f877a.h>
#fuses   XT
#use     delay(clock=4M)
#define LCD_DATA_PORT getenv("SFR:PORTD")
#define LCD_ENABLE_PIN  PIN_A3                                  
#define LCD_RS_PIN      PIN_A5                                  
#define LCD_RW_PIN      PIN_A2                                   
#define LCD_DATA4       PIN_D4
#define LCD_DATA5       PIN_D5                                   
#define LCD_DATA6       PIN_D6                                    
#define LCD_DATA7       PIN_D7 
#include <lcd.c>
#include "keypad.c"
#include "pwm.c"

#define  MOTOR1A  PIN_C0
#define  MOTOR1B  PIN_C1

void main(){
   char tecla;
   
   int duty = 125;
   pwm_init(); // PWM OUTPUT PIN_C2
   lcd_init();
   kbd_init();
   port_b_pullups(true);
   
   set_tris_c(0b10000000);
   
   for(;;){
      tecla = kbd_getc(); 
      if(tecla != 0){
         if(tecla == 'A'){
            lcd_gotoxy(1,1);
            printf(lcd_putc,"GiroDerecho");
            output_high( MOTOR1A ); output_low( MOTOR1B );   
         }
         if(tecla == 'B'){
            lcd_gotoxy(1,1);
            printf(lcd_putc,"GiroDerecho");
            output_low( MOTOR1A ); output_high( MOTOR1B );     
         }
         if(tecla == 'C'){
            duty++;
            SetPWM1( duty ); 
            lcd_gotoxy(1,2);
            printf(lcd_putc,"duty:%u",duty);        
         }
         if(tecla == 'D'){
            duty--;
            SetPWM1( duty );
            lcd_gotoxy(1,2);
            printf(lcd_putc,"duty:%u",duty);  
         }
      }
   }
}



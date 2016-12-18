#include <16f877a.h>
#device adc=10
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
#include "servomotor.c"

unsigned int16 ServoWriteAdc_To_Angle(unsigned int16 x){
   unsigned int16 out;
   out = (x - 0.0) * (180.0 - 0.0) / (1023.0 - 0.0) + 0.0;
   
   return out;
}

void main(){
   int16 adc1;
   float sens;
   unsigned int16 i;
   
   setup_adc(  ADC_CLOCK_INTERNAL );
   setup_adc_ports(  AN0 );   
   lcd_init();
   servomotor_init();
   
   for(;;){
      set_adc_channel( 0 );
      delay_us(20);
      adc1 = read_adc();  
      i = ServoWriteAdc_To_Angle( adc1 );
      ServoWriteAngle(i);
      lcd_gotoxy(1,1);
      printf(lcd_putc,"CanalAN0 = %Lu",adc1);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Angulo = %Lu",i);
      delay_ms(100);
      lcd_putc('\f');
   }
}



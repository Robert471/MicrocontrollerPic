#include <16f877a.h>
#fuses   XT
#DEVICE  ADC = 10
#use     delay(CLOCK = 4M)
#define  LCD_DATA_PORT getenv("SFR:PORTD")                                   
#define  LCD_ENABLE_PIN  PIN_A3                                  
#define  LCD_RS_PIN      PIN_A5                                  
#define  LCD_RW_PIN      PIN_A2   
#define  LCD_DATA4       PIN_D4                                   
#define  LCD_DATA5       PIN_D5                                    
#define  LCD_DATA6       PIN_D6                                    
#define  LCD_DATA7       PIN_D7   
#include <lcd.c>
#use     rs232(BAUD = 9600,XMIT = PIN_C6, RCV = PIN_C7)   

char data = '-';

#INT_RDA 
void recibir(){
   data = getc();
} 

void main(){
   int16 adc1;
   
   setup_adc(  ADC_CLOCK_INTERNAL );
   setup_adc_ports(  AN0_AN1_AN3  );   
   lcd_init();

   for(;;){
      set_adc_channel( 0 );
      delay_us(20);
      adc1 = read_adc();  
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Send Uart = %Lu",adc1);
      printf("Send Uart = %Lu\r\n",adc1);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Receive Uart: %c",data);
      delay_ms(100);
      lcd_putc('\f');
   }
}


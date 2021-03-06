#include "16f877a.h"
#fuses xt
#use delay(clock =4M)
#USE RS232(BAUD = 9600,XMIT=PIN_C6,RCV=PIN_C7)
#define LCD_DATA_PORT getenv("SFR:PORTD")
#define LCD_ENABLE_PIN  PIN_A3                                  
#define LCD_RS_PIN      PIN_A5                                  
#define LCD_RW_PIN      PIN_A2                                   
#define LCD_DATA4       PIN_D4
#define LCD_DATA5       PIN_D5                                   
#define LCD_DATA6       PIN_D6                                    
#define LCD_DATA7       PIN_D7 

// Clase2
#include <lcd.c>
#include "..\library\keypad.c"
// Clase3
#include "..\library\servomotor.c"
#include "..\library\ultrasonico.c"
// Clase4
// PWM
// ADC
// Clase5
// UART
// 


void main(){
   char tecla;
   lcd_init();
   kbd_init();
   servomotor_init();
   ServoWriteAngle(0);
   
   port_b_pullups(true);
   lcd_putc('\f');
   printf(lcd_putc,"LABOTEC");
   printf("LABOTEC\r\n");
   for(;;){
   
      tecla = kbd_getc();
      
      if(tecla!=0){
         lcd_putc('\f');
         lcd_gotoxy(1,1);
         printf(lcd_putc,"tecla:%c",tecla);
         printf("tecla:%c\r\n",tecla);
         
         if(tecla == 'A'){
            i++;
            ServoWriteAngle(i);
            lcd_gotoxy(1,2);
            printf(lcd_putc,"Angulo:%Lu",angle);
            printf("Angulo:%Lu\r\n",angle);
         }
         if(tecla == 'B'){
            i--;
            ServoWriteAngle(i);
            lcd_gotoxy(1,2);
            printf(lcd_putc,"Angulo:%Lu",angle);
            printf("Angulo:%Lu\r\n",angle);
         }
         if(tecla == 'C'){
            for(i = 0;i<=180;i++){
               ServoWriteAngle(i);
               lcd_gotoxy(1,2);
               printf(lcd_putc,"Angulo:%Lu",angle);
               printf("Angulo:%Lu\r\n",angle);
               delay_ms(10);
               lcd_putc('\f');
            }
            i=0;
         }
         
      }
     
   }
}

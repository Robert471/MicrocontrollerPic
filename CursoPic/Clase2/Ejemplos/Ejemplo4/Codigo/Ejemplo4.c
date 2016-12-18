#include <16f877a.h> 
#use delay(clock=4M) 
#fuses XT 
#include <lcd.c>     
void nuevo_caracter(void){
   lcd_send_byte(0,0x40);                                            //Defino el primero caracter en la direccion 0x40   
   lcd_send_byte(1,0b00001110);lcd_send_byte(1,0b00001110);
   lcd_send_byte(1,0b00001110);lcd_send_byte(1,0b00000100);
   lcd_send_byte(1,0b00011111);lcd_send_byte(1,0b00000100);
   lcd_send_byte(1,0b00001010);lcd_send_byte(1,0b00010001);   
   lcd_send_byte(0,0x48);                                            //   Defino el segundo caracter en la direccion 0x48      
   lcd_send_byte(1,0b00001110);lcd_send_byte(1,0b00001110);
   lcd_send_byte(1,0b00001110);lcd_send_byte(1,0b00000100);
   lcd_send_byte(1,0b00011111);lcd_send_byte(1,0b00000100);
   lcd_send_byte(1,0b00001110);lcd_send_byte(1,0b00011111);
}
           
void main(void){  
   lcd_init();       
   nuevo_caracter(); 
   lcd_putc('\f');  
   lcd_putc(0);
   lcd_putc(1);
   for(;;){         
   }
}



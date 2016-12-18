#include "16f877a.h"                   // define el pic que vamos a utilizar
#fuses XT                              // defino fusibles
#use delay(clock=4Mhz)                // frecuencia 20Mhz
#include <HDM64GS12.c>                 // Librerias para el 
#include <graphics.c>                  // manejo de la GLCD

void main(){               
   
   int data[]="LaboTEC";
   glcd_init(ON);          

   glcd_line(10,10,50,50,ON);          // GRAFICA PRIMERA DIAGONAL
   glcd_line(50,10,10,50,ON);          // GRAFICO SEGUNDA DIAGONAL
   glcd_rect(10,10,50,50,0,ON);        // DIBUJO UN RECTANGULO    
   glcd_text57(60,10,data,1,ON);       // ENVIO UN TEXTO
   
   for(;;){
   }
}




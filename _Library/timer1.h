#ifndef  __TIMER0__
#define  __TIMER0__

#define TMR1_PRESCALER    RTCC_DIV_8
#define TMR1_CHARGE       65411 
#define TMR1_SIGNAL       PIN_B0

void timer1_init();

#endif

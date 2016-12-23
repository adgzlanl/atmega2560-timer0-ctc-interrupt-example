/*
 * timer0.c
 *
 * Created: 12/23/2016 6:55:37 PM
 * Author : aniladiguzel
 * we assume that F_CPU 16MHZ and Prescale Factor=16MHZ/1024(prescale) ==>15625KHZ ==> Timer0Tick=1/15625KHZ=0,000064 sn per tick
 * and timer0 is 8 bit it means 255 therefore, 256*0,000064=0,016384 sn per timer over flow 
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
uint16_t timerOverflowCount=0;



ISR(TIMER0_COMPA_vect)
{
    timerOverflowCount++;
     
    if(timerOverflowCount > 100) // ten seconds after blink led
    {
        timerOverflowCount = 0;
        PORTB ^= (1 << PORTB7);
    }
}


int main(void)
{
    DDRB = 0xFF;
     
    TCCR0A = (1 << WGM01); //Set CTC Bit
    OCR0A = 156;
    TIMSK0 = (1 << OCIE0A);
     
    sei();
     
    TCCR0B = (1 << CS02) | (1 << CS00); 
     
    while(1)
    {
       
    }
}
 


#include <avr/io.h>
#include <avr/interrupt.h>


ISR(TIMER0_OVF_vect){ //vetor de interrupção estouro do timer 0
	
	PORTC |= (1<<PC0); //liga o led do pino PC0 ao identificar a interrupção (15 pulsos)
	TCCR0 = 0b00000000; //desabilita o contador de pulsos no pino T0
	
}


int main(void)
{
	DDRC = (1<<PC0); //pino PCO como saída
	TCCR0 = 0b00000111; //habilita o contador de pulsos no pino T0
	TCNT0 = 241; //contar 15 pulsos
	TIMSK = 0b00000001; //habilita a interupção de estouro do timer 0
	sei(); //habilita todas as interrupções
	
	while (1) {}
	
}


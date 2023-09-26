#include "stm32f10x.h"

int main(void) 
{
	int buttonVal;
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) |(0x01 << 4) ; //démarre GPIO A, B et C
	GPIOA->CRL = GPIOA->CRL & ~(0xFF << 24)  | (21 << 26); //0101 0100 0... = pin 7 push pull
	
	do
	{

	buttonVal = GPIOA->IDR & (0x1 << 6);
	GPIOA->ODR = ~(buttonVal << 1);
		
	}while(1);
}

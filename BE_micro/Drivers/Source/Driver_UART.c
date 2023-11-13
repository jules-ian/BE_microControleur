#include "stm32f10x.h"
#include "Driver_UART.h"

#define PCLK1 36000000
#define PCLK2 72000000
#define Prio 4


void (*f)(char val);


void MyUART_Init(char usart, void (*func)(char val)){
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	f = func;
	
	switch(usart){
		
		case 1:
			USART1->CR1 |= USART_CR1_UE | USART_CR1_RE | USART_CR1_TE | USART_CR1_RXNEIE;
			USART1->BRR = PCLK2 / 9600;
			NVIC->IP[37] |= Prio << 4 ; // 4 bits de poids fort sont utiles
			NVIC->ISER[1] |= 1 << (37-32); //enable timer interrupts in NVIC
		break;
		
		case 2:
			USART2->CR1 |= USART_CR1_UE | USART_CR1_RE | USART_CR1_TE | USART_CR1_RXNEIE;
			USART2->BRR = PCLK1 / 9600;
			NVIC->IP[38] |= Prio << 4 ; // 4 bits de poids fort sont utiles
			NVIC->ISER[1] |= 1 << (38-32); //enable timer interrupts in NVIC
		break;
		
		case 3:
			USART3->CR1 |= USART_CR1_UE | USART_CR1_RE | USART_CR1_TE | USART_CR1_RXNEIE;
			USART3->BRR = PCLK1 / 9600;
			NVIC->IP[39] |= Prio << 4 ; // 4 bits de poids fort sont utiles
			NVIC->ISER[1] |= 1 << (39-32); //enable timer interrupts in NVIC
		break;
		
	}
	
	
}

//TODO: fonction d'émission
	
void UART1_IRQHandler(void){
	if(f != 0){
	(*f)(USART1->DR);//TODO mettre dans une var globale et faire un getter
	}
}

void USART2_IRQHandler(void){
	if(f != 0){
	(*f)(USART2->DR);
	}
}

void UART3_IRQHandler(void){
	if(f != 0){
	(*f)(USART3->DR);
	}
}

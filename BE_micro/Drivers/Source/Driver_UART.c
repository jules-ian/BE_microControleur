#include "stm32f10x.h"
#include "Driver_UART.h"
#include <string.h>

#define PCLK1 36000000
#define PCLK2 72000000
#define Prio 4


char value1;
char value2;
char value3;

void MyUART_Init(char usart){
	
	
	
	//f = func;
	
	switch(usart){
		
		case 1:
			//Activation clock
			RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
		
		
			USART1->CR1 |= USART_CR1_UE | USART_CR1_RE | USART_CR1_TE | USART_CR1_RXNEIE;
			USART1->BRR = PCLK2 / 9600;
			NVIC->IP[37] |= Prio << 4 ; // 4 bits de poids fort sont utiles
			NVIC->ISER[1] |= 1 << (37-32); //enable timer interrupts in NVIC
		break;
		
		case 2:
			//Activation clock
			RCC->APB1ENR |= RCC_APB1ENR_USART2EN ;
		
			USART2->CR1 |= USART_CR1_UE | USART_CR1_RE | USART_CR1_TE | USART_CR1_RXNEIE;
			USART2->BRR = PCLK1 / 9600;
			NVIC->IP[38] |= Prio << 4 ; // 4 bits de poids fort sont utiles
			NVIC->ISER[1] |= 1 << (38-32); //enable timer interrupts in NVIC
		break;
		
		case 3:
			//Activation clock
			RCC->APB1ENR |= RCC_APB1ENR_USART3EN ;
		
			USART3->CR1 |= USART_CR1_UE | USART_CR1_RE | USART_CR1_TE | USART_CR1_RXNEIE;
			USART3->BRR = PCLK1 / 9600;
			NVIC->IP[39] |= Prio << 4 ; // 4 bits de poids fort sont utiles
			NVIC->ISER[1] |= 1 << (39-32); //enable timer interrupts in NVIC
		break;
		
	}
	
	
}

//TODO: fonction d'émission
	
void USART1_IRQHandler(void){
	
	//(*f)(USART1->DR);//TODO mettre dans une var globale et faire un getter
		value1 = USART1->DR;
	
}

void USART2_IRQHandler(void){
	value2 = USART2->DR;
}

void USART3_IRQHandler(void){
	value3 = USART3->DR;
}

signed char getValue1(void){ // On remet la valeur lue a 0 après l'avoir lue
	signed char tmp = value1;
	//value1 = 0;
	return tmp;
}


signed char getValue2(void){
	signed char tmp = value2;
	//value2 = 0;
	return tmp;
}


signed char getValue3(void){
	signed char tmp = value3;
	//value3 = 0;
	return tmp;
}

void MyUART_send(char* val, char usart){
	int i = 0;
	
	for(i = 0; i < strlen(val); i++){
		switch(usart){
		case 1:
			while(!(USART1->SR & USART_SR_TC)){}
			USART1->DR = val[i];
			break;
		case 2:
			while(!(USART2->SR & USART_SR_TC)){}
			USART2->DR = val[i];
			break;
			
		case 3:
			while(!(USART3->SR & USART_SR_TC)){}
			USART3->DR = val[i];
			break;
	}
	}
	
	
}

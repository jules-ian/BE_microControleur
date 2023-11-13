#include "stm32f10x.h"
#include "Driver_Timer.h"

void (*ptr)(void);

void MyTimer_Base_Init(TIM_TypeDef * Timer, unsigned short ARR, unsigned short PSC){
	
	if(Timer == TIM1){
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}else if(Timer == TIM2){
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}else if(Timer == TIM3){
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}else if(Timer == TIM4){
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}
	
	
	Timer->PSC = PSC;
	Timer->ARR = ARR;
	
	
}

void MyTimer_ActiveIT(TIM_TypeDef * Timer, char Prio, void (*func)(void)){
	Timer->DIER |= 1; //enable timer interrupts
	
	ptr = func;
	
	//TIM2 -> 28, TIM3 -> 29, TIM4 -> 30
	if (Timer == TIM2){
		NVIC->IP[28] |= Prio << 4 ; // 4 bits de poids fort sont utiles
		NVIC->ISER[0] |= (1 << 28); //enable timer interrupts in NVIC
	}else if (Timer == TIM3){
		NVIC->IP[29] |= Prio << 4 ; // 4 bits de poids fort sont utiles
		NVIC->ISER[0] |= 1 << 29; //enable timer interrupts in NVIC
	}else if (Timer == TIM4){
		NVIC->IP[30] |= Prio << 4 ; // 4 bits de poids fort sont utiles
		NVIC->ISER[0] |= 1 << 30; //enable timer interrupts in NVIC
	}else if (Timer == TIM1){
		NVIC->IP[25] |= Prio << 4 ; // 4 bits de poids fort sont utiles
		NVIC->ISER[0] |= 1 << 25; //enable timer interrupts in NVIC
	}
	
}


void MyTimer_PWM(TIM_TypeDef * Timer, char Channel){
	Timer->CR1 &= ~(0x7 << 5);
	Timer->CR1 |= (8 << 5);
	
	switch(Channel){ 
		
		case 1: {
			Timer->CCER |= TIM_CCER_CC1E;
		Timer->CCMR1 &= 3 << 2;
		Timer->CCMR1 |= 3<<5;
		break;}
		case 2:{
			Timer->CCER |= TIM_CCER_CC2E;
		Timer->CCMR1 &= 3 << 10;
		Timer->CCMR1 |= 3 << 13;
		break;}
		case 3:{
			Timer->CCER |= TIM_CCER_CC3E;
		Timer->CCMR2 &= 3<<2;
		Timer->CCMR2 |= 3<<5;
		break;}
		case 4:{
			Timer->CCER |= TIM_CCER_CC4E;
		Timer->CCMR2 &= 3 << 10;
		Timer->CCMR2 |= 3 << 13;
		break;}
	}
	
		
}

void PWM_SetCycle(TIM_TypeDef * Timer, char Channel, short int ccr){ // ccr = rapport cyclique ?
	switch(Channel){ 
		
		case 1:
			Timer->CCR1 = ccr;
		break;
		case 2:
			Timer->CCR2 = ccr;
		break;
		case 3:
			Timer->CCR3 = ccr;
		break;
		case 4:
			Timer->CCR4 = ccr;
		break;
	}
}



void TIM2_IRQHandler(){
		TIM2->SR &= ~(1);
		if(ptr != 0){(*ptr)();}
		
	}

	void TIM3_IRQHandler(){
		TIM3->SR &= ~(1) ;
		if(ptr != 0){(*ptr)();}
	}
	
	void TIM4_IRQHandler(){
		TIM4->SR &= ~(1) ;
		if(ptr != 0){(*ptr)();}
	}
	
	void TIM1_UP_IRQHandler(){
		TIM1->SR &= ~(1) ;
		if(ptr != 0){(*ptr)();}
	}

	
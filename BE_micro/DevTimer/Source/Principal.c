#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "Driver_Timer.h"

void Callback();

int main(void) 
{
	
	
	int psc = 6000;
	int arr = 6000;
	
	// pour 
	
	MyTimer_Base_Init(TIM1, arr -1, psc-1);
	//MyTimer_ActiveIT(TIM1, 7, Callback);
	MyGPIO_Init(GPIOA,9,AltOut_Ppull);
	MyTimer_Base_Start(TIM1);
	MyTimer_PWM(TIM1, 2);
	PWM_SetCycle(TIM1, 2, arr/9);
	


	do{
		
	}while(1);
}

void Callback(){
	MyGPIO_Toggle(GPIOA, 7);
}



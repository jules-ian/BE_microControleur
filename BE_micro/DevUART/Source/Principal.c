#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"
#include "Driver_Timer.h"
#include "Driver_UART.h"

void Callback(char val);



int main(void) 
{
	MyUART_Init(2);
	MyGPIO_Init(GPIOA, 6, Out_Ppull);

	do{
		if (getValue2() == 'o'){
			MyGPIO_Toggle(GPIOA, 6);
		}
	}while(1);
}

/*
void Callback(char val){
	MyGPIO_Toggle(GPIOA, 6);
}
*/


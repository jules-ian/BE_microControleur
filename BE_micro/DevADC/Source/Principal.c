#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"
#include "Driver_Timer.h"

void Callback(void);

int val;

int main(void) 
{
	Init_ADC();

	do{
		val= ADC_GetValue(0);
	}while(1);
}




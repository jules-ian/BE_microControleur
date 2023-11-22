#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"
#include "Driver_Timer.h"
#include "Driver_UART.h"
#include "Service_Moteur.h"

void Callback(char val);



int main(void) 
{ //�a tourne pas dans le meme sens et �a change pas de vitesse � 100 9C et � -100 64 dans le registre DR
	MyUART_Init(1);
	MyGPIO_Init(GPIOA,9,AltOut_Ppull);
	MyGPIO_Init(GPIOA,10, In_Floating);
	MyMoteur_Init();

	do{
		MyMoteur_Set_Power(getValue1());
	}while(1);
}

/*
void Callback(char val){
	MyGPIO_Toggle(GPIOA, 6);
}
*/


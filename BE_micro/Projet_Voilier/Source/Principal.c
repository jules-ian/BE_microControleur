#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"
#include "Driver_Timer.h"
#include "Driver_UART.h"
#include "Service_Moteur.h"
#include "io.h"
#include "Gestion_auto_voile.h"

#define SystickPeriod 10800000 // 150 ms = 10.8MHz/72MHz

int counter = 0;
int flag = 0;

void SysTick_Handler(void){
	flag = 1;
	counter++;
	//Les 2 fonctions ci-dessous sont très rapide donc on les mets directement dans le Handler, tandis que MyUART_send a un risque de durer plus longtemps et doit pouvoir être interrompu ( donc dans le while )
			gestion_mise_a_jour();
			MyMoteur_Set_Power(getValue1());
}


int main(void) 
{ //ça tourne pas dans le meme sens et ça change pas de vitesse à 100 0x009C et à -100 0x0064 dans le registre DR
	MyUART_Init(USART_Telecommande);
	MyGPIO_Init(GPIO_USART_TX, Pin_USART_TX, AltOut_Ppull); // USART TX
	MyGPIO_Init(GPIO_USART_RX, Pin_USART_RX, In_Floating); // USART RX
	MyMoteur_Init();
	gestion_init();
	
	SysTick->CTRL |= 0b111;
	SysTick->LOAD = SystickPeriod;
	
	
	do{
		
		if(flag){
			flag = 0;
			
			
			if(counter % 10 == 0){
				MyUART_send("salut le bato\n", 1); //14 caractères envoyé peuvent prendre + de 100 ms, donc il faut setup un systick + grand ( 150 ms par exemple )
			}
			
		
			
		}
		
	
	}while(1);
}




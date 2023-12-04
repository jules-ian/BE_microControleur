#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"
#include "Driver_Timer.h"
#include "Driver_UART.h"
#include "Service_Moteur.h"
#include "io.h"


int main(void) 
{ //ça tourne pas dans le meme sens et ça change pas de vitesse à 100 0x009C et à -100 0x0064 dans le registre DR
	MyUART_Init(USART_Telecommande);
	MyGPIO_Init(GPIO_USART_TX, Pin_USART_TX, AltOut_Ppull); // USART TX
	MyGPIO_Init(GPIO_USART_RX, Pin_USART_RX, In_Floating); // USART RX
	MyMoteur_Init();

	do{
		
		MyMoteur_Set_Power(getValue1());
		MyUART_send("salut le bato\n", 1); //14 caractères envoyé peuvent prendre + de 100 ms, donc il faut setup un systick + grand ( 150 ms par exemple )
	  MyUART_send("2e ligne", 1);
	
	}while(1);
}




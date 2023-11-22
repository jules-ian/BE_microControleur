#include "stm32f10x.h"
#include "Driver_GPIO.h"

int main(void) 
{
	int buttonVal;
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) |(0x01 << 4) ; //démarre GPIO A, B et C
	GPIOA->CRL = GPIOA->CRL & ~(0xFF << 24)  | (21 << 26); //0101 0100 0... = pin 7 push pull
	
	MyGPIO_Init(GPIOA, 5, Out_Ppull);
	MyGPIO_Init(GPIOA, 6, In_PullDown);
	MyGPIO_Init(GPIOA, 7 , Out_OD);
	
	
	
	MyGPIO_Init(GPIOB, 5, Out_OD);
	MyGPIO_Init(GPIOC, 5, Out_OD);
	MyGPIO_Init(GPIOD, 5, Out_OD);
	
	do
	{

int result = MyGRPIO_Read(GPIOA, 6);
	if(result){
		MyGPIO_Reset(GPIOA, 7);
	}else{
	MyGPIO_Set(GPIOA, 7);
	}

		
	
	//buttonVal = GPIOA->IDR & (0x1 << 6);
	//GPIOA->ODR = ~(buttonVal << 1);
		
	}while(1);
}
//void MyGPIO_Init(GPIO_TypeDef * GPIO, char GRPIO_Pin, char GPIO_Conf);
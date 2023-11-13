#include "stm32f10x.h"
#include "Driver_GPIO.h"



//------------------------------------ INITIALISATION FUNCTION --------------------------------------

void MyGPIO_Init(GPIO_TypeDef * GPIO, char GRPIO_Pin, char GPIO_Conf) {
	if (GPIO==GPIOA) {
		RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN);//IOPxEN (= GPIOx ) 
	} else if (GPIO==GPIOB) {
		RCC->APB2ENR |= (RCC_APB2ENR_IOPBEN);
	} else if (GPIO==GPIOC) {
		RCC->APB2ENR |= (RCC_APB2ENR_IOPCEN);
	} else if (GPIO==GPIOD) {
		RCC->APB2ENR |= (RCC_APB2ENR_IOPDEN);
	} //else on traite pas le cas si c'est pas un GPIO connu

	if(GPIO_Conf == In_PullDown){
		
		if (GRPIO_Pin <=7) {
			GPIO->CRL = GPIO->CRL & ~(0xF << 4*GRPIO_Pin)  | (0x8 << 4*GRPIO_Pin); //4* la pin car 4 bit par pin
			GPIO->ODR &= ~(1 << GRPIO_Pin);
		} else {
			GPIO->CRH = GPIO->CRH & ~(0xF <<4*(GRPIO_Pin -8))  | (0x8 << 4*(GRPIO_Pin -8) ); //-8 car c'est décalé chez CRH pour les pins > 7
			GPIO->ODR &= ~(GPIO_ODR_ODR0 << (GRPIO_Pin));
		}
	}else if(GPIO_Conf == In_PullUp){
		
		if (GRPIO_Pin <=7) {
			GPIO->CRL = GPIO->CRL & ~(0xF << 4*GRPIO_Pin)  | (0x8 << 4*GRPIO_Pin); //4* la pin car 4 bit par pin
			GPIO->ODR |= GPIO_ODR_ODR0 << GRPIO_Pin;
		} else {
			GPIO->CRH = GPIO->CRH & ~(0xF <<4*(GRPIO_Pin -8))  | (0x8 << 4*(GRPIO_Pin -8) ); //-8 car c'est décalé chez CRH pour les pins > 7
			GPIO->ODR |= GPIO_ODR_ODR0 << (GRPIO_Pin);
		}
		
	}else{
		
			if (GRPIO_Pin <=7) {
			GPIO->CRL = GPIO->CRL & ~(0xF << 4*GRPIO_Pin)  | (GPIO_Conf << 4*GRPIO_Pin); //4* la pin car 4 bit par pin
		} else {
			GPIO->CRH = GPIO->CRH & ~(0xF <<4*(GRPIO_Pin -8))  | (GPIO_Conf << 4*(GRPIO_Pin -8) ); //-8 car c'est décalé chez CRH pour les pins > 7
		}
	
	}
	
}

//------------------------------------ READING FUNCTION --------------------------------------

int MyGRPIO_Read(GPIO_TypeDef * GPIO, char GPIO_Pin){
	return GPIO->IDR & (GPIO_IDR_IDR0 << GPIO_Pin) ;
	
}


//------------------------------------ SETTING FUNCTION --------------------------------------

void MyGPIO_Set(GPIO_TypeDef * GPIO, char GPIO_Pin){
	GPIO->ODR |=  (GPIO_ODR_ODR0 << GPIO_Pin);
}
	

//------------------------------------ RESETTING FUNCTION --------------------------------------

void MyGPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_Pin){
	GPIO->ODR &=  ~(GPIO_ODR_ODR0 << GPIO_Pin);
}
	

//------------------------------------ TOGGLING FUNCTION --------------------------------------

void MyGPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_Pin){
	GPIO->ODR ^=  (GPIO_ODR_ODR0 << GPIO_Pin);
	//GPIO->ODR & (GPIO_ODR_ODR0 << GPIO_Pin) != 0 ? MyGPIO_Reset(GPIO, GPIO_Pin) : MyGPIO_Set(GPIO, GPIO_Pin);
}

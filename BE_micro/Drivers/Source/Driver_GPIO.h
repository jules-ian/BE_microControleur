#ifndef MYGPIO_H
#define MYGPIO_H
#include "stm32f10x.h"

#define In_Floating 0x4
#define In_PullDown 0x8
#define In_PullUp 0x38
#define In_Analog 0x0
#define Out_Ppull 0x1
#define Out_OD 0x5
#define AltOut_Ppull 0x9
#define AltOut_OD 0xD

void MyGPIO_Init(GPIO_TypeDef * GPIO, char GRPIO_Pin, char GPIO_Conf);
int MyGRPIO_Read(GPIO_TypeDef * GPIO, char GPIO_Pin);
void MyGPIO_Set(GPIO_TypeDef * GPIO, char GPIO_Pin);
void MyGPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_Pin);
void MyGPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_Pin);

#endif
			
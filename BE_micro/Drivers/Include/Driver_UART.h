#ifndef MYUART_H
#define MYUART_H
#include "stm32f10x.h"

void MyUART_Init(char usart, void (*func)(char val));


#endif
			

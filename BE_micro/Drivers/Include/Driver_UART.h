#ifndef MYUART_H
#define MYUART_H
#include "stm32f10x.h"

void MyUART_Init(char usart);


signed char getValue1(void);
signed char getValue2(void);
signed char getValue3(void);

void MyUART_send(char* val, char usart);


#endif
			

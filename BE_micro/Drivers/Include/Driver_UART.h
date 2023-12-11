#ifndef MYUART_H
#define MYUART_H
#include "stm32f10x.h"

void MyUART_Init(char usart);


signed char getValue1(void); //gets value of UART 1
signed char getValue2(void); //gets value of UART 2
signed char getValue3(void); //gets value of UART 3

void MyUART_send(char* val, char usart);


#endif
			

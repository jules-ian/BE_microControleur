#ifndef MYTIMER_H
#define MYTIMER_H
#include "stm32f10x.h"


// How to calculate ARR and PSC ? ARR < 2^16, PSC < 2^16 and F = CLK/(ARR*PSC) with CLK = 72MHz
void MyTimer_Base_Init(TIM_TypeDef * Timer, unsigned short ARR, unsigned short PSC);

void MyTimer_ActiveIT(TIM_TypeDef * Timer, char Prio, void (*func)(void));

void MyTimer_PWM(TIM_TypeDef * Timer, char Channel);
void PWM_SetCycle(TIM_TypeDef * Timer, char Channel, short int ccr);

int Get_angle_vent(TIM_TypeDef * Timer);
void init_TIM_Angle(TIM_TypeDef * Timer);

#define MyTimer_Base_Start(Timer) Timer->CR1 |= TIM_CR1_CEN;
#define MyTimer_Base_Stop(Timer) Timer->CR1 &= ~TIM_CR1_CEN;


#endif

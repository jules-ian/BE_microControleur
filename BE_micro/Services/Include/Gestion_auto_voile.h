#ifndef GESTION_AUTO_VOILE_H
#define GESTION_AUTO_VOILE_H
#include "Driver_Timer.h"
#include "Driver_GPIO.h"

void gestion_init_girouette(TIM_TypeDef * Timer,GPIO_TypeDef * GPIO1, char GRPIO_Pin1, char GRPIO_Pin2,char GRPIO_Pin3);
void gestion_init_voile(TIM_TypeDef * Timer,GPIO_TypeDef * GPIO, char GRPIO_Pin);
void gestion_mise_a_jour(TIM_TypeDef * Timer_girou, TIM_TypeDef * Timer_voile);


#endif
		
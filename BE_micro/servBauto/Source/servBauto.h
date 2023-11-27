#ifndef SERVBAUTO_H
#define SERVBAUTO_H
#include "Driver_Timer.h"
#include "Driver_GPIO.h"

void init_servBauto(void);

int calcul_rapport_cyclique(int angle_vente);
void set_rapport_cyclique(int Duty_cycle);

#endif
		
#include"servBauto.h"
void init_servBauto(void){
	MyGPIO_Init(GPIOA,2,AltOut_Ppull);//  TIM2 Ch-3
	MyTimer_Base_Init(TIM2,999,1439);
	MyTimer_PWM(TIM2,3);
	MyTimer_Base_Start(TIM2);
	MyGPIO_Init(GPIOA,6,In_Floating); //TIM3 CH1
	MyGPIO_Init(GPIOA,7,In_Floating); //TIM3 CH2
	//on choit TIM3 pout coder imcrémentaire en PA8
	MyTimer_Base_Init(TIM3,1439,0);
	MyTimer_Base_Start(TIM3);

}
void set_rapport_cyclique(int Duty_cycle){
		PWM_SetCycle(TIM2,3,Duty_cycle);
}
int calcul_rapport_cyclique(int angle_vente){
	//sif (angle_vente>45&&angle)
	int Duty_Cycle;
	if (angle_vente<=45){
			Duty_Cycle=100;
	}else if(angle_vente>45&&angle_vente<=68){
			Duty_Cycle=90;
	}else if(angle_vente>68&&angle_vente<=90){
			Duty_Cycle=80;
	}else if(angle_vente>90&&angle_vente<=113){
			Duty_Cycle=70;
	}else if(angle_vente>113&&angle_vente<=135){
			Duty_Cycle=60;
	}else if(angle_vente>135&&angle_vente<225){
			Duty_Cycle=50;
	}else if(angle_vente>=225&&angle_vente<248){
			Duty_Cycle=60;
	}else if(angle_vente>=248&&angle_vente<270){
			Duty_Cycle=70;
	}else if(angle_vente>=270&&angle_vente<293){
			Duty_Cycle=80;
	}else if(angle_vente>=293&&angle_vente<315){
			Duty_Cycle=90;
	}else if(angle_vente>=315){
			Duty_Cycle=100;}
	return Duty_Cycle;
}

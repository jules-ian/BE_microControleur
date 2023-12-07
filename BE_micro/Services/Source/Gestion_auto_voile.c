#include "Gestion_auto_voile.h"

void init_girouette(GPIO_TypeDef * GPIO1, char GRPIO_Pin3){
while((GPIO1->IDR&0x1<<GRPIO_Pin3)==0){}; //quand girouette est à la position init, on commence
	TIM3->CNT=0;
}

void init_TIM_Angle(TIM_TypeDef * Timer){
		Timer->SMCR&=~(0x7);
		Timer->SMCR|=0x3;
	}
	
		
int Get_angle_vent(TIM_TypeDef * Timer){
		return Timer->CNT/4;
	}

void gestion_init_girouette(TIM_TypeDef * Timer,GPIO_TypeDef * GPIO1, char GRPIO_Pin1, char GRPIO_Pin2,char GRPIO_Pin3){
	MyGPIO_Init(GPIO1,GRPIO_Pin1,In_Floating); //TIM3 CH1
	MyGPIO_Init(GPIO1,GRPIO_Pin2,In_Floating); //TIM3 CH2

	MyGPIO_Init(GPIO1,GRPIO_Pin3,In_Floating); //pour IDC de girouette

	
	MyTimer_Base_Init(Timer,1439,0);
	MyTimer_Base_Start(Timer);
	init_TIM_Angle(Timer);
	init_girouette(GPIO1,GRPIO_Pin3);

}
void gestion_init_voile(TIM_TypeDef * Timer,GPIO_TypeDef * GPIO, char GRPIO_Pin){
	MyGPIO_Init(GPIO,GRPIO_Pin,AltOut_Ppull);//  TIM4 Ch-1
	MyTimer_Base_Init(Timer,999,1439);
	MyTimer_PWM(Timer,1);
	MyTimer_Base_Start(Timer);
}
int calcul_rapport_cyclique(int angle_vente){
	//sif (angle_vente>45&&angle)
	int Duty_Cycle;
	if (angle_vente<=35){
			Duty_Cycle=100;
	}else if(angle_vente>35&&angle_vente<=68){
			Duty_Cycle=90;
	}else if(angle_vente>68&&angle_vente<=86){
			Duty_Cycle=80;
	}else if(angle_vente>86&&angle_vente<=106){
			Duty_Cycle=60;
	}else if(angle_vente>106&&angle_vente<=143){
			Duty_Cycle=50;
	}else if(angle_vente>143&&angle_vente<223){
			Duty_Cycle=50;
	}else if(angle_vente>=223&&angle_vente<262){
			Duty_Cycle=50;
	}else if(angle_vente>=262&&angle_vente<279){
			Duty_Cycle=60;
	}else if(angle_vente>=279&&angle_vente<305){
			Duty_Cycle=80;
	}else if(angle_vente>=305&&angle_vente<340){
			Duty_Cycle=90;
	}else if(angle_vente>=340){
			Duty_Cycle=100;}
	return Duty_Cycle;
}
void gestion_mise_a_jour(TIM_TypeDef * Timer_girou, TIM_TypeDef * Timer_voile){
		int cyclique;
		cyclique=calcul_rapport_cyclique(Get_angle_vent(Timer_girou));
		PWM_SetCycle(Timer_voile,1,Timer_voile->ARR*cyclique/1000);
		
}

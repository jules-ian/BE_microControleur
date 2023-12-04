#include "Gestion_auto_voile.h"
void gestion_init(){
	MyGPIO_Init(GPIOB,6,AltOut_Ppull);//  TIM4 Ch-1
	MyTimer_Base_Init(TIM4,999,1439);
	MyTimer_PWM(TIM4,1);
	MyTimer_Base_Start(TIM4);
	
	
	MyGPIO_Init(GPIOA,6,In_Floating); //TIM3 CH1
	MyGPIO_Init(GPIOA,7,In_Floating); //TIM3 CH2
	//on choit TIM3 pout coder imcrémentaire en PA8

	
	MyTimer_Base_Init(TIM3,1439,0);
	MyTimer_Base_Start(TIM3);
	TIM3->SMCR&=~(0x7);
	TIM3->SMCR|=0x3;// à voir
	TIM3->CNT=0;

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
void gestion_mise_a_jour(){
	
		//int test=0;
		//while (test==0){
			//test=(GPIOB->IDR &(0x01<<6));
		//}
	
		int cyclique;

		

		cyclique=calcul_rapport_cyclique((TIM3->CNT)/4);
		PWM_SetCycle(TIM4,1,TIM4->ARR*cyclique/1000);
		
}


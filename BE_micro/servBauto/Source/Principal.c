#include "servBauto.h"



int main(void) 
{

	int reset=0;
	
	
	

	init_servBauto();
	//Activer encoder interface mode
	TIM3->SMCR&=~(0x7);
	TIM3->SMCR|=0x3;// à voir
	
	
	
	TIM3->CNT=0;//pour commencer
	while(1){
		reset=(TIM3->CNT)/4;
		
		set_rapport_cyclique(calcul_rapport_cyclique(reset));
		
	}
}





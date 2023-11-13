#include "stm32f10x.h"
#include "Driver_ADC.h"
#include "Driver_GPIO.h"


//------------------------------------ INITIALISATION FUNCTION --------------------------------------

void Init_ADC(void){
	
	RCC->CFGR&=~RCC_CFGR_ADCPRE;
	RCC->CFGR|=RCC_CFGR_ADCPRE_1;
	
	RCC->APB2ENR|=RCC_APB2ENR_ADC1EN;
	
	ADC1->CR2 |= ADC_CR2_ADON | ADC_CR2_EXTTRIG | ADC_CR2_EXTSEL;
	ADC1->SMPR1 &= ~(ADC_SMPR1_SMP10 & ADC_SMPR1_SMP11 & ADC_SMPR1_SMP12 & ADC_SMPR1_SMP13 & ADC_SMPR1_SMP14 & ADC_SMPR1_SMP15 & ADC_SMPR1_SMP16 & ADC_SMPR1_SMP17); 
	ADC1->SMPR2 &= ~(ADC_SMPR2_SMP0 & ADC_SMPR2_SMP1 & ADC_SMPR2_SMP2 & ADC_SMPR2_SMP3 & ADC_SMPR2_SMP4 & ADC_SMPR2_SMP5 & ADC_SMPR2_SMP6 & ADC_SMPR2_SMP7 & ADC_SMPR2_SMP8 & ADC_SMPR2_SMP9); 
	// ^ mettre tous les Ts de tous les channels au minimum
	
}

int ADC_GetValue(int chan){ // Choisir la pin d'entrée du signal //surement return int
	// Pas oublier de selectionner le channel ( donc la pin voulu avec la doc ) 
	ADC1->SQR3=chan;
	//setup la pin6 en analog

	
	
	// Mettre SWSTART à 1 pour commencer à attendre,
	ADC1 -> CR2 |= ADC_CR2_SWSTART;
	// while flag EOC /= 1 on attend et une fois que c'est levé on lis la valeur dans ADCy -> DR et on la return 
	
	//EOC est dans ADC_SR le bit 1
	while (!((ADC1 -> SR) & ADC_SR_EOC)) 
	{ //on attend que la convertion soit fini ( bloquant )
	}
	//on récup la valeur converti

	return ADC1 ->DR ;
	
}

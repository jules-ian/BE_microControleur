#include "stm32f10x.h"
#include "Service_Moteur.h"
#include "Driver_Timer.h"
#include "Driver_GPIO.h"

// On veut une freq de PWM > 20kHz pour ne pas l'entendre donc on choisit arr*psc = 3600
// On veut aussi que ARR soit divisible par 100 pour pouvoir choisir un pourcentage entier de la PWM
// On choisit arr = 100 don psc = 36

short int arr = 100; 
short int psc = 36; 

void MyMoteur_Init(){
	
	MyTimer_Base_Init(TIM2, arr -1, psc-1);
	
	
	MyGPIO_Init(GPIOA,1,Out_Ppull); //pa1 DOIT ËTRE PLATEAU DIRECTION 
	MyGPIO_Init(GPIOA,0,AltOut_Ppull); //PA0 doit être plateau PWN donc channel 1 (doc)
	MyTimer_Base_Start(TIM2);
	MyTimer_PWM(TIM2, 1);

}

void MyMoteur_Set_Power(signed char value){
	
	if(value < 0){
		MyGPIO_Set(GPIOA, 1);
		PWM_SetCycle(TIM2, 1,(- value));
	}else{
		MyGPIO_Reset(GPIOA, 1);
		PWM_SetCycle(TIM2, 1, value);
	}
	
}
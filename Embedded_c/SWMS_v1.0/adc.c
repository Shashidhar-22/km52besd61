#include"header.h"

#define RCC_AHB1ENR	*((int *)0x40023830)
#define	RCC_APB2ENR *((int *)0x40023844)

#define GPIOC_MODER	*((int *)0x40020800)

#define STK_CTRL		*((int *)0xE000E010)
#define STK_LOAD		*((int *)0xE000E014)
#define STK_VAL			*((int *)0xE000E018)

#define ADC_SMPR1		*((int *)0x4001200C)
#define ADC_SQR3		*((int *)0x40012034)
#define ADC_CR1			*((int *)0x40012004)
#define ADC_CR2			*((int *)0x40012008)
#define ADC_SR			*((int *)0x40012000)
#define ADC_DR			*((int *)0x4001204C)

#define NVIC_ISER0  *((int *)0xE000E100)

volatile int LM_35=0;	                         //	Global variable for store LM-35 readings
									
void GPIOC_INIT(void)
{
	RCC_AHB1ENR |=0x4;										//set RCC clock enable for AHBENR register
	while(!(RCC_AHB1ENR & 0x4));					//wait until check	
	GPIOC_MODER &= ~0x3;	 								// Clear Mode reg for 10th
	GPIOC_MODER |=0x3<<2;									// Set ADC10th pin as ADC
}	

void ADC_INIT(void)
{
	RCC_APB2ENR |= (0x1<<8);						 // RCC enable to APB2 bus
	while(!(RCC_APB2ENR & 0x1<<8));			 // wait until set
	ADC_SMPR1 |= 0x7;									   // set sample time 480 cycles
	ADC_SQR3 |=0x0A;										 // squence reg as 1 for ADC10
	ADC_CR1  &=~(0x3<<24);							 // resolution as 12bit
	ADC_CR2		|=(0x01<<10);							 // EOC ON
	ADC_CR2		|= 0X1;										 // ADC ON
	ADC_CR1		|= 0x01<<5;								 // set EOCIE in CR1
	NVIC_ISER0 |=0x01<<18;							 // set 10th position in interrupt set enable register
}
void  ADC_READ()
{
	ADC_CR2		|=0x1<<30;								// start convertion									
}

void ADC_IRQHandler()									// ADC interrupt handler
{
								
	LM_35 =ADC_DR;	                     // data into LM_35 variable
	ADC_CR2 &=~(0x1<<30);								 // stop conversion
	MSEC(500);						               // wait for 50ms for each convertion
}
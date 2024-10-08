#define RCC_AHB1ENR *((int*)0x40023830)
#define RCC_APB2ENR *((int*) 0x40023844)
#define RCC_ADC1 *((int*) 0x400120004)	
#define GPIOC_MODE *((int*) 0x40020800)
#define GPIOC_PUPDR *((int*)0x4002080C)
//#define  RCC_APB2 *((int*) 0x40012000)
	
#define  ADC_SMPR1 *((int*) 0x4001200C)	
#define ADC_SQR3 *((int*) 0x40012034)	
#define ADC_CR1 *((int*) 0x40012004)	
#define ADC_CR2 *((int*) 0x40012008)
#define ADC_DR *((int*) 0x4001204C)
#define  ADC_SR *((int*) 0x40012000)
	
#define SYSCONFIG_EXTCR3 *((int*)0x40013810)
#define EXTI_FTSR *((int*)0x40013C0C)
#define EXTI_IMR *((int*)0x40013C00)
#define EXTI_PR *((int*)0x40013C14)
#define NVIC_ISER0 *((int *)0xE000E100)
#define DBGMCU_CR  *((int *)0xE0042004)
	
//void SYS_config();

//initilization

void init(void)
{

	RCC_AHB1ENR |=(0x01<<2);			       //port c enable.
	while(!(RCC_AHB1ENR & (0x01<<2)));
	RCC_APB2ENR |=(0x01<<8);	           //adc enable.
	while(!(RCC_APB2ENR & (0x01<<8)));
	RCC_APB2ENR |=(0x01<<14);	           //syscfg enable.
	while(!(RCC_APB2ENR & (0x01<<14)));
}
	void config(void)
{
	GPIOC_PUPDR &=0xff3fffff;            //clear 22-23 bit field.
	GPIOC_PUPDR |=0x400000;	              //pc11 as pullup mode.
	GPIOC_MODE &=0xfffffff3;               //clear 3-2 bit field.
	GPIOC_MODE |=0xc;	                     //pc1 as analog mode.
		SYSCONFIG_EXTCR3 &=0xffff0fff;       //clear 15-14-13-2 bit field.
	SYSCONFIG_EXTCR3 |=0x2000;	           //enable pc11 as external interrupt.
	EXTI_FTSR &= 0xFFFFF7FF; 
	EXTI_FTSR |= 0x00000800;
	EXTI_IMR &= 0xFFFFF7FF; 
	EXTI_IMR |= 0x00000800;

	ADC_CR2 |=(0x1);	                     //Set 0th bit ADC_CR2 to enable ADC.
	ADC_CR2 &=0xcfffffff;                  //clear 29-28 bit field.
	ADC_CR2 |=0x20000000;                  //'10' 29-28 bit field.
	ADC_CR2 &=0xf0ffffff;                  //clear 27-26-25-24 bit field.
	ADC_CR2 |=0xF000000;                     //'1111' 27-26-25-24 bit field.
	ADC_SQR3 &= 0xFFFFFFE0; 
	ADC_SQR3 |= 0x0000000B;                 //Load “01011” (channel no 11) in to 4-0 bit fields in ADC_SQR3 register.
	ADC_CR2 |=(0x1<<10);	                   //Set 10th bit (EOCS) in ADC_CR2 to select End of Conversion.
	ADC_CR1 |=(0x1<<5);	                    //eoci intrept.
	NVIC_ISER0 |=(0x1<<18);
}
void DEBUG_sleep_enable(void)
{
	DBGMCU_CR |= (0x1<<0);                   //set 0th bit to enable DEBUG sleep.
}
int potentio;
int main()
{
init();
config();
DEBUG_sleep_enable();
while(1)
{
	//__wfi();
	;
}
}

void ADC_IRQHandler (void)
{
	potentio=ADC_DR;
	ADC_SR &=~(0x01<<1);

}

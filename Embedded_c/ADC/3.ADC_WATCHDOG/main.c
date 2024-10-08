#define RCC_AHB1ENR *((int*)0x40023830)
#define RCC_APB2ENR *((int*)0x40023844)

#define GPIOB_MODER *((int*)0x40020400)
#define GPIOC_MODER *((int*)0x40020800)
#define GPIOB_ODR	*((int*)0x40020414)
//#define RCC_AHB1ENR *((int*)0x40023830)

#define ADC_SR *((int*)0x40012000)
#define ADC_CR2 *((int*)0x40012008)
#define ADC_CR1 *((int*)0x40012004)
#define ADC_SQR3 *((int*)0x40012034)
#define ADC_DR *((int*)0x4001204C)
#define NVIC_ISER0 *((int*)0xE000E100)
#define	ADC_HTR *((int*)0x40012024)
#define	ADC_LTR *((int*)0x40012028)

void GPIOB_init()
{
	RCC_AHB1ENR |=(0x1<<1);
	while(!(RCC_AHB1ENR & (0x1<<1)));
}

void GPIOC_init()
{
	RCC_AHB1ENR |=(0x1<<2);
	while(!(RCC_AHB1ENR & (0x1<<2)));
}
void ADC_init()
{
	RCC_APB2ENR |=(0x1<<8);
	while(!(RCC_APB2ENR & (0x1<<8)));
	GPIOC_MODER &=0xfffffff3;
	GPIOC_MODER |=0xc;	      //Load “11” in to PC1 bit filed in GPIOC_MODE Register
	GPIOB_MODER &=0xfcffffff;
	GPIOB_MODER	|=0x1000000;
	
	ADC_CR2 |=(0x1);	     //Set 0th bit ADC_CR2 to enable ADC.
	ADC_SQR3|=0xb;	        //Load “01011” (channel no 11) in to 4-0 bit fields in ADC_SQR3 register.
	ADC_CR2 |=(0x1<<10);	 //Set 10th bit (EOCS) in ADC_CR2 to select End of Conversion.
	ADC_CR1 |=(0x1<<5);	   //eoci intrept.
	ADC_CR1	|=(0x1<<23);   //analog watch dog enable on regular channel.
	ADC_CR1	|=(0x1<<9);	    //enable watch dog in scan mode.
	ADC_CR1	|=(0x1<<6);	     //analog watch dog intrept enable.
	ADC_CR1 |=0xb;            //enable analog watch dog.
	NVIC_ISER0 |=(0x1<<18);
}
int potentio_value;
int main()
{
GPIOB_init();
GPIOC_init();
ADC_init();
ADC_HTR=2000;
ADC_LTR=1000;
	while(1)
	{
		ADC_CR2 |=(0x1<<30);
		__wfi();
	}
}
void ADC_IRQHandler (void)
{
	potentio_value=ADC_DR;
  while((ADC_SR &((0x01))))
	{
		GPIOB_ODR |=(0x1<<12);
	}
		GPIOB_ODR &=~(0x1<<12);


}
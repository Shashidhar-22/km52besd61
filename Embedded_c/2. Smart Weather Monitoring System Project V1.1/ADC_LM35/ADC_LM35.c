#define RCC_AHB1ENR *((int*)0x40023830)
#define RCC_APB2ENR *((int*)0x40023844)

#define GPIOC_MODE *((int*)0x40020800)
#define GPIOC_ODR *((int*)0x40020814)

#define ADC_SQR3 *((int*)0x40012034)
#define ADC_CR2 *((int*)0x40012008)
#define ADC_SR *((int*)0x40012000)
#define ADC_DR *((int*)0x4001204C)
	
int LM_35;
void GPOIC_Init(void)
{
	RCC_AHB1ENR |=(0x01<<2);
	while(!(RCC_AHB1ENR & 0x4));
}
void ADC_Init(void)
{
	RCC_APB2ENR |=(0x01<<8);
	while(!(RCC_APB2ENR & (0x01<<8)));
}


void GPIOC_Config(void)
{
	GPIOC_MODE &= 0xFFFFFFF3;
	GPIOC_MODE |= 0x0000000C;
}

void ADC_Config(void)
{
	ADC_SQR3 &= 0xFFFFFFE0; // clear the 4-0 bit positions
	ADC_SQR3 |= 0x0000000A; //Load “1011” (channel no 11) in to 4-0 bit fields in ADC_SQR3 register.


	ADC_CR2 |= (0x01<<10); //Set 10th bit (EOCS) in ADC_CR2 to select End of Conversion.
	ADC_CR2 |= (0x01<<0);  //Set 0th bit ADC_CR2 to enable ADC
}

int Temperature()
{
		ADC_CR2 |=(0x01<<30);
		while(!(ADC_SR & 0x02));
		LM_35=ADC_DR;

	
		return LM_35;
}


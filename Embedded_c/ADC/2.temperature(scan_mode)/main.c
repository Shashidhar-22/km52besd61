#define NVIC_ISER0 *((int*)0xE000E100)

#define STK_CTRL *((int*)0xE000E010)
#define STK_LOAD *((int*)0xE000E014)
#define STK_VAL *((int*)0xE000E018)

#define  RCC_AHB1ENR *((int*) 0x40023830)
#define RCC_APB2ENR *((int*) 0x40023844)
#define RCC_ADC1 *((int*) 0x4001 20004)	
#define GPIOC_MODE *((int*) 0x40020800)
#define  RCC_APB2 *((int*) 0x40012000)
	
#define ADC_SQR1 *((int*) 0x4001202C)	
#define  ADC_SMPR1 *((int*) 0x4001200C)	
#define ADC_SQR3 *((int*) 0x40012034)	
#define ADC_CR1 *((int*) 0x40012004)	
#define ADC_CR2 *((int*) 0x40012008)
#define ADC_DR *((int*) 0x4001204C)
#define  ADC_SR *((int*) 0x40012000)

	
//initilization and configur

	void GPIOC_init(void) 
	{
		 RCC_AHB1ENR |=(0x1<<2);  			//set RCC clock to enable AHB1ENR     
		while(!(RCC_AHB1ENR & 0x04));		//wait untill 
		GPIOC_MODE &= 0xFFFFFFF0;       //clear mode reg for pc 0 and 1 bit
		GPIOC_MODE |= 0x0000000F;		    //load 1,1 in pc 0 and 1 bit for Temperature sensor and ADC
	}
	void ADC(void)
	{
		RCC_APB2ENR |=(0x1<<8);						//RCC enable to APB2 bus for ADC1 enable bit no 8
		while(!(RCC_APB2ENR & 0x1<<8));		//wait untill set
		ADC_SMPR1 |= 0x70;								//set simple time 480 cycles in sample register  SMP11
		ADC_SQR1 |= (0x100000);						// because 2 conversions
		ADC_SQR3 |= 0x16A;		      			//load 01011 to 0-4 bits and 01010 to 9-5 bits.
		ADC_CR1 &=~(0x03<<24);						//load 00 for 12 bit in 24,25 position to set resoulation
		ADC_CR1 |=(0x1<<5);                
		ADC_CR2  |= 0x401;								// set EOCS and ADON bit no 10,1;		
		STK_CTRL |= 0x07;									//hardware interrupt
		STK_VAL  = 0x123;										// load any value
		NVIC_ISER0 |= (0x1<<18);           //NVIC 18 th position set
		ADC_CR1 |=(0x01<<8);								// enable 8th bit for scan mode
	}
	
	void KM_mdelay(int x)
{
	STK_LOAD =16000*x;				           //loading the value
	STK_VAL=0x013;
	while((STK_CTRL &(0x1<<16)) == 0); //checking if the value is 0 or not
 }

	int potentio,Temp,vsense,temperature;
	int main()
	{
		GPIOC_init();
		ADC();
		while(1)
		{
				ADC_CR2 |=(0x01<<30);				  //start conversion set bit 30 
				//KM_mdelay(100);					 					//delay to watch
				__wfi();
		}
	}
				//	while(!(ADC_SR & (0x1<<1))){;}	//	status reg set 1st bit
	void ADC_IRQHandler (void)
	{
				//while(!(ADC_SR & (0x1<<1))){;}	//	status reg set 1st bit
				temperature=ADC_DR;						//store in variable
				vsense=((temperature/4096)*3.3);
				Temp=((vsense-0.75)*0.01)+25;
				potentio=ADC_DR;
				//ADC_CR2 &=(~(0x1<<30));				//clear off
		}
		
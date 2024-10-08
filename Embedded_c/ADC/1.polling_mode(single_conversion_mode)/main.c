#define STK_CTRL *((int*)0xE000E010)
#define STK_LOAD *((int*)0xE000E014)
#define STK_VAL *((int*)0xE000E018)

#define  RCC_AHB1ENR *((int*) 0x40023830)
#define RCC_APB2ENR *((int*) 0x40023844)
#define RCC_ADC1 *((int*) 0x4001 20004)	
#define GPIOC_MODE *((int*) 0x40020800)
#define  RCC_APB2 *((int*) 0x40012000)
	
#define  ADC_SMPR1 *((int*) 0x4001200C)	
#define ADC_SQR3 *((int*) 0x40012034)	
#define ADC_CR1 *((int*) 0x40012004)	
#define ADC_CR2 *((int*) 0x40012008)
#define ADC_DR *((int*) 0x4001204C)
#define  ADC_SR *((int*) 0x40012000)

	
//initilization and configur

	void GPIOC_init(void) 
	{
		 RCC_AHB1ENR |=(0x1<<2);  			//set RCC clock to enable AHBENR     
		while(!(RCC_AHB1ENR & 0x04));		//wait untill 
		GPIOC_MODE &= 0xFFFFFFF3;       //clear mode reg for pc 1 bit
		GPIOC_MODE |= 0x0000000C;		    //load 11 in pc 1 bit for ADC
	}
	void ADC(void)
	{
		RCC_APB2ENR |=(0x1<<8);						//RCC enable to APB2 bus for ADC1 enable bit no 8
		while(!(RCC_APB2ENR & 0x1<<8));		//wait untill set
		ADC_SMPR1 |= 0x70;								//set simple time 480 cycles in sample register  SMP11
		ADC_SQR3 |= (0x0000000B);		      //load 01011 from 0-4 bits
		ADC_CR1 &=~(0x03<<24);						//load 00 for 12 bit in 24,25 position to set resoulation
		ADC_CR2  |= 0x401;								// set EOCS and ADON bit no 10,1;		
		STK_CTRL |= 0x05;
	}
	
	void KM_mdelay(int x)
{
 STK_LOAD =16000*x;				           //loading the value
	STK_VAL=0x013;
	while((STK_CTRL &(0x1<<16)) == 0); //checking if the value is 0 or not
 }
	
	int potentio;
	int main()
	{
		GPIOC_init();
		ADC();
		while(1)
		{
			ADC_CR2 |=(0x01<<30);				  //start conversion set bit 30 
			while(!(ADC_SR & (0x1<<1))){;}	//	status reg set 1st bit
				potentio=ADC_DR;						//store in variable
			ADC_CR2 &=(~(0x1<<30));				//clear off
			KM_mdelay(100);								//delay to watch	
		}
	}
		
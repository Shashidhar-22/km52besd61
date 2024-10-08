#define RCC_AHB1ENR *((int*)0x40023830)
#define GPIOB_MODE *((int*)0x40020400)
#define GPIOB_ODR *((int*)0x40020414)
	void GPIO_init(void)
	{
	 RCC_AHB1ENR |= (0x1<<1);   //set 1st bit to enable port B clock
		while(!(RCC_AHB1ENR & 0x2))
		{
			;
		}
	}
	void RED_LED_config (void)
	{
		GPIOB_MODE &= 0xF3FFFFFF; //clear 27-26 bits
		GPIOB_MODE |= 0x04000000;  //load 0,1 into 27-26 dir fields to congiger PB 13 as output mode
	}
	void Delay (void)  //softwaredelay
	{
		int i;
		for(i=0;i<150000;i++)
		{
			;
		}
	}
	
	int main()
	{
		//initialisation phase
		 GPIO_init();
		//configuration phase
		RED_LED_config();
		//operation phase
		while(1)
		{
			GPIOB_ODR &= ~ (0x1<<13); //RED LED is ON
			Delay();										//100 m sec Delay
			GPIOB_ODR |= (0x1<<13);  //RED LED is OFF
			Delay();        //100 m sec Delay
		}
		return 0;
	}
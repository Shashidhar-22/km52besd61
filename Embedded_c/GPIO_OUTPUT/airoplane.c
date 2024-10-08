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
	void Green_LED_REDLED_config (void)
	{
		GPIOB_MODE &= 0xC3FFFFFF; //clear 29-28,27-26 bits
		GPIOB_MODE |= 0x14000000;  //load 0,1 0,1 into  29-28 27-26  dir fields to congiger PB 13 as output mode
	}
	void Delay (int x)  //softwaredelay
	{
		int i;
		x= x * 1660;
		for( i=0;i<x;i++)
		{
			;
		}
	}
	int main()
	{
		//initialisation phase
		 GPIO_init();
		//configuration phase
		Green_LED_REDLED_config();
		//operation phase
		while(1)
		{
			GPIOB_ODR &= ~ (0x1<<14); //GREEN LED is ON
			Delay(50);										//50 m sec Delay
			GPIOB_ODR |= (0x1<<14);  //GREEN LED is OFF
			Delay(50);        //50 m sec Delay
			GPIOB_ODR &= ~ (0x1<<14); //GREEN LED is ON
			Delay(50);                //50 m sec Delay
			GPIOB_ODR |=  (0x1<<14); //GREEN LED is ON
			Delay(150);              //150 LED is OFF
			GPIOB_ODR &= ~ (0x1<<13); //RED LED is ON
			Delay(50);										//50 m sec Delay
			GPIOB_ODR |= (0x1<<13);  //RED LED is OFF
			Delay(250);							//250 m sec Delay
			GPIOB_ODR &= ~ (0x1<<13); //RED LED is ON 
			Delay(50);										//50 m sec Delay
			GPIOB_ODR |= (0x1<<13);  //RED LED is OFF
			Delay(500);               // 500 m sec Dealay 
		}
		return 0;
	}
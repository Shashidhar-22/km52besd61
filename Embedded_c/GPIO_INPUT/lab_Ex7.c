#define RCC_AHB1ENR *((int*)0x40023830)
#define GPIOB_MODE *((int*)0x40020400)
#define GPIOB_ODR *((int*)0x40020414)

#define GPIOC_MODE *((int*)0x40020800)
#define GPIOC_IDR *((int*)0x40020810)
#define GPIOC_PUPDR *((int *)0x4002080C)
void GPIOB_init(void)
	{
	 RCC_AHB1ENR |= (0x1<<1);   //set 1st bit to enable port B clock
		while(!(RCC_AHB1ENR & 0x2))
		{
			;
		}
	}
	void GPIOC_init(void)
	{
	 RCC_AHB1ENR |= (0x1<<2);   //set 2nd bit to enable port c clock
		while(!(RCC_AHB1ENR & 0x4))
		{
			;
		}
	}
	void BUZZER_config (void)
	{
		GPIOB_MODE &= 0xF1FFFFFF; //clear 27-26 bits
		GPIOB_MODE |= 0x01000000;  //load 0,1 into 27-26 dir fields to congiger PB 13 as output mode
	}
	void SWITCH_config (void)
	{
		GPIOC_MODE &=  0xFFCFFFFF;
		GPIOC_PUPDR &= 0xFFCFFFFF;  //clear  21-20 bits
		GPIOC_PUPDR |= 0x00100000;  //load 0,1 into 21-20 dir fields to congiger PB 10 as input mode
	}
	void Delay (int x)  //softwaredelay
	{
		int i;
		x=x*2500;
		for(i=0;i<x;i++)
		{
			;
		}
	}
	int main()
	{
		//initialisation phase
		 GPIOB_init();
		 GPIOC_init();
		//configuration phase
		BUZZER_config();
		SWITCH_config();
		//operation phase
		GPIOB_ODR &= ~(0x1<<12);  //buzzer is OFF
		while(1)
		{
			if(!(GPIOC_IDR &= (0x1<<10)))
			{
				GPIOB_ODR |= (0x1<<12); //buzzer is ON
				Delay(250);
				GPIOB_ODR &= ~(0x1<<12); //buzzer is off
			}
		}
		return 0;
	}
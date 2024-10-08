#define RCC_AHB1ENR *((int*)0x40023830)
#define GPIOC_MODE *((int*)0x40020800)
#define GPIOC_IDR *((int*)0x40020810)
#define GPIOC_PUPDR *((int *)0x4002080C)
	void GPIOC_init(void)
	{
	 RCC_AHB1ENR |= (0x1<<2);   //set 2nd bit to enable port c clock
		while(!(RCC_AHB1ENR & 0x4));
	}
	void SWITCH_config (void)
	{
		GPIOC_MODE &=  0xFFCFFFFF;
		GPIOC_PUPDR &= 0xFFCFFFFF;  //load 0,1 into 21-20 dir fields to congiger PB 10 as input mode
		GPIOC_PUPDR |= 0x00100000;
	}
	void delay(int a)
	{
		int i;
		a=a*2500;
		for(i=0;i<a;i++);
	}
	int count;
	int main()
	{
		//initialisation phase
		 GPIOC_init();
		//configuration phase
		SWITCH_config();
		//operation phase
		while(1)
		{
			if(!(GPIOC_IDR &= (0x1<<10)))
			{
				count++;
				delay(1000);
			}
		}
	}
		
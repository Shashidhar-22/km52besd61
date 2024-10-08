#define RCC_AHB1ENR *((int*)0x40023830)
#define GPIOB_MODE *((int*)0x40020400)
#define GPIOB_ODR *((int*)0x40020414)

#define GPIOC_MODE *((int*)0x40020800)
#define GPIOC_IDR *((int*)0x40020810)
#define GPIOC_PUPDR *((int*)0x4002080C)

#define RCC_APB2ENR *((int*)0x40023844)
#define SYSCONFIG_EXTCR3 *((int*)0x40013810)
#define EXTI_FTSR *((int*)0x40013c0c)
#define EXTI_IMR *((int*)0x40013c00)
#define EXTI_PR *((int*)0x40013c14)
#define NVIC_ISER1 *((int *)0xE000E104)
#define DBGMCU_CR  *((int *)0xE0042004)

//initilization

void GPIOB_init(void)
{
	RCC_AHB1ENR |=(0x1<<1);    //set 1st bit to enable port b
	while(!(RCC_AHB1ENR & 0x2));
}
void GPIOC_init(void)
	{
	 RCC_AHB1ENR |= (0x1<<2);   //set 2nd bit to enable port c clock
		while(!(RCC_AHB1ENR & 0x4));
	}
	void SYSCONFIG(void)
	{
	 RCC_APB2ENR |= (0x1<<14);  
		while(!(RCC_APB2ENR & 0x4000));  //set 14th bit to enable p 10 to SYSCONFIG
	}
	//DEBUG sleep mode
	void DEBUG_sleepenable(void)
	{
		DBGMCU_CR |=(0x1<<0);   //set 0TH bit to enable deep sleep mode
	}
	
	//configuration mode
	
	void RED_LED_config (void)
	{
		GPIOB_MODE &= 0xF3FFFFFF; //clear 27-26 bits
		GPIOB_MODE |= 0x04000000;  //load 0,1 into 27-26 dir fields to congiger PB 13 as output mode
	}
	
	void SWITCH_ENT_config (void)
	{
		GPIOC_MODE &= 0xFFCFFFFF;   //clear 21-20 bits
		GPIOC_PUPDR &= 0xFFCFFFFF;		// clear 21-20 bits
		GPIOC_PUPDR |= 0x00100000;		//load  '01' into 21-20 bits
	}
	
	void SYS_config(void)
	{
		SYSCONFIG_EXTCR3 &= 0xFFFFF0FF;  //clear 11-8 bits
		SYSCONFIG_EXTCR3 |= 0x00000200;  //load 0010 into 11-10-9-8 bits
	}
	
	  void EXTI (void)
		{
				EXTI_FTSR &= 0xFFFFF0FF; //clear 10th bit;
				EXTI_FTSR |= 0x00000400;  //load 1 to set 10th bit;
				EXTI_IMR &= 0xfffffbff;   //clear 1oth bit;
				EXTI_IMR  |=0x00000400;			//load 1  to set 10th bit;
		}
		void NVIC_config()
		{
			NVIC_ISER1 |= (0x1<<8);
		}
	
	//operation phase
		int counter=0;
		int main()
		{
			GPIOB_init();
			GPIOC_init();
			SYSCONFIG();
			DEBUG_sleepenable();
			
	//configuration phase
			
			RED_LED_config ();
			SWITCH_ENT_config();
			SYS_config();
			EXTI();
			NVIC_config();
			
	//opertion phase
		
			while(1)
			{
				__wfi();
			}
		}
		void EXTI15_10_IRQHandler(void)
		{
		if (EXTI_PR & (0x1<<10))   //check 1oth bit
		{
			GPIOB_ODR ^=(0x1<<13); //toggle red led
			counter++;
			EXTI_PR |=(0x1<<10);
		}
	}	
			
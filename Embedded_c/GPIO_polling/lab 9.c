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
#define NVIC_ISER0 *((int *)0xE000E100)
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
	
	void REDGREEN_LED_config (void)
	{
		GPIOB_MODE &= 0xC3FFFFFF; //clear 27-26 ,29-28  bits
		GPIOB_MODE |= 0x14000000;  //load 0,1 into 29-28-27-26 dir fields to congiger PB 13 as output mode
	GPIOB_ODR |=(0x1<<13);
		GPIOB_ODR |=(0x1<<14);
	}
	
		
	void SWITCH_config (void)
	{
		GPIOC_MODE &= 0xFFCFFFFF;   //clear 21-20 bits
		GPIOC_PUPDR &= 0xFFF0FFFF;		// clear 19,18,17,16 bits
		GPIOC_PUPDR |= 0x00050000;		//load  '01' into 19,18,17,16 bits
	}
	
	void SYS_config(void)
	{
		SYSCONFIG_EXTCR3 &= 0xFFFFFF00;  //clear 7 to 0 bits
		SYSCONFIG_EXTCR3 |= 0x00000022;  //load 0010 into 7 to 0 bits
	}
	
	  void EXTI (void)
		{
				EXTI_IMR &= 0xFFFFFCFF; //clear 9,8 bit;
				EXTI_IMR |= 0x00000300;  //load 1 to set 9,8 bit;
				EXTI_FTSR &= 0xfffffCff;   //clear 1oth bit;
				EXTI_FTSR |=0x00000300;			//load 1  to set 10th bit;
		}
		void NVIC_config()
		{
			NVIC_ISER0 |= (0x1<<23);
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
			
			REDGREEN_LED_config ();
			SWITCH_config();
			SYS_config();
			EXTI();
			NVIC_config();
			
	//opertion phase
		
			while(1)
			{
				__wfi();
			}
		}
		void EXTI9_5_IRQHandler (void)
		{
		if (EXTI_PR & (0x1<<8))   //check 8 th bit
		{
			GPIOB_ODR &=~(0x1<<13); // red led ON
			EXTI_PR |= (0x1<<8);		//set 1 in 8th bit field to disable PR.
			counter++;
		}
			if(EXTI_PR & (0x1<<9))  //check 9 th bit
			{
			GPIOB_ODR &=~(0x1<<14);	//green led ON
				EXTI_PR |= (0x1<<9);	//set "1" in 9th bit field to disable PR
			
		}
	}	
		
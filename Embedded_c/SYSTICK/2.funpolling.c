#define RCC_AHB1ENR *((int*)0x40023830)
#define GPIOB_MODE *((int*)0x40020400)
#define GPIOB_ODR *((int*)0x40020414)

#define STK_CTRL *((int*)0xE000E010)
#define STK_LOAD *((int*)0xE000E014)
#define STK_VAL *((int*)0xE000E018)

void GPIO_init(void)
	{
	 RCC_AHB1ENR |= (0x1<<1);   //set 1st bit to enable port B clock
		while(!(RCC_AHB1ENR & 0x2));
	}
	void STK_init(void)
	{
		STK_CTRL |=0x05;
		STK_VAL=0x0123;   //give any value 
		}
	
	void KM_mdelay(int x)
{
//int i;
//for(i=0;i<x;i++)		//to iterate that many times
 //{
 STK_LOAD =16000*x;				//loading the value
	while((STK_CTRL &(0x1<<16)) == 0); //checking if the value is 0 or not
 //}
}

void KM_udelay(int x)
{
//int i;
//for(i=0;i<x;i++)		//to iterate that many times
// {
 STK_LOAD =160000*x;				//loading the value
	while((STK_CTRL &(0x1<<16)) == 0); //checking if the value is 0 or not
 }

	void RED_LED_config (void)
	{
		GPIOB_MODE &= 0xF3FFFFFF; //clear 27-26 bits
		GPIOB_MODE |= 0x04000000;  //load 0,1 into 27-26 dir fields to congiger PB 13 as output mode
	}
	
	int main()
	{
		//initialisation phase
		GPIO_init();
		STK_init();
		//configuration phase
		RED_LED_config();
		//operation phase
		while(1)
		{
			KM_mdelay(100);
			GPIOB_ODR ^= (0x1<<13); //RED LED is TOGGLE
			KM_udelay(10);
		}
	}

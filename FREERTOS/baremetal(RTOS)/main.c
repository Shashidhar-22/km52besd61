#define RCC_AHB1ENR *((int*)0x40023830)
#define GPIOB_MODE *((int*)0x40020400)
#define GPIOB_ODR *((int*)0x40020414)

#define STK_CTRL *((int*)0xE000E010)
#define STK_LOAD *((int*)0xE000E014)
#define STK_VAL *((int*)0xE000E018)


	void GPIO_init(void)
	{
	 RCC_AHB1ENR |= (0x1<<1);   //set 1st bit to enable port B clock
		while(!(RCC_AHB1ENR & 0x2))
		{
			;
		}
	}
	
	void STK_init(void)
	{
		STK_CTRL |=0x05;
		STK_LOAD = 1600000;
		STK_VAL=0x013;
	}

	
	void Green_LED_RED_LED_config (void)
	{
		GPIOB_MODE &= 0xC3FFFFFF; //clear 29-28,27-26 bits
		GPIOB_MODE |= 0x14000000;  //load 0,1 0,1 into  29-28 27-26  dir fields to congiger PB 13 as output mode
	}
	
	
	int redled()
		{
			GPIOB_ODR ^=  (0x1<<13); //RED LED is ON 
			while((STK_CTRL &(0x1<<16)) == 0)   //check if vlaue is 0 or not
			{
				;
			}

			GPIOB_ODR |= (0x1<<13);  //RED LED is OFF
			while((STK_CTRL &(0x1<<16)) == 0)   //check if vlaue is 0 or not
			{
				;
			}

			greenled();
		}
		
		int greenled()
		{
			GPIOB_ODR ^=  (0x1<<14); //GREEN LED is ON
			while((STK_CTRL &(0x1<<16)) == 0)   //check if vlaue is 0 or not
			{
				;
			}
			
			GPIOB_ODR |= (0x1<<14);  //GREEN LED is OFF
			
			while((STK_CTRL &(0x1<<16)) == 0)   //check if vlaue is 0 or not
			{
				;
			}
		}
		
	//int (*fun_pointer[2])(void)={redled,greenled};//array of fun pointer
	int (*fun_pointer)(void); //function pointer
	int main()
	{
		//initialisation phase
		 GPIO_init();
			STK_init();
		//configuration phase
		Green_LED_RED_LED_config();
		//operation phase
		while(1)
		{
			//fun_pointer[0]();
			fun_pointer=redled;//assigning
			fun_pointer();//calling
			  
		}
		return 0;
	}
#define RCC_APB1ENR *((int*)0x40023840)
#define RCC_AHB1ENR *((int*)0x40023830)
#define GPIOA_MODE *((int*)0x40020000)
#define GPIOA_AFRL *((int*)0x40020020)
	
#define GPIOB_MODE *((int*)0x40020400)
#define GPIOB_ODR *((int*)0x40020414)
#define GPIOC_MODE *((int*)0x40020800)
#define GPIOC_IDR *((int*)0x40020810)
#define GPIOC_PUPDR *((int*)0x4002080C)

#define USART2_BRR *((int*)0x40004408)
#define USART2_CR1 *((int*)0x4000440C)
#define USART2_SR  *((int*)0x40004400)
#define USART2_DR  *((int*)0x40004404)
	
void	USART2_outchar(unsigned char c);
unsigned char USART2_inchar();

	void init(void)
	{
		RCC_APB1ENR |= (1<<17);             //unable clock to UART2
		while(!(RCC_APB1ENR & 1<<17));			//wait untill set
		
		RCC_AHB1ENR |= (0x1<<1);              //set 1st bit to enable port B clock
		while(!(RCC_AHB1ENR & 0x2));
			
		RCC_AHB1ENR |= (0x1<<2);             //set 2nd bit to enable port B clock
		while(!(RCC_AHB1ENR & 0x4));
			
		RCC_AHB1ENR |= (0x01);							//unable clock to port a
		while (!(RCC_AHB1ENR & 0x01));			//set untill that
	}
	
	void config(void)
	{
		RCC_AHB1ENR |= (0x01);							//unable clock to port a
		while (!(RCC_AHB1ENR & 0x01));			//set untill that
		GPIOA_MODE &= 0xFFFFFF0F;        //clear PA2,PA3
		GPIOA_MODE |= 0xA0;								//load 1,0 to PA2 1,0 to PA3.,	 
		GPIOA_AFRL  &= 0xFFFF00FF;				//clear
		GPIOA_AFRL  |= 0x00007700;				//enable UART2 Tx,UART2 Rx functionality using mux register load 7 in GPIO PORT_A_AFRL. 
		USART2_BRR  |=0x683;							// for 104 hexa is 68 and 0.1875*16 = 3 gives 0x683 
		USART2_CR1 |= 0x0000200c;         //enable  reciever(2) ,transmitter(3),USART(13).
		
		GPIOB_MODE &= 0xF3FFFFFF; //clear 27-26 bits     for RED LED
		GPIOB_MODE |= 0x04000000;  //load 0,1 into 27-26 dir fields to congiger PB 13 as output mode
		
		GPIOB_MODE &= 0xCFFFFFFF; //clear 29-28 bits		for GREEN LED
		GPIOB_MODE |= 0x10000000;  //load 0,1 into 29-28 dir fields to congiger PB 14 as output mode
	
		GPIOC_MODE &=  0xFFFCFFFF;   //clear
		GPIOC_PUPDR &= 0xFFFCFFFF;  
		GPIOC_PUPDR |= 0x00010000;		//load 0,1 into 21-20 dir fields to congiger PB 10 as input mode    for UP switch
	
		GPIOC_MODE &=  0xFFF3FFFF;		//clear
		GPIOC_PUPDR &= 0xFFF3FFFF;  
		GPIOC_PUPDR |= 0x00040000;		//load 0,1 into 21-20 dir fields to congiger PB 10 as input mode    for DOWN switch
	}
	
		
		void UART2_OutChar(unsigned char c)
	{
	USART2_SR |=(0x1<<7);
	while(!(USART2_SR &(0x1<<7)));
	USART2_DR =c;
	}
	unsigned char UART2_InChar(void)
	{
	USART2_SR |=(0x1<<5);
	while(!(USART2_SR &(0x1<<5)));
	return USART2_DR;
	}
	
	unsigned char S;
	int main()
	{
		//initilization phase
		init();
		
		// configuration phase
		config();
		
		//operation phase
		GPIOB_ODR |= (0x1<<13);  //RED LED is OFF
		GPIOB_ODR |=(0x1<<14);	//GREEN LED  is OFF
		
		while(1)
		{
			
	if(!(GPIOC_IDR & (0x1<<8)))
	{
	if(USART2_SR & (0x1<<7))
		{
			UART2_OutChar('R');
	}
}
	if(!(GPIOC_IDR & (0x1<<9)))
		{
			if(USART2_SR & (0x1<<7))
				{
					UART2_OutChar('G');
		}
}
	if(USART2_SR & (0x1<<5))
		{
			if('R'==UART2_InChar())
				{
					GPIOB_ODR &=(~(0X1<<13));			//RED LED ON
	}				
	if('G'==UART2_InChar())
			{
	GPIOB_ODR &=(~(0X1<<14));							//GREEN LED  ON
		}
	}
}
}
		


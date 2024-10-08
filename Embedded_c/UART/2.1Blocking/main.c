#define RCC_APB1ENR *((int*)0x40023840)
#define RCC_AHB1ENR *((int*)0x40023830)
#define GPIOA_MODE *((int*)0x40020000)
#define GPIOA_AFRL *((int*)0x40020020)
#define USART2_BRR *((int*)0x40004408)
#define USART2_CR1 *((int*)0x4000440C)
#define USART2_SR  *((int*)0x40004400)
#define USART2_DR  *((int*)0x40004404)

	void inti(void)
	{
		RCC_APB1ENR |= (1<<17);             //unable clock to UART2
		while(!(RCC_APB1ENR & 1<<17));			//wait untill set
	
		RCC_AHB1ENR |= (1<<0);							//unable clock to port a
		while (!(RCC_AHB1ENR & 0x01));			//set untill that
	}
	
	void config(void)
	{
		GPIOA_MODE &= 0xFFFFFF0F;        //clear PA2,PA3
		GPIOA_MODE |= 0xA0;								//load 1,0 to PA2 1,0 to PA3.,	 
		GPIOA_AFRL  &= 0xFFFF00FF;				//clear
		GPIOA_AFRL  |= 0x00007700;				//enable UART2 Tx,UART2 Rx functionality using mux register load 7 in GPIO PORT_A_AFRL. 
		USART2_BRR  |=0x683;							// for 104 hexa is 68 and 0.1875*16 = 3 gives 0x683 
		USART2_CR1 |= 0x0000200c;         //enable  reciever(2) ,transmitter(3),USART(13).
	}
	
	unsigned char s;
	void USART2_outchar(unsigned char c)
	{
		USART2_SR |= (0x1<<7);
		while(!(USART2_SR  & 0x1<<7));
		USART2_DR = c;
	}
	
	unsigned char USART2_inchar(void)
	{
		USART2_SR |= (0x1<<5);
		while((USART2_SR  & 0x1<<5));
	return USART2_DR;
	}
	
	int main()
	{
		inti();
		config();
		while(1)
		{
			USART2_outchar('G');
			s=USART2_inchar();
			USART2_DR;
		}
	}
	
#define RCC_APB2ENR *((int*)0x40023844)
#define RCC_AHB1ENR *((int*)0x40023830)

#define STK_CTRL *((int*)0xE000E010)
#define STK_LOAD *((int*)0xE000E014)
#define STK_VAL *((int*)0xE000E018)
	
#define GPIOC_MODE *((int*)0x40020800)
#define GPIOC_AFRL *((int*)0x40020044)
	
#define USART6_BRR *((int*)0x40011408)
#define USART6_CR1 *((int*)0x4001140C)
#define USART6_CR2 *((int*)0x40011410)	
#define USART6_SR  *((int*)0x40011400)
#define USART6_DR  *((int*)0x40011404)
	
	void STK_init(void)
	{
		STK_CTRL |=0x05;
		STK_VAL=0x0123;   										//give any value 
		}
	
	void KM_mdelay(int x)
	{
	STK_LOAD =16000*x;												//loading the value
	while((STK_CTRL &(0x1<<16)) == 0); 			//checking if the value is 0 or not
	}

	void inti(void)
	{
		RCC_APB2ENR |= (1<<5);             //unable clock to UART2
		while(!(RCC_APB2ENR & 1<<5));			//wait untill set
	
		RCC_AHB1ENR |= (1<<2);							//unable clock to port a
		while (!(RCC_AHB1ENR & 1<<2));			//set untill that
	}
	
	void config(void)
	{
		GPIOC_MODE &= 0xFFFF0FFF;  						//ALternate Function Enabled_PC-6,PC-7
		GPIOC_MODE |= 0x0000A000;
		GPIOC_AFRL &= 0x00FFFFFF;
		GPIOC_AFRL |= 0x88000000; 					//MUX-7 loaded into Alternative register
		USART6_BRR |= 0x8B;									// 115200   8NI 
		USART6_CR1 |= 0x0000200c;       			//enable  reciever(2) ,transmitter(3),USART(13).
	}

	unsigned char s;
	
	void USART6_outchar(char str[])
	{
		int i=0;
		for(i=0;str[i];i++)
		{
		USART6_SR |= (0x1<<7);
		while(!(USART6_SR  & 0x1<<7));
		USART6_DR = str[i];
		KM_mdelay(1);
	}
}
		void wifi_init(void)
 {
	USART6_outchar("AT\r\n");
	KM_mdelay(500);
	USART6_outchar("AT+RST\r\n");
	KM_mdelay(500);
	USART6_outchar("AT+CWMODE=3\r\n");
	KM_mdelay(500);
	USART6_outchar("AT+CWJAP=\"KM-2.4G\",\"9963111084\"\r\n");
	KM_mdelay(500);
	USART6_outchar("AT+CIFSR\r\n");
	KM_mdelay(500);
	USART6_outchar("AT+CIPMUX=0\r\n");
	KM_mdelay(500);
	USART6_outchar("AT+CWLAP\r\n");
	KM_mdelay(500);
	USART6_outchar("AT+CIPMODE=0\r\n");
	KM_mdelay(500);
}
	int main()
	{
		inti();
		STK_init();
		config();
		wifi_init();
		
		while(1)
{
		USART6_outchar("AT+CIPSTATUS\r\n");
		KM_mdelay(500);
		USART6_outchar("AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n");
		KM_mdelay(500);
		USART6_outchar("GET /page.php?temp=25&hum=10&dev=61\r\n\r\n");
		KM_mdelay(500);
		USART6_outchar("AT+CIPSEND=40\r\n");
		KM_mdelay(500);
		USART6_outchar("AT+CIPCLOSE\r\n");
		KM_mdelay(500);
}
}
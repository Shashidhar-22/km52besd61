#define RCC_AHB1ENR *((int*)0x40023830)
#define RCC_APB1ENR *((int*)0x40023840)
#define DBGMCU_CR *((int*)0xE0042004)
#define NVIC_ISER1 *((int*)0xE000E104)
      
#define GPIOA_MODE *((int*)0x40020000)
#define GPIOA_AFRL *((int*)0x40020020)
      
#define USART2_BRR *((int*)0x40004408)
#define USART2_CR1 *((int*)0x4000440C)
#define USART2_SR *((int*)0x40004400)
#define USART2_DR *((int*)0x40004404)
      
#define STK_CTRL *((int*)0xE000E010)
#define STK_LOAD *((int*)0xE000E014)
#define STK_VAL *((int*)0xE000E018)

unsigned char out;
void Delay_mSec(int x)
{
      STK_CTRL |= 0x05;
      STK_LOAD |= 16000*x;
      STK_VAL |=0x123;
      while((STK_CTRL & (0x01<<16))==0);
}
void GPIOA_Init(void)
{
      RCC_AHB1ENR |= (0x01<<0);
      while(!(RCC_AHB1ENR & 0x01));
}
void UART2_Init(void)
{
      RCC_APB1ENR |= (0x01<<17);
      while(!(RCC_APB1ENR & (0x01<<17)));
}
void DBG_SLEEP_Init(void)
{
      DBGMCU_CR |=(0x1<<0);
      while(!(DBGMCU_CR & 0x1));
}

void config(void)
	{
		GPIOA_MODE &= 0xFFFFFF0F;        //clear PA2,PA3
		GPIOA_MODE |= 0xA0;								//load 1,0 to PA2 1,0 to PA3.,	 
		GPIOA_AFRL  &= 0xFFFF00FF;				//clear
		GPIOA_AFRL  |= 0x00007700;				//enable UART2 Tx,UART2 Rx functionality using mux register load 7 in GPIO PORT_A_AFRL. 
		USART2_BRR  |=0x683;							// for 104 hexa is 68 and 0.1875*16 = 3 gives 0x683 
		USART2_CR1 |= 0x0000200c;         //enable  reciever(2) ,transmitter(3),USART(13).
		NVIC_ISER1 |= (0x01<<6);
}

void UART2_OutChar(unsigned char ch)
{
      //UART_SR |= (0x01<<7);
      while(!(USART2_SR & (0x01<<7)));
      USART2_DR= ch;
}
unsigned char UART2_InChar(void)
{
      while(!(USART2_SR & (0x01<<5)));
      return USART2_DR;
}
int main()
{
      // Initilization Phase
      GPIOA_Init();
      UART2_Init();
      
      //Configuraton Phase
      config();
      
      //Operation Phase
      while(1)
      {
            __wfi();
	
				Delay_mSec(500);				
      }
}
		void USART2_IRQHandler(void)
{
      if(USART2_SR & (0x01<<5))
       out =USART2_DR;
}
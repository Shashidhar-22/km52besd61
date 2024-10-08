#include"header.h"

#define RCC_AHB1ENR *((int *)0x40023830)
#define RCC_APB2ENR *((int *)0x40023844)
	
#define GPIOC_MODER *((int *)0x40020800)
#define GPIOC_AFRL	*((int *)0x40020820)
	
#define UART6_BRR		*((int *)0x40011408)
#define UART6_CR1		*((int *)0x4001140C)
#define UART6_SR		*((int *)0x40011400)
#define UART6_DR		*((int *)0x40011404)
	
#define STK_CTRL		*((int *)0xE000E010)
#define STK_LOAD		*((int *)0xE000E014)
#define STK_VAL			*((int *)0xE000E018)
	


	
//Global variable
unsigned char ch;												


//GPIOA INITIALIZATION 
void GPIOA_INIT()
{
	RCC_AHB1ENR |=0x04;								//set clock for AHB1 bus GPIOA
	while(!(RCC_AHB1ENR & 0x04));			//check until clock is ON for AHB1ENR
	GPIOC_MODER&=~(0xF<<12);					// clear PC6 & PC7 ports in GPOIOC
	GPIOC_MODER |= (0xA<<12);				// set PA6 & PA7 in GPOIOC as a UART(load '10')
	GPIOC_AFRL &=~(0x88<<24);					//clear GPIOC_AFRL register port-6 and port-7 with '8'
	GPIOC_AFRL |=(0x88<<24);					//set GPIOA_AFRL register port-6 and port-7 with '8' as a alternate function
}

//UART1 CQNFIGURATION
void UART6_CONIF()
{
	RCC_APB2ENR |=(0x01<<5);					//set clock for USART1ENR register 
	while(!(RCC_APB2ENR & (0x01<<5)));		//check until clock is ON in APB2ENR
	UART6_BRR |= 0x8A;								//Set 115200 baud rate in BRR (0x89)
	UART6_CR1 &=~(0x200C);								//Clear 13th, 2nd and 3rd bits in CR1 register
	UART6_CR1 |=0x200C;								//Set 13th, 2nd and 3rd bits in CR1 register to enable USART 2 enable
}


//Transmit character
void UART6_OutChar (unsigned char TX)
{
	while(!(UART6_SR & (0x01<<7)));			//Read UART1_SR register and check 7th bit (TXE) value, If TXE=0, go to loop otherwise next statement
	UART6_DR = TX;									//Load input in to USART1_DR register
}



void outstring(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
		{
		UART6_OutChar(str[i]);					//Transmiting character
		}	
}
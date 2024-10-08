	
	#include<stdio.h> 
	#include<stdarg.h>
	
	#define RCC_APB1ENR *((int*)0x40023840)
	#define RCC_AHB1ENR *((int*)0x40023830)
	#define GPIOA_MODE *((int*)0x40020000)
	
	#define GPIOA_AFRL *((int*)0x40020020)
	#define UART2_BRR *((int*)0x40004408)
	#define UART2_CR1 *((int*)0x4000440C)
	#define UART2_SR  *((int*)0x40004400)
	#define UART2_DR  *((int*)0x40004404)
		
	//decrations
	void UART2_outchar (char c);
	unsigned char UART2_inchar (unsigned char c);
	void UART2_outstring(char str[]);
	void UART2_DEC(char str[]);
	void  UART2_HEX(char str[]);
	void UART2_OCT(char str[]);
	

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
		
		UART2_BRR  |=0x683;							// for 104 hexa is 68 and 0.1875*16 = 3 gives 0x683 
		UART2_CR1 |= 0x0000200c;         //enable  reciever(2) ,transmitter(3),USART(13).



	}
	
	unsigned char s;
	
	void UART2_outchar (char c)
	{
		UART2_SR |= (0x1<<7);
		while(!(UART2_SR &0x1<<7));
			UART2_DR = c;
	}
	
	
	unsigned char UART2_inchar ( unsigned char c)
	{
		int i;
		int b=1666;
		for(i=0; i<(b*100);i++)
	{
		if(!(UART2_SR &0x1<<5))
			return UART2_DR;
	}
}
	
	void UART2_outstring(char str[])
	{
		int i;
		for (i=0;str[i]!='\0';i++)
		{
			while(!(UART2_SR &0x1<<7));
			UART2_DR=str[i];
		}
	}
	
	
	void UART2_DEC(char str[])
	{	
	UART2_outstring(str);
	}
	
	void  UART2_HEX(char str[])
	{
		UART2_outstring(str);
	}
	
	void UART2_OCT(char str[])
	{
		UART2_outstring(str);
	}
	
	
	void Myprintf(char *,...); //Our printf function
	char* convert(unsigned int, int); //Convert integer number into octal, hex, etc.
	
	int main() 
	{ 
		inti();
		config();
		
		Myprintf(" Kernel Masters \n %d, %x, %o , %c ,%s",-10,10,10,'a',"kernal"); 
		

	return 0;
	}


	void Myprintf(char* format,...) 
	{ 
	char *traverse; 
	 int i; 
	char *s; 
	//Module 1: Initializing Myprintf's arguments 
	va_list arg; 
	va_start(arg, format); 
	for(traverse = format; *traverse != '\0'; traverse++) 
	{ 
	while( *traverse != '%' ) 
	{ 
	UART2_outchar(*traverse);
	traverse++; 
	} 
	traverse++;

	
	//Module 2: Fetching and executing arguments
	switch(*traverse) 
	{ 
	case 'c' : i = va_arg(arg,int); //Fetch char argument
	UART2_outchar(i);
	break; 
	case 'd' : i = va_arg(arg,int); //Fetch Decimal/Integer  argument
	
		if(i<0)
	{ 
	i = -i;
	UART2_outchar('-'); 
	} 
	UART2_outstring(convert(i,10));
	break; 
	case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
	UART2_outstring(convert(i,8));
	
	break; 
	case 's': s = va_arg(arg,char *); //Fetch string
	UART2_outstring(s); 
	break; 
	case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal 
	UART2_outstring(convert(i,16));
	break; 
	}
	}

	//Module 3: Closing argument list to necessary clean-up
	va_end(arg); 
	}
	
	
	char *convert(unsigned int num, int base) 
	{ 
	char Representation[]= "0123456789ABCDEF";
	char buffer[50]; 
	char *ptr; 
	ptr = &buffer[49]; 
	*ptr = '\0'; 
	do 
	{ 
	*--ptr = Representation[num%base]; 
	num /= base; 
	}
	while(num != 0); 
	return(ptr); 
	}



#include<string.h>

#define RCC_AHB1ENR *((int*) 0x40023830)
#define RCC_APB2ENR *((int*) 0x40023844)
#define GPIOC_MODE *((int*) 0x40020800)
#define GPIOC_AFRL *((int*) 0x40020820)
#define UART6_SR *((int *) 0x40011400)
#define UART6_DR *((int *) 0x40011404)
#define UART6_BRR *((int *) 0x40011408)
#define UART6_CR1 *((int *) 0x4001140C)
#define UART6_CR2 *((int *) 0x40011410)
#define STK_CTRL *((int*) 0xE000E010)
#define STK_LOAD *((int*) 0xE000E014)
#define STK_VAL *((int*) 0xE000E018)
#define DBGMCU_CR *((int*) 0xE0042004) //DBGMCU_CR |= (0x1);
	
char buff[5000];
int ret;

void STK_INIT(void)
{
STK_CTRL |= 0x5;
STK_VAL =0x123;
}

void Delay_ms(long double a)
{
STK_VAL =0;
STK_LOAD= (16000*a);
while(!(STK_CTRL & (0x1 <<16)));
}

void UART6_init(void)
{
RCC_AHB1ENR |= (0x1<<2); 						//set 2st bit to enable PORTC clock.
while(!(RCC_AHB1ENR & 0x4)); 				//wait until PORTC clock is set.
RCC_APB2ENR |=(0X01<<5); 							//enable UART6 clock.
while(!(RCC_APB2ENR & (0x01<<5)));
GPIOC_MODE &= 0xFFFF0FFF;  							//ALternate Function Enabled_PA-2,PA-3
GPIOC_MODE |= 0x0000A000;
GPIOC_AFRL &= 0x00FFFFFF;
GPIOC_AFRL |= 0x88000000; 							//MUX-7 loaded into Alternative register
UART6_BRR |= 0x8B;
UART6_CR1 |= 0x0000200c;         //enable  reciever(2) ,transmitter(3),USART(13).
}
void UART6_OutChar(char c)
{
UART6_SR |=(0x1<<7);
while(!(UART6_SR &(0x1<<7)));
UART6_DR =c;
}

unsigned int UART2_InChar(unsigned int x)
	{
	int i;
	for(i=0; i<x*2500; i++)
	{
	while(!(UART6_SR &(0x1<<5)));
	return UART6_DR&0xFF;
	}
		}

void UART_Outstring(char c[])
{
int i,l;
l=strlen(c);
for(i=0;i<l;i++)
{
UART6_OutChar(c[i]);
}
}

/* return 0 -> ESP8266 sucess
return 1 -> ESP8266 FAIL
*/

int ESP8266_Response_OK(int a)
{
	int i;
  for(i=0;i<200; i++)
		{
buff[i] = UART2_InChar(a);				// Device not working
if ((buff[i] == 'K') && (buff[i-1] == 'O'))
return 0; //success
}
return 1; // fail
}

/*
return 1 -> fail
return 0 -> success
*/

int wifi_init(void)
{
		
UART_Outstring("AT\r\n");
ret = ESP8266_Response_OK(5000);
if (ret != 0)
{
  return 1;// fail
}

UART_Outstring("AT+RST\r\n");
ret = ESP8266_Response_OK(5000);
if (ret != 0)
{
  return 1;// fail
}
UART_Outstring("AT+CWMODE=3\r\n");
ret = ESP8266_Response_OK(5000);
if (ret != 0)
{
  return 1;// fail
}

UART_Outstring("AT+CWJAP=\"KM-2.4G4F\",\"9963111084\"\r\n");
ret = ESP8266_Response_OK(5000);
if (ret != 0)
{
  return 1;// fail
}
UART_Outstring("AT+CIFSR\r\n");

ret = ESP8266_Response_OK(5000);
if (ret != 0)
{
  return 1;// fail
}
UART_Outstring("AT+CIPMUX=0\r\n");
ret = ESP8266_Response_OK(5000);
if (ret != 0)
{
  return 1;// fail
}
UART_Outstring("AT+CWLAP\r\n");
ret = ESP8266_Response_OK(5000);
if (ret != 0)
{
  return 1;// fail
}
UART_Outstring("AT+CIPMODE=0\r\n");

ret = ESP8266_Response_OK(5000);
if (ret != 0)
{
  return 1;// fail
}
return 0; //wifi init success.
}

int main()
{
UART6_init();
STK_INIT();

	
while(1)
{
	
UART_Outstring("AT+CIPSTATUS\r\n");
ret = ESP8266_Response_OK(5000);
if (ret != 0)
{
  return 1;// fail
}

UART_Outstring("AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n");
ret = ESP8266_Response_OK(5000);
if (ret != 0)
{
  return 1;// fail
}
UART_Outstring("AT+CIPSEND=40\r\n");
ret = ESP8266_Response_OK(5000);
if (ret != 0)
{
  return 1;// fail
}
UART_Outstring("GET /page.php?temp=50&hum=13&dev=61\r\n\r\n");

UART_Outstring("AT+CIPCLOSE\r\n");
ret = ESP8266_Response_OK(5000);
if (ret != 0)
{
  return 1;// fail
}
return 0;
}
}

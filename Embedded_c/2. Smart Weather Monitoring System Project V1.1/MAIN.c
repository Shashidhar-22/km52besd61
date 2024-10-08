// include header files

#include "UART6.h"
#include "ADC.h"
#include "LCD.h"
#include "systick.h"
#include "WiFi.h"
#include "I2C.h"
#include "timechange.h"
#include <stdio.h>

//all task function declarations

void wifi_init1(void);
int wifi_response(void);
void Task1_ReadRTC_WriteLCD_1Sec(void);
void Task2_ReadLM35_WriteLCD_10Sec(void);
void Task_3_and_4_Wi_Fi_Tx(void);
void Task4_write_eeprom(void);
void Task5_SWMS_Config(void);

// required global variables

int val,a,b;
char t[10];
int IM35_FLAG;
int retu;
unsigned char str[7];
//unsigned char str1[7]={0x30,0x51,0x12,0x01,0x01,0x01,0x24};
char lcd_ds[10];
char lcd_dt[10];
char fetch2[10];
char fetch3[10];
char buff[200];
char LM35_Data[4];
unsigned char eprom_buff[10];
int res;

#define RCC_AHB1ENR *((int*)0x40023830)
#define GPIOC_IDR *((int*)0x40020810)
#define GPIOB_MODE *((int*)0x40020400)
#define GPIOB_ODR *((int*)0x40020414)
int wifi;
void GPIOB_init(void)
{
	RCC_AHB1ENR |=(0x1<<1);
	while(!(RCC_AHB1ENR&0x2))
	{
		;
	}
}
void red_cofig(void)
{
	GPIOB_MODE &=0xf3ffffff;
	GPIOB_MODE |=0x04000000;
}


//main program
int main()
{
	int i;
	STK_Init();
	
	KM_LCD_Init();
	KM_I2C1_Init();					KM_I2C1_Config();	
	
	GPIOA_INIT();
	UART6_CONIF();
	
	GPOIC_Init();						GPIOB_init();
	
	ADC_Init();
	GPIOC_Config();
	ADC_Config();
	
	GPIOC_PUPDR_cofig();
	red_cofig();
	
	KM_LCD_Write_Cmd(0x01);
	KM_LCD_Write_Cmd(0x80);
	KM_LCD_Write_Str("Welcome To SWMS V1.1");
	Delay_Sec(1);

	retu=KM_I2C_IsDeviceReady(0X68,200);
	
	//KM_I2C_Mem_Write(0x68,0x00,0x01,str1,7);
	
	wifi_init1();
	
	KM_LCD_Write_Cmd(0x01);
	while(1)
	{
		KM_I2C_Mem_Read(0x68,0x00,0x01,str,7);
		
 		Task1_ReadRTC_WriteLCD_1Sec();
		
		if(str[0] == 0x00 | str[0] == 0x10 | str[0] == 0x20 | str[0] == 0x30 | str[0] == 0x40 | str[0] == 0x50  )
			Task2_ReadLM35_WriteLCD_10Sec();
		
		KM_LCD_Write_Cmd(0xCC);
		
		if(IM35_FLAG == 1)
			Task_3_and_4_Wi_Fi_Tx();
		
		GPIOB_ODR &=~(0x01<<13);
		for(i=0;i<20000;i++)
		{
			if(!(GPIOC_IDR &=(0x01<<10)))
				Task5_SWMS_Config();
		}
		GPIOB_ODR |=(0x01<<13);
	}
	
}
void Task1_ReadRTC_WriteLCD_1Sec(void)
{
	
			
	sprintf(lcd_ds,"%02x:%02x:%02x",str[2],str[1],str[0]);
	KM_LCD_Write_Upper_Str(lcd_ds);
	
	sprintf(lcd_dt,"%02x/%02x/%02x",str[4],str[5],str[6]);
	KM_LCD_Write_Lower_Str(lcd_dt);
	
	
}
void Task2_ReadLM35_WriteLCD_10Sec(void)
{
	extern int LM_35;
	
	Temperature();
	a=LM_35/10;
		b=LM_35%10;
		t[0]= 'T';
		t[1] = ':';
		t[2]= ((char)a)+48;
		t[3] = ((char)b)+48;
		t[4] = 0XDF;
		t[5] = 'C';
	
	KM_LCD_Write_Cmd(0x89);
	KM_LCD_Write_Str(t);
	IM35_FLAG=1;
}

void Task_3_and_4_Wi_Fi_Tx(void)
{
	extern int LM_35;
	
	
	outstring("AT+CIPSTATUS\r\n");
	res=wifi_response();
	if(res==0)
	{
		KM_LCD_Write_Cmd(0xCA);
		KM_LCD_Write_Str("CS:OK");
	}
	else
	{
		KM_LCD_Write_Cmd(0xCA);
		KM_LCD_Write_Str("CS:ER");
		Task4_write_eeprom();
		goto lable1;
	}
	//wifi operation
	outstring("AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n");
	res=wifi_response();
	if(res==0)
	{
		
	}
	else if(res==1)
	{
	goto lable1;
	}
	outstring("AT+CIPSEND=38\r\n");
	res=wifi_response();
	if(res==0)
	{
		
	}
	else if(res==1)
	{
	goto lable1;
	}
	sprintf(fetch3,"GET /page.php?temp=%d&hum=5&dev=61\r\n\r\n",LM_35);
	outstring(fetch3);
		res=wifi_response();
	if(res==0)
	{
		
	}
	else if(res==1)
	{
	goto lable1;
	}
	outstring("AT+CIPCLOSE\r\n");
	IM35_FLAG=0;
	lable1:return;
	
}
void Task4_write_eeprom(void)
{
	KM_I2C_Mem_Write(0x50,0x00,0x07,str,8);
	KM_I2C_Mem_Read(0x50,0x00,0x01,eprom_buff,7);
	
}
void Task5_SWMS_Config(void)
{
	timechange();
}
void wifi_init1(void)
{
	//wifi init
	//command 1
	outstring("AT\r\n");
	res=wifi_response();
	if(res==0)
	{
		KM_LCD_Write_Cmd(0x1);
		KM_LCD_Write_Str("AT");
		KM_LCD_Write_Cmd(0xc0);
		KM_LCD_Write_Str("Status: OK");
	}
	else if(res==1)
	{
	KM_LCD_Write_Cmd(0x1);
	KM_LCD_Write_Str("AT");
	KM_LCD_Write_Cmd(0xc0);
	KM_LCD_Write_Str("Status: ERROR");
	}
	//command 2
	outstring("AT+RST\r\n");
	res=wifi_response();
	if(res==0)
	{
		KM_LCD_Write_Cmd(0x1);
		KM_LCD_Write_Str("AT+RST");
		KM_LCD_Write_Cmd(0xc0);
		KM_LCD_Write_Str("Status: OK");
	}
	else if(res==1)
	{
	KM_LCD_Write_Cmd(0x1);
	KM_LCD_Write_Str("AT+RST");
	KM_LCD_Write_Cmd(0xc0);
	KM_LCD_Write_Str("Status: ERROR");
	}
	//command 3
	outstring("AT+CWMODE=3\r\n");
	res=wifi_response();
	if(res==0)
	{
		KM_LCD_Write_Cmd(0x1);
		KM_LCD_Write_Str("AT+CWMODE=3");
		KM_LCD_Write_Cmd(0xc0);
		KM_LCD_Write_Str("Status: OK");
	}
	else if(res==1)
	{
	KM_LCD_Write_Cmd(0x1);
	KM_LCD_Write_Str("AT+CWMODE=3");
	KM_LCD_Write_Cmd(0xc0);
	KM_LCD_Write_Str("Status: ERROR");
	}
	//command 4
	outstring("AT+CWJAP=\"KM-2.4G4F\",\"9963111084\"\r\n");
	res=wifi_response();
	if(res==0)
	{
		KM_LCD_Write_Cmd(0x1);
		KM_LCD_Write_Str("KM-2.4G4F");
		KM_LCD_Write_Cmd(0xc0);
		KM_LCD_Write_Str("Status: Connected");
	}
	else if(res==1)
	{
	KM_LCD_Write_Cmd(0x1);
	KM_LCD_Write_Str("KM-2.4G4F");
	KM_LCD_Write_Cmd(0xc0);
	KM_LCD_Write_Str("Status: ERROR");
	}
	//command 5
	outstring("AT+CIFSR\r\n");
	res=wifi_response();
	if(res==0)
	{
		KM_LCD_Write_Cmd(0x1);
		KM_LCD_Write_Str("AT+CIFSR");
		KM_LCD_Write_Cmd(0xc0);
		KM_LCD_Write_Str("Status: OK");
	}
	else if(res==1)
	{
	KM_LCD_Write_Cmd(0x1);
	KM_LCD_Write_Str("AT+CIFSR");
	KM_LCD_Write_Cmd(0xc0);
	KM_LCD_Write_Str("Status: ERROR");
	}
	//command 6
	outstring("AT+CIPMUX=0\r\n");
	res=wifi_response();
	if(res==0)
	{
		KM_LCD_Write_Cmd(0x1);
		KM_LCD_Write_Str("AT+CIPMUX=0");
		KM_LCD_Write_Cmd(0xc0);
		KM_LCD_Write_Str("Status: OK");
	}
	else if(res==1)
	{
	KM_LCD_Write_Cmd(0x1);
	KM_LCD_Write_Str("AT+CIPMUX=0");
	KM_LCD_Write_Cmd(0xc0);
	KM_LCD_Write_Str("Status: ERROR");
	}
	
	//command 7
	outstring("AT+CWLAP\r\n");
	res=wifi_response();
	if(res==0)
	{
		KM_LCD_Write_Cmd(0x1);
		KM_LCD_Write_Str("AT+CWLAP");
		KM_LCD_Write_Cmd(0xc0);
		KM_LCD_Write_Str("Status: OK");
	}
	else if(res==1)
	{
	KM_LCD_Write_Cmd(0x1);
	KM_LCD_Write_Str("AT+CWLAP");
	KM_LCD_Write_Cmd(0xc0);
	KM_LCD_Write_Str("Status: ERROR");

	}
	//command 8
	outstring("AT+CIPMODE=0\r\n");
	res=wifi_response();
	if(res==0)
	{
		KM_LCD_Write_Cmd(0x1);
		KM_LCD_Write_Str("AT+CIPMODE=0");
		KM_LCD_Write_Cmd(0xc0);
		KM_LCD_Write_Str("Status: OK");
	}
	else if(res==1)
	{
	KM_LCD_Write_Cmd(0x1);
	KM_LCD_Write_Str("AT+CIPMODE=0");
	KM_LCD_Write_Cmd(0xc0);
	KM_LCD_Write_Str("Status: ERROR");
	}
}
int wifi_response(void) //Wifi Response Function
{
	int i=0;

	for(i=0; i<200; i++)
	{
		buff[i]=UART6_InChar();
		if((buff[i]=='5') && (buff[i-1]==':'))
		{
			return 0;
		}
		else if((buff[i]=='K') && (buff[i-1]=='O'))
		{
			return 0;
		}
	}
	return 1;
}

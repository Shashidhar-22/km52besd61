#include "main.h"
#include <string.h>
#include <stdio.h>

extern UART_HandleTypeDef huart6;
extern volatile int  LM_35;
char R_buffer[150];
char Fetch[50];
char sent_data[50];

void command_send(char *cmd)
{
HAL_UART_Transmit(&huart6,(unsigned char *)cmd,strlen(cmd),100);
}

int wifi_responce_ok()
{
HAL_UART_Receive(&huart6,R_buffer,50,150);
for(int i=0;i<R_buffer[i]!='\0';i++)
{
		if(R_buffer[i]=='K' && R_buffer[i-1]=='O')
		{
		return 1;
		}
}
return 0;
}
int chip_responce()
{
	HAL_UART_Receive(&huart6,R_buffer,150,300);
for(int i=0;i<R_buffer[i]!='\0';i++)
	{
		if(R_buffer[i]=='4' || R_buffer[i]=='2')
		{
			return 1;
		}
		else if(R_buffer[i]=='3' || R_buffer[i]=='5')
		{
			return 0;
		}
		}
	return 0;
}

int wifi_responce_done()
{
HAL_UART_Receive(&huart6,R_buffer,150,300);

for(int i=0;i<R_buffer[i]!='\0';i++)
{
	if(R_buffer[i]=='e' && R_buffer[i-1]=='n' && R_buffer[i-2]=='o' && R_buffer[i-3]=='d')
	{
	return 1;
	}
}	
return 0;
}

void wifiinit(void)
{
	/*basic command*/
	command_send("AT\r\n");
	/*Step1: ESP8266 Reset*/
	//command_send("AT+RST\r\n");
	/*Step2: ESP8266_SetWifiMode*/
	command_send("AT+CWMODE=3\r\n");
	/*Step3: ESP8266_JoinAccessPoint*/
	command_send("AT+CWJAP=\"KM-2.4G4F\",\"9963111084\"\r\n");
	if(!(wifi_responce_ok()))
	{
		for(int i=0;i<5;i++)
		{
		command_send("AT+CWJAP=\"KM-2.4G4F\",\"9963111084\"\r\n");
			if(wifi_responce_ok())
			{
			break;
			}
		}
	}
	/*ESP8266_GetIPAddress*/
	command_send("AT+CIFSR\r\n");
	/*ESP8266_SetConnectionMux*/
	command_send("AT+CIPMUX=0\r\n");
	/* ESP8266_SetDataTransmissionMode*/
	command_send("AT+CIPMODE=0\r\n");
	
}

void wifioperation()
{
/*ESP8266_GetStatus*/
	command_send("AT+CIPSTATUS\r\n");
	if(!chip_responce())
	{
	for(int i=0;i<2;i++)
	{
		command_send("AT+CIPSTATUS\r\n");
		if(chip_responce())
		{
		break;
		}
	}
	}
	/*ESP8266_MakeTCPConnection*/
	command_send("AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n");
	if(!(wifi_responce_ok()))
	{
		for(int i=0;i<2;i++)
		{
		command_send("AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n");
			if(wifi_responce_ok())
			{
			break;
			}
		}
	}
	 /*ESP8266_SendTcp*/
	command_send("AT+CIPSEND=40\r\n");
	sprintf(sent_data,"GET /page.php?temp=%d&hum=14&dev=32\r\n",LM_35);

	command_send(sent_data);
	HAL_Delay(10);
	if(!wifi_responce_done())
	{
	for(int i=0;i<3;i++)
		{
		sprintf(sent_data,"GET /page.php?temp=%d&hum=14&dev=32\r\n",LM_35);
		command_send(sent_data);
			if(wifi_responce_done())
			{
			break;
			}
		}
	}	
	
}


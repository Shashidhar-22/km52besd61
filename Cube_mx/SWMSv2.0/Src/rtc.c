
#include"main.h"
#include<stdio.h>
#include"lcd.h"
#include"adc.h"
 extern I2C_HandleTypeDef hi2c1;
 unsigned char T_buffer[7];
 char hms[15];
 char date[15];
 
 void RTC_oper()
		{

		HAL_I2C_Mem_Read(&hi2c1,0x68<<1,0x00,0x01,T_buffer,7,15);
		sprintf(hms," %02x:%02x:%02x",T_buffer[2],T_buffer[1],T_buffer[0]);
		Write_cmd(0x80); 
		LCD_string(hms);   //hour, minute ,sec
		
		sprintf(date," %02x/%02x/%02x",T_buffer[4],T_buffer[5],T_buffer[6]);
		Write_cmd(0xC0); 
		LCD_string(date);  //date		
}
		


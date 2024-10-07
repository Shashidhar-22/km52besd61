#include"main.h"
#include<stdio.h>

void Write_higher_nibble(unsigned char c)
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,(c&16));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,(c&32));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,(c&64));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,(c&128));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);//EN HIGH -pb8 high
	HAL_Delay(10);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);//EN LOW -pb8 low.
	
	
}

void Write_lower_nibble(unsigned char c)
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,(c&1));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,(c&2));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,(c&4));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,(c&8));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);  //EN HIGH -pb8 high.
	HAL_Delay(10);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);//EN LOW -pb8 low.
	
}

void Write_cmd(unsigned char c)
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);//RS LOW - pb4 low.
	Write_higher_nibble(c);
	 Write_lower_nibble(c);
}

void Write_data(unsigned char c)
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_SET);//RS HIGH - pb4 high.
	Write_higher_nibble(c);
	Write_lower_nibble(c);
}

void LCD_string(char *str)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
	Write_data(str[i]);	
	}
}

void LCD_init(void)
{
 	HAL_Delay(20);
	Write_cmd(0x33);
	HAL_Delay(2);
	Write_cmd(0x32);
	Write_cmd(0x0c);
	Write_cmd(0x01);
}


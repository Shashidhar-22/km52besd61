#include "main.h" 
#include "device_h.h"
#include <stdio.h>

extern ADC_HandleTypeDef hadc1;
volatile int  LM_35;
volatile int  adc;
char fetch[25];

void ADC_DATA(void)
{
			HAL_ADC_Start(&hadc1);
			HAL_ADC_PollForConversion(&hadc1,15);
			adc=HAL_ADC_GetValue(&hadc1);
			LM_35=(adc*300)/4096.2;
			HAL_ADC_Stop(&hadc1);
			sprintf(fetch," T:%d%cc",LM_35,0xdf);
			KM_LCD_Write_CMD(0x89);
			KM_LCD_string(fetch);
}
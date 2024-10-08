#include "systick.h"

#define RCC_AHB1ENR *((int*)0x40023830)
      
#define GPIOB_MODE *((int*)0x40020400)
#define GPIOB_ODR *((int*)0x40020414)

void Delay_ms(int n)
{
      int i,c;
      c=1666*n;
      for(i=0;i<c;i++);
}

void write_high_nibble( unsigned char data )
{
      data=data>>4;
      GPIOB_ODR &=0xFFFFFFF0;
      GPIOB_ODR |=data;
      GPIOB_ODR |=(0x01<<8);
      Delay_ms(10);
      GPIOB_ODR &=~(0x01<<8);
}

void write_low_nibble( unsigned char data )
{
      GPIOB_ODR &=0xFFFFFFF0;
      GPIOB_ODR |= (data&0x0f);
      GPIOB_ODR |=(0x01<<8);
      Delay_ms(10);
      GPIOB_ODR &=~(0x01<<8);
}

void KM_LCD_Write_Cmd( unsigned char  data)
{
      GPIOB_ODR &=~(0x01<<4);
      write_high_nibble(data);
      write_low_nibble(data);
}                              

 

void KM_LCD_Write_Data( unsigned char data )
{

      GPIOB_ODR |=(0x01<<4);
      write_high_nibble(data);
      write_low_nibble(data);
}

void KM_LCD_Init(void)
{
      RCC_AHB1ENR |= (0x01<<1);
      while(!(RCC_AHB1ENR & 0x02));
      
      GPIOB_MODE &= 0xFFFCF000;
      GPIOB_MODE |= 0x00010555;
      
      Delay_mSec(20);
      KM_LCD_Write_Cmd(0x33);
      Delay_mSec(1);
      KM_LCD_Write_Cmd(0x32);
      KM_LCD_Write_Cmd(0x0C);
      KM_LCD_Write_Cmd(0x01);
}

void KM_LCD_Write_Str(char *str)
{
      int i=0;
      while(str[i]!=0)
      {
            KM_LCD_Write_Data(str[i]);
            i++;
            if(i==16)
                  KM_LCD_Write_Cmd(0xC0);
      }
}
void KM_LCD_Write_Upper_Str(char *str)
{
      int i=0;
      KM_LCD_Write_Cmd(0x80);
      while(str[i]!=0 && i<17)
      {
            KM_LCD_Write_Data(str[i]);
            i++;
      }
}

void KM_LCD_Write_Lower_Str(char *str)
{
      int i=0;
      KM_LCD_Write_Cmd(0xC0);
      while(str[i]!=0 && i<17)
      {
            KM_LCD_Write_Data(str[i]);
            i++;
      }
}


#include "LCD.h"
#include "systick.h"
#include "I2C.h"
#include <stdio.h>


#define RCC_AHB1ENR *((int*)0x40023830)
#define GPIOC_PUPDR *((int*)0x4002080C)
#define GPIOC_IDR *((int*)0x40020810)
void GPIOC_PUPDR_cofig(void)
{
GPIOC_PUPDR &=0xfff0ffff;
GPIOC_PUPDR |=0x00150000;
}
unsigned char TC[7];
char lcd_ds1[10],lcd_dt1[10];
int x=0,q,z,retn;
void print(void)
{
sprintf(lcd_ds1,"%02x:%02x:%02x",TC[2],TC[1],TC[0]);
KM_LCD_Write_Upper_Str(lcd_ds1);

sprintf(lcd_dt1,"%02x/%02x/%02x",TC[4],TC[5],TC[6]);
KM_LCD_Write_Lower_Str(lcd_dt1);
}
void check(void)
{

if( x==0 | x==1)
{
if(TC[x]>=0x60)
TC[x]=0x00;
}
if(TC[2]>=0x24)
TC[2]=0x00;
if(TC[3]>0X7)
TC[3]=0x01;
if(TC[4]>0X31)
TC[4]=0x01;
if(TC[5]>0X12)
TC[5]=0x01;
}
void check1(void)
{
if( x==0 | x==1)
{
if(TC[x]>=0x60)
TC[x]=0x59;
}
if(TC[2]>=0x24)
TC[2]=0x23;
if(TC[3]>0X7)
TC[3]=0x07;
if(TC[4]>0X31)
{
if(TC[5]==0x2)
TC[4]=0x29;
else if(TC[5]==0x1 |TC[5]==0x3 |TC[5]==0x5 |TC[5]==0x7 |TC[5]==0x8 |TC[5]==0x10 |TC[5]==0x12)
TC[4]=0x31;
else if(TC[5]==0x4 |TC[5]==0x6 |TC[5]==0x9 |TC[5]==0x11 )
TC[4]=0x30;
}
if(TC[5]>0X12)
TC[5]=0x01;
}
void timechange()
{
retn = KM_I2C_IsDeviceReady(0X68,200);
retn = KM_I2C_Mem_Read(0x68,0x00,0x01,TC,7);
sprintf(lcd_ds1,"%02x:%02x:%02x",TC[2],TC[1],TC[0]);
KM_LCD_Write_Upper_Str(lcd_ds1);
sprintf(lcd_dt1,"%02x/%02x/%02x",TC[4],TC[5],TC[6]);
KM_LCD_Write_Lower_Str(lcd_dt1);
  while(1)
{
if(!(GPIOC_IDR &=(0x01<<10)))
{
x++;
KM_Delay_ms(200);
}
if(!(GPIOC_IDR &=(0x01<<8)))
{
TC[x]=TC[x]+0x01;
z=TC[x] & 0x0f;
if(z==0x0a)
TC[x]=TC[x]+0x06;
check();
print();
}
if(!(GPIOC_IDR &=(0x01<<9)))
{
TC[x]=TC[x]-0x01;

z=TC[x] & 0x0f;
if(z==0x0f)
TC[x]=TC[x]-0x06;
z=TC[x] & 0xf0;
if(z==0xf0)
{
TC[x]=TC[x]-0x90;
TC[x]=TC[x]-0x10;
}
check1();
print();
}
if(x==7)
{
x=0;
KM_I2C_Mem_Write(0x68,0x00,0x01,TC,7);
break;
}
}
}

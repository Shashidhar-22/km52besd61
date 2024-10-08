#define RCC_AHB1ENR *((int*)0x40023830)
#define GPIOB_MODE *((int*)0x40020400)
#define GPIOB_ODR *((int*)0x40020414)
	
#define GPIOC_MODE *((int*)0x40020800)
#define GPIOC_IDR *((int*)0x40020810)
#define GPIOC_PUPDR *((int *)0x4002080C)
#include <stdio.h>
//char data[] = "INDIA IS A GREAT COUNTRY";
char arr[16];
void GPIOB_Init(void)
{
      RCC_AHB1ENR |=(0x1<<1);  //set 1st bit to enable the PORT_B clock
      while(!(RCC_AHB1ENR & 0x2)) ;     //wait until the PORT_B clock is set
}

void GPIOC_init(void)
	{
	 RCC_AHB1ENR |= (0x1<<2);   //set 2nd bit to enable port c clock
		while(!(RCC_AHB1ENR & 0x4));
	}
	
	void SWITCH_config (void)
	{
		GPIOC_MODE &=  0xFFCFFFFF;
		GPIOC_PUPDR &= 0xFFCFFFFF;  //load 0,1 into 21-20 dir fields to congiger PB 10 as input mode
		GPIOC_PUPDR |= 0x00100000;
	}
	
void LCDPINS_Config(void)
{
      GPIOB_MODE &= 0xFFFCF000; //
      GPIOB_MODE |= 0x00010555; //
}
void Delay(int x)
{
int i;
x = x*2500;
for(i=0;i<x;i++)
 {
   ;
 }
}
void high_Nibble(unsigned char data)
{
unsigned char a;
GPIOB_ODR &= 0xFFFFFFF0;
a = data>>4;
GPIOB_ODR |= a;
GPIOB_ODR |= (0x1<<8);  //enable ON
Delay(10);
GPIOB_ODR &= ~(0x1<<8);		//enable OFF
}
void low_Nibble(unsigned char data)
{
unsigned char a;
GPIOB_ODR &= 0xFFFFFFF0;
a = data & 0x0F;
GPIOB_ODR |= a;
GPIOB_ODR |= (0x1<<8);     //enable ON
Delay(10);
GPIOB_ODR &= ~(0x1<<8);			//enable OFF
}
void LCD_WRITE_CMD(unsigned char data)
{
GPIOB_ODR &= ~(0x1<<4);
high_Nibble(data);
low_Nibble(data);
}
void LCD_WRITE_DATA(unsigned char data)
{
GPIOB_ODR |= (0x1<<4);
high_Nibble(data);
low_Nibble(data);
}

void LCD_Write_Str(char str[]){
	int i=0;
	for(i=0;str[i];i++){
		LCD_WRITE_DATA(str[i]);
	}
}

void LCD_Clear(){
	LCD_WRITE_CMD(0x01);
}
void LCD_INIT()
{
Delay(20);
LCD_WRITE_CMD(0x33);
Delay(1);
LCD_WRITE_CMD(0x32);
LCD_WRITE_CMD(0x0C);
LCD_WRITE_CMD(0x01);
}

void print(int counter)
{
				if(counter==1){
					LCD_Clear();
					sprintf(arr,"count->%d",counter);
					LCD_Write_Str(arr);
					LCD_WRITE_CMD(0x89);
					LCD_Write_Str("INDIA");
					Delay(3000);
					counter=0;
					LCD_Clear();
					}
				if(counter==2){
					LCD_Clear();
					sprintf(arr,"count->%d",counter);
					LCD_Write_Str(arr);
					LCD_WRITE_CMD(0x89);
					LCD_Write_Str("IS");
					Delay(3000);
					counter=0;
					LCD_Clear();
				}
				if(counter==3){
					LCD_Clear();
					sprintf(arr,"count->%d",counter);
					LCD_Write_Str(arr);
					LCD_WRITE_CMD(0x89);
					LCD_Write_Str("A");Delay(3000);
					counter=0;
					LCD_Clear();
				}
				if(counter==4){
					LCD_Clear();
					sprintf(arr,"count->%d",counter);
					LCD_Write_Str(arr);
					LCD_WRITE_CMD(0x89);
					LCD_Write_Str("GREAT");Delay(3000);
					counter=0;
					LCD_Clear();
				}
				if(counter==5){
					LCD_Clear();
					sprintf(arr,"count->%d",counter);
					LCD_Write_Str(arr);
					LCD_WRITE_CMD(0x89);
					LCD_Write_Str("COUNTRY");Delay(3000);
					counter=0;
					LCD_Clear();
				}
				if(counter==6){
				LCD_Clear();
					sprintf(arr,"count->%d",counter);
					LCD_Write_Str(arr);
				LCD_WRITE_CMD(0xC0);
					//LCD_Write_Str(data);
					counter=0;
					Delay(3000);
					LCD_Clear();
				}
				LCD_Clear();
				LCD_WRITE_CMD(0x80);
	LCD_Write_Str("Press -> SW_ENT");
}
int counter=0;
int main()
{
int i=0;
int Prest_Val=1,Prev_Val=1;
GPIOB_Init();
GPIOC_init();
SWITCH_config();
LCDPINS_Config();
LCD_INIT();
LCD_WRITE_CMD(0x80);
LCD_Write_Str("Press -> SW_ENT");
while(1)
{
	int i=0;
	for(;i<2500*10;i++)
	{
	Prest_Val = (GPIOC_IDR &(0x1<<10));
				if(Prest_Val==0){
					counter++;
					LCD_Clear();
					sprintf(arr,"KEY:%d",counter);
					LCD_Write_Str(arr);
					Delay(500);
				}
	}
	if(counter)
	print(counter);
	counter=0;
	Prev_Val = Prest_Val;
}
}
		
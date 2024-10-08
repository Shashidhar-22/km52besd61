#define RCC_AHB1ENR *((int*)0x40023830)
#define GPIOB_MODE *((int*)0x40020400)
#define GPIOB_ODR *((int*)0x40020414)
void GPIOB_Init(void)
{
      RCC_AHB1ENR |=(0x1<<1);  //set 1st bit to enable the PORT_B clock
      while(!(RCC_AHB1ENR & 0x2)) //wait until the PORT_B clock is set
      {
                  ;
      }
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
GPIOB_ODR |= (0x1<<8);
Delay(10);
GPIOB_ODR &= ~(0x1<<8);
}
void low_Nibble(unsigned char data)
{
unsigned char a;
GPIOB_ODR &= 0xFFFFFFF0;
a = data & 0x0F;
GPIOB_ODR |= a;
GPIOB_ODR |= (0x1<<8);
Delay(10);
GPIOB_ODR &= ~(0x1<<8);
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
void LCD_INIT()
{
Delay(20);
LCD_WRITE_CMD(0x33);
Delay(1);
LCD_WRITE_CMD(0x32);
LCD_WRITE_CMD(0x0C);
LCD_WRITE_CMD(0x01);
}
int main()
{
unsigned char data[] = "   Welcome to    Kernel Masters";
int i=0;
GPIOB_Init();
LCDPINS_Config();
LCD_INIT();
for(i=0;data[i] !='\0';i++)
{
  if(data[i] == 'K')
{
LCD_WRITE_CMD(0xC0);
}
LCD_WRITE_DATA(data[i]);
}
}

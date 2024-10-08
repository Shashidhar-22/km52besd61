#define RCC_AHB1ENR *((int*)0x40023830)
#define GPIOB_MODE *((int*)0x40020400)
#define GPIOB_ODR *((int*)0x40020414)
	
#define STK_CTRL *((int*)0xE000E010)
#define STK_LOAD *((int*)0xE000E014)
#define STK_VAL *((int*)0xE000E018)

//initilization
void GPIOB_Init(void)
{
      RCC_AHB1ENR |=(0x1<<1);  //set 1st bit to enable the PORT_B clock
      while(!(RCC_AHB1ENR & 0x2));	//wait until the PORT_B clock is set
}
	void STK_init(void)
	{
		STK_CTRL |=0x05;    //101 in control and enable bits
		//STK_VAL=0x013; 
	}
	
	//configertion
void LCDPINS_Config(void)
{
      GPIOB_MODE &= 0xFFFCF000; //clear
      GPIOB_MODE |= 0x00010555; //set pb 0 t0 5 and 8 as output direction
}

//delay functions
void KM_sdelay(int x)
{
//int i;
//for(i=0;i<x;i++)		//to iterate that many times
 //{
 STK_LOAD =16000000*x;	 //loading the value
	 STK_VAL=0x013; 
	while((STK_CTRL &(0x1<<16)) == 0); //checking if the value is 0 or not
 }

void KM_mdelay(int x)
{
 STK_LOAD =16000*x;				//loading the value
	STK_VAL=0x013;
	while((STK_CTRL &(0x1<<16)) == 0); //checking if the value is 0 or not
 }

void KM_udelay(int x)
{
//int i;
//for(i=0;i<x;i++)		//to iterate that many times
 STK_LOAD =160000*x;				//loading the value
	 STK_VAL=0x013;
	while((STK_CTRL &(0x1<<16)) == 0); //checking if the value is 0 or not
 }
void high_Nibble(unsigned char c)
{
GPIOB_ODR &= 0xFFFFFFF0;    //clear the 3-2-1-0 bit fields
GPIOB_ODR |= (c>>4);
GPIOB_ODR |= (0x1<<8);    //enable on pb8
KM_mdelay(10);
GPIOB_ODR &= ~(0x1<<8);		//enable off pb8
}
void low_Nibble(unsigned char c)
{
GPIOB_ODR &= 0xFFFFFFF0;
GPIOB_ODR |= (c&0x0F);
GPIOB_ODR |= (0x1<<8);   //enable ON  pb8
KM_mdelay(10);
GPIOB_ODR &= ~(0x1<<8);		//enable OFF pb8
}
void LCD_WRITE_CMD(unsigned char c)
{
GPIOB_ODR &= ~(0x1<<4);   // 0 for command register
high_Nibble(c);
low_Nibble(c);
}
void LCD_WRITE_DATA(unsigned char c)
{
GPIOB_ODR |= (0x1<<4);     //1 for data register
high_Nibble(c);
low_Nibble(c);
}
void LCD_INIT()
{
KM_mdelay(20);
LCD_WRITE_CMD(0x33);
KM_mdelay(1);
LCD_WRITE_CMD(0x32);
LCD_WRITE_CMD(0x0C);
LCD_WRITE_CMD(0x01);
}
int main()
{
GPIOB_Init();
STK_init();
LCDPINS_Config();
LCD_INIT();
	{
unsigned char c[] = "kernal masters";
int i=0;
for(i=0;c[i] !='\0';i++)
LCD_WRITE_DATA(c[i]);
	}
	}
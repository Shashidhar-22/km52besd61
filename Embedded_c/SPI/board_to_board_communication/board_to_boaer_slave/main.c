//RCC register
#define RCC_AHB1ENR *((int*)0x40023830) //SYSTEM CLOCK
#define RCC_APB2ENR *((int*)0x40023844)	//PERIPHERAL CLOCK ENABLE

//GPIO registers
#define GPIO_PORTA_MODE *((int*)0x40020000)	//GPIOA_MODER REGISTER
#define GPIO_PORTA_ODR *((int*)0x40020014)	//GPIOA OUTPUT DATA REGISTER
#define GPIO_PORTA_AFRL *((int*)0x40020020)	//GPIOA_ALTERNATE_FUNCTION_LOW REGISTER
#define GPIO_PORTA_AFHL *((int*)0x40020024)	//GPIOA_ALTERNATE_FUNCTION_HIGH REGISTER
#define GPIOB_MODE *((int*)0x40020400)
#define GPIOC_MODE *((int*)0x40020414)
#define GPIOB_ODR *((int*)0x40020414)
#define GPIOC_PUPDR *((int*)0x4002080C)
#define GPIOC_IDR *((int*)0x40020810)
	
//SPI1 REGISTER
#define SPI1_CR1 *((int*)0x40013000)	//SPI1 CONTROL REGISTER 1
#define SPI1_CR2 *((int*)0x40013004)	//SPI1 CONTROL REGISTER 2
#define SPI1_SR *((int*)0x40013008)	//SPI1 STATUS REGISTER 
#define SPI1_DR *((int*)0x4001300C)	//SPI1 DATA REGISTER 

//FUNCTION DECLERATIONS
void GPIO_PORTA_INIT(void);
void GPIOB_Init(void);
void GPIOC_Init(void);
void SPI1_INIT_CONFIG(void);
void GREEN_RED_LED_Config(void);
void GPIOC_PUPDR_config(void);


void GPIOB_Init(void)
{
	RCC_AHB1ENR |= (0x1<<1);	//set 1st bit to enable PORTB clock.
	while(!(RCC_AHB1ENR & 0x2))	//wait until PORTB clock is set.
	{
		;
	}
}
void GPIOC_Init(void)
{
	RCC_AHB1ENR |= (0x1<<2);	//set 2st bit to enable PORTC clock.
	while(!(RCC_AHB1ENR & 0x4))	//wait until PORTC clock is set.
	{
		;
	}
}

void GREEN_RED_LED_Config(void)
{
	GPIOB_MODE &= 0xc3ffffff;	//clear 29-28 & 27-26 bits.
	GPIOB_MODE |=0x14000000;	//load "01" into 29-28 &27-26 bit fields to configure PB14 & PB13 as output mode.
	GPIOB_ODR |=((0X1<<13));
	GPIOB_ODR |=((0X1<<14));
}

void GPIOC_PUPDR_config(void) //configure pc8 and pc9 as pullup mode.
{
	GPIOC_PUPDR &=0xfff0ffff;	//clear 17-16 and 19-18 bits.
	GPIOC_PUPDR |=0x50000;	//load "01" into 17-16 and 19-18 bit fields to configure Pc8 and pc9 as pullup mode.
}

void GPIO_PORTA_INIT(void)
{
	RCC_AHB1ENR |= 0x1;		//ENABE CLOCK FOR PORT A
	while(!(RCC_AHB1ENR & 0x1));
	GPIO_PORTA_MODE &=0xFFFF00FF;		//CLEAR pins pa4,pa5,pa6,pa7 by loading '00' in that bit field
	GPIO_PORTA_MODE |=0xAA00;				//configure alternate function mode for pins pa4,pa5,pa6,pa7 by loading '10' in that bit field
	GPIO_PORTA_AFRL &=0x0000FFFF;
	GPIO_PORTA_AFRL |=0x55550000;	//CONFIGURE CORRESPONDING ALTERNATE FUNCTION FOR PIN 4,5,6,7 BY LOADING '5' IN THE BIT FIELD
}

void SPI1_INIT_CONFIG(void)
{
RCC_APB2ENR |=(0x1<<12);	//ENABLE SPI1 CLOCK
while(!(RCC_APB2ENR & (0x1<<12)));
SPI1_CR1 &= ~(0x38);		//SELECT THE 'BR' BIT FIELD TO DEFINE SERIAL CLOCK  BOARD RATE CONTROLE.
SPI1_CR1 &= ~(0x0800);	//CLEAR THE 'DFF' TO SELECT 8 BIT DATA FRAME FORMATE.
SPI1_CR1 &=	~(0x1<<2);		//master select enable to make board as master
SPI1_CR2 |= (0x1<<2);	//slave select is enable inorder to use external slave	
SPI1_CR1 |=(0x1<<6);	//spi pheripheral enable	
}
void Delay(int x)
{
	int i;
for(i=0;i<(x*1666);i++)
	{
		;
	}
}
	
	//global variable.
unsigned char receive;
unsigned char ch1='R';
unsigned char ch2='G';

char ch;
//operation phase
int main()
{
	GPIO_PORTA_INIT();
	GPIOB_Init();
	GPIOC_Init();
	GREEN_RED_LED_Config();
	GPIOC_PUPDR_config();
	SPI1_INIT_CONFIG();
	while(1)
	{
		while(!(SPI1_SR & 0x01));
		if(ch1==SPI1_DR)
		{
			GPIOB_ODR &=(~(0X1<<13));		
		}
	}
}
//Experiment 1:
//Write a pseudo code and Embedded C program to SPI1 Configuration using the below conditions,
//And transmit character ‘A’ and Receive same character using hardware Loop back.
//a. Full duplex comm.
//b. Motorola Frame format
//c. Enable Polling (nothing but disable SPI Interrupts)
//Short PA6 & PA7 pins

//PA4 - SPI1_NSS
//PA5 - SPI1_SCK
//PA6 - SPI1_MISO
//PA7 - SPI1_MOS


//RCC register
#define RCC_AHB1ENR *((int*)0x40023830) //SYSTEM CLOCK
#define RCC_APB2ENR *((int*)0x40023844)	//SPI PERIPHERAL CLOCK ENABLE

//GPIO registers
#define GPIO_PORTA_MODE *((int*)0x40020000)	//GPIOA_MODER REGISTER
#define GPIO_PORTA_ODR *((int*)0x40020014)	//GPIOA OUTPUT DATA REGISTER
#define GPIO_PORTA_AFRL *((int*)0x40020020)	//GPIOA_ALTERNATE_FUNCTION_LOW REGISTER
#define GPIO_PORTA_AFHL *((int*)0x40020024)	//GPIOA_ALTERNATE_FUNCTION_HIGH REGISTER
	
//SPI1 REGISTER
#define SPI1_CR1 *((int*)0x40013000)	//SPI1 CONTROL REGISTER 1
#define SPI1_CR2 *((int*)0x40013004)	//SPI1 CONTROL REGISTER 2
#define SPI1_SR *((int*)0x40013008)	//SPI1 STATUS REGISTER 
#define SPI1_DR *((int*)0x4001300C)	//SPI1 DATA REGISTER 

//FUNCTION DECLERATIONS
void GPIO_PORTA_INIT(void);
void SPI1_INIT_CONFIG(void);

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
SPI1_CR1 |=(0x300);			//SOFTWARE SLAVE MANAGEMENT AND INTERNAL SLAVE SELECT ENABLE
SPI1_CR1 |=(0x44);			//MASTER CONFIGURATION AND SERIAL PHERIPHERAL ENABE.(SPI MASTER CONFIGURATION ENABLE)
}
	
	
	
char ch;
//operation phase
int main()
{
	GPIO_PORTA_INIT();
	SPI1_INIT_CONFIG();
	while(1)
	{
		/*TRANSMIT 'A'*/
		while(!(SPI1_SR & 0x02));	//piling the (transfer buffer empty ) TXE bit in SPI1 STATUS REGISTER
		SPI1_DR = 'A';
		
		/*RECEIVE*/
		while(!(SPI1_SR & 0x01));	//polling the (Receive buffer not empty) RXNE IN SPI1 STATUS REGISTER
		ch= SPI1_DR &0xFF;
		//ch++;
	} 

}
	

	

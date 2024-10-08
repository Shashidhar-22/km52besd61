#define STK_CTRL *((int*)0xE000E010)
#define STK_LOAD *((int*)0xE000E014)
#define STK_VAL *((int*)0xE000E018)
	
void STK_Init(void)
{
	STK_CTRL |= 0x05;
	STK_VAL |=0x123;
}

void Delay_Sec(int n)
{
	while(n--)
	{
		STK_LOAD |= 16000000;
		while((STK_CTRL & (0x01<<16))==0);
	}
}
void Delay_mSec(int n)
{
	STK_LOAD |= 1600*n;
	while((STK_CTRL & (0x01<<16))==0);
}
void Delay_uSec(int n)
{
	STK_LOAD |= 16*n;
	while((STK_CTRL & (0x01<<16))==0);
}
void KM_Delay_ms(int n)
{
	STK_CTRL |= 0x05;
	STK_VAL |=0x123;
	STK_LOAD |= 1600*n;
	while((STK_CTRL & (0x01<<16))==0);
}

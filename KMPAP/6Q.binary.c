#include<stdio.h>
int main()
{
	int x;
	int c;
	scanf("%d",&x);
	while(x>0)
		{
			if(x&0x01)
			{
				c++;
			}
			x=x>>1;
		}
	printf("count is : %d\n",c);
}

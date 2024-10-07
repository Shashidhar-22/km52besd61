#include<stdio.h>
int main()
{
	int s,c=0,i;
	printf("Enter a number:");
	scanf("%d",&s);
	int a=sizeof(s);
	for(i=0;i<a*8;i++)
	{
		if(s&(0x1<<(a*8)-1))
		{
			c++;
		}
		s=s<<1;
	}
	if(c==1)
		printf("It is power of 2\n");
		else
		printf("It is not power of 2\n");

	return 0;
}

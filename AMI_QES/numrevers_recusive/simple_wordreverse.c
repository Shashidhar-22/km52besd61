#include<stdio.h>
int main()
{
	int s;
	printf("Enter a number to reverse:\n");
	scanf("%d",&s);
	int rev=0,rem=0;
	while(s!=0)
	{
		rem=s%10;
		rev=rev*10+rem;
		s=s/10;
	}
	printf("Reverse is :%d",rev);
	printf("\n");
return 0;
}

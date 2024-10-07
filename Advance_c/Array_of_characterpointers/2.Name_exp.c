#include<stdio.h>
int main()
{
	int a;
	char *str[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	printf("Enter an integer number:");
	scanf("%d",&a);
	int i=0,rev=0,rem=0,s;
	for(;i<(sizeof(str)/sizeof(str[0]));i++)
	{
		while(a>0)
		{
			rem = a%10;
			 rev = rev*10+rem; 
			 a /= 10;
		}
	}
	for(i=0;i<(sizeof(str)/sizeof(str[0]));i++)
	{
		while(rev>0)
		{
			s=rev%10;
			printf("%s ",str[s]);
			rev /= 10;

		}
	}

}

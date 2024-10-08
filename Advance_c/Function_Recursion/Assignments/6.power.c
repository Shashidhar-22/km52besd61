//6) Write a program to find the power of a number( x to the power of n = x * x * x * x....n times)

#include<stdio.h>
int power(int s,int a)
{
	if(a==0)
		return 1;
	return s * power(s,a-1);
}
int main()
{
	int s,a,b;
	printf("Enter a number  and power: ");
	scanf("%d %d",&s,&a);
	printf("power is : %d\n",power(s,a));
}

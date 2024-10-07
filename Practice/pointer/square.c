#include<stdio.h>
int square(int a)
{
	a=a*a;
	printf("%d",a);
	return a;
}
int main()
{
	int a=4;
	square(a);
//	printf("%d",a);
}


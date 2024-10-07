#include<stdio.h>
int fun(int *a)
{
	int y;
	a=&y;
	*a=300;
}
int main()
{
	int a=100;
	fun (&a);
	printf("%d",a);
}


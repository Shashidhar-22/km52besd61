#include<stdio.h>
int *ptr;
int main()
{
	int x=10;
	ptr=&x;
	fun();
	printf("%d",x);
}
fun()
{
	*ptr=30;
}



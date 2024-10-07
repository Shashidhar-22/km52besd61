#include<stdio.h>
int *ptr;
fun()
{
	int x=30;
	ptr=&x;
}
int main()
{
	*ptr=40;
	fun();
		printf("%d",*ptr);
}



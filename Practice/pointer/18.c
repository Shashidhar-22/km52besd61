#include<stdio.h>
int *fun()
{
	static int x=10;
	x++;
	return &x;
}

int main()
{
int *p= fun();
	*p=50;
fun();
printf("%d",*p);
}


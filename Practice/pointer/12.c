#include<stdio.h>
int main()
{
	int x=1,y=1;
	int *ptr;
	x=0;
	ptr=&x;
	y=*ptr;
	*ptr=1;
	printf("%d%d",x,y);
}

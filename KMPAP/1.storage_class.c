#include<stdio.h>
static int b=1;
int s=100;
void fun();
int main()
{
	static int a=10;
	int s=22;
	register int r=11;
	printf("auto: %d\n",s);

	printf("register: %d\n",r);
	a+=10;
	printf("static local: %d\n",a);
	if(b)
	{
	printf("static global: %d\n",b);
	}
	fun();//this defination in 2.1.stro.c file for extern strorage class
	return 0;
}

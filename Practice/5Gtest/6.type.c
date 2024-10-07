
#include<stdio.h>
typedef int (*funptr)(int);
int inc(int a)
{
	printf("inside inc %d\n",a);
	return (a+1);
}
int main()
{
	funptr incptr1=NULL,incptr2=NULL;

	incptr1=&inc;

	incptr2=inc;
	(*incptr1)(5);
	incptr2(5);
	return 0;
}


#include<stdio.h>

extern int s;
//int s;
void fun() 
{
	s *= 2;
	printf("extern class:%d\n", s);
}


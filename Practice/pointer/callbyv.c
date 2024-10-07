/*
#include<stdio.h>
int main()
{
	int a=10,b=20;
	fun(a,b);
	printf("a=%d b=%d",a,b);
}
void fun(int x,int y)
{
	int temp;
       temp=x;
	x=y;
	y=temp;
	printf("x=%d y=%d",x,y);
}	*/


#include<stdio.h>
int main()
{
	int a=10,b=20,t;
	printf("a=%d b=%d",a,b);
	swap( a, b);
	printf("s=%d d=%d",a,b);
}
int swap (int s,int d)
{
	int t;
	t=s;
	s=d;
	d=t;
	printf("s=%d d=%d",s,d);
	return 0;
	}


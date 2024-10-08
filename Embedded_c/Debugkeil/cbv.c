#include<stdio.h>
void swap(int a,int b);
int main()
{
	int a=10,b=20;
	swap(a,b);
}
void swap(int a,int b)
{
	int t;
	t=a;
	a=b;
	b=t;
}

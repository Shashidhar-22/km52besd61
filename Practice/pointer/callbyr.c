/*
#include<stdio.h>
int main()
{
	int a=10,b=20;
	int *p,*p1;
	p=&a,p1=&b;
	fun(p,p1);
	printf("a=%d b=%d",a,b);
}
void fun(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
	printf("x=%d y=%d",*x,*y);
}

#include<stdio.h>
int main()
{
	int a=10,b=20,t;
	int *p=&a, *p2=&b;
	printf("a=%d b=%d\n",a,b);
	 cbr(p,p2);
	 printf("a=%d b=%d\n",a,b);
}
void cbr(int *p , int *p2 )
{
	int t;
	t=*p;
	*p=*p2;
	*p2=t;
	printf("*p=%d *p2=%d\n",*p,*p2);
}
*/
#include<stdio.h>
int main()
{
	int x=2,y=9,t;
	printf("x=%d y=%d\n",x,y);
	swap(&x,&y);
	printf("x=%d y=%d\n",x,y);
	printf("x=%p y=%p\n",x,y);
}
void swap(int *p1, int *p2)
{
	int t;
	t=*p1;
	*p1=*p2;
	*p2=t;
	printf("p1=%d p2=%d\n",*p1,*p2);
	printf("p1=%p p2=%p\n",*p1,*p2);

}



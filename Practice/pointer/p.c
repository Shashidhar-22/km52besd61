#include<stdio.h>
int main()
{
	int a=10;
	int *p=&a;
	//p=&a;
	printf("a=%d\np=%d\n",a,*p);
	scanf("%d",p);
	printf("a=%d\np=%d\n",a,*p);
	printf("a=%d\np=%d\n",p,&p);
	return 0;
}

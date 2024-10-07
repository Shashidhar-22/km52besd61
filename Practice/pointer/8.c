#include<stdio.h>
int main()
	{
		int x=10,y=20,z;
		int *ptr=&x;
		z=*ptr;
		ptr=&y;
		*ptr=30;
		printf("%d%d%d\n",x,y,z);
	}


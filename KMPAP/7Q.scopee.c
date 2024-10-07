#include<stdio.h>
int main()
{
	int x,*ptr;
	{
		int z=10;
		ptr=&z;
	}
	printf("%d\n",*ptr);
}

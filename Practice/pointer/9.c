#include<stdio.h>
int main()
{
	int x;
	char *pc=&x;
	printf("%d\n",sizeof(*pc)); //*pc means 1 byte 
				    //pc means 8 bytes
}


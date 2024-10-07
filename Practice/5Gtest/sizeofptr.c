#include<stdio.h>
int main()
{
	printf("%ld %ld\n",sizeof(int*),sizeof(int**));//for double pointer also size is 8
	return 0;
}

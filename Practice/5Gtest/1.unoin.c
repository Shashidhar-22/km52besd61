#include<stdio.h>
union st
{
	int x;
	char c[8];//think in memory  how it is assigning
	int y;
};

int main()
{
	printf("%ld",sizeof(union st));
	return 0;
}

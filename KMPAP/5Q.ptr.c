#include<stdio.h>
int main()
{
	int i=256;
	char *ptr=&i;
	*ptr++;
	printf("%d\n",*ptr);
}

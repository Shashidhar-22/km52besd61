#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr=malloc(20*sizeof(int));
	printf("%ld\n",sizeof(ptr));
	free(ptr);
	ptr=NULL;
	return 0;
}

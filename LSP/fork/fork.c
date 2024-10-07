#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{
	fork();
	fork();
//	fork();
	printf("hi\thelloworld\n");
	getchar();
return 0;
}

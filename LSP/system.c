//WAP to start a process in command line,not system call by using "system()" library

#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("start\n");
	system("echo");
	printf("stop\n");
	exit(0);
return 0;
}

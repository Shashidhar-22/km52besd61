#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(int argc ,char *argv[])
{
	int data_processed;
	char buff[BUFSIZ+1];
	int fd;
	memset(buff,'\0',sizeof(buff));
		sscanf(argv[1],"%d",&fd);
		//memset(argv[1],"%d",&fd);
		data_processed=read(fd,buff,BUFSIZ);
		printf("%d dytes read:%d\n",getpid(),data_processed);
		exit(EXIT_SUCCESS);
		}


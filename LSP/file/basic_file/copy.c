#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	int fd,ret,i,fd1;
	char ch;
//      	fd=open("/home/mbd_sw/Documents/abc",O_RDONLY);
//	for(i=1;i<argc;i++)
//	{
	fd=open(argv[1],O_RDONLY);
//	printf("fd:%d\n",fd);
	if(fd<0)
	{
		perror("OPEN FAIL");
		exit(0);
	}
	fd1=open(argv[2],O_RDWR|O_TRUNC|O_CREAT,0666);
	while(1)
	{
           ret=read(fd,&ch,1);
	   if(ret==0)
	   {
	      break;
	   }
           write(fd1,&ch,1);
	}
//	}
	close(fd);
	close(fd1);
	return 0;
}

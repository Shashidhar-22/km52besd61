#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	int fd,ret,i;
	char ch;
//	for(i=1;i<argc;i++)
//	{
	fd=open(argv[1],O_RDONLY);
	printf("fd:%d\n",fd);
	if(fd<0)
	{
		perror("OPEN FAIL");
		exit(0);
	}
	while(1)
	{
           ret=read(fd,&ch,1);
	   if(ret==0)
	   {
	      break;
	   }
           write(1,&ch,1);
	}
	close(fd);
	
	return 0;
}

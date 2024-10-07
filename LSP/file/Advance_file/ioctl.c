#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<linux/fb.h>
#include<sys/stat.h>

#include<linux/input.h>
int main(int argc,char *argv[])
{

	struct input_event ev;

	int fd,ret,res;
	char buff[50];
	fd=open(argv[1],O_RDONLY);
	if(fd<0){
		perror("open fail");
		exit(0);}
	ret=ioctl(fd,EVIOCGNAME(sizeof(buff)),buff);
			printf("device name:%s\n",buff);
			



}

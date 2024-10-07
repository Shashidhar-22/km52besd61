#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
int fd;
char ch[20];
fd=open(argv[1],O_RDWR);
//lseek(fd,5,SEEK_SET);
read(fd,ch,20);
//printf("read string:%s\n",ch);
lseek(fd,5,SEEK_CUR);
//lseek(fd,5,SEEK_END);
write(fd,&ch,5);
close(fd);
return 0;
}

/*
int main(int argc,char *argv[])
{
	int fd;
	char ch[10];
	fd=open(argv[1],O_RDWR);
//	lseek(fd,3,SEEK_SET);
	read(fd,ch,10);
	printf("read string:%s\n",ch);

//	lseek(fd,3,SEEK_CUR);
	lseek(fd,3,SEEK_END);
	write(fd,"123445678",10);
	close(fd);
return 0;
}

*/

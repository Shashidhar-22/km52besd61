#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char* argv[])
{
	if(argc < 2)
	{
		printf("invalid\nusage:%s <file 1> <file 2> .... <file n>\n",argv[0]);
		exit(0);
	}
	int fd,ret,ret1;
	char ch;
	for(int i=1;i<argc;i++){

		fprintf(stdout,"----------%s file----------\n",argv[i]);
		int line=0,count=0,line1=0;
		fd=open(argv[i],O_RDONLY);
		if(fd < 0){
			perror("OPEN FAIL");
			exit(0);
		}
		while(1){
			ret=read(fd,&ch,1);
			if(ret == 0)
			{
				break;
			}
			if(ch == '\n')
			{
				line++;
			}
		}
		line1=line-10;
		close(fd);
		fd=open(argv[i],O_RDONLY);
		while(1){
			ret=read(fd,&ch,1);
			if(ret == 0)
				break;
			if(ch == '\n')
			{
				count++;
			}
			if(count >= line1)
			{
				write(1,&ch,1);
			}
		}
		close(fd);

	}
	return 0;
}	

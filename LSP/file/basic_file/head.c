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
}
	int fd;
	char ch;
	for(int i=1;i<argc;i++){

		fprintf(stdout,"----------%s file----------\n\n",argv[i]);
		int line=0;
		fd=open(argv[i],O_RDONLY);
		if(fd < 0){
			perror("OPEN FAIL");
			exit(0);
		}
		while(1){
			read(fd,&ch,1);
			if(ch == '\n')
			{
				line++;
				//write(1,"\n",1;)
			}
			write(1,&ch,1);
			if(line == 10)
			{
				break;
			}
		}
		close(fd);
		write(1,"\n",1);
	}
	return 0;
}

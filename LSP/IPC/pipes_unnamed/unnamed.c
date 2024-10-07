#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int data_processed;
	int file_pipe[2];
	const char some_data[]="shashidhar";
	char buff[BUFSIZ+1];
	memset(buff,'\0',sizeof(buff));
	getchar();
	printf("before pipe s/m call\n");
	if(pipe(file_pipe)==0){
		getchar();


		data_processed=write(file_pipe[1],some_data,strlen(some_data));
		printf("wrote %d bytes\n",data_processed);
		data_processed=read(file_pipe[0],buff,BUFSIZ);
		printf("%d dytes read:%s\n",data_processed,buff);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

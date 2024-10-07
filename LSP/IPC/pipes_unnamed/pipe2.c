#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	int data_processed,wstatus,exit_code=0;
	int file_pipe[2];
	const char some_data[]="shashidhar";
	char buff[BUFSIZ+1];
	pid_t fork_result;
	memset(buff,'\0',sizeof(buff));
	//getchar();
	//printf("before pipe s/m call\n");
	if(pipe(file_pipe)==0){
		getchar();
		fork_result=fork();
		getchar();
		if(fork_result<0){
			fprintf(stderr,"Fork failed");
			exit(EXIT_FAILURE);
		}
		if(fork_result!=0){
		data_processed=read(file_pipe[0],buff,BUFSIZ);
		printf("%d dytes read:%s\n",data_processed,buff);
		exit(EXIT_SUCCESS);
		}
		else{
			
		data_processed=write(file_pipe[1],some_data,strlen(some_data));
		printf("wrote %d bytes\n",data_processed);
		}
	}
	exit(EXIT_FAILURE);
}

//when fork1.c is exicuting but background in RAM duplicate the process,by creating the child process ----------------so both if()condition and else condition also execute------------------i-.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	pid_t pid;
	pid = fork();

	if(pid == -1)
	{
	   printf("FORK FAIL !\n");
	   exit(0);
	}
        
	else if(pid == 0)
	{
	  // sleep(2);
	   printf("CHILD PROCESS : %d\n",getpid());
	   printf("PARENT PROCESS : %d\n",getppid());
	}
	else
		//   sleep(2);
	   printf("1CHILD PROCESS : %d\n",getpid());
           printf("1PARENT PROCESS : %d\n",getppid());
	

	return 0;
}

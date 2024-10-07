#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/mman.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

sem_t *prod_lock,*cons_lock;

char *ptr;
int a,b,n=0,m=0,shmid;
pid_t child_pid;
 char buff[BUFSIZ+1];


void terminate(int sig)
{
	printf("I got a signal for terminate, for terminate CTRL+C\n");
	sem_unlink("producer1");
	sem_unlink("consumer1");
	signal(SIGINT,SIG_DFL);
}



void main()
{
	signal(SIGINT,terminate);
	prod_lock=sem_open("producer1",0666);
	if(prod_lock==NULL)
	{
		perror("semaphore1");
		exit(0);
	}

	cons_lock=sem_open("consumer1",0666);
	if(cons_lock==NULL)
	{
		perror("semaphore2");
		exit(1);
	}

	sem_getvalue(prod_lock,&a);
	sem_getvalue(cons_lock,&b);

	printf("prod:%d   cons:%d\n",a,b);

	if ((shmid=shmget(35,1024,IPC_CREAT|0666))==-1)
	{
		perror("shmget");
		exit(1);
	}
	

		while(1)
		{
		
				sem_wait(cons_lock);
				ptr=shmat(shmid,0,0);
				printf("Data sucessfully read:%s",ptr);
				shmdt(ptr);
				sem_post(prod_lock);
			
		}	

	}

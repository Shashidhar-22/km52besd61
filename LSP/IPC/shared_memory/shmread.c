//consumer
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main()
{
	int shmid;
	char *msg;
	if((shmid=shmget(10,1024,0))==-1){
		perror("shmget");
		exit(1);}
	msg=shmat(shmid,0,0);
	printf("Data written in the shared memory is :%s\n",msg);
	getchar();
	shmdt(msg);



return 0;
}


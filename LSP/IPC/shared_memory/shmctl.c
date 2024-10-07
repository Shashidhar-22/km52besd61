//remove
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main()
{
	int shmid;
	char *msg;
	if((shmid=shmget(10,10,0))==-1){
		perror("shmid");
		exit(1);}
	if(shmctl(shmid,IPC_RMID,0)==-1){
		perror("shmctl");
		exit(1);
	}
	printf("shared memory sucessfully removed\n");

return 0;
}


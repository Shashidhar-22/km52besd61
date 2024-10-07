//delete

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<string.h>

#define KEY 100

struct mesg{
	long int type;
	char msg[20];
};

int main()
{
	struct mesg messege;
	int qid,n;
	qid=msgget(KEY,0666);
	if(qid<0)
	{
		perror("msgget");
		exit(0);
	}
	//messege.type=123;
	//strcpy(messege.msg,"hello");
	if((n=msgctl(qid,IPC_RMID,0))<0)
			{
			perror("msgctl");
			exit(0);}
	printf("%d\n",n);
	printf("100 msg removed\n");
}



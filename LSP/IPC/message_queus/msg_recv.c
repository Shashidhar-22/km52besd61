//consumer

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>

#define KEY 100

struct mesg{
	long int type;
	char msg[20];
};

int main()
{
	struct mesg messege;
	int qid,n;
	qid=msgget(100,0666);
	if(qid<0){
		perror("msgget");
		exit(0);}
	if((n=msgrcv(qid,&messege,20,0,0)<0))
			{
			perror("msgrcv");
			exit(0);}
	printf("msgis:%s\n",messege.msg);
	printf("msg type is %d\n",messege.type);
}



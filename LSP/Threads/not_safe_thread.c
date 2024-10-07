
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>

void *Producer(void *);
void *Consumer(void *);

char buffer[5];
int counter=0;

int main()
{
	int ret;
	pthread_t a,b;

	ret = pthread_create(&a,NULL,Producer,NULL);
	if(ret<0)
	{
		perror("PRODUCER FAIL");
	}
	ret = pthread_create(&b,NULL,Consumer,NULL);
	if(ret<0)
	{
		perror("CONSUMER FAIL");
	}
	pthread_join(a,NULL);
	pthread_join(b,NULL);
}


void *Producer(void *arg)
{
	int in = 0;
	char ch = 'A';
	while(1)
	{
		while(counter==5);
		buffer[in] = ch;
		in = (in+1)%5;
		counter++;
		ch++;
		if(counter==5){
			in = 0;
			ch = 'A';
			printf("P:%s\n",buffer);}
	}
}

void *Consumer(void *arg)
{
	int out = 0;
	char temp[5];
	while(1)
	{
		while(counter==0);
		temp[out] = buffer[out];
		out = (out+1)%5;
		counter--;
		if(counter==0)
			printf("   C:%s\n",temp);
	}
}

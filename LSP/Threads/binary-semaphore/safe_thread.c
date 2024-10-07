#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>
#include<semaphore.h>

void *Producer(void *);
void *Consumer(void *);

char buffer[5];
sem_t empty,full;
//int counter=0;

int main()
{
	int ret,ret1;
	pthread_t a,b;

	/* Create the full semaphore and initialize to 0 */
	sem_init(&full, 0, 0);

	/* Create the empty semaphore and initialize to BUFFER_SIZE (binary Semaphore 0,1) */
	sem_init(&empty, 0, 1);


	ret = pthread_create(&a,NULL,Producer,NULL);
	if(ret<0)
	{
		perror("PRODUCER FAIL");
	}
	ret1 = pthread_create(&b,NULL,Consumer,NULL);
	if(ret1<0)
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
		//	while(counter==5)i;
		sem_wait(&empty);
		for(int i=0;i<=4;i++){
			buffer[i] = ch;
			ch++;
		}
		printf("P:%s",buffer);	
		ch='A';
		sem_post(&full);
	}
}
void *Consumer(void *arg)
{
	int out = 0;
	char temp[5];
	while(1)
	{
		//while(counter==0);
		sem_wait(&full);
		for(int j=0;j<=4;j++){
			temp[j] = buffer[j];
		}
		printf("   C:%s\n",temp);
		sem_post(&empty);
	}

}


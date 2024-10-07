#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

static int i;
void *even()
{
	while(i<=100)
	{
		if(i%2==0)
		{
			printf("EVEN:%d\n",i);
			i++;
		}
		getchar();
	}
}
void *odd()
{
	while(i<=100)
	{
		if(i%2!=0)
		{
			printf("ODD:%d\n",i);
			i++;
		}
	}
}

int main()
{
	int ret=0;
	pthread_t abc,xyz;
	ret=pthread_create(&abc,NULL,even,NULL);
	if(ret!=0){
		perror("THREAD E CREATION FAIL");
		exit(0);
	}

	ret=pthread_create(&abc,NULL,odd,NULL);
	if(ret!=0){
		perror("THREAD O CREATION FAIL");
		exit (1);
	}
	pthread_join(abc,NULL);
	pthread_join(xyz,NULL);
}

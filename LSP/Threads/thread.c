#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

void *func();
int main()
{
    int ret;
    pthread_t abc;
    ret = pthread_create(&abc,NULL,func,NULL);
    pthread_join(abc,NULL);
    while(1)
    {
      printf("HI!\n");
 //     sleep(2);
    }
}

void *func()
{
	int i = 1;
  while(i)
  {
   printf("Hello World\n");
   i++;
  }
}

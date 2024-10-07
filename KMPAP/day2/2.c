#include<stdio.h>
 void outer_function() 
{
	int counter = 0;
	counter++;
	printf("Counter: %d\n", counter);
}

static void (*fun)()= outer_function;

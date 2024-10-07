#include<stdio.h>
static void outer_function() //note static function is used in within the same fie not acses in 2.c file
{
	 int counter = 0;
	counter++;
	printf("Counter: %d\n", counter);
}
int main() 
{
	void (*fun)()= outer_function;
	(*fun)();		//count=1
	outer_function(); // Output: Counter: 2
	outer_function(); // Output: Counter: 3
	outer_function(); // Output: Counter: 4
	return 0;
}

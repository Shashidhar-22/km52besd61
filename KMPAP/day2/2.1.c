#include<stdio.h>
 void outer_function();		
static void (*fun)()= outer_function;
int main() 
{

	(*fun)();		//count=1
	outer_function(); // Output: Counter: 2
	outer_function(); // Output: Counter: 3
	outer_function(); // Output: Counter: 4
	return 0;
}

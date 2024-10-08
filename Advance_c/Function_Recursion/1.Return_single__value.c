//Return sigle value to function


/*
 * method 1 with static variable
#include<stdio.h>
int main()
{
	int n=5;	//It is like initilization
	printf("%d\n",sumofn(n));
}
int sumofn(int n)
{
	static  int s;		//s=0 initially
	if(n==0)
		return s;	// loop ends at this point
	s=s+n;
	n--;			//decrement
	return sumofn(n);	//recursive function it wil call again sunofn()function  | It will create again memory in stack segement  | after returning it will comeback. 
}
*/


//method 2
#include<stdio.h>
int main()
{
	int n=5;	//It is like initilization
	printf("%d\n",sumofn(n));
}
int sumofn(int n)
{
	if(n==0)
		return 0;	// loop ends at this point
	return n+sumofn(n-1);	//recursive function it wil call again sunofn()function  | It will create again memory in stack segement  | after returning it will comeback. 
}





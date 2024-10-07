#include<stdio.h>
int main()
{
	int x=5,y=6;	//pointer decleration & Initilizaion.
	int *ptr; //pointer decleration.
	ptr=&x;	//assigning adsress of x to the ptr.
	printf("x address:&x: %p\n",&x); 
	printf("x addres :ptr: %p\n",ptr);
	printf("ptr address : &ptr: %p\n",&ptr);
	printf("x value : x : %d \n",x);
	printf("x value : *ptr : %d\n",*ptr);
	ptr=&y;
	printf("y value : *ptr : %d\n",*ptr);
}

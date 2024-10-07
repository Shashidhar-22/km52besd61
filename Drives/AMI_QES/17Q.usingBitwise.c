//17.   Write a program to add 2 numbers without using addition or subtraction operators.

/*
#include<stdio.h>
int main()
{
	int x,y;
	printf("enter any 2 numbers:");
	scanf("%d%d",&x,&y);
//	get(x,y);
	x=x-(~y)-1;
	printf("The addition of 2 numberfs without using add/sub:%d\n",x);
}*/


#include <stdio.h>
int add(int a, int b) 
{
	int carry;
	while (b != 0) {
		carry = a & b;  // Carry is the AND of a and b (bits set to 1 in both)
		a = a ^ b;      // Result is the XOR of a and b (excluding carry bits)
		b = carry << 1; // Shift carry bits to the left for the next iteration
	}
	return a;
}

int main()
{
	int num1, num2, sum;
	printf("Enter two numbers: ");
	scanf("%d %d", &num1, &num2);
	sum = add(num1, num2);
	printf("Sum of %d and %d is %d\n", num1, num2, sum);
	return 0;
}

/*
#include <stdio.h>
int sub(int a, int b) 
{
	int carry;
	while (b != 0) {
		carry = (~a) & b;  // Carry is the AND of a and b (bits set to 1 in both)
		a = a ^ b;      // Result is the XOR of a and b (excluding carry bits)
		b = carry << 1; // Shift carry bits to the left for the next iteration
	}
	return a;
}

int main()
{
	int num1, num2, sub;
	printf("Enter two numbers: ");
	scanf("%d %d", &num1, &num2);
	sub = sub(num1, num2);
	printf("Sub of %d and %d is %d\n", num1, num2, sub);
	return 0;
}	*/



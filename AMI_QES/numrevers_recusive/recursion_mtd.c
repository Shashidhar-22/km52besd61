//7 Print the given number in reverse order using recursion.

#include<stdio.h>
#include<stdlib.h>

void printReverse(int n) 
{   
       	// Base case: if the number becomes zero, return
    if (n == 0)
    {
        return;
    }
    // Print the last digit of the number
    printf("%d", n % 10);
    
    // Recursively call the function with the remaining digits
    printReverse(n / 10);
}

int main() 
{
    int number;
    `
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Number in reverse order: ");
   
    // Call the function to print the number in reverse order
    printReverse(number);

    return 0;
}

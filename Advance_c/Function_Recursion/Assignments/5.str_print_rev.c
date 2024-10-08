//5) Print a string in normal and then reverse, using recursion, without modifying the string.


#include<stdio.h>
void printNormal(char *ch)
{
	if (*ch == '\0')
		return;
	printf("%c", *ch);
	printNormal(ch + 1);
}

void printReverse(char *ch) 
{
	if (*ch == '\0')
		return;
	printReverse(ch + 1);
	printf("%c", *ch);
}

int main()
{
	char ch[20];
	printf("Enter a string: ");
	scanf("%s", ch);
	printf("Normal string: ");
	printNormal(ch);
	printf("\nReverse String: ");
	printReverse(ch);
	printf("\n");
	return 0;
}


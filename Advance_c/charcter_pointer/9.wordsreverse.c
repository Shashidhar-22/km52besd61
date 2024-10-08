#include <stdio.h>
#include <string.h>
void mystrrev(char str[])
{
	int n = strlen(str);
	int i;
	for (i = n - 1; i >= 0; i--) {
		if (str[i] == ' ') {
			str[i] = '\0';
			printf("%s ",&(str[i+1]));
		}
	}
	printf("%s", str);
	printf("\n");
}

int main()
{
	int s;
	printf("Enter the size of string : ");
	scanf("%d",&s);
	char str[s];
	printf("Entier the string : ");
	scanf(" %[^\n]s",str);
	mystrrev(str);
	return 0;
}

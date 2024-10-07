#include <stdio.h>
#include <string.h>

void mystrrev(char str[])
{
	int n= strlen(str);

	int i;
	for (i = n - 1; i >= 0; i--) {
		if (str[i] == ' ') {

			str[i] = '\0';


			printf("%s ",&(str[i]) + 1);
		}
	}


	printf("%s", str);
}

int main()
{
	char str[100];
	printf("enter the elements of the array:\n");
	scanf("%[^\n]s",str);
	mystrrev(str);
	return 0;
}


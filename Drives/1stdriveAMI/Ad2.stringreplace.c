
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* fun(char *str, char *sub, char *rep);

int main() {
	char str[20], sub[5], rep[10];
	printf("Enter a main string: ");
	scanf("%19[^\n]", str);
	getchar(); // consume newline
	printf("Enter a sub string: ");
	scanf("%4[^\n]", sub);
	getchar(); // consume newline
	printf("Enter a replace string: ");
	scanf("%9[^\n]", rep);
	printf("Output is: %s\n", fun(str, sub, rep));
	return 0;
}

char* fun(char *str, char *sub, char *rep) {
	int i = 0, j = 0, k = 0, len1, len2;
	len1 = strlen(sub);
	len2 = strlen(rep);
	char new[30];
	while (str[i]) 
	{
		if (str[i] != sub[j]) 
		{
			new[k] = str[i];
			i++;
			k++;
		}
	       	else if(str[i]==sub[j])
		{
			strcat(new, rep);
			k += len2;
			i += len1;
		}

	}
	new[k] = '\0';
	char *result = malloc(strlen(new) + 1); // allocate memory for result
	strcpy(result, new); // copy new string to result
	return result;
}


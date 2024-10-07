
#include <stdio.h>
#include <string.h>

int fdindex(char input1[], char input2[]);

int main() {
    char input1[10], input2[20];
    printf("Enter string: ");
    scanf("%s", input1);
    printf("Enter string: ");
    scanf("%s", input2);
   int index = fdindex(input1, input2);
    if (index != -1)
	    printf("Index of first matching character: %d\n", index);
    else
	    printf("No matching character found.\n");
    // printf("%s",fdindex(input1, input2));
    return 0;
}

int fdindex(char input1[], char input2[]) 
{
	int l1 = strlen(input1);
	int l2 = strlen(input2);
	int shashi;
	for (int i = 0; i < l1; i++) 
	{
		for (int j = 0; j < l2; j++)
		{
			if (input1[i] == input2[j])
				return i;
			break;
		}
	}
	return -1;
}


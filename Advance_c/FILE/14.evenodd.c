/*14	read numbers entered by user and write to a file. Open the file and read the numbers and write even numbers to even file and odd numbers to odd file.   */
#include<stdio.h>
int main()
{
	FILE *input=NULL,*even=NULL,*odd=NULL;
	int i;
	input=fopen("input.txt","w");
	if(input==NULL)
	{
		printf("Error opening file:\n");
		return -9;
	}
	for( i=0;i<=100;i++)
	{
		fprintf(input," %d ",i);
	}
	printf("written 100 numbers to input file\n");
	fclose(input);

	input = fopen("input.txt", "r");
	if (input == NULL)
	{
		printf("Error opening input file for reading.\n");
		return -1;
	}

	even = fopen("even.txt", "w");
	if (even == NULL) 
	{
		printf("Error opening even file for writing.\n");
		return 1;
	}

	odd= fopen("odd.txt", "w");
	if (odd == NULL)
	{
		printf("Error opening odd file for writing.\n");
		return 1;
	}

	// Read numbers from input file and write to even or odd file based on parity
	while (fscanf(input, " %d ", &i) != EOF)
	{
		if (i % 2 == 0) 
		{
			fprintf(even, " %d ", i);
		} 
		else 
		{
			fprintf(odd, " %d ", i);
		}
	}

	// Close all files
	fclose(input);
	fclose(even);
	fclose(odd);

	printf("\nNumbers separated into even.txt and odd.txt files.\n");

	return 0;
}



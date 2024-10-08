#include <stdio.h>
#include <stdlib.h>

void mergeFiles(FILE *file1, FILE *file2, FILE *output) 
{
	int num1, num2;

	// Read the first number from each file
	int eof1 = fscanf(file1, "%d", &num1);
	int eof2 = fscanf(file2, "%d", &num2);

	// Merge the files
	while (eof1 != EOF && eof2 != EOF) 
	{
		if (num1 < num2)
	       	{
			fprintf(output, "%d\n", num1);
			eof1 = fscanf(file1, "%d", &num1);
		} 
		else 
		{
			fprintf(output, "%d\n", num2);
			eof2 = fscanf(file2, "%d", &num2);
		}
	}

	// Write remaining numbers from file1, if any
	while (eof1 != EOF) {
		fprintf(output, "%d\n", num1);
		eof1 = fscanf(file1, "%d", &num1);
	}

	// Write remaining numbers from file2, if any
	while (eof2 != EOF) {
		fprintf(output, "%d\n", num2);
		eof2 = fscanf(file2, "%d", &num2);
	}
}

int main(int argc, char *argv[])
{
	// Check if correct number of arguments is provided
	if (argc != 4) 
	{
		printf("Usage: %s <data1> <data2> <data>\n", argv[0]);
		return 1;
	}

	// Open the input files for reading
	FILE *file1 = fopen(argv[1], "r");
	FILE *file2 = fopen(argv[2], "r");

	// Check if files opened successfully
	if (file1 == NULL || file2 == NULL) 
	{
		printf("Error opening input files.\n");
		return 1;
	}

	// Open the output file for writing
	FILE *output = fopen(argv[3], "w");
	if (output == NULL)
       	{
		printf("Error opening output file.\n");
		return 1;
	}

	// Merge the files
	mergeFiles(file1, file2, output);

	// Close all files
	fclose(file1);
	fclose(file2);
	fclose(output);
	printf("Files merged successfully.\n");
	return 0;
}

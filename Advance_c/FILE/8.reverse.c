//8	Write a program to write a set of characters to a file, and read and print the contents in reverse.

#include<stdio.h>
int main() 
{
	FILE *fp = NULL;
	char ch;
	char buff[20];int i;
	fp = fopen("rev.txt", "w+");
	if (fp == NULL)
       	{
		printf("Error opening file.\n");
		return -1;
	}

	printf("Enter characters to write to the file: \n");
	scanf("%s",buff);
	fputs(buff,fp);
	
	rewind(fp); // Rewind file pointer to the beginning of the file

	printf("\nContents of the file in reverse order: \n");
	fseek(fp, 0, SEEK_END); // Move file pointer to the last character
	int size=ftell(fp);
       	for(i=size;i>=0;i--)
	{
		fseek(fp,i,SEEK_SET);
		ch = fgetc(fp);
		printf("%c", ch);
	}
	printf("\n");
	fclose(fp);
	return 0;
}

















//2.Open the file  in append mode, and write new numbers to it, and print entire content of the file.
#include<stdio.h>
int main()
{
	FILE * file=NULL;int a;
	file=fopen("abc.txt","a");
	if(file==NULL)
	{
		printf("Error fail:");
		return -1;
	}
	printf("Enter numbers in file:");
	while(1)
	{
		scanf(" %d",&a);
		if(a==-1)
		{
			break;
		}
		fprintf(file,"%d",a);	
	}
	fclose(file);
	

	file=fopen("abc.txt","r");
	if(file==NULL)
	{
		printf("Error fail:");
		return -1;
	}
	printf("contents of file:");
	while(fscanf(file ,"%d", &a)!=EOF)
	{
		printf("%d",a);
	}
	printf("\n");
	fclose(file);
	return 0;
}



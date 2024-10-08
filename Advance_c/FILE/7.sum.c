/*7	Write a program that reads a file containing integers and appends the sum of all integers at the end.*/
#include<stdio.h>
#include<stdlib.h>
int main()
{

	FILE *fp;
	int a,sum=0;
	fp=fopen("int.txt","r");
	if(fp==NULL)
	{
		printf("Error open fail:\n");
		exit(0);
	}
	while((fscanf(fp,"%d",&a))!=EOF)
	{
		sum=sum+a;
	}		
	printf("Sum is :%d\n",sum);
	fclose(fp);


	fp=fopen("int.txt","a");
	if (fp==NULL)
	{
		printf("Error opening:");
		exit(0);
	}
	fprintf(fp,"\n%d",sum);
	fclose(fp);
	return 0;
}





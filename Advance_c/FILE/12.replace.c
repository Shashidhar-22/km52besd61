/* Assume that there is a file with 0 to 1000 numbers. Take input of two integers, and replace the first integer with next.
 * Eg., 365 ,563
 * 365 must be replaced everywhere with 563*/

#include<stdio.h>
int main()
{
	FILE *fp;
	int n,c,b;
	fp=fopen("rep.c","w+");
	if(fp==NULL)
	{
		printf("Error open fail:\n");
		return -1;
	}
	for(int i=0;i<=1000;i++)
	{
		fprintf(fp,"%d ",i);
	}
	printf("Entered numbers to replace file :\n");
	rewind(fp);
	printf("enter integers\n");
	scanf("%d%d",&b,&c);
	while(fscanf(fp,"%d",&n)!=EOF)
	{
		if(n==b)
		{
			fseek(fp,-sizeof(int)+1,1);
			fprintf(fp," %d ",c);
		}
	}
	fclose(fp);
}

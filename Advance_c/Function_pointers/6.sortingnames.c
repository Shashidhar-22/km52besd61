#include <stdio.h>
#include<string.h>

int main()
{
	int m,n,s;
	printf("enter the row and column:");
	scanf("%d%d",&n,&m);
	char arr[n][m],temp[50];
	int i=0,j;
	printf("Enter the names:");
	for(i=0;i<n;i++)
	{
		scanf(" %s",arr[i]);
	}    

	printf("select operation \n 0:for string compare\n 1:for string case sensitive\n");
	scanf("%d",&s);

	int (*p[2])(const char *,const char *)={strcmp,strcasecmp};

	for(i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{

			if(p[s](arr[i],arr[j])>0)
			{
				strcpy(temp,arr[i]);
				strcpy(arr[i],arr[j]);
				strcpy(arr[j],temp);

			}
		}

	}

	for(int i=0;i<n;i++)
	{
		printf("%s\n",arr[i]);
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mysort(char *arr[], int n, int s, int sort, int argc);

int main(int argc, char *argv[])
{
	if(argv[1][0] == '-')
	{
		if(argv[1][1] == 'r' && argv[2][0] == '-' && argv[2][1] == 'i')
			mysort(argv,3,1,0,argc);	
		else if(argv[1][1] == 'r')
			mysort(argv,2,0,0,argc);	
		else if(argv[1][1] == 'i')
			mysort(argv,2,1,1,argc);	
	}
	else
		mysort(argv,1,0,1,argc);	
}

void mysort(char *arr[], int n, int s, int sort, int argc)
{
	int i,j;
	int (*sel[])(const char *, const char *) = {strcmp,strcasecmp};
	
	for(i=n;i<argc;i++)
	{
		for(j=n;j<argc-1;j++)
		{
			if(sort==1)
			{
				if(sel[s](arr[j],arr[j+1])>0)
				{
					char temp[20];
					strcpy(temp,arr[j]);
					strcpy(arr[j],arr[j+1]);
					strcpy(arr[j+1],temp);
				}
			}
			else
			{
				if(sel[s](arr[j],arr[j+1])<0)
				{
					char temp[20];
					strcpy(temp,arr[j]);
					strcpy(arr[j],arr[j+1]);
					strcpy(arr[j+1],temp);
				}


			}
		}
	}

	printf("The sorting of array is: ");
	for(i=n;i<argc;i++)
		printf("%s, ",arr[i]);
	printf("\n");
}

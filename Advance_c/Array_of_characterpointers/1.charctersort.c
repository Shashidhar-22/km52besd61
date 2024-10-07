#include<stdio.h>
#include<string.h>
int main()
{
	char *str[]={"January","Febrary", "March","April","May","June","July","Augest","september","Octember","November","December"};
	int i=0; 
	char *temp;
	printf("Before sorting strings are:\n");
	for(;i<(sizeof(str)/sizeof(str[0]));i++)
	{
		printf("%s  ",str[i]);

	}
	printf("\n");
	printf("After sorting the strings:\n");
	for(i=0;i<(sizeof(str)/sizeof(str[0]));i++)
	{
		for(int j=i+1;j<(sizeof(str)/sizeof(str[0]));j++)
		{
			if(strcmp(str[i],str[j])>0)
			{
				temp=str[i];
				str[i]=str[j];
				str[j]=temp;
			}

		}
	}
	for(i=0;i<(sizeof(str)/sizeof(str[0]));i++){
	printf("%s  ",str[i]);}
	printf("\n");
}



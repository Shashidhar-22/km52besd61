#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
	{
		int i,j,k,n;
		printf("Enter the size of string:");
		scanf("%d",&n);
		char ray[n],ben[n],kelvin[n];

		printf("Enter a string:");
		scanf(" %s", ray);
	
		for(i=0;ray[i];i++)               //|| ben[j] || kelvin[k] ;i++,j++,k+	{
		{
			if(ray[i+2])
			{
				ben[i]=ray[i+2];
			}
			if(ray[i])
			{
				ben[i+2]=ray[i];
			}




		}
		printf("%s\n",ray);
		printf("%s\n",ben);
		printf("%s\n",kelvin);

		

		
		





return 0;
	}

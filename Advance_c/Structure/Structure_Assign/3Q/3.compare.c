#include<stdio.h>
#include"compare.h"
#include<string.h>
struct student s1,s2;
int main()
{
	int i,r,s;
	for(i=0;i<2;i++)
	{
		printf("Enter the ID 1:");
		scanf("%d",&s1.ID);
		printf("Enter the name 1:");
		scanf(" %[^\n]s",s1.name);
		printf("Enter the ID 2:");
		scanf("%d",&s2.ID);
		printf("Enter the name 1:");
		scanf(" %[^\n]s",s2.name);

		r=IDcmp(s1,s2);
		s=namecmp(s1,s2);
		if(r==0)
			printf("both id's are same\n");
		else
			printf("both id's are different\n");

		if(s==0)
			printf("both name's are same\n");
		else
			printf("both name's are different\n");
		return 0;
	}
}
	int IDcmp(struct student s1,struct student s2)
	{
		if(s1.ID==s2.ID)
			return 0;
		else 
			return 1;
	}
	int namecmp(struct student s1,struct student s2)
	{
		if (strcmp(s1.name,s2.name)==0)
			return 0;
		else
			return 1;

	}



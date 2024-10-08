#include<stdio.h>
#include"count.h"
#include<string.h>
int main()
{
	int n,boy=0,girl=0,Trans=0;
	printf("Enter number of student: ");
	scanf("%d",&n);
	struct student s[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter student %d name: ", i+1);
		scanf(" %[^\n]s",s[i].name);
		printf("Enter student %d gender : ",i+1);
		scanf(" %c",&s[i].gender);
	}

	for(int i=0;i<n;i++){
		if((s[i].gender=='m'|| s[i].gender=='M'))
			boy++;
		else if((s[i].gender=='f'|| s[i].gender=='F'))
			girl++;
		else if((s[i].gender=='o'||s[i].gender=='O'))
				Trans++;
	}
	printf("total no of boys in class room is: %d\n",boy);
	printf("total no of girls in class room is %d\n",girl);
	printf("others:%d\n",Trans);


	








}

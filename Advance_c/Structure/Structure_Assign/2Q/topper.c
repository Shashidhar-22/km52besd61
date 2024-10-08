#include<stdio.h>
#include "2.arrheader.h"

float percentage(int arr[6])
{
	int sum=0;
	for(int i=0;i<6;i++)
		sum=sum+arr[i];
		 sum/=6;
	return sum;
}
int main()
{
	int n;
	float p,total=0;
	printf("Enter number of student: ");
	scanf("%d",&n);
	struct student s[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter student ID: ");
		scanf("%d",&s[i].ID);
		printf("Enter student name: ");
		scanf("%s",s[i].name);
		printf("Enter student 6 subjects marks:\n");
		for(int j=0;j<6;j++)
			scanf("%d",&s[i].marks[j]);
		printf("Enter student DOJ: ");
		scanf("%d%*c%d%*c%d",&s[i].d,&s[i].m,&s[i].y);
		p=percentage(s[i].marks);
		s[i].per=p;
		if(total<p)
			t=i;
		getchar();
		printf("Enter student Gender: ");
		scanf("%c",&s[i].gender);
	}
	printf("\n\n");
	printf("\n\nTOPPER OF STUDENTS");
	printf("ID : %d\nName : %s\nMarks : %d %d %d %d %d %d\nDOB : %d-%d-%d\nPercentage : %.2f%%\nGender : %c\n",s[t].ID,s[t].name,s[t].marks[0],s[t].marks[1],s[t].marks[2],s[t].marks[3],s[t].marks[4],s[t].marks[5],s[t].d,s[t].m,s[t].y,s[t].per,s[t].gender);
}

/*10	Write a program, using structures to read details of n students,with details,ID,name,fathername,date of birth and marks, and write those details to a file, one line per student, each detail separated by a comma. The first record must be a Heading. Open the file with .csv extension.   */



#include<stdio.h>
#include<stdlib.h>

struct student
{
	int id;
	char name[20];
	char fathernamme[20];
	int d,m,y;
	int marks;
};
int main()
{
	int n;
	FILE *fp=fopen("e10.csv","a+");
	if(fp==NULL){
		printf("open fail");
	}
	printf("enter the no.of students");
	scanf("%d",&n);
	struct student s[n];
	for(int i=0;i<n;i++)
	{
		printf("enter id,name,fathername,dob,marks");
		scanf(" %d %s %s %d-%d-%d %d",&s[i].id,s[i].name,s[i].fathernamme,&s[i].d,&s[i].m,&s[i].y,&s[i].marks);
		fprintf(fp,"id:%d name:%s fathername:%s dob:%d-%d-%d marks:%d\n",s[i].id,s[i].name,s[i].fathernamme,s[i].d,s[i].m,s[i].y,s[i].marks);

	}
	fclose(fp);
}

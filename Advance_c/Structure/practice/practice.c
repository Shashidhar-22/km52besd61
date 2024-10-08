#include<stdio.h>
struct student       //student is tag name
{
	int a;			//a,name,f are structure members
	char name[100];
	float f;
};
int main()
{
	struct student s1;				//s1,s2,s3,a1 are structure members.
	struct student s2={10,"mahesh babu",10.0003};
	struct student a1={123,"ramulu",100};
	struct student s3;
	s3=s2;

	
	printf("Enter info of student 1: ");
	scanf("%d %s %f \n ",&s1.a,&s1.name,&s1.f);
	printf("edi student 1 dhi:");
	printf("%d %s %f \n ",s1.a,s1.name,s1.f);	

	printf("info of student 2: ");
	printf(" %d %s %f \n",s2.a,s2.name,s2.f);

	printf("info of student 3: ");
	printf(" %d %s %f \n",a1.a,a1.name,a1.f);

	printf("info of student 4:");
	printf(" %d %s %f \n",s3.a,s3.name,s3.f);


}


#include<stdio.h>
#include"1.header.h"
float percentage(struct student s1 );
struct student s1;
int main()
{
	int i;
	float s;
	printf("Enter the student Id : ");
	scanf("%d",&s1.ID);
	printf("Enter the student name : ");
	scanf(" %[^\n]s",s1.name);
	printf("Enter the 6 subjects marks :");
	for(i=0;i<6;i++){
		scanf("%d",&s1.marks[i]);}
	printf("Enter the date of join : ");
	scanf("%d%*c%d%*c%d",&s1.d,&s1.m,&s1.y);
	s=percentage(s1);
	printf("Enter the student gender : ");
	scanf(" %c",&s1.gender);
	printf("\n\n");
	printf("Details of student is :\n ");
	printf("ID NO:%d\nName:%s\n",s1.ID,s1.name);
	printf("student marks:");
	for(int i=0;i<6;i++){
		printf("%d\t",s1.marks[i]);}
	printf("\n");
	printf("student marks percentage :%.2f\nGender:%c\n",s,s1.gender);

}
float percentage(struct student s1)
{
	int a=0;
	for(int i=0;i<6;i++){
		a=a+s1.marks[i];}
	a/=6;
	return  a;
}






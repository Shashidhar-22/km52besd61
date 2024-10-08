#include<stdio.h>
#include"student.h"
void print(struct student s1);
struct student s1 = {22,"shashidhar",1, 6, 2000, 22, 6 ,2000,'m'},s2,s4;
int main()
{
	print(s1);
}


void print(struct student s1){
	//int s=sizeof(struct student);
	//printf("sizeof structer:%d\n",s);
	printf("student 1 information : ");
	printf("student ID: %d | student name: %s | student DOB: %d-%d-%d | Student joining: %d %d %d | gender: %c \n",s1.ID,s1.name,s1.d1,s1.m1,s1.y1,s1.d2,s1.m2,s1.y2,s1.gender);
	printf("Enter the information of student 2 :");
	scanf("%d %s%d-%d-%d%d-%d-%d %c",&s2.ID,&s2.name,&s2.d1,&s2.m1,&s2.y1,&s2.d2,&s2.m2,&s2.y2,&s2.gender);
	printf("student ID: %d | student name: %s | student DOB: %d-%d-%d | Student joining: %d %d %d | gender: %c\n ",s2.ID,s2.name,s2.d1,s2.m1,s2.y1,s2.d2,s2.m2,s2.y2,s2.gender);
	s4=s1;
	printf("student ID: %d | student name: %s | student DOB: %d-%d-%d | Student joining: %d %d %d | gender: %c\n ",s4.ID,s4.name,s4.d1,s4.m1,s4.y1,s4.d2,s4.m2,s4.y2,s4.gender);
}


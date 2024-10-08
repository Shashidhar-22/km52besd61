#include<stdio.h>
	struct student    
	{
		int rollno;
		char name[10];
		float marks;

	};
int main()
{
	//struct student s[5]	//array with  5 elements of 5 objects
	struct student s[5]; 
	for ( int i=0;i<5;i++)
	{
	//	printf("Enter the  rollno,name,marks of student  %d:\n",i);
		scanf("%d%s%f\n",&s[i].rollno,&s[i].name,&s[i].marks);  //asking user to entrt th e data   (for string '&' not required default is there)

	}
	
	for ( int i=0;i<5;i++)
	{
		printf("%d %s %f\n",s[i].rollno,s[i].name,s[i].marks);
	}
}




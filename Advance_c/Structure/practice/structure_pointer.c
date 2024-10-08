#include<stdio.h>
//structrue pointer
//pointer points the address of memory block that stores structure is called structure pointer.
struct student{
	int rollno;
	char name[20];
	float marks;

};
int main()
{
	struct student su={22,"jenny",100}; //compile time initilization.
	struct student s1={61,"shashidhar",70};					    
	struct student *ptr=&su;
	printf("info of student 0: ");
	printf("%d %s %f\n",ptr->rollno,(*ptr).name,ptr->marks);

	printf("info of student 1:");
	ptr=&s1;
	printf("%d %s %f\n",ptr->rollno,(*ptr).name,ptr->marks);    //ptr->rollno (or) (*ptr).rolno are same.
}


#include<stdio.h>
struct stu1
{
	int x;
	char y;
	short z;
};

struct stu2
{
	
	char y;
	int x;
	short z;
};

struct stu3
{
	short z;
	char y;
	int x;
};
struct stu4
{
	char y;
	short z;
	int x;
};

int main()
{
	printf("%ld  %ld  %ld  %ld\n",sizeof(struct stu1),sizeof(struct stu2),sizeof(struct stu3),sizeof(struct stu4 ));

return 0;
}

#include<stdio.h>
struct stu
{
	int x;	
	int y;
};

int main()
{
	
	struct stu p={1};
	struct stu p1={1};
	if(p==p1)
	printf("equal");
	else
		printf("not equal");
	
}

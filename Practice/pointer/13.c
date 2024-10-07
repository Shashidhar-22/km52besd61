#include<stdio.h>
int main()
{
int var=10;
int *ptr=&var;
*ptr=5;
printf("var=%d &*ptr=%d var*",var,*ptr);
}


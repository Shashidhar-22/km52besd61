#include<stdio.h> 
int main()
{
int arr1[]={1,2,3,4,5};
int arr2[]={100,200,300,400,500};
//int s=sizeof(arr1)+sizeof(arr2);
//int arr3={};
printf("arr3[]={");
for(int i=0;i<5;i++)
{
printf("%d %d ",arr2[i],arr1[i]);
//arr3[i]=arr2[i];
//arr3[i+1]=arr1[i];
}
printf("}");
//printf("%ld",sizeof(arr3));
//for(int i=0;i<sizeof(arr3);i++)
//{
//printf("%d",arr3[i]);
}


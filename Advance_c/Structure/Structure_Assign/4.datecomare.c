#include<stdio.h>
struct student {
	int d,m,y;
};
struct student oldeststudent(struct student s[],int) ;
struct student p;
int main()
{
	int i,n;
	printf("Enter the no of dates:");
	scanf("%d",&n);
	struct student s[n];
	for (i=0;i<n;i++)
	{
		printf("Enter student %d DOB :",i+1);
		scanf("%d%*c%d%*c%d",&s[i].d,&s[i].m,&s[i].y);
	}
	p= oldeststudent(s,n);
	printf("%d-%d-%d is oldest\n",p.d,p.m,p.y);
	return 0;


}
struct student oldeststudent(struct student s[],int n)
{
	int d1=0,m1=0,y1=0,i,j=0;
	d1=s[0].d;m1=s[0].m;y1=s[0].y;
	for (i=0;i<n;i++)
	{
		if((y1>s[i].y)||((y1==s[i].y))&&(m1>s[i].m)||(y1==s[i].y)&&(m1==s[i].m)&&(d1>s[i].d))
		{
			d1=s[i].d;m1=s[i].m;y1=s[i].y;j=i;
		}
	}
	return s[j];
}

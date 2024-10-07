#include<stdio.h>
#include<string.h>
int main()
	{
	char *month[]={"NULL","January","Febrary", "March","April","May","June","July","Augest","september","Octember","November","December"};
	       
		int d,m,y;
		printf("Enter the date of birth:\n");
		scanf("%d%*c%d%*c%d",&d,&m,&y);
	switch(d)
	{
		case 1:
		case 21:
		case 31:
			printf("%dst ",d);break;
		case 2:
		case 22:
			printf("%dnd ",d);break;
		case 3:
		case 23:
			printf("%drd ",d);break;

		case 4 ... 20:
		     	printf("%dth ",d);break;
		case 24 ... 30:
			printf("%dth ",d);break;
	}
	for(int i=0;i<(sizeof(month)/sizeof(month[0]));i++)
	{
		if(m==i)
			printf("%s, ",month[i]);
	}
	printf("%d\n",y);
	}

	


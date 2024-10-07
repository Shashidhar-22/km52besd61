#include <stdio.h>
int main()
{
	char *arr[]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","Twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	char *arr1[]={"","twenty","thirty","fouty","fivty","sixty","seventy","eighty","ninety"};
	char *arr2[]={"hundreed","thousands","lakhs","croes"};
	char *c[20];
	int x,r,i,h=0,s=0;
	printf("enter input:");
	scanf("%d",&x);
	for(i=0;x;i++)
	{
		if(h==1)
		{
			r=x%10;         x=x/10;
			c[i]=arr[r-1];
		}
		else
		{
			r=x%100;        x=x/100;
			if(r<20)
				c[i]=arr[r-1];
			else
			{
				c[i]=arr[(r%10)-1];
				r=r/10; i++;
				c[i]=arr1[r-1];
			}
		}
		h++;
		if(x)
		{
			i++;        c[i]=arr2[s];      s++;
		}
	}
	while(i--)
		printf("%s ",c[i]);
	printf("\n");
	return 0;
}


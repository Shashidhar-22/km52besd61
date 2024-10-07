#include<stdio.h>
int main()
{
	int i,j,c=0,p=0;
	int arr[10]={3,4,5,1,2,6,7,4,4,8};
	for(i=0;i<10;i++)
	{
		for(j=1;j<10;j++)
		{
			if(arr[i]<arr[j])
			{
				c++;
			else
			p=c;
			c=0;
			}

			if(arr[i]<arr[j])
			{	
			c++;
			else
				p=c;
				c=0;
				}

				if(arr[i]<arr[j])
				{
					c++;
				}
		}
			
			printf("%d\n",p);

}
}


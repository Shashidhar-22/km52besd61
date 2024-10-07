#include<stdio.h>
int main()
{
	int N,i,sum=0,j,c=0,k;
	int arrA[N];
	printf("Enter the size of arry:");
	scanf("%d",&N);
	printf("Enter array elements:");
	for( i=0;i<N;i++)
	{
		scanf("%d",&arrA[i]);
	}

	for( i=0;i<N;i++)
	{
		sum |= arrA[i];
		if(sum==arrA[i+1])
		{
			c++;
		}
	}
	printf("output bitwise is :%d\n",sum);

	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(arrA[i]==arrA[j])
			{
				//c++;
				for(k=j;k<N;k++)
				{
					arrA[k]=arrA[k+1];
			//		c++;
				}
				j--;
				N--;
			}

		}
	}

	for(i=0;i<N;i++)
	{
//		printf("THe array elements are:%d\n",arrA[i]);
		
	}

	//printf("output bitwise is :%d\n",sum);
	printf("output is :%d\n",c);
return 0;
}


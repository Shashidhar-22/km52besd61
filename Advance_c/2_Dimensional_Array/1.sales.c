#include<stdio.h>
int main()
{
  int r,c;
  printf("Enter rows and coloumns :\n");
  scanf("%d%d",&r,&c);
  int i,j,sum=0;
  int arr[r][c];
  int printrow[r];
  int printcoloumn[c];
  printrow[0] = 0;
  printcoloumn[0] = 0;
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      scanf("%d",&arr[i][j]);
      printrow[i] += arr[i][j];
      printcoloumn[j] += arr[i][j];
      sum += arr[i][j];
    }
  }
  for(i=0;i<r;i++)
  {
     printf("SALEMAN:%d total sales:%d\n",i,printrow[i]);
  }
  for(j=0;j<c;j++)
  {
     printf("TOTAL SALES FOR ITEM:%d : %d\n",j,printcoloumn[j]);
  }
  printf("TOTAL SALES : %d\n",sum);
}

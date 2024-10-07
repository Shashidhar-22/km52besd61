#include<stdio.h>
int main()
{
  int r,c,i,j;
  printf("Enter rows and coloumns :\n");
  scanf(" %d%d",&r,&c);
  char str[r][c];
  for(i=0;i<r;i++)
  {
     printf("Enter the name : ");
     scanf("%s",str[i]);
  }

  for(i=0;i<r;i++)
  {
	  for(j=0;str[i][j];j++)
	  {
	     printf("%c",str[i][j]);
	  }
	  printf("\n");
  
  }
}

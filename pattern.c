#include<stdio.h>
int main()
{
    int row,i,j;
    printf("Enter the row size\n");
    scanf("%d",&row);
    for(i = 0;i < row;i++)
    {
	for(j = 0;j < row*2-1;j++)
	{
	    if(j >= row-(i-1) && j <= row+(i-1))
	    {
		printf("*");
	    }
	    else
	    {
		printf(" ");
	    }
	}
	printf("\n");
    }
    return 0;
}

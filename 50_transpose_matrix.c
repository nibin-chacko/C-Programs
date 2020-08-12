/*Name:Nibin chacko
 * Date:24/1/2020
 * Description:To find the transpose 
 * Input:
 *        Row :2
          Coloum :2
          1 2
          3 4
  Output:
         Enterd matrix 
           1 2 
           3 4 
         Transpose matrix 
           1 3 
           2 4 
         Product matrix
           5 11 
           11 25 
 */    
#include<stdio.h>
int main()
{
    char ch;
    do
    {
    int row,col,val=0;
    printf("Row :");
    scanf("%d",&row);            //scan the row
    printf("Coloum :");
    scanf("%d",&col);            //scan the col
    int a[row][col];
    for(int i=0;i < row;i++)    //loop for store the values
    {
	for(int j = 0;j < col;j++)
	{
	    scanf("%d",&a[i][j]);
	}
    }
    printf("Enterd matrix \n");
    for(int i = 0;i < row;i++)          //loop fo print the matrix
    {
	for(int j = 0;j < col;j++)
	{
	    printf("%d ",a[i][j]);
	}
	printf("\n");
    }
    int b[col][row];                 //2d array for storing the transpose
    for (int i = 0;i < row;i++)       //loop for storing the transpose
    {
	for(int j = 0;j < col;j++)
	{
	    b[j][i] = a[i][j];
	}
    }
    printf("Transpose matrix \n");
    
    for(int i = 0;i < col;i++)    //loop for print the transpose matrix
    {
	for(int j = 0;j < row;j++)
	{
	    printf("%d ",b[i][j]);
	}
	printf("\n");
    }
    int c[row][row];
    printf("Product matrix\n");
    for(int i = 0;i < row;i++)        //loop for multiply the matrix
    {
	for(int j = 0;j < row;j++)
	{
	    for(int k = 0;k < col;k++)
	    {
		val = (a[i][k] *b[k][j])+val;
	    }
	    printf("%d ",val);    //print the value
	    c[i][j] = val;
	    val = 0;
	}
	printf("\n");
    }
    getchar();
    printf("Do you want to continue y/n :");  
    scanf("%c",&ch);
    }
    while(ch == 'y');   //loop for continue the program
    return 0;
}

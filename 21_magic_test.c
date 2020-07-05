/*Name :Nibin chacko
 * Date:5/6/2020
 * Description:To find magic square of 3*3 matrix
 * Input:Enter a number:3
 * Output:(1,2)=1
          (0,0)=2
          (2,1)=3
          (2,0)=4
          (1,1)=5
          (0,2)=6
          (0,1)=7
          (2,2)=8
          (1,0)=9*/
#include<stdio.h>
void check(int *i,int *j,int n);
int main()
{
    int n,i,j,k;
    printf("Enter a number:");
    scanf("%d",&n);
    printf("\n");
    if(n%2==0)                //check the enterd number even
    {
	printf("Enter the valid input!!!!!!!!!!!!!!\n");
    }
    else
    {
	int a[n][n];
	for(i=0;i<n;i++)      //fill -1 at all coloums
	{
	    for(j=0;j<n;j++)
	    {
		a[i][j]=-1;
	    }
	}
	
	
    k=1;
    
    
    for(i=n/2;i<n&&k<(n*n+1); )   //loop for taking row
    {
	for(j=n-1;j<n&&k<(n*n+1); )  //loop for taking coloum
	{
	    if(a[i][j] != -1)       //check the i th row and j th coloum are filled or not
	    {
		i=i+1;
		j=j-2;
	    }
	    check(&i,&j, n);         //call the function for checking the value of i and j
	   /* if( i == -1 && j ==n)   //
	    {
		i=0;
		j=n-2;
	    }*/
	    a[i][j]=k;        //assigning the value
	   k++;
	    i=i-1;   //decrease the value of i
	    j=j+1;   //increase the value of j
	    check(&i,&j,n); //again call the function for checking the i and j
	   /* if( i == -1 && j == n)
	    {
		i=0;
		j = n-2;
	    }
	    if(i==-1)
	    {
    
		i=n-1;
	    }
	    if(j==n)
	    {
		j=0;
	    }*/
	}
     }
    for(i=0; i<n; i++)
    {
    for(j=0; j<n; j++)
	printf("%3d", a[i][j]);
    printf("\n");
    }

   }
}
void check(int *i,int *j,int n)    //function decleration
{
	    if( *i == -1 && *j ==n)   // check the i is -1 and j is n
	    {
		*i=0;
		*j=n-2;
	    }
	    if(*i==-1)        //check if i is -1
	    {
    
		*i=n-1;
	    }
	    if(*j==n)        //check if j is n
	    {
		*j=0;
	    }
}



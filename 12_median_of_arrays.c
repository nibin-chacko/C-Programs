/*
  Auther : Nibin chacko
  Date : 27-6-2020 
  Description : To find the median of two arrays
  Input : Enter the 'n' value for Array A: 5
	  Enter the elements one by one for Array A: 3 2 8 5 4
	  Enter the 'n' value for Array B: 5
	  Enter the elements one by one for Array A: 12 3 7 8 5
  Output : Median = 5.5 
*/

#include <stdio.h>

int main()
{
    int size1,i,j,temp,k,n;
    double med;
    char ch;
    do
    {
	printf("Enter the number of array\n");
	scanf("%d",&n); //for n number of array
	double median[n];    
	for ( k = 1; k <= n; k++ )
	{
	    printf("Enter the number of elements of array %d : ",k);
	    scanf("%d",&size1);
	    int a[size1];
	    if ( size1 > 10 )
	    {
		printf("Max array elements exceeded\n");
		break;
	    }
	    else
	    {
		printf("Enter the elements : ");
		for ( i = 0; i < size1; i++ )
		    scanf("%d",&a[i]);
		for ( i = 0; i < size1; i++ )  //sorting
		{
		    for ( j = i; j < size1; j++ )
		    {
			if ( a[i] < a[j] )
			{
			    temp=a[i];
			    a[i]=a[j];
			    a[j]=temp;
			}
		    }
		}	   		
		if ( size1%2 == 1 )
		    median[k]= a[size1/2]; //median for odd array
		else 
		    median[k]= (a[(size1/2)-1]+a[size1/2])/2.0; //median for even array
	    }
	}
	for ( k = 1; k <= n; k++ )
	{
	    med=med+median[k];//finding median
	}
	med=med/n;
	printf("Median = %f\n",med); //printing median
	getchar();
	printf("Do you want to continue (y/n) : ");
	scanf("%c",&ch);
    }while(ch=='y');

    return 0;
}

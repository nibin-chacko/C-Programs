//Author:Nibin Chacko
//date:19/6/2020
//Description:Check the enetrd number is odd or even
//input:1
//output:It is a positive odd
#include <stdio.h>
#include <math.h>
int main()
{
    char c;
    do
    {
    int num1;
    printf("Enter the number\n");
    scanf("%d",&num1);
    if (num1 == 0)
    {
	printf("This is neighter positve or negative\n");
    }
    
    else if(num1>pow (2,10))                           //condition check if the enterd number is less than 2^10
    {
	printf("Enter the valid number\n");
    }
    
    else if ( (num1%2)==0 )                       //condition is false then check the statement
    {
	if (num1>0)
	{
          printf("%d is a positive even number\n",num1);
	}
	else
	{
	    printf("%d is a negative even number\n",num1);
	}
    }
    else
    {
	if (num1>0)
	{
	    printf("%d is a positive odd number\n",num1);
	}
	else
	{
	    printf("%d is a negative odd number\n",num1);
	}
    }
    getchar ();
    printf("Do you want to continue y or n\n");
    scanf("%c",&c);
    }
    while ( c=='y' );          //again running statement

    return 0;
}


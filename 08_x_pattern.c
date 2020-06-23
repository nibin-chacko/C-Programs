//Author:Nibin chacko
//Date:23/6/2020
//Description:print the hello in x format
//input:6
//output:
//HELLO    HELLO
// HELLO  HELLO 
 // HELLOHELLO  
  //HELLOHELLO  
 //HELLO  HELLO 
//HELLO    HELLO
#include <stdio.h>
#include <math.h>
int main()
{
    int num;
    int i;
    int j;
    int mid;
    char c;
    do
    {
    printf("Enter the range\n");
    scanf("%d",&num);
    mid=1+(num/2);
    if( (num>pow(2,5)) || (num<3) )      //check the input is greater than 2^5
    {
	printf("Enterd number is out of range\n");
    }
    else
    {
    for(i=1 ;i<=num;i++)
    {
	for(j = 1;j <= num;j++ )
	{
	    if(i==j || j+i==num+1 )  //print hello in starting and end of the line
	    {
		printf("HELLO");
		if ( num%2 ==1 )
		{
		if (i == mid)     //to take mid value for odd values
		{
		    printf("HELLO");
	        }
	        else
	        {
		 printf(" ");
	        }
	       }
	    }
       else
	printf(" ");
       }

	printf("\n");
    }
	
    }
    getchar();
    printf("Do you want to continue\n");
    scanf("%c",&c);
    }
    while(c == 'y');
    return 0;
    
}


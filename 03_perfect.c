//Author:Nibin chacko
//date:21/6/2020
//Description:find the perfect numbers
//input:6
//output:It is a perfect number
#include <stdio.h>
int main()
{
    int num;
    int i;
    int sum;
    float x;
    char c;
    
    do
    {
    sum=0;                    //initialise sum=0
    printf("Enter the number\n");
    scanf("%d",&num);
    if(num <= 0)
    {
	printf("Invalid number\n");
    }
    else
    {

    for(i = 1;i < num;i++)
    {
	x=(num%i);                //Take mode of enterd number
	if(x == 0)        
	{
	sum=i+sum;                //increment the value of sum according to the value of i
    }
    }
    if(sum == num)               //if the num and sum same then print it is a perfect number
    {
	printf("It is a perfect number\n");
    }
    else
    {
	printf("It is not a perfect number\n");
    }
    getchar();
    printf("Do you want to continue y or n\n");
    scanf("%c",&c);
    }
    }
    while(c == 'y');
    return 0;

	
}

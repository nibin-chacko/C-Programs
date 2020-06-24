//Name:Nibin chacko
//Date:24/6/2020
//Description:Check the given number is odd or Even
//input:Enter the value of 'N':4
//output:4 is even number

#include <stdio.h>
int main()
{
    int n;
    char c;
    do
    {

    printf("Enter the value of 'N':");
    scanf("%d",&n);
    if(n == 0)
    {
	printf("This is not an evan and odd\n");
    }
    else if( n & 1)                //check the n value 0 or 1
    {
	printf("%d is odd number\n",n);
    }
    else
    {
	printf("%d is even number\n",n);
    }
    getchar();
    printf("Do you want to continue y or n\n");
    scanf("%c",&c);
    }
    while(c == 'y');
    return 0;
}




















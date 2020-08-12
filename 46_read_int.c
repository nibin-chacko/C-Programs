/*
Author:Nibin chacko
Date:29/1/2020
assignment name:scanf.c
input:enter a number 7568
output:7568
input:enter a number -7568
output:-7568
*/
#include<stdio.h>
void scan(int *num)   // function for read a value from getchar
{
    int ch,value = 0;
int flag=0;    
	int s=1;
    while((ch = getchar()) != ' ')   // checking space to get end point of the number 
    {
	if ( ch == 45) // condition for -(negative)
	{
	    s = -1;
	    continue; // continue the procee
	}
	if(ch == 43 ) // condition for +(positive)
	{
	    continue;   // continue
	}
	if ( 48 <= ch && ch <= 57 ) // check number (0 to 9) in octal value
	{

	   value= value * 10 + (ch - 48); // store in the variables
	}
	else
	{
	    break;  // when start with charactor break the loop
	}
    }
    if (s == -1)
    {
    *num=s*(value); // store the value in address of num
    }
    else
    {
	*num=value;
    }
}
int main()   // main function
{
    int num;
    printf("enter a number ");
    scan(&num);   // calling the scan function
 
    printf("%d\n",num);  //print
}

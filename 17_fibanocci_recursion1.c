/*Author:Nibin
 * Date:3/7/2020
 * description:Find the palindrome of a given number
 * input:Enter the number
          10
   output:0
          1
          1
          2
          3
          5
          8
*/



#include<stdio.h>
int fibo(int first,int second,int n);
void fiboo(int first,int second,int n);
int main()
{
    char u;
    do
    {
    int n;
    int first=0,second=1;
    printf("Enter the number\n");
    scanf("%d",&n);
    if(n == 0)               //check the user enterd 0
    {
	printf("%d\n",first);
    }
    else if(n == 1)          //check the user enterd 1
    {
	printf("%d\n%d\n",first,second);
    }
    else if(n > 0)           //check the user enterd number is greaterthan 0
    {
	printf("%d\n%d\n",first,second);
	fibo(first,second,n);    //call function
    }
    else if(n < 0)          //check the user enterd number is less than 0
    {
	printf("%d\n%d\n",first,second);
	fiboo(first,second,n);   //call function
    }
    getchar();
    printf("Do you want to continue y/n\n");
    scanf("%c",&u);
    }
    while(u == 'y');

}


int fibo(int first,int second,int n)    //function declaration
{
    static int c=0;                
    if((first+second) > n)             //check the sum is greater than enterd number
    {
	return 0;
    }
    else
    {
    c=first+second;
    first=second;
    second=c;
    printf("%d\n",c);
    fibo(first,second,n);           //again call the same function
}
}
void fiboo(int first,int second,int n)   //function declaration
{
  if((first-second)<=(-n) && (first-second>=n))  //check the condition
    {
	int c;
	c=first-second;
	printf("%d\n",c);
	first=second;
	second=c;
	fiboo(first,second,n);  //again call the same function
    }
  return;
}

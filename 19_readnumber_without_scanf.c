/*Author:Nibin chacko
 * Date:5/7/2020
 * Description:scan the number without using scanf
 * input:
 *       Enter the number:
         123
 *Output:
          The Enterd number is 123*/
#include<stdio.h>
#include<stdio_ext.h>   //for fpurge(stdin)
int read_num(char *c); //function decleration
int main()
{
    char ch;
    do
    {
	char *num;
	printf("Enter the number:\n");
	__fpurge(stdin);//clear the buffer
	printf("The Enterd number is %d\n",read_num(num));//printing enetrd number
	__fpurge(stdin);//clear the buffer
	printf("Do you want to continue y/n\n");
	scanf("%c",&ch);
    }
    while(ch == 'y');
    return 0;
}

int read_num(char *c)
{
    int i=0,sum=0,n=0;
    for(i=0;(*(c+i)=getchar()),*(c+i) != '\0';i++)
    {
	if( c[i] == '-')
	{
	n = -1;  ///for negative number
        }
    else
    {
	if(*(c+i) >= '0' && *(c+i) <='9')
	{
	    sum=(sum*10)+(*(c+i)-48); //converting asci numbers
	}
    
	else
	{
	    break;
	}
    }

  }
    if( n == -1)
	return -sum;//for negative sign
    return sum; //return number
}

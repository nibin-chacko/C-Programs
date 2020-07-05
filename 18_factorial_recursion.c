/*Name:Nibin chacko
 * Date:5/7/20
 * Description:To find the factorial of given number
 * Input:3
 * output:
 *        6
 */
#include<stdio.h>
int main()
{
    char ch;
    do
    {
    static int n=0,fac=1;  //allow specific space for store the value n and fac
    if(n == 0)          //this check the n is 0 then enter the number
    {
	printf("Enter the number\n");
	scanf("%d",&n);
    }
    if(n == 1)          //this for print the factorial
    {
	printf("The factorial is %d\n",fac);
    }
    else
    if(n<=0)          //condition for invalid input
    {
	printf("Enter the valid input\n");
    }
	else
	{
	    fac=fac*n;    //equation of factorial
	    n--;
	return main();
    }
        n=0;
	fac=1;
    getchar();
    printf("Do you want to continue y/n\n");      //run the loop again
    scanf("%c",&ch);
}
while(ch == 'y');
    return 0;
}

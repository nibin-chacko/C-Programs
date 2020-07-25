/*Author:Nibin Chacko
 * Date:22/12/2019
 * Description:To find the system ile little endian or big endian
 * Input:
         Enter the number
         12345678
 *Output:
        The system is little endian
*/

#include<stdio.h>
int main()
{
    int n;
    char *c;
    printf("Enter the number\n");
    scanf("%d",&n);
    c=(char *)&n;     //take the stored first byte
    printf("%d\n",*c);
    n=n&0xff;            //take the last byte of the enterd number
    printf("%d\n",n);
    if(*c==n)            //condition
    {
	printf("The system is little endian\n");
    }
    else
	printf("The system is big endian\n");
    return 0;
}

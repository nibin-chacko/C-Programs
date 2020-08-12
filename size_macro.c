/*Name:NIBIN CHACKO
 * Date:22/1/2020
 * Description:to find the size of data type using macro
 * Input:./a.out
 * Output:
 * Size of int		:4
   Size of char		:1
   Size of float	:4
   Size of double	:8
   Size of long int	:8
   Size of unsigned int	:4
*/
#include<stdio.h>
#define SIZEOF(a) (char *)(&a+1) - (char *)(&a)      //defining a macro to type cast the address

int main()
{
    int i;
    char j;
    float k;
    double l;
    long int m;
    unsigned int n;
    printf("Size of int\t\t:%ld\n",SIZEOF(i));   //print then size
    printf("Size of char\t\t:%ld\n",SIZEOF(j));   //print then size
    printf("Size of float\t\t:%ld\n",SIZEOF(k));   //print then size
    printf("Size of double\t\t:%ld\n",SIZEOF(l));   //print then size
    printf("Size of long int\t:%ld\n",SIZEOF(m));   //print then size
    printf("Size of unsigned int\t:%ld\n",SIZEOF(n));   //print then size
}

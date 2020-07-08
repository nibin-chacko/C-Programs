/*Author:Nibin Chacko
 *Date:8/7/2020
Description:To swap the enterd numbers
Input:
             Enter the value of a
              10
             Enter the value of b
              20
Output:
           After swapping
             a=20
             b=10

*/
#include<stdio.h>
void fun(int *a,int *b);
int main()
{
    char c;
    do
    {
    int a,b;
    printf("Enter the value of a\n");
    scanf("%d",&a);
    printf("Enter the value of b\n");
    scanf("%d",&b);
    fun(&a,&b);             //call by function
    printf("After swapping\n");
    printf("a=%d\nb=%d\n",a,b);     //print after swapping
    getchar();
    printf("Do you want to continue y/n\n");     //loop for agairn run program
    scanf("%c",&c);
    }
    while(c == 'y');
    return 0;
}



void fun(int *a,int *b)           //function definition
{
    *a=*a^*b;                        //xor the inputs
    *b=*a^*b;
    *a=*a^*b; 
}

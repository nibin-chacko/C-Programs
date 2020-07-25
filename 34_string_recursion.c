/*Author:Nibin chacko
 * Date:27/12/2019
 * Description:To reverse the string using recursion and non recursion
 * Input:Nibin chacko
 *       1.recursion
 *       2.Non recursion
 *Output:
         
	 dlrow olleh
*/




#include<stdio.h>
void nonrecursion(char c[],int count);
void recursion(char *c);
int main()
{char m;
    do
    {
    char c[100];
    int count=0,i,op;
    //fgets(c,50,stdin);
    printf("Enter the string\n");
    scanf("%100[^\n]",c);
    for(i=0;c[i]!=0;i++)     //loop for count the length of a string
    {
	count++;
    }
    printf("1.Recursion\n2.Non Recursion\n");
    scanf("%d",&op);
    switch(op)
    {
	case 1:
     recursion(c);        //function call for recursion
    break;
	case 2:
    nonrecursion(c,count);  //function call for non recursion
    printf("\n");
     break;
         }
    printf("\n");
    getchar();
    printf("Do you want to continue yes or no\n");
    scanf("%c",&m);
    getchar();
    }
    while(m == 'y');   //run the program again
    return 0;
}


void nonrecursion(char c[],int count)       //function declaration
{
    int i;
    for(i=count;i>=0;i--)                //loop for printing the string in reverse order
    {
	printf("%c",c[i]);
    }
}
void recursion(char *c)    //function decleration
{
    if(*c)                 //check the condition
    {
     recursion(c+1);        //go the last of the string using recursion and print
     printf("%c",*c);
    }
}

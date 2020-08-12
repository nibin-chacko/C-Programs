/*Name :Nibin chacko
 * Date:12/1/2020
 */

#include<stdio.h>
int disk(int n,char source,char aux,char des);
int main()
{
    char ch;
    do

    {
    int n;
    printf("Enter the number of disk\n");
    scanf("%d",&n);
    disk(n,'A','B','C');
    getchar();
    printf("Do you want to continue y/n\n" );
    scanf("%c",&ch);
    }
    while(ch == 'y');
	return 0;
}


int disk(int n,char source,char aux,char des)
{
    if(n==1)
    {
	printf("Make illegal move from %c to %c\n",source,des);
	return 0;
    }
    disk(n-1,source,aux,des);
    printf("Make illegal move from %c to %c \n",source,des);
    disk(n-1,des,aux,source);
}




/*Author : Nibin chacko
Date : 07/01/2020
Description :to print no of characters, no of lines,no of words 
input : ./a.out
output:
venu
bu	 	ko
No.of lines	 No.of Words	No of char
1	       	 3		11
Comments
*/

#include<stdio.h>
#include<stdio_ext.h>//for fpurge 
int count ( char *a,int *c,int *w,int *l);
int main()
{
    char ch;
    do
    {
	char a[100];
	int c=0,w=0,l=0;
	count(a,&c,&w,&l);/*function calling */
	printf("\nNo.of lines\tNo.of Words\tNo of char\n");
	printf("%d\t\t%d\t\t%d\n",l,w,c);/*printing the values*/
	printf("Do You Want To Continue(y/n): \n");
	scanf("\n%c",&ch);/*asking user to continue */

    }while ( ch == 'y' );

    return 0;
}
int count ( char *a,int *c,int *w,int *l)
{
    int i;
    __fpurge(stdin);//clear buffer of stdio
    for ( i = 0 ; (a[i]=getchar()) != EOF ;i++);//storing elements into array
    for ( i = 0 ; a[i] != EOF ;i++)  //for loop for counting
    {
	if ( a[i] )
	    (*c)++;//character incrementing
	if ( a[i] == '\n' )
	    (*l)++;//lines count incrementing
	if ( i == 0 )
	{
	    if ( a[i] != 32 && a[i] != 9 && a[i] != 10 )
	    {
		(*w)++;//word count incrementing
	    }
	}

	if ( a[i] == ' ' || a[i] == '\t' || a[i] == '\n' )
	{
	    if ( a[i+1] != ' ' && a[i+1] != '\t' && a[i+1] != '\n' )
	    {
		if ( a[i+1] == EOF )//end of file
		{
		}
		else
		{
		    (*w)++;//word increment
		}
	    }

	}
    }
    return *c,*w,*l;//returning values to main function
}




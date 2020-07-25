/*Author:Nibin chacko
 * Date: 08/1/2020
 * Description:delete multiple space in a string
 *Input:Enter the string
        heloo             world
 *Output:
           heloo world
*/
#include<stdio.h>
#include<stdlib.h>
void delete(char *a);
int main()
{
    char ch;
    do
    {

    char a[100];
    puts("Enter the string");
    scanf("%99[^\n]",a);
    delete(a);          //cal the function
    printf("\n");
    printf("Do you want to continue y/n\n");
    getchar();  //clear the buffer
    scanf("%c",&ch);
    getchar();
    }
    while(ch == 'y');
    return 0;
}

void delete(char *a)   //function declaration
{
    int c=0,i;
    for(i=0;a[i] != '\0';i++)     //loop for taking character
    {
	if(a[i] == '\t')      //if the charatcter is tab then placed with space
	{
	    a[i]=' ';
	
	}
    }
    for(i=0;a[i] != '\0';i++)    //loop for taking the characters
    {
	if(a[i] == ' ')         //first chara is space then enter the the statement
	{
	if(a[i] ==' ' && c ==0)  //check the character is space and count is 0 is true the print only one space
	{
	    printf(" ");
	    c++;
	}
	}
	else   //if the character is not space
	{
	    printf("%c",a[i]);
	    c=0;
	}
    }
    return;
}




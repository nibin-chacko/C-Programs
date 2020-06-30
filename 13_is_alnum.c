/*Author:Nibin
 * Date:30/06/2020
 * Description:check the character
 * input:Enter the character
           d
         1.isalnum
         2.isalpha
         3.isascii
         4.isblank
        Enter the choice
          1
 output:  The a isalnum
            Do you want to continue y/n
	  */

#include<stdio.h>
int ismyalpha(char input);
int ismyalnum(char input);
int ismyascii(char input);
int ismyblank(char input);
int main()
{
    char ch;
    do
    {
    char a;
    int b,x;
    printf("Enter the character\n");
    scanf("%c",&a);
    printf("1.isalnum\n2.isalpha\n3.isascii\n4.isblank\n");
    printf("Enter the choice\n");
    scanf("%d",&b);
    switch(b)               //case
    {
	case 1:
	    x=ismyalnum(a);
	    if(x==1)        
            {
		printf("The %c isalnum\n",a);
	    }
	    else
		printf("The %c is not alnum",a);
	    break;
	case 2:
	    x=ismyalpha(a);
	    if(x==1)
	    {
		printf("The %c is alpha\n",a);
	    }
	    else
		printf("The %c is not alpha\n",a);

	    break;
	case 3:
	    x=ismyascii(a);
	    if(x==1)
	    {
		printf("The %c is ascii\n",a);
	    }
	    else
		printf("The %c is not ascii\n",a);

	    break;
	case 4:
	    x=ismyblank(a);
	    if(x==1)
	    {
		printf("The %c is blank\n",a);
	    }
	    else
		printf("The %c is not blank\n",a);
	    break;
    }
    getchar();
    printf("Do you want to continue y/n\n");
    scanf("%c",&ch);
    getchar();
    }
    while(ch == 'y');   //again run the program
    return 0;
}

int ismyalpha(char input)
{
    if(input>=65 && input<=90 || input >= 97 && input <=122)   //checking the enterd character with ascii values of capital letters and small letters
    {
	return 1;
    }
    else
	return 0;
}
int ismyalnum(char input)
{
    if(input>=65 && input<=90 || input >= 97 && input <= 122 || input >= 48 && input <= 57)    //checking the enterd character with ascii values of capital letter,small letters and numbers
    {
	return 1;
    }
    else
	return 0;
}
int ismyascii(char input)
{
    if(input >= 0 && input <=127)   //checking the enterd character with ascii of ascii values
    {
	return 1;
    }
    else
	return 0;
}
int ismyblank(char input)
{
    if(input >= 9 && input <= 32)     //checking the eneterd character with ascii values of characters
    {
	return 1;
    }
    else
	return 0;
}

/*
 * Name:Nibin chacko
 * Date: 16-01-2020
 * Description: Implement strtok function
 * Input:./a.out
 * Output:
   Enter string:hi,hello,/world
   Enter string2:,/
   hi
   hello
   world
   Do You Want To Continue(y/n)
     n

 * comments end */
#include <stdio.h> 
#include <stdio_ext.h> 
#include <string.h> 
#include <stdlib.h> 

char *mystrtok( char *str, const char *tokens);  
int main()
 { char option;
    do
    {
	char str[100];  /*for string 1*/ 
	char str2[50];  /*for string 2*/
	__fpurge(stdin);
	printf("Enter string:");
	scanf("%[^\n]",str);
	getchar();
	printf("Enter string2:");
	scanf("%[^\n]",str2);
	char *p = malloc(100); /*allocating memory to pointer*/
	 p = mystrtok( str, str2);  /* calling my strtok func */
	 while( p != NULL)
	{
       	 printf("%s\n", p);  /*printing return address data*/
	 p = mystrtok(NULL, str2); /*calling again my_strtok func*/
	}
printf("Do You Want To Continue(y/n)\n"); //asking user to wether continue or not
scanf("\n%c",&option);
    } while ( option == 'y' );
    return 0;
}
char *mystrtok( char *str, const char *tokens)  
{
    static char *temp; /*Static for continues calling*/
    if( str != NULL)   /*if string is not NULL than copy address to local pointer*/
    {  temp = (char*) malloc(strlen(str)); /* at first time allocating memory to temp*/
       temp = str; 
    }
    else if( temp == NULL)  /* if it is null return NULL*/
	return NULL;
    else      /*else give temp address to string*/
	str = temp;
    int chars = 0, len = strlen(tokens), flag = 0, i;
    while(*temp)
    {

    for(i=0 ; i<len; i++)
    {
	if( *temp == tokens[i]) /* character checking with delimiter each charactor*/
	{
	    if( chars == 0)
	    {
		flag = 1;
		str++;
	    }
	    else
	    {
		temp++;
		str[chars]='\0';
		return str;  /*return address of string*/
	    }
	}
    }
	if( flag == 0)
	    chars++;
	temp++;
	flag=0;
    }
    temp = NULL;
    str[chars]='\0'; 
    return str;   /*retun address of string*/ 
}


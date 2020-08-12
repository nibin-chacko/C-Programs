/* Author: nibin
 * Date: 22-1-2020
 * Description: Implement myprintf function 
 * Input:./a.out
 * Output:
 * comments end */
#include <stdio.h> 
#include <stdio_ext.h> 
#include <stdarg.h> 
char *convert(unsigned int num, int base); 

void Myprintf(char* format,...) 
{ 
    char *op; 
    int i; 
    char *s; 

    //Initializing Myprintf's arguments 
    va_list arg; 
    va_start(arg, format); 

    for(op = format; *op != '\0'; op++) 
    { 
	if( *op != '%' ) //checking format specifier
	{ 
	    putchar(*op);
	} 
	else
	{
	op++; 
	//Fetching and executing arguments
	switch(*op) 
	{ 
	    case 'c' :
			i = va_arg(arg,int);		//Fetch char argument
		       if(i < 0) 
		       {  i = -i;
			   putchar('-'); 
		       } 
		       putchar(i);
		       break; 

	    case 'd' :
		       i = va_arg(arg,int); 		//Fetch Decimal/Integer argument
		       if(i < 0) 
		       {  i = -i;
			   putchar('-'); 
		       } 
		       fputs(convert(i,10),stdout);
		       break; 

	    case 'o':
		       i = va_arg(arg,unsigned int); //Fetch Octal representation
		      fputs(convert(i,8),stdout);
		      break; 

	    case 's':
		      s = va_arg(arg,char *); 		//Fetch string
		      fputs(s,stdout); 
		      break; 

	    case 'x':
		      i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
		      fputs(convert(i,16),stdout);
		      break; 
	}
	}
    } 

    // Closing argument list to necessary clean-up
    va_end(arg); 
} 

char *convert(unsigned int num, int base) 
{ 
    static char Representation[]= "0123456789ABCDEF";  //for assigning this value to ptr i.e changing decimal or x or o
    static char buffer[50]; 
    char *ptr; 

    ptr = &buffer[49]; 
    *ptr = '\0'; 

    do 
    { 
	*--ptr = Representation[num%base];   //num/base if decimal=10, hexa=16,octa=8
	num /= base; 
    }while(num != 0); 

    return(ptr);
} 
int main()
{ char option;
    do
    {
	int var;
	__fpurge(stdin);
	Myprintf("Enter Variable:\n"); //asking user to wether continue or not
	scanf("%d", &var);
	Myprintf("%d %d\n %c\n", var, -100,'Z');  //calling myprintf
	__fpurge(stdin);
	Myprintf("Do You Want To Continue(y/n)\n",1); //asking user to wether continue or not
	scanf("\n%c",&option);
    } while ( option == 'y' );
    return 0;
}

#include<stdio.h>
#include<stdio_ext.h>
char *itoa(int num,char *p);
void getword(char *p);
int atoi(const char *p);
int main()
{
    char ch;
    do
    {
    char arr[100];
    int op,num;
    char *p;
    printf("1.get word\n2.atoi\n3.itoa\nEnter the option:");
    scanf("%d",&op);
    __fpurge(stdin);

    switch(op)    //switch case to select operation
    {
	case 1:
	    printf("Enter a word: ");
	    scanf("%[^\n]",arr);
	    getword(arr);   //function call to get word
	    break;
	case 2:
	    printf("Enter a numeric string: ");
	    scanf("%[^\n]",arr);
	    num= atoi(arr);  //function call for atoi function
	    printf("String to integer is : %d\n",num);
            break;
	case 3:
	    arr[100] ='\0';  //assign the last is end of the string
	    printf("Enter a string: ");
	    scanf("%d",&num);
	    p = itoa(num,&arr[99]); //function call
	    printf("Integer to string is : %s\n",p);
	    break;
	default:
	    printf("Enter a valid operation\n");
    }
    printf("\n");
    printf("do you want to continue y/n:");     //loop for continue the prgm
    scanf("\n%c",&ch);
    }
    while(ch == 'y');
}
    void getword(char *p)
    {
	while(*p != '\0')
	{
	    if(*p == ' ' ||  *p == '\t')
		return;
	    else
		printf("%c",*p);
	    p++;
	}
	printf("\n");
    }

    int atoi(const char *p)
    {
	int n = 0,s = 1;
	if(p[0] == '-')
	{
	    s = -1;
	    p++;
	}
	while ( *p != '\0')
	{
	    if( *p >= 48 && *p <= 57)   //condition for check the number
	    
		n = n * 10 + (*p - 48);  //to get the number
	    else 
		return n*s;
	    p++;
	}
	return n*s;
    }
char *itoa(int num,char *p)
{
    int r,n = num;
    if( num < 0)
	num *= -1;
    while(num != 0)
    {
	r = num % 10; //gives reminder
	*p = r + 48;
	num = num / 10;  //to eleminate last digit
	--p;
    }
    if( n < 0)
    *p = '-';
    else
	p++;
    return p;
}

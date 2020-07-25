
/* 
Author:Nibin chacko
Date: 28/1/2020
Input:./a.out f1.txt f2.txt f3.txt 

Output:

nibin chacko
12345
Do you want to continue[y/n] :n

*/
#include<stdio.h>
void my_cp()
{
    char ch;
    //to take stdin and to print the stdout
    while((ch = getchar()) != '\n')
    {
	putchar(ch);
    }
    printf("\n");
}
void my_cp1(FILE *src,FILE *src1)
{
    char ch;
    //to read from file
    while((ch = getc(src)) != EOF)
    {
	fputc(ch,src1);
    }
    printf("\n");
}
void my_cp2(FILE *src,FILE *src1,FILE *dest)
{
    char ch;
    //to read from file and print
    while((ch = getc(src)) != EOF)
    {
	fputc(ch,dest);
    }
    while((ch = getc(src1)) != EOF)
    {
	fputc(ch,dest);
    }
}
void my_cp3(FILE *src)
{
    char c;
    while((c = getc(src)) != EOF)
    {
	putchar(c);
    }
    printf("\n");
}

int main(int argc,char *argv[])
{
    char ans;
    do
    {
	//Declaring variables
	FILE *src,*src1,*dest;
	int choice;
	char ch;
	choice = argc;
	switch (choice)
	{
	    //when no argument is passed
	    case 1: printf("Enter the input characters :");
		    my_cp();
		    break;
		    //When one file is passed
	    case 2: src = fopen(argv[1],"r");
		    my_cp3(src);
		    //closig the file
		    fclose(src);
		    break;
		    //when two files are passed throuh CLA
	    case 3: src = fopen(argv[1],"r");
		    src1 = fopen(argv[2],"a");
		    my_cp1(src,src1);
		    fclose(src);
		    fclose(src1);
		    break;
		    //concatination of two files
	    case 4: src = fopen(argv[1],"r");
		    src1 = fopen(argv[2],"r");
		    dest = fopen(argv[3],"a");
		    my_cp2(src,src1,dest);
		    fclose(src);
		    fclose(src1);
		    fclose(dest);
		    dest = fopen(argv[3],"r");
		    while((ch = getc(dest)) != EOF)
		    {
			putchar(ch);
		    }
		    break;
	    default:printf("invalid choice\n");
	}
	//getchar();
	printf("Do you want to continue[y/n] :");
	scanf("%c",&ans);
	getchar();
    }while(ans == 'y');
}


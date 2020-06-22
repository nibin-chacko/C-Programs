//author:Nibin Chacko
//Date:22/6/2020
//Description:To print the ascii
//Input:
//Output:

#include<stdio.h>
int main()
{
    int i;
    printf("Dec\tHexa\tocta\tchar\n");  //to print the headline
    printf(".....\t.....\t.....\t.....\n");  //to print the headline
for(i=0;i<=32;i++)                    //loop for taking each number
{
    printf("%d\t%.2X\t%.3o\tNot printable\n",i,i,i);//print the decimal number,Hexadecimal number,octal number and character.
}
for(i = 33;i <= 126;i++)
{
    printf("%d\t%.2X\t%.3o\t%c\n",i,i,i,i);//print the decimal number,Hexadecimal number,octal number and character.
}
for(i = 127;i <= 127;i++)
{
    printf("%d\t%.2X\t%.3o\tNot printable\n",i,i,i);//print the decimal number,Hexadecimal number,octal number and character.
}
    return 0;
}

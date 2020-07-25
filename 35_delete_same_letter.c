/*Author:Nibin chacko
 * Date:31/12/2019
 * Description:Squeeze the enterd sring
 * Input:
 *      Enter s1          :dennis ritchie
        Enter s2          :linux
 *Output:
        After squeeze s1  :es rtche
*/
        
#include<stdio.h>
#include<stdio_ext.h>
void squeeze(char a[],char b[]);
int main()
{
    char ch;
    do
    {
    char a[100],b[100];
    printf("Enter s1          :");
    getchar();
    scanf("%[^\n]",a);
    printf("Enter s2          :");
    getchar();
    scanf("%[^\n]",b);
    printf("After squeeze s1  :");
    squeeze(a,b);     //call the function
    printf("Do you want to continue y/n\n");
    getchar();
    scanf("%c",&ch);
    }
    while(ch == 'y');   //loop for continue the program
    return 0;
}


void squeeze(char a[],char b[])     //function decleration
{
    int count=0,i,j;
    for(i=0;a[i] != '\0';i++)      //loop for taking the letters of string s1
    {
	for(j=0;b[j] != '\0';j++)  //loop for taking the letters of string s2
	{
	    if(a[i]==b[j])          //check if same letters are in 2 string
	    {
		count++;
	    }
	}
	    if(count==0)        //the letters are not same then print that letter
	    {
		printf("%c",a[i]);
		count=0;
	    }
	    else
	    {
		count=0;
	    }
    }
    printf("\n");
}

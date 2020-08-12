/*Name : Nibin chacko
 * Date:23/1/2020
 * Description:To find the combinations of enterd string
 * Input:
 * Enter the number of input characters
      3
   Enter the string
   abc
*Output:
        abc
        acb
        bac
        bca
        cba
        cab
*/
#include<stdio.h>
#include<string.h>
void print(char *str,int i,int n);
int main()
{
    char chr;
    do
    {
	int n;
	char str[200];
	printf("Enter the number of input characters\n");
	scanf("%d",&n);
	printf("Enter the string\n");
	scanf("%s",str);
	printf("\n");
	print(str,0,n - 1); //function call to print combinations
	getchar();
	printf("Do you want to continue y/n\n");
	scanf("%c",&chr);
    }
    while(chr == 'y');
}

void print(char *str,int i,int n)
{
    int j;
    char temp;
    if( i == n)   //condition to print combination
	printf("%s\n",str);
    else
    {
	for(j = i;j <= n;j++) //loop to swap characters
	{
	    temp = *(str + i);
	    *(str + i) = *(str + j);
	    *(str + j) = temp;
	    print(str,(i + 1),n);  //calling function recursively
	    temp = *(str + i);
	    *(str + i) = *(str + j);
	    *(str + j) = temp;
	}
    }
}


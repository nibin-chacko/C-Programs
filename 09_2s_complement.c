//Name:Nibin chacko
//date:25/6/2020
//description:To print the positive binary and negative binary
//input:12
//output:+12
//         00000000000000000000000000001100
//        -12
//        11111111111111111111111111110100
 

#include <stdio.h>
    int main()
    {
	int n,i,m;
	char c;
	do
	{
        printf("enter the number\n");
        scanf("%d",&n);
        for(i = 31;i >= 0;i--)
        {
         printf("%d",n>>i&1);     //take the each element and print
        }  
        printf("\n");
        m=n;

        for(i= 31;i >= 0;i--)
        n=n^(1<<i);           //xor the values for 1s complemengt

        printf("\n");
        n=n+1;              //add 1s complement+1
        printf("%d\n",n);    //print the negative number in decimal
        for(i= 31;i >= 0;i--)
        printf("%d",n>>i&1);     //take the eacch element
        printf("\n");
        getchar();
        printf("Do you want to continue y or n\n");
        scanf("%c",&c);
        }
        while(c == 'y');
       return 0;
}

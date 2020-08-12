/*name :Nibin chacko
 * Date:24/1/2020
 * Description:
 * input:1.Float
         2.Double
        Enter your option:1
	Enter the float value: 12.5

 * output:0 10000010 10010000000000000000000

 * */
#include<stdio.h>
#include<stdio_ext.h>
void my_float(void *y);
void my_double(void *y);
int main()
{char ch;
    do
    {
    int op;
    printf("1.Float\n2.Double\nEnter your option:");
    scanf("%d",&op);           //select the option

    switch(op)
    {
	case 1:
	    {
		float x;
		printf("Enter the float value: ");
		getchar();
		scanf("%f",&x);
		my_float(&x);              //call the function for float
		break;
	    }
	case 2:
	    {
		double x;
		printf("Enter the double value: ");
		scanf("%lf",&x);
		my_double(&x);            //call the function for double
		break;
	    }
    }
    printf("\n");
    getchar();
    printf("Do you want to continue y/n\n");
    scanf("%c",&ch);
}
while(ch == 'y');
return 0;
}


void my_float(void *y)        //function decleration
{
    int i,bit;
    for(int i = 31;i >= 0;i--)      
    {
	if( i==30 || i==22)
	{
	    printf(" ");
	}
	bit=((*(int *)y)>>i)&1;     
	printf("%d",bit);
    }
    return;
} 
void my_double(void *y)             //function decleration
{
    int i,bit;
    for(i =63;i>=0;i--)
    {
	if(i==62 || i==51)
	{
	    printf(" ");
	}
	bit=((*(long int *)y)>>i)&1;
	printf("%d",bit);
    }
    return;
}

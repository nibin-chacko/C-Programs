/*Author:Nibin chacko
 * Date:9/1/2020
 * Description:Swap using MACRO
 * Input:1.int
         2.short
         3.Float
         4.double
            1
       Enter the elements
         4
         5
 *Output:a = 5 and b = 4*/

#include<stdio.h>
#include<stdio_ext.h>
/*This is macro define*/
#define SWAP(t,a,b) t temp=a;\
			   a=b;\
			   b=temp;

int main()
{
    char ch;
    do
    {
    int op;
    __fpurge(stdin);
    printf("1.int\n2.short\n3.Float\n4.double\n");
    scanf("%d",&op);         //scsnning the option
    switch (op)
    {
	case 1:
	    {
		 int a,b;
		printf("Enter the elements\n");
		scanf("%d%*c%d",&a,&b);
		SWAP(int,a,b)                      //macro function
		    printf("a = %d and b = %d\n",a,b);

	    }
	    break;
	case 2:
	    {
		short a,b;
		printf("Enter the elements\n");
		scanf("%hd%*c%hd",&a,&b);
		SWAP(char,a,b)   //macro function
		    printf("a = %hd and b = %hd\n",a,b);
	    }
	    break;

	case 3:
	    {
		float a,b;
		printf("Enter the elements\n");
		scanf("%f%*c%f",&a,&b);
		SWAP(float,a,b)
		    printf("a = %.2f and b = %f.2\n",a,b);
	    }
	    break;
	case 4:
	    {
		double a,b;
		printf("Enter the elements\n");
		scanf("%lf%*c%lf",&a,&b);
		SWAP(double,a,b)   //macro function
		    printf("a = %.2lf and b = %.2lf\n",a,b);
	    }
	    break;
    }
    getchar();
    __fpurge(stdin);
    printf("Do you want to continue yes or no\n");         //loop for continue the prgm
    scanf("%c", &ch);
    }
    while(ch == 'y');

}
		

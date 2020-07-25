/*
Author      : Nibin chacko
Date        : 31/1/2020
Description : Program to print bits of float and double
Input       : Enter the float value : 2.3
Output      : 0   10000000 00100110011001100110011
 */

#include<stdio.h>

int intr()  //Function to print (-)
{
    int i;
    for (i = 0;i < 70;i++)
    {
	printf("-");
    }
    printf("\n");
}

void float_num(float *num1)
{
    int i;
    int *p = (int *)num1; //Type casting float number to integer
    for(i = ((sizeof(num1) * 8)/2 - 1);i >= 0;i--) // Loop to print bits of the number
    {
	if ( i == 30 || i == 22)
	{
	    printf("\t");
	}
	if((*p >> i) & 1 )
	    printf("1");
	else
	    printf("0");
    }
}
void double_num(double *num2)
{
    int i;
    long int *p = (long int *)num2; //Type casting double number to long int
    for(i = (sizeof(num2) * 8 - 1); i >= 0;i--) //Loop to  print bits of the number

    {
	if ( i == 62 || i == 51)
	{
	    printf("\t");
	}
	if((*p >> i) & 1 )
	    printf("1"); 
	else
	    printf("0");
    }
}

int main()
{
    char chr;
    do //loop for continue prompt
    {
	float num1;
	double num2;
	int option;
	printf("Enter the choice : \n1.float\n2.double\nChoice:");
	scanf("%d",&option);
	switch(option) //Switch case to select float or double
	{
	    case 1: //Case for float value
		{
		    printf("Enter the float value : ");
		    scanf("%f",&num1);
		    printf("Sign \tExponent \tMantissa\n");
		    intr();
		    float_num(&num1); //Function call to print IEEE std of float value
		    printf("\n");
		}
		break;
	    case 2:  //Case for double value
		{
		    printf("Enter the float value:");
		    scanf("%lf",&num2);
		    printf("Sign \tExponent\tMantissa\n");
		    intr();
		    double_num(&num2); //Function call to print IEEE std of double value
		    printf("\n");
		}
		break;
	    default :
		printf("Enter a valid choice \n");

	}
	printf("\nDo you want to continue? (y/n) :");
	scanf("\n%c",&chr);
    } while (chr == 'y');

}

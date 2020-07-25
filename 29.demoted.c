/*
Author:Nibin chacko
Date:10/1/2020
input:Enter a float value: 4.5
output:Your float values is: 4
 */
#include <stdio.h>

//Function prototype
void demoted(float* f);

int main()
{
    //Declaration of local variables
    char ch;
    do
    {
	float f;
	printf("\nEnter a float value: ");
	scanf("%f",&f);
	//Call of function 
	demoted(&f);
	printf("\nDo you want to continue(y/n): ");
	scanf(" %c",&ch);
    }
    while(ch == 'y');
    return 0;
}

//Function to demote the int
void demoted(float *z)
{

    //Union used to split the bits of float value
    union ieee
    {
	float fl;
	struct bits
	{
	    unsigned mant:23;
	    unsigned expo:8;
	    unsigned sign:1;
	}elements;
    };
    union ieee var;
    var.fl = *z;
    int f1 = 0;
    //Found the value for the mandissa part
    int k = var.elements.expo;
    k = k - 127;
     int j = 0;
    //Loop to find the mandissa bit
    for (int i = (23 - k);i <23;i++)
    {
	int ch = (var.elements.mant >> (i)) & 1;
	f1 = f1 | (ch << j);
	j++;
    }
    //storing the exponent element
    f1 = f1 | (1 << j);
    //Condition to check whether the number is possitive or not
    if (var.elements.sign == 1)
    {
	f1 = -f1;
    }
    else
    {
	f1=f1;
    }
	printf("\nYour coverted integer  values is: %d\n",f1);
}

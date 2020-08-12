/*
Author      : Nibin chacko
Date        : 05/2/2020
Description : Program to implement calc_mean for all data types
Input       : option - 1, 10,20,30,40,50
Output      : The mean value : 25.00
*/

#include<stdio.h>
double calc_mean(int option, void *ptr, int size)
{
    double var = 0;
    if (option == 1)
    {
	int sum = 0;
	for (int i = 0 ; i < size ; i++) //Loop to find sum of elements
	{
	    sum += *((int *)ptr + i);
	}
	var = (double)sum / size; //Finding mean                                 
	return var;
    }
    else if (option == 2)
    {
	short sum = 0;
	for (int i = 0 ; i < size ; i++) //Loop to find sum of elements
	{
	    sum += *((short *)ptr + i);
	}
	var = (double)sum / size;                               
	return var;
    }
    else if (option == 3)
    {
	float sum = 0;
	for (int i = 0 ; i < size ; i++) //Loop to find sum of elements
	{
	    sum += *((float *)ptr + i);
	}
	var =(double) sum / size;                               
	return var;
    }
    else if (option == 4)
    {
	double sum = 0;
	for (int i = 0 ; i < size ; i++) //Loop to find sum of elements
	{
	    sum += *((double *)ptr + i);
	}
	var = sum / size;                                       
	return var;
    }
}

int main()
{
    char chr;
    do //Loop for continue prompt
    {
    int option = 0, size = 0;
    double result = 0;
    printf("Enter the option\n1.int\n2.short\n3.float\n4.double\n");
    scanf("%d", &option);
    switch(option)  //Switch case for different options
    {
	case 1:
	    {
		printf("Enter the length of the array:");
		scanf("%d", &size);
		int arr[size];
		for(int i = 0; i < size ; i++) //Loop to read the elements and store in array
		{
		    printf("[%d]->",i);
		    scanf("%d", &arr[i]);
		}
		result = calc_mean(option,arr,size); //Function call to find the mean
		printf("the mean value:%g\n", result);
	    }
	    break;
	case 2:
	    {
		printf("Enter the length of the array:");
		scanf("%d", &size);
		short arr[size];
		for(int i = 0; i < size ; i++) //Loop to read the elements and store in array
		{
		    printf("[%d]->",i);
		    scanf("%hd", &arr[i]);
		}
		result = calc_mean(option,arr, size); //Function call to find the mean 
		printf("the mean value:%g\n", result);
	    }
	    break;
	case 3:
	    {
		printf("Enter the length of the array:");
		scanf("%d", &size);
		float arr[size];
		for(int i = 0; i < size ; i++) //Loop to read the elements and store in array
		{
		    printf("[%d]->",i);
		    scanf("%f", &arr[i]);
		}
		result = calc_mean(option,arr, size); //Function call to find the mean
		printf("the mean value:%g\n", result);
	    }
	    break;
	case 4:
	    {
		printf("Enter the length of the array:");       
		scanf("%d", &size);
		double arr[size];
		for(int i = 0; i < size ; i++) //Loop to read the elements and store in array
		{
		    printf("[%d]->",i);
		    scanf("%lf", &arr[i]);
		}
		result = calc_mean(option,arr, size); //Function call to find the mean
		printf("the mean value:%g\n", result);
	    }
	    break;

	default: //Default condition
	    printf("Enter a valid option\n");
    }
    printf("Do you want to continue(y/n) : ");
	scanf("\n%c",&chr);
    }while(chr == 'y');

}


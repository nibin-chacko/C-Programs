/*
Name:Nibin chacko
Date: 28-01-2020
Description: Array sorting and binary search 
Input:./a.out 5
Output:Choose Choice:
       1.int
       2.short
       3.float
       4.double
       5.char
       Enter Choice:2
       Enter 5 Elements:
       [0]-> 25
       [1]-> 88
       [2]-> 47
       [3]-> 36
       [4]-> 90
       Enter Key element to search:88
       after sorting
       88 Found at index 3.
Comments
 */
#include <stdio.h>
#include<stdlib.h>

void binary( void *ptr, int argv, int opt);
int main( int argc, const char **argv)
{ 
    char ch;
    do
    {
	int opt, i, j, args; /*reading command line argument */
	if( (argv[1]) ==  NULL || argc <= 1)
	    printf("Not Possible!!\n");
	else
	{
	     args = atoi(argv[1]); /*reading command line argument */
	     if( args <= 0)
	    printf("give elements more,Not Possible!!\n");
	    else
	     {
	    printf("Choose Choice:\n1.int\n2.short\n3.float\n4.double\n5.char\nEnter Choice:");
	    scanf("%d", &opt); /*reading user choice*/
	    printf("Enter %d Elements:\n", args);
	    switch(opt)
	    {
		case 1:
		    {
			int arr[args];      // for int array
			int temp;
			for(i=0; i<args; i++)  /*reading input*/
			{
			    printf("[%d]-> ", i);
			    scanf("%d", &arr[i]);
			}
			for(i=0; i<args; i++) /*sorting array*/
			for(j=i+1; j<args; j++)
			{
			    if( arr[i] > arr[j] )
			    {
				temp = arr[j];
				arr[j]= arr[i];
				arr[i]= temp;
			    }
			}
			binary( arr, args , opt);
			for(i=0; i<args; i++)  /*reading input*/
			    printf("[%d]->%d\n", i,arr[i]);
		    }
		    break;
		case 2:
		    {
			short arr[args];   // for short array
			short temp;
			for(i=0; i<args; i++)
			{
			    printf("[%d]-> ", i);  /*reading input*/
			    scanf("%hi", &arr[i]);
			}
			for(i=0; i<args; i++)
			for(j=i+1; j<args; j++) /*sorting array*/
			{
			    if( arr[i] > arr[j] )
			    {
				temp = arr[j];
				arr[j]= arr[i];
				arr[i]= temp;
			    }
			}
			binary( arr, args , opt);
			for(i=0; i<args; i++)  /*reading input*/
			    printf("[%d]->%hi\n", i,arr[i]);
		    }
		    break;
		case 3:
		    {
			float arr[args]; //for float array
			float temp;
			for(i=0; i<args; i++) /*reading input*/
			{
			    printf("[%d]-> ", i);
			    scanf("%f", &arr[i]);
			}
			for(i=0; i<args; i++)
			for(j=i+1; j<args; j++) /*sorting array*/
			{
			    if( arr[i] > arr[j] )
			    {
				temp = arr[j];
				arr[j]= arr[i];
				arr[i]= temp;
			    }
			}
			binary( arr, args , opt);
			for(i=0; i<args; i++)  /*reading input*/
			    printf("[%d]->%.2f\n", i,arr[i]);
		    }
		    break;
		case 4:
		    {
			double arr[args];  // for double
			double temp;
			for(i=0; i<args; i++) /*reading input*/
			{
			    printf("[%d]-> ", i);
			    scanf("%lf", &arr[i]);
			}
			for(i=0; i<args; i++)
			for(j=i+1; j<args; j++) /*sorting array*/
			{
			    if( arr[i] > arr[j] )
			    {
				temp = arr[j];
				arr[j]= arr[i];
				arr[i]= temp;
			    }
			}
			binary( arr, args , opt);
			for(i=0; i<args; i++)  /*reading input*/
			    printf("[%d]->%.2lf\n", i,arr[i]);
		    }
		    break;
		case 5:
		    { 
			char arr[args];  // for double
			char temp;
			for(i=0; i<args; i++)
			{
			    printf("[%d]-> ", i);
			    scanf("\n%c", &arr[i]); /*reading array*/
			}
			for(i=0; i<args; i++) /*sorting array*/
			for(j=i+1; j<args; j++)
			{
			    if( arr[i] > arr[j] )
			    {
				temp = arr[j];
				arr[j]= arr[i];
				arr[i]= temp;
			    }
			}
			binary( arr, args , opt);
			for(i=0; i<args; i++)  /*reading input*/
			    printf("[%d]->%c\n", i,arr[i]);
		    }
		    break;
		default:
		    printf("No Such Case Available\n");
	    }
	     }

	}
	printf("Do You Want To Continue(y/n)\n"); //asking user to wether continue or not
	scanf("\n%c",&ch);
    } while ( ch == 'y' );
    return 0;
}

void binary( void *ptr, int argv, int opt)  /*function definition for array binary search*/
{
    int begin=0, end=argv-1, mid;
    switch(opt)
    {
	case 1:  // for int values
	    {int key;
	    printf("Enter Key element to search:\n");
	    scanf("%d", &key);   /*reading key word from user*/
	    printf("After sorting ");
	    while( begin <= end)   /*loop runs upto begin is less than end */
	    {
		mid = (begin+end)/2; /*mid index giving to mid*/
		if( key > *((int *)ptr+mid)) /*key is greter than array value add 1 */
		    begin = mid+1;
		else if( key < *((int *)ptr+mid)) /*key is less than array value subtrate 1 */
		    end = mid-1;
		else
		{
		    printf("%d Found at index %d in array.\n", key, mid); /*if is both are equal ,than print index*/
		    return ;
		}

	    }
		    printf("%d Not Found at any index in array.\n", key); /*if not found any where in array */
	    }
	    break;
	case 2:    // for short
	    { short key;
	    printf("Enter Key element to search:");
	    scanf("%hi", &key); /*reading key word from user*/
	    printf("After sorting ");
	    while( begin <= end) /*loop runs upto begin is less than end */
	    {
		mid = (begin+end)/2;
		if( key > *((short *)ptr+mid))/*key is greter than array value add 1 */
		    begin = mid+1;
		else if( key < *((short *)ptr+mid))/*key is greter than array value sub 1 */
		    end = mid-1;
		else
		{
		    printf("%hi Found at index %d.\n", key, mid);
		    return ;
		}
	    }
		    printf("%hi Not Found at any index.\n", key);

	    }
	    break;
	case 3:		// for flaot 
	    { float key;
	    printf("Enter Key element to search:");
	    scanf("%f", &key);/*reading key word from user*/
	    printf("After sorting ");
	    while( begin <= end)/*loop runs upto begin is less than end */
	    {
		mid = (begin+end)/2;
		if( key > *((float *)ptr+mid))/*key is greter than array value add 1 */
		    begin = mid+1;
		else if( key < *((float *)ptr+mid))/*key is greter than array value sub 1 */
		    end = mid-1;
		else
		{
		    printf("%.2f Found at index %d.\n", key, mid);
		    return ;
		}
	    }
		    printf("%.2f Not Found at any index.\n", key);

	    }
	    break;
	case 4:		    //for double
	    { double key;
	    printf("Enter Key element to search:");
	    scanf("%lf", &key);/*reading key word from user*/
	    printf("After sorting ");
	    while( begin <= end)/*loop runs upto begin is less than end */
	    {
		mid = (begin+end)/2;
		if( key > *((double *)ptr+mid))/*key is greter than array value add 1 */
		    begin = mid+1;
		else if( key < *((double *)ptr+mid))/*key is greter than array value sub 1 */
		    end = mid-1;
		else
		{
		    printf("%.2lf Found at index %d.\n", key, mid);
		    return ;
		}
	    }
		    printf("%.2lf Not Found at any index.\n", key);

	    }
	    break;
	case 5:		    //for double
	    { char key;
	    printf("Enter Key element to search:");
	    scanf("\n%c", &key);/*reading key word from user*/
	    printf("After sorting ");
	    while( begin <= end)/*loop runs upto begin is less than end */
	    {
		mid = (begin+end)/2;
		if( key > *((char *)ptr+mid))/*key is greter than array value add 1 */
		    begin = mid+1;
		else if( key < *((char *)ptr+mid))/*key is greter than array value sub 1 */
		    end = mid-1;
		else
		{
		    printf("%c Found at index %d.\n", key, mid);
		    return ;
		}
	    }
		    printf("%c Not Found at any index.\n", key);
	    }
	    break;
    }
}



/* Author: Nibin chacko
 * Date: 06-01-2020
 * Description:print distinct characters
 * Input:./37.out
 * Output:
    Enter the number of characters C: 3
    Enter the length of string N i.e( N<=C*C*2): 9
    Enter 3 distinct charactor:abc
    Possible NRPS is: abcbcacab

 * comments end */
#include <stdio.h> 

void nrps( char *arr, int *c, int *l )
{
    int i=0,j,k,m;
    char temp;
    printf("Possible NRPS is: "); 
	for(j=0; i<*l; j++)
	{
	    printf("%c",arr[j]);    /*printing first set of elementsn i.e given input*/
	    if( j == *c-1 && i != *c * *c)  /* if j reached to no.of chars ,than manupulating array*/
	     {//printf(" ");
	    for(k=0; k<*c-1; k++)  //for loop for manupulateing array
        	{
	    temp= arr[k+1];
	    arr[k+1]=arr[k];
	    arr[k]=temp;
		}
		j = -1;  // seting j value to -1 , then it will increment to 1, because it is in loop
	    }
	    else if( i == *c * *c )  //if the i value reached to c*c  ,then manupulate one time 
	    {
	    for(k=0; k<1; k++)
        	{
	    temp= arr[k+1];
	    arr[k+1]=arr[k];
	    arr[k]=temp;
		}
	    for(k=0; k<*c-1; k++) // one for loop for one more total mix
        	{
	    temp= arr[k+1];
	    arr[k+1]=arr[k];
	    arr[k]=temp;
		}
		j = 0;  // seting j=0 to neglect first value
	    }
	    i++;
	}
}

int main()
{ char option;
    do
    {
	char arr[50],sch;
	int C=0, N=0, i, j,count=0;
	printf("Enter the number of characters C: ");
	scanf("%d", &C);
	printf("Enter the length of string N: ");
	scanf("%d", &N);
	if( C <= 1 || C >= 10 )	    /*checking input validation*/
	    printf("NRPS NOT POSSIBLE !!, Invalid input!!\n");
	else
	{
	printf("Enter %d distinct charactor:", C);
	for(i=0; i<C; i++)	    /*loop for reading input*/
	{
	    scanf("\n%c", &arr[i]);
	    if( arr[i] >= 'A' && arr[i] <= 'Z' || arr[i] >= 'a' && arr[i] <= 'z');/*validating input as alphabets or not*/
	    else
	    {   
		count++;    /*if not alpthbet increse count value*/
	        break;
	    }
	}
	if( count == 0)  /*if count zero only enter loop and check for distinct char*/
	{
	    for(i=0; i<C; i++)
	    {
		for(j=i+1; j<C; j++)
		{
			if( arr[i] == arr[j] )
			    count++;
		}
		if( count != 0)
		    break;
	    }
	}

	if( count == 0 ) /*if count=0 only call function to print distinct charactors*/
	    nrps( arr,  &C, &N );
	else
	    printf("NRPS NOT POSSIBLE !!, Invalid input!!\n");
	}
	printf("\nDo You Want To Continue(y/n)\n"); //asking user to wether continue or not
	scanf("\n%c",&option);
	getchar();
    } while ( option == 'y' );
    return 0;
}

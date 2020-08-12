/*
Date:9/12/19
Input:
Enter the 3 names of length max 32 characters in each:

nibin
chacko
hello

Output:
After sorting: 
chacko
hello
nibin


 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void sortnames(int count, int size, char **ptr);
int main()
{
    	char ch;
    	do
    	{
		int count, i;	                                      	//Declaring local variables
		printf("\nEnter the count of person: ");
		scanf("%d", &count);
		char *ptr[count];
	
		for (i = 0; i < count; i++)                            	//Allocating memory 
		{
	    		ptr[i] = malloc(32 * sizeof(char));
		}

            	//Reading the names
             	printf("\nEnter the %d names of length max 32 characters in each:\n\n", count);
         	for (i = 0; i < count; i++)
		{
	    		scanf("%*c%[^\n]",ptr[i]);
		}

		sortnames(count,32,ptr);	                //Calling function
		printf("\nAfter sorting: \n\n");              	//printing array
		for (i = 0; i < count; i++)
		{
	    		printf("%s\n",ptr[i]);
		}
		printf("\nDo you want to continue(y/n): ");
		scanf(" %c", &ch);
    	}
       	while (ch == 'y');
        return 0;
}

void sortnames(int count, int size,char **ptr)               //Function
{
    	int i,j,k;
    	char *temp;
    	j=0;
        for (k = 0; k < count; k++)                          //Checking all names and sorting
    	{
		for (i = k + 1; i < count; i++)
		{

                 	    //Comparing with other names if one character is equal to then it compare next character
	                    while (ptr[k][j] == ptr[i][j])
			    {
		    		    j++;
			    }
	                    if(ptr[k][j] > ptr[i][j])         //Comparing names
			    {
		    		    temp=ptr[k];
		    		    ptr[k]=ptr[i];
		    		    ptr[i]=temp;
			    }
		}
		
		j=0;
    	}
}

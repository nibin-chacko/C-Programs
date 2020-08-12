/*
Date:9/1/2020

input:
Enter the number of rows: 2
Enter the number of elements of [0]th col: 2
Enter the number of elements of [1]th col: 1
enter the elements of [0] col: 1
enter the elements of [0] col:
2
enter the elements of [1] col: 3
Output:
Pre-Final Result

  1.00  2.00  1.50
  3.00  3.00

Final array

  1.00  2.00  1.50
  3.00  3.00
*/
#include <stdio.h>
#include <stdlib.h>
void fragments(int size)					// this function performs fragments operations
{
	int col[size], i, j,temp_col;				// variable declarations
	float sum = 0, avg, *temp,*array[size];
	for (i = 0; i < size; i++)				// read number of Nth columns and creating dynamic memory
	{
		printf("Enter the number of elements of [%d]th col: ", i);
		scanf("%d", &col[i]);
		array[i] = (float *) malloc((col[i] + 1) * sizeof(float));
	}
	for (i = 0; i < size; i++)				// if dynamic array can not allocate memory and exit
	{
		if (array[i] == NULL)
		{
			fprintf(stderr, "Error: Unable to allocate memory\n");
			exit(1);
		}
	}
	for (i = 0; i < size; i++)				// reading elements and find averages and store at last
	{
		for (j = 0; j <col[i]; j++)
		{
			printf("enter the elements of [%d] col: ",i);
			scanf("%f", &array[i][j]);
		}
		for (j = 0; j < col[i]; j++)
		{
			sum = sum + array[i][j];
		}
		avg = sum / col[i];
		//float *r=realloc(arr[i],1);
		array[i][col[i]] = avg;
		sum = 0;
	}   printf("\npre-Final Result\n\n");
	for (i = 0; i < size; i++)				// printing all elements from the array
	{
		for (j = 0; j <= col[i]; j++)
		{
			printf("%6.2f", array[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < size; i++)				// sorting array addresses depends on averages
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i][col[i]] > array[j][col[j]])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				temp_col = col[i];
				col[i] = col[j];
				col[j] = temp_col;
			}
		}
	}
	printf("\nFinal array\n\n");
	for (i = 0; i < size; i++)				// printing final result of array elements
	{
		for (j = 0; j <= col[i]; j++)
		{
			printf("%6.2f", array[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < size; i++)				// making dynamic array memory to NULL
	{
		free(array[i]);
		array[i] = NULL;
	}
} 
int main()
{
	int size;						// variable declaration
	char continue_option;
	do
	{
		printf("\nEnter the number of rows: ");				// prompt user to enter the number of rows
		scanf("%d", &size);						// read number from the user
		fragments(size);						// function call
		printf("\nDo you want to continue(y/n): ");			// printing prompt message
		scanf("\n%c", &continue_option);				// read continue_option from the user
	} while (continue_option == 'y');	                                // condition for continue_option

	return 0;
}

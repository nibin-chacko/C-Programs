/*Author:Nibin chacko
 * Date:19/12/2019
 * Description:sort the enterd float elements
 * Input:
          Enter the number of elements
           5
          Enter the 5 Elements
           [0] = 1.2
           [1] = 3.6
           [2] = 0.5
           [3] = -1.5
           [4] = 4.5
 *Output:
            -1.50
             0.50
             1.20
             3.60
             4.50
*/

#include<stdio.h>
int mysorting(float a[],int n);
int main()
{
    int i,n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    float a[n];
    printf("Enter the %d Elements\n",n);
    for(i=0;i<n;i++)
    {
	printf("[%d] = ",i);
	scanf("%f",&a[i]);
    }

    mysorting(a,n);               //call the function

    return 0;
}

int mysorting(float *a,int n)     //function declaration
{
    int i,count,j,k;
    printf("After sorting\n");
    for(k=1;k<=n;k++)
    {
    for(i=0;i<n;i++)     //loop for taking one element from array
    {
	count=0;
	for(j=0;j<n-1;j++)   //it will compare all elements in the array
	{
	    if(*(a+i)<*(a+j))  //check the condition
	    {
		count++;
	    }
	}
	if( count == n-k)
	    printf("%.2f\t",*(a+i));
    }
    }
printf("\n");

}

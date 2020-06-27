/*author:Nibin chacko
 * date:27/6/2020
 * Description:to find the primr numbers
 * input:10
 * output: 
 *        2
          3
          5
          7*/
#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,k,n;
    char c;
    do
    {
    printf("Enter the value of 'n'\n");
    scanf("%d",&n);
    if(pow (2,20) < n)     //check the number is less than 2^20
    {
	printf("Out of Range\n");
    }
    else
    {
    int a[n];
    j=0;
    for(i=2;i<=n;i++)       //to store the numbers in arry
    {
	a[j]=i;
	j=j+1;
    }
/*    for(i=0;i<n-1;i++)
    {
	printf("%d\n",a[i]);
    }*/
	for(k=2;k<=7;k++)     //dividing terms will be given
	{
    for(j=0;j<n-2;j++)         //take each array number
    {
	if(a[j] !=k)           //if array number and dividing number is not equal then enter the condition
	{
	if((a[j]%k)==0)        //the number mode is zero then store that array equal to zero
	{
	    a[j]=0;
	}
    }
    }
	}

    for(i=0;i<n-2;i++)      //to print the prime numbers
    {
	if(a[i] !=0)        //print only non zero elements
	{
	printf("%d\n",a[i]);
    }
    }
    }
    getchar();
    printf("Do you want to continue yes or no\n");
    scanf("%c",&c);
    }
    while(c == 'y');


    return 0;
}

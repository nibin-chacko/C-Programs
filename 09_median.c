/*Author:Nibin chacko
 * Date :26/6/2020
 * Description :To find the median
 * Input:*/
#include<stdio.h>
int main()
{
    char c;
    do
    {
    int m,i,j,temp,n;
    float median1=0.0,middle=0.0,median=0.0;

    printf("Enter the 'n' value for Array A\n");
    scanf("%d",&m);
    if (m>=10)    ///check the enterd number is grater tha 10
	    {
	    printf("Enter the valid number\n");
	    }
	    else
	    {
    int a[m];
    printf("Enter the elements one by one for Array A\n");
    for(i=0;i<m;i++)          //loop for entering the elements of array 1
    {
	scanf("%d",&a[i]);
    }
    printf("Enter the 'n' value for Array B\n");
    scanf("%d",&n);
    int b[n];
    printf("Enter the elements one by one for Array B\n");
    for(i=0;i<n;i++)        //loop for entering the elements of array 2
    {
	scanf("%d",&b[i]);
    }
    for(i=1;i<m;i++)        //loop for sorting the elements in array 1
    {
	for(j=0;j<m-i;j++)
	{
	    if(a[j]>a[j+1])
	    {
		temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp;
	    }
	}
    }
   /* for(i=0;i<m;i++)
    {
	printf("%d \n",a[i]);
    }*/
    for(i=1;i<n;i++)        //loop for sorting the elemnts in array 2
    {
	for(j=0;j<n-i;j++)
	{
	    if(b[j]>b[j+1])
	    {
		temp=b[j];
		b[j]=b[j+1];
		b[j+1]=temp;
	    }
	}
    }
if(m%2==0)                  //check the length of array1 is even
{
median=(a[((m/2)-1)]+a[m/2])/2.0;   //take the median 
}
else
{
median=a[m/2];                     //take the median
}
//printf("The middle is %f\n",median);

if(n%2==0)                     //check the length of array 2 is even
{
middle=(b[((n/2)-1)]+b[n/2])/2.0;     //take the median
}
else
{
middle=b[n/2];                       //take the median
}
//printf("The middle is %f\n",middle);
median1=((median+middle)/2.0);
printf("The middle is %f\n",median1);
getchar();
printf("Do you want to continue yes or no\n");
scanf("%c",&c);

}
}
while(c == 'y');                   //loop for again run this program
return 0;
}


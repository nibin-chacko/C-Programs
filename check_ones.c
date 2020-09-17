#include<stdio.h>
int main()
{
    unsigned int a,count=0;
    printf("Enter the number :");
    scanf("%d",&a);
    while(a != 0)
    {
	int b = a%10;
	if(b == 1)
	{
	   count++; 
	}
	else
	{
	    printf("All are not ones\n");
	    return 0;
	}
	a = a/10;
    }
    printf("All are ones\n");
    return 0;
}

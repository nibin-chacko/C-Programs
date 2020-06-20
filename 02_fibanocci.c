//Author:Nibin chacko
//date:20/6/2020
//Description:to find the fibanocci serirs
//input:10
//output:0 1 1 2 3 5 8
#include <stdio.h>
int main()
{
    int num;
    char c;
    do
    {
	printf("Enter the number\n");
	scanf("%d",&num);


	if(num == 0)
	printf("\t0\t\n");
        int f;
	int s;
	int t;
	f=0;
	s=1;

	 if (num > 0)        //condition to check the enterd number is positive
	
	{
	    {
	    printf("\t%d\n",f);
	}
	t=(f+s);
	
	while (t <= num )
	{
	    printf("\t%d\n",t);
	    t=f+s;
	    f=s;
	    s=t;
	}
	}
	else if (num < 0)               //check the condition to check the enterd number is negative
	{
	    while (-f > num)
	    {
	    printf("\t %d\n",f);
	    t=(f-s);
	    f=s;
	    s=t;
	}
	}

	getchar();
	printf("Do you want to continue y or n\n");
	scanf("%c",&c);
    }
    while( c == 'y');
    return 0;
}


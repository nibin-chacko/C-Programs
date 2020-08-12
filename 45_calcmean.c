/*
AUTHOR:Nibin chacko
DESCRIPTION:MEAN CALCULATOR
DATE:21/12/19
INPUT:./a.out
OUTPUT:
1.int
2.short
3.Float
4.double
Enter the choice
3
Enter number of ellements:4
Enter array ellements
1.2
2.2
3.3
4.4
mean is 2.775000
Do you want to continue(y/n)
n
*/
#include<stdio.h>
double mean(int z,int);//function prototype
int main()
{
    char ch;
    do
    {   int x,z;
	double m;
	printf("1.int\n2.short\n3.Float\n4.double\n");
	printf("Enter the choice\n");
	scanf("%d",&x);
	switch(x) //switch condition
	{
	   case 1:m=mean(x,z);
		  printf("mean is %f",m);
		  break;
           case 2:m=mean(x,z);
		  printf("mean is %f",m);
		  break;
           case 3:m=mean(x,z);
		  printf("mean is %f",m);
		  break;
           case 4:m=mean(x,z);
		  printf("mean is %f",m);
		  break;
	   default:printf("Enter correct option\n");
	}
	getchar();
	printf("\nDo you want to continue(y/n)\n");
	scanf("%c",&ch);
    }while(ch=='y');
    return 0;
}
double mean(int x,int z)
{    
    int t,i;
    short k=0;
    float f=0,s=0;
    double m,j;    
    printf("Enter number of ellements:");
    scanf("%d",&t);
    if(x==1)
    {
	int a[t];//declaring array
	printf("Enter array ellements\n");
    for(i=0;i<t;i++)
    {
	scanf("%d",&a[i]);
	s=s+a[i];
	m=s/t;//calculating mean
    }
    return m;//returning the value of mean
    }
    else
	if(x==2)
	{
	    short b[t];
	printf("Enter array ellements\n");
    for(i=0;i<t;i++)
    {
	scanf("%hd",&b[i]);
	k=k+b[i];
	m=k/t;
    }
    return m;
	}
	else
	    if(x==3)
	    {
		float c[t];
	printf("Enter array ellements\n");
    for(i=0;i<t;i++)
    {
	scanf("%f",&c[i]);
	f=f+c[i];
	m=f/t;
    }
    return m;
	    }
	    else
		if(x==4)
		{
		    double d[t];
	printf("Enter array ellements\n");
    for(i=0;i<t;i++)
    {
	scanf("%lf",&d[i]);
	j=j+d[i];
	m=j/t;
    }
    return m;
		}
}

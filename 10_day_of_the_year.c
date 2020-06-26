//Name:Nibin chacko
//date:26/6/2020
//descripton:to print the day
//input:
//output:
#include<stdio.h>
int main()
{
  char ch;
do
{
  int n,i,day,day1,result;
  printf("Enter the value of n\n");
  scanf("%d",&n);
  printf("choose First day:\n1.sunday\n2.Monday\n3.Tuesday\n4.Wednesday\n5.Thursday\n6.Friday\n7.Saturday\n");
  printf("Enter the first day\n");
  scanf("%d",&day1);
  if(n>365 || n<=0 || day1>=8) //checking the condition
   {
    printf("Enter valid input\n"); 
   }
   else
   {
    result=(n + day1) % 7 - 1;
    switch(result )
    {
    case -1: 
	    
	   printf("The %dth day is friday\n",n);
	   break;
    case 0:printf("The %dth day is saturday\n",n);
	   break;
    case 1:printf("The %dth  day is sunday\n",n);
	   break;
    case 2:printf("The %dth day is monday\n",n);
	   break;

    case 3:printf("The %dth day is tuesday\n",n);
	   break;
    case 4:printf("The %dth day is wednesday\n",n);
            break;	
    case 5: printf("The %dth day is friday\n",n); //for all other condition use default statement
	     break;
}
}
getchar();
printf("Do you want to continue (y/n)\n");
scanf("%c",&ch); //loop control variable
}while(ch=='y');
return 0;
}

/*Name :Nibin chacko
 * Date:5/7/2020
 * Description:To find the average
 * Input:./a.out 1 2 3 4 5 6
 *           Select the method to calculate average:
               1.Scan from keyboard.
               2.Proceed with provided command line argument.
               3.Proceed with environment variale arguments.
              Enter you choice  :2
 *Output:The average of enterd numbers    :3.50
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
int main(int argc,char **argv,char *envp[])
{
    char ch;
    do
    {
    int arr[50],op,in,sum=0,count=0;
    char *en;
    char *token;
    printf("Select the method to calculate average:\n 1.Scan from keyboard.\n 2.Proceed with provided command line argument.\n 3.Proceed with environment variale arguments.\n");
    printf("Enter you choice  :");
    scanf("\n%d",&op);
    switch(op)        //switch case to select the operator
    {
	case 1:
	    printf("Enter the total number of integers: ");
	    scanf("%d",&in);
	    printf("Enter the elements :"); 
	    for(int i = 0;i < in;i++)     //loop for scanning elements
	    {
		scanf("%d",&arr[i]);
	    }
	    for(int i = 0;i < in; i++)      //loop for adding elements
	    {
		sum += arr[i];
	    }

	    printf("The average of entered numbers    :%.2f\n",((float)sum/in));
	    break;
	case 2:
	    if(argc == 1)       //if only file name in the command line
	    printf("Enter the numbers in command line\n");
	    for(int i = 1;argv[i] != NULL;i++)     //loop for taking the all elemnts int the command line
	    {
		sum += atoi(argv[i]);
	    }
	    printf("The average of enterd numbers    :%.2f\n",((float)sum/(argc-1)));
	    break;
	case 3:
	    en=getenv("num");   //get value from envirnment
	    if(en == NULL)
	    {
		printf("Enter the values in envirnment\n");
	    }
	    token=strtok(en," "); //split the strings
	    while(token != NULL)  //loop for taking each number
	    {
		sum +=atoi(token); //atoi convert the string into integer values
		count++;   //count for count the numbers
	//	printf("%d ",atoi(token));
		token=strtok(NULL," ");
	    }
	    printf("The average of passed environmental variable is %.2f\n",(float)sum/count);
	    break;
	default:
	    printf("Enter the valid operation\n");
	    break;

    }
    
    
    printf("Do you want to continue y / n :");   
    getchar();
    scanf("%c",&ch);
    }
    while(ch == 'y');  //loop for continue
}





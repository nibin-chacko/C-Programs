/* Author: Nibin Chacko
 * Date: 01-7-2020
 * Description: replace_nbits_from_pos
 * Input:Enter the number:10
   Enter the 'i':110
   Enter the 'a'position(bits):3
   Enter the 'b' position:5
 * Output:86
 * comments end */
#include <stdio.h>

int replace_nbits_from_pos( int num, int i, int a, int b ); //function called.

int main()    //main function
 { char option;  
    do
    {
	int opt, num, i, a, b;
        printf("Enter the number:");
        scanf("\n%d",&num);		// reading number
        printf("Enter the 'i'(new number):");
        scanf("\n%d",&i);    // reading number2
        printf("Enter the 'a'(bits):");
        scanf("\n%d",&a);   // reading how many bits
        printf("Enter the 'b' position:");
        scanf("\n%d",&b);    //reading bits position to change
	if ( a <= 0 || a >=31 || b<= 0 || b >=31 )
	    printf("bits or Positon is out of range!!\n");
	else
	{
        i=replace_nbits_from_pos( num, i, a, b);  //calling function 
	    printf("%d\n",i);  // printing output
	}
printf("Do You Want To Continue(y/n)\n"); //asking user to wether continue or not
scanf("\n%c",&option);
    } while ( option == 'y' );
    return 0;
}

int replace_nbits_from_pos( int num, int i, int a, int b )    //function called.
{
      int num1 = i;	//storing number into another variable
      i=(i>>b+1);   //right shifting by postion+1 time to clear the bits
      i=(i<<b+1); // left shifting by position+1 time to clear the bits
      num1= num1 & ((1<<(b-a+1))-1); // getting num1 value required bits
      num = ((1<<a)-1) & num; // num and with 1<<bits , -1 value  
      num = num<<(b-a+1);  // num left shifting with position-bits+1 time
      return  num+num1+i; // adding all those outputs
}      

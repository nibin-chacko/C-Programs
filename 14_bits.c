/* Author: Nibin chacko
 * Date: 30-6-2020
 * Description: print as per user requirement
 * Input:
   1.get bits
   2.replace 'n' bits
   3.get'n' bits from position
   4.replace'n' bits from position
   5.toggle bits from position
   6.print'n' bits
   Enter your choise:1
   Enter the number:14
   Enter the 'n':3
 * Output:6
 * comments end */
#include <stdio.h>

int get_nbits(int num, int n)
{ 
    return (((1<<n)-1) & num); //first puting one and 1 in 4byte and and moving upto n and removing -1 and with num to get reuired bits by num
}

int replace_nbits(int num, int n, int val)
{
        num=(num>>n);  //right shifting num by n 
	num=(num<<n);  // left shifting num by n to get required bits
	num |=(((1<<n)-1) & val); // seting value of index bit value to num of value
    return num;
}

int get_nbits_from_pos( int num, int n, int pos)
{ 
    return (((1<<n)-1) & num>>(pos-n+1)); //first puting one and 1 in 4byte and and moving upto n and removing -1 and geting req num by setting pos
}

int replace_nbits_from_pos( int num, int n, int val, int pos )
{
     int num1 = num;//storing number into another variable
        num=(num>>pos+1);//right shifting by postion+1 time to clear the bits
	num=(num<<pos+1);// left shifting by position+1 time to clear the bits
	num1= num1 & ((1<<(pos-n+1))-1);// getting num1 value required bit
        val = ((1<<n)-1) & val; // num and with 1<<bits , -1 value 
        val = val<<(pos-n+1);// num left shifting with position-bits+1 time
       return num | num1 | val;// adding all those outputs and returning
}
int toggle_bits_from_pos( int num, int n, int pos)
{ 
     int mask;//mask variable to protect num remaining bits
	mask = ~(~0<<n)<<(pos-n+1);// getting mask value required bit
       return  num^mask;// mask xor with num, returning output
}
void print_bits( int num, int n)
{ 
    int i;
    for(i=n-1; i>=0; i--) //loop to zero the n bits
    {
     printf("%d",num>>i & 1);
    }
    printf("\n");
}
int main()
 { char option;
    do
    {
	int opt, output, num, n, val, pos, var;
     printf("1.get bits\n2.replace 'n' bits\n3.get'n' bits from position\n4.replace'n' bits from position\n5.toggle bits from position\n6.print'n' bits\nEnter your choise:");
     scanf("\n%d",&opt);
     if( opt >= 7 || opt <= 0)
	 printf("No such case available\n");
     else
     {
     printf("Enter the number:");
     scanf("%d",&num);
     printf("Enter the 'n':");
     scanf("%d",&n);
     switch(opt)
     {
	 case 1:
	     output=get_nbits( num, n);// calling fuction
		break;
	 case 2:
	     printf("Enter the value:");
	     scanf("\n%d",&val);
	     output=replace_nbits( num, n, val);//calling fuction
		break;
	 case 3:
	     printf("Enter the position:");
	     scanf("\n%d",&pos);
	     output=get_nbits_from_pos( num, n, pos); //calling function
		break;
	 case 4:
	     printf("Enter the position:");
	     scanf("\n%d",&pos);
	     printf("Enter the value:");
	     scanf("\n%d",&val);
	     output=replace_nbits_from_pos( num, n, val, pos);//calling function
		break;
	 case 5:
	     printf("Enter the position:");
	     scanf("\n%d",&pos);
	     output=toggle_bits_from_pos( num, n, pos);//calling function
		break;
	 case 6:
	     print_bits( num, n );  //print bits
		break;
/*	 default:
	      printf("NO More,choose one  from above\n");
		break;;*/
     }
     if(opt != 6)//print output for all cases here , but not case 6
     printf("%d\n",output);
     }
printf("Do You Want To Continue(y/n)\n"); //asking user to wether continue or not
scanf("\n%c",&option);
    } while ( option == 'y' );
    return 0;
}

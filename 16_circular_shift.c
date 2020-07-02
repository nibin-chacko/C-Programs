/*author:Nibin Chacko
 * date:2/7/2020
 * description:To make the given number left shift and right shift
input:Enter the number
            12
          Enter the position
             3
	     choose the operation
                  1.Circular right shift
                  2.circular left shift
output:After circular right shifting by 3
New binary from ---> 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

*/ 
#include<stdio.h>
void print_bits(int num);
int right_shift(int num,int n);
int left_shift(int num,int n);
int main()
{
    char ch;
    do
    {
  int num,n,c,new;
  printf("Enter the number\n");    //gets the user option
  scanf("%d",&num);
  printf("Enter the position\n");
  scanf("%d",&n);
  printf("1.Circular right shift\n2.circular left shift\n");
  scanf("%d",&c);
  switch (c)      //case to select option
  {
      case 1:    //case for right shift
	  printf("\nAfter circular right shifting by %d\n",n);
	  new = right_shift(num,n);
	      break;
      case 2:   //case for left shift
	  printf("\nAfter circular left shifting by %d\n",n);
	  new = left_shift(num,n);
	      break;
      default:
	      printf("Invaliod choice!!!!!!\n");
  }
  printf("New binary from --->");
  print_bits(new);
  getchar();
    printf("Do you want to continue yes or no\n");
  scanf("%c",&ch);
    }
    while( ch == 'y');
  return 0;
}


  void print_bits(int num)   //function to print bits of numbers
  
{
    int i;
    unsigned int mask=0x80000000;
    for(i=0;i<32;i++)      //loop for printing bits of numbers
    {
    if ( num & mask)
	printf(" 1");
    else
	printf(" 0");
    mask >>=1;
    }
    printf("\n");
    
  }
int right_shift(int num,int n)    //function for circular right shift
{
    int j,y,z;
    unsigned int msk = 0x80000000,mask = 0x01;
    for(j = 0;j < n; j++)       //loop for circular right shift
    {
	y = num & mask;
	num >>= 1;
	z = num & msk;
	if ((y == 0 && z !=0) || (y != 0 && z == 0))

	    num ^= msk;
    }
    return num;
}
int left_shift(int num,int n)            //function for circular left shift
{
    int j,y,z;
    unsigned int msk = 0x80000000,mask = 0x01;
    
    for(j = 0;j < n; j++)               //loop for circular left shift
    {
	y = num & msk;
	num <<= 1;
	z = num & mask;
	if(( y == 0 && z != 0) || ( y != 0 && z == 0))
	{
	    num ^= msk;
	}
	return num;
    }
}

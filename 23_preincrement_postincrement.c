/*Author:Nibin chacko
 * Date:
 * Description:post increment and pre increment
 * input:
         Enter the number:
          3
        1.post increment
        2.pre increment
          1
 *Output:
           After post incremnt i=3,num=4
*/
#include<stdio.h>
int postincrement(int *n,int mask);
int preincrement(int *n,int mask);
int main()
{
    char ch;
    do
    {
    int n,mask,op,x,y;
    mask=0x01;                   //set the mask
    printf("Enter the number:\n");
    scanf("%d",&n);
    printf("1.post increment\n2.pre increment\n");
    scanf("%d",&op);
    switch (op)
    {
	case 1:
	  x = postincrement(&n,mask);            //call function for postincrement
	    printf("After post incremnt i=%d,num=%d\n",x,n);
	    break;
	case 2:
	    y= preincrement(&n,mask);           //call function for preincrement
	    printf("After pre increment i=%d,num=%d\n",y,y);
            break;
    }
    getchar();
    printf("Do you want to continue y/n\n");
    scanf("%c",&ch);
    }
    while(ch == 'y');

    return 0;
}
 
int postincrement(int *n,int mask)    //call description
{
    int k;
    k=*n;
   
    while(*n & mask)
    {
	*n^=mask;            //num is  mask with num
	mask<<=1;            //left shift
    }
    *n^=mask;
    return k;
}



int preincrement(int *n,int mask)           //call description
{
    while(*n & mask)
    {
	*n^=mask;                        //num is mask with num
	mask<<=1;                        //left shift
    }
    *n^=mask;
    return *n;
}

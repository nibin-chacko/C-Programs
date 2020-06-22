//Author:Nibin chacko
//Date:21/11/19
//Description:To print size of all basic data types of c
//input:
//output:
       //Size of int           :4 bytes
       //Size of char          :1 bytes
       //Size of float         :4 bytes
       //Size of double        :8 bytes
       //Size of unsigned int  :4 bytes
       //Size of long double   :16 bytes
       //Size of long long int :8 bytes
       //Size of short int     :2 bytes
       //Size of long int      :8 bytes
       //Size of unsigned char :1 bytes


#include<stdio.h>

int main()
{
 printf("Size of int           :%zu bytes\n",sizeof(int));//size of the given data type
 printf("Size of char          :%zu bytes\n",sizeof(char));
 printf("Size of float         :%zu bytes\n",sizeof(float));
 printf("Size of double        :%zu bytes\n",sizeof(double));
 printf("Size of unsigned int  :%zu bytes\n",sizeof(unsigned int));
 printf("Size of long double   :%zu bytes\n",sizeof(long double));
 printf("Size of long long int :%zu bytes\n",sizeof( long long int));
 printf("Size of short int     :%zu bytes\n",sizeof(short int));
 printf("Size of long int      :%zu bytes\n",sizeof(long int));
 printf("Size of unsigned char :%zu bytes\n",sizeof(unsigned char));
 return 0;
} 


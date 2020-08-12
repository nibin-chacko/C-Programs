/*Author    : Nibin chacko
Date	    : 24/01/2020
Description : To read and print the marks and grades of students
Input	    : ./a.out
Comments
*/
#include<stdio.h>
#include<string.h>//string comparision
#include<ctype.h>//string comparision
typedef struct Student//structure
{
    char name[30],sub[10],find[10];//,roll[10];//arrays for storing names
    int Mark[150];//marks
}student;
void read (int n,int N,student *st);//function decleration
void search (int n,int N,student *dt);//
void marks(int P,int n,int N, student *m );//function decleration
int compare(char *str1,char *str2);
int main()
{
    char ch;
    do
    {
	int n,N,i=0;
	char M;
	printf("Enter No Of students:\n");//students
	scanf("%d",&n);
	printf("Enter No of subjects:\n");//subjects
	scanf("%d",&N);
	if(n > 0 && N > 0 && N <= 6 )
	{
	    student s[n];//name
	    read(n,N,s);//function
	    for(i=0; ; i++)
	    {
		printf("Do you Want To see details with same data:\n");
		scanf("\n%c",&M);
		if(M == 'y')
		    search(n,N,s);
		else
		    break;
	    }
	}
	else
	{
	    printf("Please Enter Valid No Of Students OR Subjects\n");
	}
	printf("Do You Want To Continue(y/n):\n");
	scanf("\n%c",&ch);//for more examples
    }while ( ch == 'y');
    return 0;
}
void read (int n,int N,student *st)
{
    int i=0,j=0,k=0,z;//
    for(i=0;i<N;i++)
    {
	printf("Enter Name of %d Subject :",i+1);
	scanf("\n%[^\n]",(st+i)->sub);//names of subjects
	//scanf("\n%s",(st+i)->sub);
    }
    for(i=0;i<n;i++)
    {
	printf("Enter Name of %d student:\n",i+1);
	scanf("\n%s",((st+i)->name));//student name
	for(j = 0; j< N ;j++)
	{
	    printf("Enter Marks of subject %s :",(st+j)->sub);
	    //scanf("%d",(st+k)->Mark);//marks of each subject
	    scanf("%d",&z);//marks of each subject
	    if(z >= 0 && z <= 100)
	    {
		*((st+k)->Mark) = z;
		k++;
	    }
	    else
	    {
		j--;
	    }
	}
    }
    search(n,N,st);
}
void search (int n,int N,student *dt)//searching purpose
{
    int P=0,i=0,opt;
    printf("Enter Choice of\n1.Perticular Student record\n2.All students Record:\n");
    scanf("%d",&opt);//choice of user
    switch (opt)
    {
	case 1:
	    printf("Enter Student Name of Details Required :");
	    scanf("\n%s",(dt->find));//student name
	    for ( i = 0; i < n; i++ )
	    {
		P=compare((dt+i)->name,dt->find);
		if( P==0 )
		{
		    P=i+1;
		    break;
		}
	    }
	    if( P == 0 )
	    {
		printf("Name Is Not Found\n");
	//	search(n,N,dt);
	    }
	    else
	    {
		marks(P,n,N,dt);//function call
	    }
	    break;
	case 2:
	    marks(P,n,N,dt);//all students
	    break;
	/*default:
	    printf("You Have Selected Other option so Default Printing All Students Rcord");
	    marks(P,n,N,dt);
	   break; */
    }

}
int compare(char *str1,char *str2)
{
    while(*str1 && *str2 && (toupper(*str1) == toupper(*str2)))
    {
	str1++,str2++;
    }
    return *str1-*str2;
}
void marks(int P,int n,int N, student *m )
{
    int i=0,j=0,k=0;

    printf("----------------------------------------------------------------------\n");
    printf("Roll.No\tName");//print name
    for(i=0;i<N;i++)
    {
	printf("\t%s",(m+i)->sub);//print subjects names
    }
    printf("\tAverage\tGrade\n");//print average and grade
    printf("----------------------------------------------------------------------\n");
    i=0;
    if(P >= 1)
    {
	i = P-1;
	n=P;
	k=N*i;
    }
    for(i;i<n;i++)
    {
	double avg=1;
	int sum=0,count=0;//initiation
	printf("%d\t%s\t",i+1,(m+i)->name);//printing student name
	for(j=0; j< N ;j++)
	{
	    if( (*(m+k)->Mark) < 35 )
	    {
		count+=1;//for less than 35 marks in subjects
	    }
	    sum+=*(m+k)->Mark;//sum of all subjects
	    printf("%d\t",*(m+k)->Mark);//print marks of each subject
	    k++;
	}
	avg=(avg*sum)/N;//average
	printf("%.2lf",avg);//print average
	if( count == 0 )//if not failed in any subject
	{ 
	    if ( avg >= 95 )//printing grades
	    {
		printf("\tA+ Excellent\n");
	    }
	    else if ( avg < 95 && avg >= 85 )
	    {
		printf("\tA Good\n");
	    }   
	    else if ( avg < 85 && avg >= 75 )
	    {
		printf("\tB+ Good\n");
	    }
	    else if ( avg < 75 && avg >= 65 )
	    {
		printf("\tB Above Average\n");
	    }
	    else if ( avg < 65 && avg >= 55 )
	    {
		printf("\tC Average\n");
	    }
	    else if ( avg < 55 && avg >= 45 )
	    {   
		printf("\tD Below Average\n");
	    }
	    else
	    {   
		printf("\tE Poor\n");
	    }
	}
	else //if failed in any subject 
	{
	    printf("\tF Failed in %d subs\n",count);
	}

    }
    printf("----------------------------------------------------------------------\n");
}

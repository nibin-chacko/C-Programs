/*Name :Nibin chacko
 * Date:28/1/2020
 * Description:To copy the contents of file1 to file2
 * Input:./a.out file1.txt file2.txt
 * Output:copy completed
 * */
#include<stdio.h>
int main(int argc,char **argv)
{
    char chr;
    do
    {
    int c;
    char ch;
    FILE *fp1;
    FILE *fp2;  //declering file pointers
    if(argc == 1)  //condition for vslid inputs
    {
	printf("Enter the sourse file and destination file in command line\n");
	return 1;
    }
    else if(argc == 2)
    {
	fp1 = fopen(argv[1],"r");
	if(fp1 == NULL)
	{
	    printf("file is not present\n");
	    return 1;
	}
	else
	{
	    while((ch = fgetc(fp1)) != EOF)
	    {
		putchar(ch);
	    }
	}
	fclose(fp1);
    }
    else if(argc == 3)

    {
	fp1 = fopen(argv[1],"r");  //open the file1 in read mode
	if(fp1 == NULL)
	{
	    printf("The sourse file is not present\n"); //if the file is not present
	    return 1;
	}
	fp2 = fopen(argv[2],"w");   //open file for write mode
    
    while((c = fgetc(fp1)) != EOF)   //getting characters till eof
    {
      fputc(c,fp2);    //printing the contents of file1 to file2
    }
    fclose(fp1);
    fclose(fp2);  //close the files
    printf("Copy completed\n");
    }
    printf("\nDo you want to continue y/n :");
    scanf("\n%c",&chr);
}while(chr == 'y');
}


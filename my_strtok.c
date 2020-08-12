/*Name:Nibin chacko
  Date:24/1/2020
  Description:program for my stroke
  Input :
  Output :
*/
#include<stdio.h>
#include<string.h>
char my_stroke(char *str,char *delim);
int main()
{
    char str1[100],str2[50],*token;
    printf("Enter string1:");
    scanf("%99[^\n]",str1);
    printf("Enter string2:");
    getchar();
    scanf("%49[^\n]",str2);
    printf("Tokens are:\n");
    token = my_stroke(str1,str2);
    while(token != NULL)
    {
	printf("%s\n",token);
	token = my_stroke(NULL,str2);
    }
    return 0;
}

char my_stroke(char *str,char *delim)          //function for extracting the token
{
    static char *s,str3[50]; 
    static int pos=0,stop;
    int j,k;
    if(str != NULL)
    {
	s = str;   //stores whole string in static strong
        stop = strlen(s);  //store the length of the string for indication of final stop
	for(j = 0;s[j] != '\0';j++)
	{
	    for(k = 0;delim[k] != '\0';k++)
	    {
		if(s[j] == delim[k])
		{
		    s[j] = '\0';
		}
	    }
	}
	j =0;
	while(s[pos] != '\0')  //extract the first token and store in seperate array
	{
	    str3[j] = s[pos];
	    pos++;
	    j++;
	}
	while(s[pos] == '\0')
	{
	    pos++;
	}
	str3[j] = '\0';
	return str3;   //return the base address of token string obtained
    
    else  //this block executes for the further call of the my strokr function
	if(s[pos] != '\0')  //starts from pos which is the at the starting point of next string
        {
	    str3[j] = s[pos];
	    pos++;
	    j++;
	}
    while( s[pos] == stop)
    {
	if(pos == stop)
	    break;
	pos++;
    }
    str3[j] = '\0';
    return str3;
}
else
return NULL;    //return null if end of string is reached
}


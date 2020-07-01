#include<stdio.h>
#include "encode.h"
#include "types.h"
int main(int argc, char *argv[])
{
   if((check_operation_type(&argv[1]))==e_encode)
    {
	printf("encode is proceeded\n");
        return 0;
    }
    else if((check_operation_type(&argv[1]))==e_decode)
    {
	printf("decode is proceeded\n");
    }
    else
    {
	printf("unsupported format\n");
    }
}

OperationType check_operation_type(char *argv[])
{
    if(*(*(argv)+1)== 'e')
	return 0;
    else if(*(*(argv)+1)=='d')
	return 1;
    else
	return 2;
}

Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo);


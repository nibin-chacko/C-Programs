#include<string.h>
#include <stdio.h>
#include"common.h"
#include"encode.c"
#include "encode.h"
#include"decode.h"
#include"decode.c"
#include"types.h"



int main(int argc, char *argv[])
{
    EncodeInfo encInfo;
    DecodeInfo decInfo;

    //check operation type
    if(check_operation_type(argv) == e_encode)
    {

	//read and validation check type
	if(argc < 3)
	{
	    fprintf(stderr, "ERROR:Unable to open the files\n");
	    return e_failure;
	}
	else
	{
	    //checking reading of files are normal or not
	    if(read_and_validate_encode_args(argv, &encInfo) == e_success)
	    {

		// checking encoding process is normal or not
		if( do_encoding(&encInfo) == e_success)
		{
		    printf("INFO:Encoding done successfully\n");
		}
		else
		{
		    printf("INFO:Encoding not done successfully\n");
		}
	    }
	    else
	    {
		//if reading of files has error
		fprintf(stderr,"ERROR:Unable to open the files\n");
		return e_failure;
	    }
	}

    }
    else if(check_operation_type(argv) == e_decode)
    {
	if(argc < 3)
	{
	    fprintf(stderr,"ERROR:Unable to open the files\n");
	    return e_failure;
	}
	else
	{
	    if(read_and_validate_decode_args(argv,&decInfo) == e_success )
	    {
		if(do_decoding(argv,&decInfo) == e_success)
		{
		    printf("INFO:Successfully done decoding\n");
		    return e_success;
		}
		else
		{
		    printf("INFO:error while  decoding");
		    return e_failure;
		}

	    }
	    else
	    {
		puts("Decoding error");
	    }
	}
    }		
    else
    {
	//operation types problems
	fprintf(stderr,"ERROR:unsupported formate\n");
	return e_failure;
    }

}

/*int main()
  {
  Status status;
  char *secret_file, *src_image, *stego_image;

// Fill with sample filenames
secret_file = "secret.txt";
src_image = "beautiful.bmp";
stego_image = "stego_img.bmp";

// Test open_files
if (do_encoding(secret_file, src_image, stego_image) == e_failure)
{
fprintf(stderr, "ERROR: Unable to encode %s file into %s image\n", secret_file, src_image);
return 1;
}
else
{
printf("SUCCESS: %s file is encoded in %s image\n", secret_file, stego_image);
return 0;
}
}*/

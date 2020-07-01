#include <stdio.h>
#include<string.h>
#include "encode.h"
#include "types.h"
#include "common.h"

//>>>>>>>>>>>>>>>to check the the operation is encoding or decoding>>>>>>>>>
OperationType check_operation_type(char *argv[])
{
    //if null 
    if(argv[1] != NULL)
    {
	//if encoding 
	if(strcmp(argv[1], "-e") == 0)
	    return e_encode;

	//if decoding
	else if(strcmp(argv[1], "-d") == 0)
	    return e_decode;

	//if unsupported format
	else
	    return e_unsupported;
    }
    else
	return e_unsupported;
}


//>>>>>>>>>>>>>>>>>>to check the passing files are correct or not>>>>>>>>>>>
Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
    short int bytes;

    //to open the .bmp file
    FILE *fp = fopen(argv[2], "r");

    //to read the first two byte
    fread(&bytes, sizeof(short int), 1, fp);

    //to check the whether  the it is bmp or not
    if(bytes != 0x4D42)
    {
	return e_failure;
    }
    fclose(fp);
    encInfo->src_image_fname = argv[2];
    
    //to check secret file is null or not
    if(argv[3] == NULL)
    {
	return e_failure;
    }
    else
    {
    	printf("INFO:secret file present\n");
	encInfo -> secret_fname = argv[3];
    }

    //to check destination file is given or not
    if(argv[4] == NULL)
    {
    	printf("INFO:Output file not mentioned .Created steged image.bmp as default\n");

	encInfo->stego_image_fname = "stego_img.bmp";
	return e_success;

    }
    else
    {
    	printf("INFO:Taking the given file output file name\n");

	encInfo->stego_image_fname = argv[4];

	return e_success;
    }

}
//>>>>>>>>>>>>>>>>>to check all files are open or not>>>>>>>>>>>>>>>>>>>>

Status open_encode_files(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo -> src_image_fname, "r");

    //Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
	perror("fopen");

	fprintf(stderr, "ERROR: Unable to open file1 %s\n", encInfo -> src_image_fname);

	return e_failure;
    }
    else
    {
	printf("INFO:opened beautiful.bmp file\n");
    }

    // Secret file
    encInfo -> fptr_secret = fopen(encInfo -> secret_fname, "r");

    //Do Error handling
    if (encInfo -> fptr_secret == NULL)
    {
	perror("fopen");

	fprintf(stderr, "ERROR: Unable to open file 2%s\n", encInfo -> secret_fname);

	return e_failure;
    }
    else
    {
	printf("INFO:opened secret file\n");
    }

    // Stego Image file
    encInfo -> fptr_stego_image = fopen(encInfo -> stego_image_fname, "w");

    //Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file 3%s\n", encInfo->stego_image_fname);
	return e_failure;
    }
    else
    {
	printf("INFO:opened stego image file\n");
    }

    // All files opened, return e_success
    return e_success;

}



//>>>>>>>>>>>>>>>to find the size of the beautiful.bmp image>>>>>>>>>>>>>>>>>>>>

uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (int)
    fread(&width, sizeof(int), 1, fptr_image);
    //printf("width = %u\n", width);

    // Read the height ( int)
    fread(&height, sizeof(int), 1, fptr_image);
    //printf("height = %u\n", height);

    
    rewind(fptr_image);
    // Return image capacity
    return width * height * 3;
}




//>>>>>>>>>>>>>>get secret file size >>>>>>>>>>>>>>>>>>>>>>>

uint get_file_size(FILE *fptr)
{
    int size;
    //to get the secret file size
    fseek(fptr, 0, SEEK_END);
    size = ftell(fptr);
    rewind(fptr);
    return size;
}

//>>>>>>>>>>>>>>>>>>start the encoding>>>>>>>>>>>>>>>>>>>>>>>>>>>

Status do_encoding(EncodeInfo *encInfo)
{
    printf("INFO:opening the requried files\n");
    if(open_encode_files(encInfo) == e_success)
    {
	printf("INFO:Done\n");
    }
    else
    {
	return e_failure;
    }
    printf("\n##ENCODING PROCEDURE IS STARTED##\n\n");
    printf("INFO:checking the file capacity\n"); 
    
    //to check check capacity is succeed or not
    if(check_capacity(encInfo) == e_success)
    {
    	printf("INFO:Done\n");
    }
    else
    {
    	return e_failure;
    }
    printf("INFO:coping the header file from bmp file\n");
    if(copy_bmp_header(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
    {
    	printf("INFO:Done\n");
    }
    else
    {
    	return e_failure;
    }
    printf("INFO:Encoding the magic string signature\n");
    //check magic string encoding is succeed or not
    if(encode_magic_string(MAGIC_STRING, encInfo) == e_success)
    {
	printf("INFO:Done\n");
    }
    else
    {
    	return e_failure;
    }

    //to get the file extension type
    char *str = ".";
    char *ret = strstr(encInfo->secret_fname, str);

    printf("INFO:Encoding the file extension size\n");

    int size=strlen(ret);
    //printf("%d\n",size);
    if(encode_secret_extn_size(size,encInfo) == e_success)
    {
	printf("INFO:Done\n");
    }
    else
    {
	return e_failure;
    }

    printf("INFO:Encoding the file extension file\n");
    //char *string = ".";
   // char *rett = strstr(encInfo->secret_fname, string);
  // printf("%s",ret);
    if(encode_secret_file_extn(ret,encInfo) == e_success)
    {
    	printf("INFO:Done\n");
    }
    else
    {
    	return e_failure;
    }

   printf("INFO:Encoding the secret file size\n");
    unsigned sec_size=get_file_size(encInfo->fptr_secret);
  //  printf("\n%d\n",sec_size);
    if(encode_secret_file_size(sec_size, encInfo) == e_success)
    {
    	printf("INFO:Done\n");
    }
    else
    {
    	return e_failure;
    }
    printf("INFO:Encoding the file data\n");
    if(encode_secret_file_data(encInfo) == e_success)
    {
    	printf("INFO:Done\n");
    }
    else
    {
	return e_failure;
    }
    printf("INFO:Coping the remaining image file data\n");

    if(copy_remaining_img_data(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)

    {
    	printf("INFO:Done\n");
    	return e_success;
    }
    else
    {
    	return e_failure;
    }
}



 //>>>>>>>>>>>>>>>>>>to check the image size is greater than 480>>>>>>>>>>>>>>>> 
Status check_capacity(EncodeInfo *encInfo)
{
    int total_size;
    unsigned int image_size;

    //to get the file extension type
    char *str = ".";
    char *ret = strstr(encInfo->secret_fname, str);

    //to calculate the total size required for file
    total_size =(strlen(MAGIC_STRING) + sizeof(int) + strlen(ret) + get_file_size(encInfo->fptr_secret) + get_file_size(encInfo->fptr_secret))*8;


   // image_size = get_image_size_for_bmp(encInfo->fptr_src_image);

    //to check  the capacity of file
    if(image_size > total_size)
    {
	return e_success;
    }
    else
    {
	return e_failure;
    }

}







//>>>>>>>>>>>>>>>>>>copy the 54 bytes to destination file>>>>>>>>>>>>>>>>
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)
{
    int i;
    char chara[54];
    //reading the first 54byte of beatiful.bmp file
    fread(chara, 54, 1, fptr_src_image);


   // printf("%c",chara[0]);


    //to write into the destination file
    fwrite(chara, 54, 1, fptr_dest_image);

    //to compare the file is copied or not
    if(ftell(fptr_src_image) == ftell(fptr_dest_image))
    {
	return e_success;
    }
    else
    {
	return e_failure;
    }
    
}



//>>>>>>>>>>>>>>>>>encoding of the magic string>>>>>>>>>>>>>>>>
Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo)
{
    int i, j;
    int ch, num = 0;

    //char *star="*";

    //char * magic = strstr(magic_string,star);
    //printf("\n%s\n",magic);

    //printf("\n%d\n",strlen(magic_string));
    //encoding the magic string
    for(i = 0; i < strlen(magic_string); i++)
    {
	for(j = 0; j < (sizeof(char)*8) ; j++)
	{
	    fread(&ch, sizeof(char), 1, encInfo->fptr_src_image);

	    num = (ch & (-1 << 1)) | ((*(magic_string + i) >> j) & ~(-1 << 1));  

	    fwrite(&num, sizeof(char), 1, encInfo->fptr_stego_image);
	    

	}
    }
   // printf("   extn %d\n",ftell(encInfo->fptr_stego_image));

    return e_success;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

Status encode_secret_extn_size(int size_extn,EncodeInfo *encInfo)
{
    int i,j,num;
    char chara;
    
     //encoding the file extension 
    for(i = 0; i < sizeof(char); i++)
    {   
        for(j = 0; j < (sizeof(char) * 8) ; j++)
        {

            fread(&chara, sizeof(char), 1, encInfo->fptr_src_image);

            num = (chara & (-1 << 1)) | ((size_extn >> j) & ~(-1 << 1));  
            fwrite(&num, sizeof(char), 1, encInfo->fptr_stego_image);
        }

    }
    //printf(" size of extn %d\n",ftell(encInfo->fptr_stego_image));
    return e_success;
}

//>>>>>>>>>>>to check the extension of file>>>>>>>>>>>>>>>>>>>>>>

Status encode_secret_file_extn(const char *file_extn,EncodeInfo *encInfo)
{
    int i, j, num;
    int chara;

//    printf("\n%d\n",strlen(file_extn));
    //encoding the file extension 
    for(i = 0; i < strlen(file_extn); i++)
    {
	for(j = 0; j < (sizeof(char) * 8) ; j++)
	{

	    fread(&chara, sizeof(char), 1, encInfo->fptr_src_image);

	    num = (chara & (-1 << 1)) | ((*(file_extn + i) >> j) & ~(-1 << 1));  
	    fwrite(&num, sizeof(char), 1, encInfo->fptr_stego_image);
	}

    }
   // printf("   extn %d\n",ftell(encInfo->fptr_stego_image));
    return e_success;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>encode secret file size>>>>>>>>>>>>>>>>>>
Status encode_secret_file_size(long file_size, EncodeInfo *encInfo)
{
    int i,j, num,lenght;
    lenght=file_size;

  //  printf("%d\n",lenght);
    char chara;


    //encoding the secret file size
    for(i = 0; i< sizeof(int); i++)
    {
    	for(j = 0; j < (sizeof(int)*8) ; j++)
	{
	    
	    fread(&chara, sizeof(char), 1, encInfo->fptr_src_image);

	    num = (chara & (-1 << 1)) |((lenght >> j) & ~(-1 << 1));  

	    fwrite(&num, sizeof(char), 1, encInfo->fptr_stego_image);
	}

    }
    return e_success;
}
//>>>>>>>>>>>>>>>>>>>>encoding of the secret file data>>>>>>>>>>>>>>>>>>>>>>
Status encode_secret_file_data(EncodeInfo *encInfo)
{
    int i, j, num = 0;
    char chara1,chara2;

    //to set the offset to zero of the secret file
    fseek(encInfo->fptr_secret, 0, SEEK_SET);

    //to read and write to destination file
    while(fread(&chara2, 1, 1, encInfo->fptr_secret) > 0)
    {
	for(j = 0; j < (sizeof(char)*8) ; j++)
	{
	    fread(&chara1, 1, 1, encInfo->fptr_src_image);

	    num = (chara1 & (-1 << 1)) |((chara2 >> j) & ~(-1 << 1));  

	    fwrite(&num, 1, 1, encInfo->fptr_stego_image);
	}
    }

    //to copy the end of file
    chara2= EOF;
    for(j = 0; j < (sizeof(char)*8) ; j++)
    {
	fread(&chara1, 1, 1,encInfo->fptr_src_image);

	num = (chara1 & (-1 << 1)) |((chara2 >> j) & ~(-1 << 1));  

	fwrite(&num, 1, 1, encInfo->fptr_stego_image);
    }

    return e_success;
}

//>>>>>>>>>>>>>>>>>copy the remaining bytes to destination file>>>>>>>>>>>>
Status copy_remaining_img_data(FILE *fptr_src,FILE *fptr_dest)
{
    //to set offset to the current position
    fseek(fptr_src,ftell(fptr_src), SEEK_SET);

    fseek(fptr_dest,ftell(fptr_dest), SEEK_SET);

    char chara;

    //to copy the remaining the data
    while(fread(&chara, 1, 1, fptr_src) > 0)
    {
	fwrite(&chara, 1, 1, fptr_dest);
    }
    return e_success;
}



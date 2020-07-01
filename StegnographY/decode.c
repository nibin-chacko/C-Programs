#include<stdio.h>
#include"types.h"
#include<string.h>
#include"decode.h"


//>>>>>>>>>>>>>>>>>>>decoding process>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Status do_decoding(char *argv[],DecodeInfo *decInfo)
{
    printf("INFO:opening the required files\n");

    if(open_decode_files(decInfo) == e_success)
    {
        printf("INFO:Done\n");
    }
    else
    {
        return e_failure;
    }
    printf("\n\n##DECODING PROCEDURE STARTED##\n\n");

    printf("INFO:Decoding the the magic string\n");
    
    //to check decoding of magic string is success or not
    if(decode_magic_string(MAGIC_STRING, decInfo) == e_success)
    {
        printf("INFO:Done\n");
    }
    else
    {
        return e_failure;
    }
    printf("INFO:decode the file extension size\n");
    if(decode_extn_size(decInfo) == e_success)
    {
        printf("INFO:Done\n");
    }
    else
    {
        return e_failure;
    }

    printf("INFO:decode the file extension type\n");

    if(decode_output_file_extn(argv,decInfo) == e_success)
    {
        printf("INFO:Done\n");
    }
    else
    {
        return e_failure;
    }

    printf("INFO:Decode the file size\n");
    
    //to check file decode is success or not

    if(decode_file_size(decInfo) == e_success)
    {
        printf("INFO:Done\n");
    }
    else
    {
        return e_failure;
    }

    printf("INFO:Decode the file data\n");

    if(decode_file_data(decInfo->fptr_stego_image, decInfo->fptr_secret) == e_success)

    {
        printf("INFO:Done\n");
        fclose(decInfo->fptr_secret);
    return e_success;
    }
    else
    {
        return e_failure;
    }

}



//>>>>>>>>>>>>>>>>>>read and validate of commondline arguments>>>>>>>>>>>>>>>>>>

Status read_and_validate_decode_args(char *argv[],DecodeInfo *decInfo)
{
    short int bytes;

    //to check the file type
    FILE *fp = fopen(argv[2],"r");

    fread(&bytes, sizeof(short int), 1, fp);

    if(bytes != 0x4D42)
    {
        return e_failure;
    }
    fclose(fp);
    if(argv[2] == NULL)
    {
        return e_failure;
    }
    else
    {
        decInfo->stego_image_fname = argv[2];
        return e_success;
    }
    
}
//>>>>>>>>>>>>>>>>>to check all files are opened or not>>>>>>>>>>>>>>>>
Status open_decode_files(DecodeInfo *decInfo)
{
    // Stego Image file
    decInfo->fptr_stego_image = fopen(decInfo->stego_image_fname, "r");
     
     //Do Error handling
    if (decInfo->fptr_stego_image == NULL)
    {
        perror("fopen");

        fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->stego_image_fname);

        return e_failure;
    }
    else
    {
        printf("INFO:opened the stego image.bmp file\n");
    }
    return e_success;
}
//>>>>>>>>>>>>>>decode magic string>>>>>>>>>>>>>>>>>>>>

Status decode_magic_string(const char *magic_string, DecodeInfo *decInfo)
{
    int i, j, count = 0;

    char chara2, chara1;
//setting the offset to 54byte of the file
    fseek(decInfo->fptr_stego_image, 54, SEEK_CUR);


    //decoding the magic string
    for(i = 0; i < strlen(magic_string); i++)
    {
        for(j = 0; j < (sizeof(char)*8) ; j++)
        {
            fread(&chara1, sizeof(char), 1, decInfo->fptr_stego_image);
            chara2 = ((chara1 & 1) << j) | (~(1 << j) & chara2);
        }
//	    printf("%c\n",chara2);
        if(chara2 == magic_string[i])
        {
            count++;
        }
    }
  //  printf(" fp is %d\n",ftell(decInfo->fptr_stego_image));

    //comparing the magic string
    if(count == 2)
    {
        return e_success;
    }
    else
    {
        return e_failure;
    }

}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Status decode_extn_size(DecodeInfo *decInfo)
{
    int i,j;
    char chara2,chara1;

    for(i=0;i<1;i++)
    {
	for(j=0;j<sizeof(char)*8;j++)
	{
	    fread(&chara1,sizeof(char),1,decInfo->fptr_stego_image);
	    chara2=((chara1  & 1) << j) | (~(1<<j) & chara2);
	}
    decInfo->e_size=chara2;
    //printf("%d",decInfo->e_size);
   // printf("%d",decInfo->e_size);
    }
   // printf(" fp is %d\n",ftell(decInfo->fptr_stego_image));
    return e_success;

}
//>>>>>>>>>>>>>>>>>>>>decoding of file extension>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Status decode_output_file_extn(char *argv[],DecodeInfo *decInfo)
{
    int i,j,count = 0;
    char chara2,chara1;
 //   decode_extn_size(decInfo)
    
    int size = decInfo->e_size;
   // printf("\n%d\n",size);
   // printf("\n%d\n",size);

    //decoding the file extension
    for(i = 0; i<size; i++)
    {
        for(j = 0; j < (sizeof(char)*8) ; j++)
        {
            fread(&chara1, sizeof(char), 1, decInfo->fptr_stego_image);
            chara2 = ((chara1 & 1) << j) | (~(1 << j) & chara2);
        }
        decInfo->secret_data[i]=chara2;
    }
  
    //checking the file or to creat
    if(argv[3] == NULL)
    {
        printf("default file name is  taken \n");

        char chara[10] = "decode";

        decInfo->secret_fname = strcat(chara,decInfo->secret_data);
    }
    else
    {
        printf("output file taken\n");

        decInfo->secret_fname = argv[3];

        decInfo->secret_fname = strcat(decInfo->secret_fname,decInfo->secret_data);

    }
    // Secret file
    decInfo->fptr_secret = fopen(decInfo->secret_fname, "w");
    
    //Do Error handling
    if (decInfo->fptr_secret == NULL)
    {
        perror("fopen");

        fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->secret_fname);

        return e_failure;
    }
    else
    {
        printf("INFO:opened the %s \n",decInfo -> secret_fname);
    }
   // printf("\n%s\n",decInfo->secret_fname);
   // printf(" fp is %d\n",ftell(decInfo->fptr_stego_image));
    return e_success;

    
}

//>>>>>>>>>>>>>>>>>>>>>>>>decoding of file size>>>>>>>>>>>>>>>>>>>>>>>>>>>
Status decode_file_size(DecodeInfo *decInfo)
{
    int i,j;
    char chara2,chara1;

 //decoding the file size
    for(i = 0; i < 1; i++)
    {
        for(j = 0; j < (sizeof(char) * 8) ; j++)
        {
            fread(&chara1, sizeof(char), 1, decInfo->fptr_stego_image);
            chara2 = ((chara1 & 1) << j) | (~(1 << j) & chara2);
        }
    }
    //printf("\n%d\n",chara2);
    //printf(" fp is %d\n",ftell(decInfo->fptr_stego_image));
    return e_success;
}


//>>>>>>>>>>>>>>>>>>>>>>>decode data of file>>>>>>>>>>>>>>>>>>>>>>>>>>.
Status decode_file_data(FILE *secret_file,FILE *file_dest)
{
    int j;

    char chara1, chara2;

    //coping the data into the destination file
    while(chara2 !=  EOF)
    {
        for(j = 0; j < (sizeof(char) * 8) ; j++)
        {
            fread(&chara1, sizeof(char), 1, secret_file);

            chara2 = ((chara1 & 1) << j) | (~(1 << j) & chara2);
        }
           if(chara2 != EOF)
           {
           fwrite(&chara2, sizeof(char), 1, file_dest);
           }
    }
    //printf(" fp is %d\n",ftell(decInfo->fptr_stego_image));
return e_success;
}



#ifndef DECODE_H
#define DECODE_H

#include"types.h"


#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4

typedef struct _DecodeInfo
{
    char *stego_image_fname;
    FILE * fptr_stego_image;
    char *secret_fname;
    FILE * fptr_secret;
    char secret_data[5];
    int e_size;
}DecodeInfo;


/*performing the decodig*/
Status do_decoding(char *argv[],DecodeInfo *decInfo);

/*get file pointers for i/p ad o/p files*/
Status open_decode_files(DecodeInfo *decInfo);
Status read_and_validate_decode_args(char *argv[],DecodeInfo *decInfo);
/*decoding magic string*/
Status decode_magic_string(const char *magic_string,DecodeInfo *decInfo);
Status decode_extn_size(DecodeInfo *decInfo);

/*decoding output file extension*/
Status decode_output_file_extn(char *argv[],DecodeInfo *decInfo);

/*decode file size*/
Status decode_file_size(DecodeInfo *decInfo);
Status decode_file_data(FILE *secret_file,FILE *file_dest);
#endif


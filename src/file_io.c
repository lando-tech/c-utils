#include <stdio.h>
#include <stdlib.h>
#include "file_io.h"

/*
 * Reads a file and prints its contents
 */

void read_file(char* fpath) 
{
    FILE* fptr = fopen(fpath, "r");
    if (fptr == NULL) 
    {
        perror("fopen");
        return;
    }
    char buff[1024];
    
    while (fgets(buff, sizeof(buff), fptr) != NULL)
    {
        printf("%s", buff);
    }
    fclose(fptr);
}

/*
 * Reads a file specified by fpath and returns
 * a dynamically allocated char* to the caller.
 * The caller must free the char*.
 */
char* get_filestr(char* fpath)
{
    // Open the file and check for error
    FILE* fptr = fopen(fpath, "r");
    if (!fptr)
    {
        perror("fopen");
        return NULL;
    }

    // Get the size of the file
    fseek(fptr, 0, SEEK_END);
    long file_size = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    // Allocate room for the file dynamically
    char* buff = (char *)malloc(sizeof(char) * (file_size + 1));
    if (buff == NULL)
    {
        perror("malloc");
        return NULL;
    }

    fread(buff, 1, file_size, fptr);
    buff[file_size] = '\0';
    fclose(fptr);
    return buff;
}
#include <stdio.h>
#include <stdlib.h>
#include "file_io.h"

/*
 * Reads a file and prints its contents
 */

 // TODO dynamically resize buffer to handle large files
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

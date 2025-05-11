#include <stdio.h>
#include <stdlib.h>
#include "file_io.h"

void read_file(char* fpath) 
{
    FILE* fptr = fopen(fpath, "r");
    if (fptr == NULL) 
    {
        perror("Failed to open file!\n");
        return;
    }
    char buff[1024];
    
    while (fgets(buff, sizeof(buff), fptr) != NULL)
    {
        printf("%s", buff);
    }
    fclose(fptr);
}

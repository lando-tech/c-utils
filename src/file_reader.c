#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include "../include/file_reader.h"

/* Reads a file and prints each line to stdout.
 * Will return status 1 if unable to open file.
 */
int read_file(char *fpath)
{
    // Create a pointer to the open file
    FILE *fptr = fopen(fpath, "r");
    if ( fptr == NULL )
    {
        perror("Unable to open file\n");
        return 1;
    }

    char buffer[1024];
    int i = 0;
    printf("\n");
    while ( fgets(buffer, sizeof(buffer), fptr) != NULL )
    {
        // size_t buf_size = sizeof(buffer);
        // int buf_len = strlen(buffer);
        // printf("Size of buffer %zu\n", buf_size);
        // printf("Length of Buffer: %d\n", buf_len);
        printf("%s\n", buffer);
        if ( i >= 2 )
        {
            break;
        }
        ++i;
    }
    fclose(fptr);
    return 0;
}

void evaluate_line(char* line)
{
    for ( int i = 0; i < strlen(line); ++i )
    {
        printf("%c", line[i]);
    }
}

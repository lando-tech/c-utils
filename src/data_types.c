#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>
#include "data_types.h"

/* Prints the primitive data type limits in C.
 * Each data type has a specific range. Note that each data
 * type can be either signed (- or +) or unsigned.
 */
void print_limits()
{
    printf("\n C data type limits:\n\n");
    printf("\tMax size of a char bit data type:  %20d\n", CHAR_BIT);
    printf("\tMin size of a char:                %20d\n", CHAR_MIN);
    printf("\tMax size of a char:                %20d\n", CHAR_MAX);
    printf("\tMin size of a short int:           %20d\n", SHRT_MIN);
    printf("\tMax size of a short int:           %20d\n", SHRT_MAX);
    printf("\tMax size of an unsigned short int: %20i\n", USHRT_MAX);
    printf("\tMin size of an int:                %20d\n", INT_MIN);
    printf("\tMax size of an int:                %20d\n", INT_MAX);
    printf("\tMax size of an unisigned int:      %20u\n", UINT_MAX);
    printf("\tMin size of a long int:            %20ld\n", LONG_MIN);
    printf("\tMax size of a long int:            %20ld\n", LONG_MAX);
    printf("\tMax size of an unsigned long int:  %20lu\n\n", ULONG_MAX);
    //printf("\tMin size of a long long int:       %20lld\n", LLONG_MIN);
    //printf("\tMax size of a long long int:       %20lld\n\n", LLONG_MAX);
}

/*
 * Prints the format specifiers for each data type
 * It is useful as a lookup table
 */

void print_format_specifiers()
{
    printf("\n Format Specifiers:\n\n");
    printf("\tCharacter:             %%c\n");
    printf("\tInt:                   %%d\n");
    printf("\tUnsigned Int:          %%u\n");
    printf("\tScientific Notations:  %%e or %%E\n");
    printf("\tFloat:                 %%f\n");
    printf("\tSigned int:            %%i\n");
    printf("\tLong int:              %%ld or %%li\n");
    printf("\tLong double:           %%lf\n");
    printf("\tUnsigned int/long:     %%lu\n");
    printf("\tLong long int:         %%lli or %%lld\n");
    printf("\tUnsigned long long:    %%llu\n");
    printf("\tOctal:                 %%o\n");
    printf("\tPointer:               %%p\n");
    printf("\tString literal:        %%s\n");
    printf("\tHexadecimal:           %%x or %%X\n\n");
}

/*
 * Prints the alphabet, optionally in ASCII format as a 
 * reference guide.
 */
void print_alphabet(bool ascii)
{
    char alpha[26];
    alpha[0] = 'A';

    if ( ascii )
    {
        for ( int i = 1; i < 26; ++i )
        {
            alpha[i] = alpha[0]+ i;
        }
        for ( int i = 0; i < 26; ++i )
        {
            printf("%d ", alpha[i]);
        }
        printf("\n");
    }
    else
    {
        for ( int i = 1; i < 26; ++i )
        {
            alpha[i] = alpha[0]+ i;
        }
        for ( int i = 0; i < 26; ++i )
        {
            printf("%c ", alpha[i]);
        }
        printf("\n");
    }
}


/*
 * This function prints the ASCII table in a readable format as
 * a quick reference guide.
 */
void print_ascii_table()
{
    char ascii_table[95];
    ascii_table[0] = 32;
    printf("\n ASCII Table:");
    for ( int i = 1; i < 95; ++i )
    {
        ascii_table[i] = ascii_table[0] + i;
    }
    for ( int j = 0; j < 95; ++j )
    {
        if ( j % 8 == 0 )
        {
            printf("\t");
            printf("\n\n");
            for ( int us = 0; us < 136; ++us )
            {
                printf("_");
            }
            printf("\n\n\n");
            // printf("\t");
        }
        printf("  '%c' -- '%3d'  |", ascii_table[j], ascii_table[j]);
    }
    printf("\n\n\n");
    for ( int i = 0; i < 136; ++i )
    {
        printf("_");
    }
    printf("\n\n");
}

/*
 * Prints the escape characters as a quick reference guide.
 */
void print_escape_chars()
{
    printf(" Escape Characters:\n\n");
    printf("\tNewline:         \\n\n");
    printf("\tTab:             \\t\n");
    printf("\tBackspace:       \\b\n");
    printf("\tCarriage Return: \\r\n");
    printf("\tNull Character:  \\0\n\n");
}


void print_spacer(int size)
{
    for ( int i = 0; i < size; ++i )
    {
        printf("-");
    }
}

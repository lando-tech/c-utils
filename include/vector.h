#ifndef VECTOR_H
#define VECTOR_H

typedef enum
{
    STRING,
    INT,
    DOUBLE,
    LONG_INT,
    LONG_DOUBLE,
    U_INT,
    U_LONG_INT

} DataTypes;

typedef struct
{
    void **data;
    size_t size;
    size_t capacity;
} Vector;

Vector* vector(DataTypes dtype);

#endif // VECTOR_H

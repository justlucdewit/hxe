#ifndef HXE_FILEREADER_GUARD
#define HXE_FILEREADER_GUARD

#include <stdlib.h>
#include <stdio.h>

// buffer_length   = length of the string thats currently in buffer
// buffer_capacity = total capacity of the buffer
// buffer          = pointer to the buffer 
typedef struct
{
    size_t buffer_length;
    size_t buffer_capacity;
    char* buffer;
} file_content;

// Takes a fileName as a string
// Retruns a file_content struct
file_content readFile(char* fileName);

#endif
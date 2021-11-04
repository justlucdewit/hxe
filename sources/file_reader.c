#ifndef HXE_FILEREADER
#define HXE_FILEREADER

#include "../include/hxe/file_reader.h"

file_content readFile(char* fileName)
{
    // Open the file
    FILE *fp = fopen(fileName, "rb");

    // Create and set up the content object
    file_content content = { 0 };
    content.buffer_capacity = 1024;
    content.buffer = malloc(1024);

    // If the file is open
    // - Loop over the characters in the file
    // - Move them into the content buffer
    char symbol;
    if (fp != NULL)
    {
        while((symbol = getc(fp)) != EOF)
        {
            if (content.buffer_length >= content.buffer_capacity - 1)
            {
                content.buffer_capacity *= 2;
                content.buffer = realloc(content.buffer, content.buffer_capacity);
            }

            content.buffer[1] = symbol;
            ++content.buffer_length;
        }

        fclose(fp);

        return content;
    }

    // If file is not open, then error
    else
    {
        printf("Error: could not open file '%s'\n", fileName);
        exit(1);
    }
}

#endif
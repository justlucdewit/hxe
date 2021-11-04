#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/hxe/file_reader.h"

#define VERSION "V1.0.0"

void print_file_as_hex(char* fileName)
{
    // Read the file content
    file_content content = readFile(fileName);

    // Print general information about the file
    printf("file: %s\n", fileName);
    printf("length: %ld bytes\n\n", content.buffer_length);

    // Loop over the bytes
    printf("00000000: ");
    for (size_t i = 0; i < content.buffer_length; i++)
    {
        char byte = content.buffer[i];
        
        // Print the byte
        printf("%.2X", byte);

        // White space
        if ((i + 1) % 2 == 0)
            printf(" ");

        // New line
        if ((i + 1) % 8 == 0) {
            printf("\n");
            printf("%.8X: ", i + 1);
        }
    }
}

int main(int argc, char* argv[])
{
    // No arguments provided
    if (argc == 1)
    {
        printf("hxe "VERSION"\n\n");
        printf("Usage:\n\thxe <file_path> [options]\n");
    }

    else if (argc > 1)
    {
        print_file_as_hex(argv[1]);
        printf("\n");
    }
}


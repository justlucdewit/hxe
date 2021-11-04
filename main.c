#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "V1.0.0"

typedef struct
{
    size_t buffer_length;
    size_t buffer_capacity;
    char* buffer;
} file_content;

file_content readFile(char* fileName)
{
    FILE *fp = fopen(fileName, "rb");
    file_content content = { 0 };
    content.buffer_capacity = 1024;
    content.buffer = malloc(1024);
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

    else
    {
        printf("Error: could not open file '%s'\n", fileName);
        exit(1);
    }
}

void print_file_as_hex(char* fileName)
{
    // Read the file content
    file_content content = readFile(fileName);

    // Print general information about the file
    printf("file: %s\n", fileName);
    printf("length: %d bytes\n\n", content.buffer_length);
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
    }
}


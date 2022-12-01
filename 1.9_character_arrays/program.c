#include <stdio.h>

// Set static buffer size
#define CHAR_BUFFER_SIZE 1000

int test;
int getLine(char[]);
void copyLine(char[], char[]);

int main()
{
    example();

    int lineLength = 0;
    int maxLineLength = 0;
    char charBuffer[CHAR_BUFFER_SIZE];
    char maxLine[CHAR_BUFFER_SIZE] = {'\n', '\0'};

    while ((lineLength = getLine(charBuffer)) != EOF)
    {

        if (lineLength > maxLineLength)
        {
            maxLineLength = lineLength;
            copyLine(charBuffer, maxLine);
        }
    }

    printf("%s", maxLine);
    // for (int i = 0; maxLineLength > 0; i++)
    // {
    //     putchar(maxLine[i]);
    //     if (maxLine[i] == '\n')
    //         return i;
    // }

    return maxLineLength;
}

int getLine(char buffer[])
{
    int c = 0;
    int lineLength = 0;
    int test;
    test = 1;

    for (int i = 0; i < CHAR_BUFFER_SIZE - 1; i++)
    {
        c = getchar();

        if (c == EOF)
            return EOF;

        lineLength++;
        buffer[i] = c;

        if (c == '\n')
        {
            buffer[i + 1] = '\0';
            break;
        }
    }

    return lineLength;
}

void copyLine(char source[], char destination[])
{
    int test;
    test = 1;

    for (int i = 0; i < CHAR_BUFFER_SIZE; i++)
    {
        destination[i] = source[i];
        if (source[i] == '\0')
            return;
    }
}

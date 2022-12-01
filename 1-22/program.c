#include <stdio.h>

#define BUFFER_SIZE 1000
#define MAX_LINE_LENGTH 100

void getSplitInput(char[], int, int);

int main()
{
    char buffer[BUFFER_SIZE] = {'\0'};

    getSplitInput(buffer, MAX_LINE_LENGTH, BUFFER_SIZE);

    printf("%s", buffer);
}

void getSplitInput(char buffer[], int lineLength, int bufferSize)
{
    char c;
    int i = 0;
    int charCount = 0;
    int iLastSpace = 0;
    int isWhiteSpace = 0;

    for (i = 0; i < bufferSize - 1 && (c = getchar()) != EOF; i++)
    {
        charCount++;
        buffer[i] = c;
        isWhiteSpace = c == ' ' || c == '\t' || c == '\n';

        if (isWhiteSpace)
            iLastSpace = i;

        if (charCount % lineLength == 0)
        {
            buffer[iLastSpace] = '\n';
            charCount = charCount - iLastSpace - 1;
        }
    }

    buffer[i] = '\0';
}

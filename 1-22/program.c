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

    // if a line is more than n characters split it
    // count characters after '\n' or from beginning
    // store last space
    // replace last space with '\n'
    for (i = 0; i < bufferSize && (c = getchar()) != EOF; i++)
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

void nextLine1(char buffer[], char tail[], int lineLength, int bufferSize)
{
    char c;
    int i = 0;

    // Copy carryOver  to buffer
    while (tail[i] != '\0')
    {
        buffer[i] = tail[i];
        i++;
    }

    // Reset tail
    tail[0] = '\0';

    // Fill buffer with lineLength
    for (; i < lineLength && i < bufferSize; i++)
    {
        c = getchar();

        if (c == EOF)
            break;

        buffer[i] = c;
    }

    //
    for (int i = lineLength; i < bufferSize - lineLength; i++)
    {
    }
}

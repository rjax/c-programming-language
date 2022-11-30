#include <stdio.h>

#define MAX_WORD_LENGTH 60 // Longest word in
#define MIN_CHAR ' '
#define MAX_CHAR '~'

void count_stats()
{

    int digitCounts[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int wordCount = 0, charCount = 0, nonWhiteSpaceCount = 0, lineCount = 0, whiteSpaceCount = 0;
    int c, isWhiteSpace = 0, prevIsWhiteSpace = 1, isEndOfLine = 0, isDigit = 0;

    while ((c = getchar()) != EOF)
    {
        isEndOfLine = c == '\n';
        isDigit = c >= '0' && c <= '9';
        isWhiteSpace = c == ' ' || c == '\t' || isEndOfLine;

        ++charCount;

        if (isWhiteSpace)
        {
            ++whiteSpaceCount;

            if (isEndOfLine)
                ++lineCount;
        }
        else
        {
            ++nonWhiteSpaceCount;

            if (prevIsWhiteSpace)
                ++wordCount;

            if (isDigit)
                ++(digitCounts[c - '0']);
        }

        prevIsWhiteSpace = isWhiteSpace;
    }
    printf("Line count: %d\n", lineCount);
    printf("Word count: %d\n", wordCount);
    printf("Character count: %d\n", charCount);
    printf("Whitespace count %d\n", whiteSpaceCount);
    printf("Non-white space count: %d\n", nonWhiteSpaceCount);
    printf("Digit counts:\n\t");
    for (int i = 0; i <= '9' - '0'; i++)
    {
        // if (digitCounts[i] > 0)
        printf("[%c, %d]%s", i + '0', digitCounts[i], (i == 9 ? "" : ", "));
    }
    printf("\b\b\n");
}

void word_length_histogram()
{
    int c;
    int lengths[MAX_WORD_LENGTH];
    int minLength = MAX_WORD_LENGTH;
    int maxLength = 0;
    int maxCount = 0;

    // Start of file is considered whitespace
    int isPrevWhitespace = 1;
    int isWhitespace = 0;
    int wordLength = 0;

    // Init lengths
    for (int i = 0; i < MAX_WORD_LENGTH; i++)
    {
        lengths[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        // printf("%c", c);

        isWhitespace = c == ' ' || c == '\t' || c == '\n';

        if (!isWhitespace)
        {
            ++wordLength;
        }
        else if (!isPrevWhitespace)
        {
            // Position in lengths == wordLength
            if (wordLength < minLength)
                minLength = wordLength;

            if (wordLength > maxLength)
                maxLength = wordLength;

            ++(lengths[wordLength]);

            if (lengths[wordLength] > maxCount)
                maxCount = lengths[wordLength];

            wordLength = 0;
        }
        isPrevWhitespace = isWhitespace;
    }

    // // Horizontal histogram
    // for (int i = minLength; i <= maxLength; i++)
    // {
    //     printf("\n%d\t", i);
    //     for (int n = 1; n <= lengths[i]; n++)
    //         printf("%c", '#');
    // }

    // Vertical histogram
    printf("\n");
    for (int i = maxCount; i > 0; i--)
    {
        // y axis
        printf("\n%-4d | ", i);

        // y values
        for (int j = minLength; j <= maxLength; j++)
        {
            printf("%s", (lengths[j] >= i ? "##### " : "      "));
        }
    }

    // x axis
    printf("\n-----|");
    for (int j = minLength; j <= maxLength; j++)
    {
        printf("------");
    }

    // x values
    printf("\n     | ");
    for (int j = minLength; j <= maxLength; j++)
    {
        printf("%5d ", j);
    }

    printf("\n\n");
}

void character_frequency_histogram()
{
    int c;
    int frequencies[MAX_CHAR + 1];
    int maxFrequency = 0;
    int isWhitespace = 0;

    // Init lengths
    for (int i = MIN_CHAR; i <= MAX_CHAR; i++)
    {
        frequencies[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        // printf("%c", c);

        isWhitespace = c == ' ' || c == '\t' || c == '\n';

        if (!isWhitespace)
        {
            ++frequencies[c];
            if (frequencies[c] > maxFrequency)
                maxFrequency = frequencies[c];
        }
    }

    // // Horizontal histogram
    // for (int i = minLength; i <= maxLength; i++)
    // {
    //     printf("\n%d\t", i);
    //     for (int n = 1; n <= lengths[i]; n++)
    //         printf("%c", '#');
    // }

    // Vertical histogram
    printf("\n");
    for (int i = maxFrequency; i > 0; i--)
    {
        // y axis
        printf("\n%-4d | ", i);

        // y values
        for (int j = MIN_CHAR; j <= MAX_CHAR; j++)
        {
            printf("%s", (frequencies[j] >= i ? "##### " : "      "));
        }
    }

    // x axis
    printf("\n-----|");
    for (int j = MIN_CHAR; j <= MAX_CHAR; j++)
    {
        printf("------");
    }

    // x values
    printf("\n     | ");
    for (int j = MIN_CHAR; j <= MAX_CHAR; j++)
    {
        printf("%3c   ", j);
    }

    printf("\n\n");
}

int main()
{
    // word_length_histogram();
    character_frequency_histogram();
    return 0;
}

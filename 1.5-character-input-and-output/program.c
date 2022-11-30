#include <stdio.h>

void copy_stdin_to_stdout()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
}

void print_eof()
{
    printf("%d\n", EOF);
}

void count_white_space()
{
    int c;
    int whiteSpaceCount = 0;
    while ((c = getchar()) != EOF)
    {
        whiteSpaceCount += c == ' ' || c == '\t' || c == '\n';
    }
    printf("White space count: %d", whiteSpaceCount);
}

void count_lines()
{
    int c;
    int lineCount = 0;
    while ((c = getchar()) != EOF)
    {
        lineCount += c == '\n';
    }
    printf("Line count: %d\n", lineCount);
}

void count_stats()
{

    int wordCount = 0, charCount = 0, lineCount = 0;
    int c, isWhiteSpace = 0, prevIsWhiteSpace = 1, isEndOfLine = 0;

    while ((c = getchar()) != EOF)
    {
        isEndOfLine = c == '\n';
        isWhiteSpace = c == ' ' || c == '\t' || isEndOfLine;

        ++charCount;

        if (isEndOfLine)
            ++lineCount;

        else if (prevIsWhiteSpace && !isWhiteSpace)
            ++wordCount;

        prevIsWhiteSpace = isWhiteSpace;
    }
    printf("Line count: %d\n", lineCount);
    printf("Word count: %d\n", wordCount);
    printf("Character count: %d\n", charCount);
}

void count_stats_ex()
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
}

void list_words()
{

    int wordCount = 0, charCount = 0, lineCount = 0;
    int c, isWhiteSpace = 0, prevIsWhiteSpace = 1, isEndOfLine = 0;

    while ((c = getchar()) != EOF)
    {
        isEndOfLine = c == '\n';
        isWhiteSpace = c == ' ' || c == '\t' || isEndOfLine;

        if (!isWhiteSpace)
            putchar(c);

        if (isWhiteSpace && !prevIsWhiteSpace)
            putchar('\n');

        prevIsWhiteSpace = isWhiteSpace;
    }
}

int main()
{
    // copy_stdin_to_stdout();
    // count_white_space();
    // count_stats();
    list_words();
    // print_eof();
    // count_lines();
}

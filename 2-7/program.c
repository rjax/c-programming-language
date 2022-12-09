// Write a function invert(x,p,n) that returns x with the n bits that begin at
// position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
// define position p starts from 0

#include <stdio.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

void printBitmap(int, int);
unsigned invert(unsigned, int, int);
char *color(const char *, const char *);

char stringBuffer[256];

int main()
{
    int tst = 1073741824;
    printBitmap(tst, 1);
    tst = 1360072977;
    printBitmap(tst, 1);

    unsigned arg = 1360072977;
    unsigned expected;
    unsigned actual;

    expected = 1360073185;
    actual = invert(arg, 4, 4);
    printf("%s\n", actual == expected ? color("OK", GREEN) : color("FAIL", RED));

    expected = 1360073198;
    actual = invert(arg, 0, 8);
    printf("%s\n", actual == expected ? color("OK", GREEN) : color("FAIL", RED));

    expected = 2920354065;
    actual = invert(arg, 24, 8);
    printf("%s\n", actual == expected ? color("OK", GREEN) : color("FAIL", RED));
}

void printBitmap(int arg, int addLineFeed)
{
    int bit;
    unsigned long bitmap = arg;
    unsigned long shiftCount = sizeof(arg) * 8 - 1;

    for (int i = shiftCount; i >= 0; i--)
    {
        if (i < shiftCount && i % 4 == 3)
            printf(" ");
        bit = (bitmap >> i) & 0x1;
        printf("%d", bit);
    }

    if (addLineFeed)
        printf("\n");
}

unsigned invert(unsigned x, int p, int n)
{
    printf("x: %d, p: %d, n %d\n", x, p, n);

    unsigned bitmap = x;
    printBitmap(bitmap, 1);

    // Wipe right
    unsigned long left = bitmap >> p + n;
    left = left << p + n;
    printBitmap(left, 1);

    // Wipe left
    unsigned long right = bitmap << 31 - p + 1;
    right = right >> 31 - p + 1;
    printBitmap(right, 1);

    unsigned center = ~bitmap >> p;
    center = center << p;
    center = center << 31 - (p + n - 1);
    center = center >> 31 - (p + n - 1);
    printBitmap(center, 1);

    printf("\n");
    printBitmap(bitmap, 1);
    printBitmap(left | center | right, 1);

    return left | center | right;
}

char *color(const char *msg, const char *color)
{
    extern char stringBuffer[256];
    int i = 0;

    for (; color[i] != '\0'; i++)
        stringBuffer[i] = color[i];

    for (int j = 0; msg[j] != '\0'; j++)
        stringBuffer[i++] = msg[j];

    for (int k = 0; WHITE[k] != '\0'; k++)
        stringBuffer[i++] = WHITE[k];

    stringBuffer[i] = '\0';
    return stringBuffer;
}

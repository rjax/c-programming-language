#include <stdio.h>

int setbits(unsigned x, int p, int n, unsigned y);
int setbits1(int x, int p, int n, int y);
int getRight(unsigned arg, unsigned count);
int getLeft(unsigned arg, unsigned count);

int main()
{
    unsigned arg1, arg2, expected, actual;

    arg1 = __UINT32_MAX__;
    arg2 = 0;
    expected = 0;
    // getRight(arg1, 20);
    // getLeft(arg1, 20);
    // printf("\n");
    actual = setbits(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");

    arg1 = 0;
    arg2 = __UINT32_MAX__;
    expected = __UINT32_MAX__;
    actual = setbits(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");

    arg1 = 2222;
    arg2 = __UINT32_MAX__;
    expected = __UINT32_MAX__;
    actual = setbits(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");

    arg1 = 2222;
    arg2 = 0;
    expected = 0;
    actual = setbits(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");

    arg1 = 0;
    arg2 = 2222;
    expected = 2222;
    actual = setbits(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");

    arg1 = 2222;
    arg2 = 255;
    expected = 63662;
    actual = setbits(arg1, 13, 4, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");
}

void printBitmap(unsigned bitmap, int addLineFeed)
{
    int bit;
    int shiftCount = sizeof(bitmap) * 8 - 1;
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

int setbits(unsigned x, int p, int n, unsigned y)
{
    printf("x: %u, p: %d, n: %d, y: %u\n", x, p, n, y);
    printBitmap(x, 1);
    printBitmap(y, 1);
    printf("\n");

    unsigned long right = (x << 32 - p + 1);
    right = right >> (32 - p + 1);
    printBitmap(right, 1);

    unsigned long left = y << 32 - n;
    left = left >> 32 - n + 1 - p;
    printBitmap(left, 1);
    unsigned long result = right |= left;
    printBitmap(result, 1);

    return result;
}

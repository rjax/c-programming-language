#include <stdio.h>

int setbits(unsigned x, int p, int n, unsigned y);
int setbits2(int x, int p, int n, int y);
int getRight(unsigned arg, unsigned count);
int getLeft(unsigned arg, unsigned count);

int main()
{
    unsigned arg1, arg2, expected, actual;

    arg1 = __INT32_MAX__;
    arg2 = 0;
    expected = 0;
    actual = setbits(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");
    actual = setbits2(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");

    arg1 = 0;
    arg2 = __INT32_MAX__;
    expected = __INT32_MAX__;
    actual = setbits(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");
    actual = setbits2(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");

    arg1 = 2222;
    arg2 = __INT32_MAX__;
    expected = __INT32_MAX__;
    actual = setbits(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");
    actual = setbits2(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");

    arg1 = 2222;
    arg2 = 0;
    expected = 0;
    actual = setbits(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");
    actual = setbits2(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");

    arg1 = 0;
    arg2 = 2222;
    expected = 2222;
    actual = setbits(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");
    actual = setbits2(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");

    arg1 = 2222;
    arg2 = 255;
    expected = 63662;
    actual = setbits(arg1, 13, 4, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");
    actual = setbits2(arg1, 13, 4, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");
}

int main1()
{
    unsigned arg1, arg2, expected, actual;

    arg1 = __UINT32_MAX__;
    arg2 = 0;
    expected = 0;
    actual = setbits(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");
    actual = setbits2(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");

    arg1 = 0;
    arg2 = __UINT32_MAX__;
    expected = __UINT32_MAX__;
    actual = setbits(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");
    actual = setbits2(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");

    arg1 = 2222;
    arg2 = __UINT32_MAX__;
    expected = __UINT32_MAX__;
    actual = setbits(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");
    actual = setbits2(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");

    arg1 = 2222;
    arg2 = 0;
    expected = 0;
    actual = setbits(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");
    actual = setbits2(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");

    arg1 = 0;
    arg2 = 2222;
    expected = 2222;
    actual = setbits(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");
    actual = setbits2(arg1, 1, 32, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");

    arg1 = 2222;
    arg2 = 255;
    expected = 63662;
    actual = setbits(arg1, 13, 4, arg2);
    printf("%s\n", actual == expected ? "OK" : "Fail");
    actual = setbits2(arg1, 13, 4, arg2);
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

// Shift right causes problems with the msb.
// The msb is set to it's original value when >> is performed
// To avoid this, the function uses an unsigned long but only 
// uses the lower 32 bits 
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

// This function works without right shift and 
// the associated problem, but at the expense of 
// setting each bit in 2 for loops.
int setbits2(int x, int p, int n, int y)
{
    printf("x: %d, p: %d, n: %d, y: %d\n", x, p, n, y);
    printBitmap(x, 1);
    printBitmap(y, 1);
    printf("\n");

    int i = 0;
    int num = p > 1 ? 1 : 0;
    int rightMask = p > 1 ? 1 : 0;
    for (i = 1; i < p; i++)
    {
        rightMask += num *= 2;
    }

    int right = x & rightMask;
    printBitmap(right, 1);

    num = n > 0 ? 1 : 0;
    int leftMask = n > 0 ? 1 : 0;
    for (i = 1; i < n; i++)
    {
        leftMask += num *= 2;
    }

    printBitmap(leftMask, 1);
    int left = y & leftMask;
    printBitmap(left, 1);
    left <<= p - 1;
    printBitmap(left, 1);

    int result = right | left;
    printBitmap(result, 1);

    return result;
}

#include <stdio.h>

int getBitsInt();
int getBitsLong();
int getBitsChar();
int getBitsShort();

int main()
{
    int bitCount = getBitsChar();
    printf("char is %d bits or %d bytes\n", bitCount, bitCount / 8);

    bitCount = getBitsShort();
    printf("short is %d bits or %d bytes\n", bitCount, bitCount / 8);

    bitCount = getBitsInt();
    printf("int is %d bits or %d bytes\n", bitCount, bitCount / 8);

    bitCount = getBitsLong();
    printf("long is %d bits or %d bytes\n", bitCount, bitCount / 8);
}

int getBitsShort()
{
    int i = 8;
    short arg = 128; // 2^7

    while (arg > 0 && (i += 8) < 128)
    {
        arg <<= 8;
    }
    return i;
}

int getBitsInt()
{
    int i = 8;
    int arg = 128; // 2^7

    while (arg > 0 && (i += 8) < 128)
    {
        arg <<= 8;
    }
    return i;
}

int getBitsLong()
{
    int i = 8;
    long arg = 128; // 2^7

    while (arg > 0 && (i += 8) < 128)
    {
        arg <<= 8;
    }
    return i;
}

int getBitsChar()
{
    int i = 8;
    char arg = 128; // 2^7

    while (arg > 0 && (i += 8) < 128)
    {
        arg <<= 8;
    }
    return i;
}
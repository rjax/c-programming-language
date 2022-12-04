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
    int i = 1;
    short arg = 1;

    while (arg > 0 && i++ < 128)
    {
        arg <<= 1;
    }
    return i;
}

int getBitsInt()
{
    int i = 1;
    int arg = 1;

    while (arg > 0 && i++ < 128)
    {
        arg <<= 1;
    }
    return i;
}

int getBitsLong()
{
    int i = 1;
    long arg = 1;

    while (arg > 0 && i++ < 128)
    {
        arg <<= 1;
    }
    return i;
}

int getBitsChar()
{
    int i = 1;
    char arg = 1;

    while (arg > 0 && i++ < 128)
    {
        arg <<= 1;
    }

    return i;
}
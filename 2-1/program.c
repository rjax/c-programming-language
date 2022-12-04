#include <stdio.h>

int getBitsInt();
int getBitsUInt();

int getBitsLong();
int getBitsULong();

int getBitsChar();
int getBitsUChar();

int getBitsShort();
int getBitsUShort();

int main()
{
    int bitCount = getBitsChar();
    printf("char is %d bits or %d bytes\n", bitCount, bitCount / 8);

    bitCount = getBitsUChar();
    printf("unsigned char is %d bits or %d bytes\n", bitCount, bitCount / 8);

    bitCount = getBitsShort();
    printf("short is %d bits or %d bytes\n", bitCount, bitCount / 8);

    bitCount = getBitsUShort();
    printf("unsigned short is %d bits or %d bytes\n", bitCount, bitCount / 8);

    bitCount = getBitsInt();
    printf("int is %d bits or %d bytes\n", bitCount, bitCount / 8);

    bitCount = getBitsUInt();
    printf("unsigned int is %d bits or %d bytes\n", bitCount, bitCount / 8);

    bitCount = getBitsLong();
    printf("long is %d bits or %d bytes\n", bitCount, bitCount / 8);

    bitCount = getBitsULong();
    printf("unsigned long is %d bits or %d bytes\n", bitCount, bitCount / 8);
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
int getBitsUShort()
{
    int i = 1;
    unsigned short arg = 1;

    while (arg > 0 && i++ < 128)
    {
        arg <<= 1;
    }
    return i - 1;
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

int getBitsUInt()
{
    int i = 1;
    unsigned int arg = 1;

    while (arg > 0 && i++ < 128)
    {
        arg <<= 1;
    }
    return i - 1;
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

int getBitsULong()
{
    int i = 1;
    unsigned long arg = 1;

    while (arg > 0 && i++ < 128)
    {
        arg <<= 1;
    }
    return i - 1;
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

int getBitsUChar()
{
    int i = 1;
    unsigned char arg = 1;

    while (arg > 0 && i++ < 128)
    {
        arg <<= 1;
    }

    return i - 1;
}

#include <stdio.h>

int getBitsInt();
int getBitsUInt();

int getBitsLong();
int getBitsULong();

int getBitsChar();
int getBitsUChar();

int getBitsShort();
int getBitsUShort();

int getBitsFloat();

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

    printf("\n");
    getBitsFloat();
    printf("\n");
}

int getBitsShort()
{
    int i = 0;
    short arg = 1;

    while (arg > 0 && (i += 8) < 128)
    {
        arg <<= 8;
    }
    return i;
}

int getBitsUShort()
{
    int i = 0;
    short arg = 1;

    while (arg > 0 && (i += 8) < 128)
    {
        arg <<= 8;
    }
    return i;
}

int getBitsInt()
{
    int i = 0;
    int arg = 1;

    while (arg > 0 && (i += 8) < 128)
    {
        arg <<= 8;
    }
    return i;
}

int getBitsUInt()
{
    int i = 0;
    unsigned int arg = 1;

    while (arg > 0 && (i += 8) < 128)
    {
        arg <<= 8;
    }
    return i;
}

int getBitsLong()
{
    int i = 0;
    long arg = 1;

    while (arg > 0 && (i += 8) < 128)
    {
        arg <<= 8;
    }
    return i;
}

int getBitsULong()
{
    int i = 0;
    unsigned long arg = 1;

    while (arg > 0 && (i += 8) < 128)
    {
        arg <<= 8;
    }
    return i;
}

int getBitsChar()
{
    int i = 0;
    char arg = 1;

    while (arg > 0 && (i += 8) < 128)
    {
        arg <<= 8;
    }
    return i;
}

int getBitsUChar()
{
    int i = 0;
    unsigned char arg = 1;

    while (arg > 0 && (i += 8) < 128)
    {
        arg <<= 8;
    }
    return i;
}
void printBitmap(unsigned bitmap)
{

    printf("\ns7654321021098765432109876543210\n");
    for (int k = sizeof(bitmap) * 8 - 1; k > 0; k--)
    {
        printf("%d", (bitmap >> k) & 0x1);
    }
    printf("\n");
}
int getBitsFloat()
{
    union
    {
        float f;
        __uint32_t bitMap;
    } u;

    // for (int i = 1; i < 100; i++)
    // {
    u.f = 3.141590;
    printBitmap(u.bitMap);

    u.f = 10.0;
    printBitmap(u.bitMap);
    u.f = 11.0;
    printBitmap(u.bitMap);
    u.f = 12.0;
    printBitmap(u.bitMap);
    // printf("\n%-4d", i);
    // }
}
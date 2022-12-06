#include <stdio.h>

int getBitsInt();
int getBitsUInt();

int getBitsLong();
int getBitsULong();

int getBitsChar();
int getBitsUChar();

int getBitsShort();
int getBitsUShort();

// int getBitsFloat();

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

    // bitCount = getBitsFloat();
    // printf("float is %d bits or %d bytes\n", bitCount, bitCount / 8);
    // float a;
    // printf("%f\n", __FLT_MAX__);
    // printf("float is %ld bits or %ld bytes\n", sizeof(a) / 8, sizeof(a));
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

// int getBitsFloat()
// {
//     int i = 1;
//     float arg = 1;
//     unsigned int ui;
//     unsigned long ul;
//     unsigned short us;
//     unsigned long long ull;

//     for (; i < 128 && (ui + us + ul + ull) > 0; i++)
//     {
//         arg *= 2;
//         ui = arg;
//         ul = arg;
//         us = arg;
//         ull = arg;
//         printf("%d: %-50f\t%d\t%d\t%ld\t%lld\n", i, arg, us, ui, ul, ull);
//     }

//     // for (; arg > 0 && arg > arg/2 , i < 256; i++)
//     // {
//     //     arg *= 2;
//     //     printf("%d - %f\n", i, arg);
//     // }
//     return i;
// }
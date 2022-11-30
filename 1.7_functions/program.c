#include <stdio.h>

long power(int, int);

int main()
{

    for (int i = 0; i < 10; i++)
    {
        printf("2^%d = %5ld\t-3^%d = %6ld\n", i, power(2, i), i, power(-3, i));
    }
    printf("\n");
    return 0;
}

long power(int base, int n)
{
    long product = 1;
    for (int i = 1; i <= n; i++)
    {
        product *= base;
    }

    return product;
}
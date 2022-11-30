#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("Fahrenheit to Celsius\n");

    while (fahr <= upper)
    {
        celsius = 5.0 / 9.0 * (fahr - 32);
        printf("%4.0f %12.1lf\n", fahr, celsius);
        fahr = fahr + step;
    }

    step = 10;
    upper = 150;
    celsius = lower;

    printf("\nCelsius to Fahrenheit\n");

    while (celsius <= upper)
    {
        fahr = (celsius * 9.0 / 5.0) + 32;
        printf("%4.0f %12.1lf\n", celsius, fahr);
        celsius = celsius + step;
    }
}
#include <stdio.h>

int main(void)
{
    double result = 0.0;
    for (int i = 1; i <= 100; i++)
        result += i;
    for (int i = 1; i <= 50; i++)
        result += i * i;
    for (int i = 1; i <= 10; i++)
        result += 1.0 / i;
    printf("%f",result);
    return 0;
}
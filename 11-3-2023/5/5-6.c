#include <stdio.h>

int main()
{
    int n;
    long result = 0, f = 1; // result for sum of all, f for factorial
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            f *= i;
        }
        result += f;
        f = 1;
    }
    printf("%ld",result);
    return 0;
}
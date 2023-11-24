#include <stdio.h>

_Bool is_prime(int);

int main(void)
{
    int n;
    scanf("%d",&n);
    printf("%d is%s prime.\n",n,(is_prime(n))? "":" not");
    return 0;
}

_Bool is_prime(int n)
{
    if (n <= 1)
        return 0;
    else if (n == 2)
        return 1;
    else
    {
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return 0;
        return 1;
    }
}
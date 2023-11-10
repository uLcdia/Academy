#include <stdio.h>
long pow(int,int);
int main()
{
    int x;
    do
    {
        scanf("%d",&x);
    } while (x > 1000);
    printf("%d",pow(x,2));
}

long pow(int x, int p)
{
    long result = x;
    for (int i = 1; i < p; i++)
    {
        result *= x;
    }
    return result;
}
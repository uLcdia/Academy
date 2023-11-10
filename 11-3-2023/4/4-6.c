#include <stdio.h>

int main()
{
    double x,y;
    scanf("%lf",&x);
    if (x < 1)
    {
        y = x;
        printf("%f",y);
    }
    else if (x < 10)
    {
        y = 2 * x - 1;
        printf("%f",y);
    }
    else
    {
        y = 3 * x - 11;
        printf("%f",y);
    }
    
}
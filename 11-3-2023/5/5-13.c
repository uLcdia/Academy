#include <stdio.h>
#include <math.h>

double n_sqrt(double,double);

int main()
{
    double a, x, x_p;
    scanf("%lf",&a);
    x = a;
    x_p = 0;
    while (fabs(x - x_p) > 1e-5)
    {
        x_p = x;
        x = n_sqrt(x,a);
    }
    printf("%lf",x);
    return 0;
}

double n_sqrt(double x,double a)
{
    return (x + a / x) / 2;
}
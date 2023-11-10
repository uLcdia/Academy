#include <stdio.h>
#define POSITION 2.0F // once accidentally added ';'

double abs(double);
double calculation(double,double);

int main(void)
{
    double x,y;
    printf("input format: x,y: ");
    scanf("%lf,%lf",&x,&y);
    x = abs(x);
    y = abs(y);
    printf("%d",(calculation(x,y) >= 1) ? 0 : 10);
    return 0;
}

double abs(double x) // absolute
{
    return (x > 0)? x : -x;
}

double calculation(double x, double y) // r^2
{
    return ((x - POSITION) * (x - POSITION) + (y - POSITION) * (y - POSITION));
}
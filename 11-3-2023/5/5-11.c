#include <stdio.h>

int main()
{
    double s = 100.0, t = 50.0;
    for (int i = 0; i < 9; i++)
    {
        s += t;
        t /= 2;
    }
    printf("%f %f\n",s,t/2);
    return 0;
}
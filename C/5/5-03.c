#include <stdio.h>

int main(void)
{
    int a,b,c;
    scanf("%d %d",&a,&b);
    c = a * b;
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    printf("gcd: %d\n",a);
    printf("lcm: %d",c / a);
    return 0;
}
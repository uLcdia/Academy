#include <stdio.h>

int main()
{
    int a = 1,b = 2,c;
    double result = 0;
    for (int i = 0; i <=19; i++)
    {
        result += (double)b / a;
        c = a;
        a = b;
        b += c;
    }
    printf("%f",result);
    return 0;
}
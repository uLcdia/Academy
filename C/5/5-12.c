#include <stdio.h>

int main(void)
{
    int t = 1;
    for (int i = 0; i < 10; i++)
    {
        t = (t + 1) * 2;
    }
    printf("%d",t);
    return 0;
}
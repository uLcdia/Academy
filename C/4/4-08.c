#include <stdio.h>

int main(void)
{
    int x;
    scanf("%d",&x);
    if (x > 100 || x < 0)
        printf("Invalid input.");
    else if (x > 90)
        putchar('A');
    else if (x > 80)
        putchar('B');
    else if (x > 70)
        putchar('C');
    else if (x > 60)
        putchar('D');
    else
        putchar('E');
    return 0;
}
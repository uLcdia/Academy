#include <stdio.h>

#define N 5
#define LINES 5

void starbar(void);

int main(void)
{
    for (int i = 0; i < LINES; i++)
    {
        starbar();
        for (int j = 0; j <= i; j++)
            printf("  ");
    }
    return 0;
}

void starbar(void)
{
    for (int i = 0; i < N; i++)
        printf("* ");
    putchar('\n');
}
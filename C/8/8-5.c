#include <stdio.h>

#define N 64
#define M 3

int main(void)
{
    int list[N] = {0};
    int * p = list;
    register int i = 0, n = 0, j = 1;
    while (n < N)
    {
        if (*(p + i) == 0)
        {
            if (j % M == 0)
            {
                *(p + i) = n + 1;
                j = 0;
                n++;
            }
            j++;
        }
        i = (i + 1) % N;
    }
    printf("The last one is %d\n", i);
    return 0;
}
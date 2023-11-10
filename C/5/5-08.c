#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if (100 * i + 10 * j + k == i * i * i + j * j * j + k * k * k)
                    printf("%d\n",100 * i + 10 * j + k);
    return 0;
}
#include <stdio.h>
#define N 100

int main(void)
{
    int prime[N] = {2}, length = 1, flag;
    for (int i = 3; i <= N; i++)
    {
        flag = 0;
        for (int j = 0; j < length; j++)
            if (i % prime[j] == 0)
            {
                flag = 1;
                break;
            }
        if (!flag)
            prime[length++] = i;
    }
    for (int i = 0; i < length; i++)
        printf("%d ",prime[i]);
    return 0;
}
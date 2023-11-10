#include <stdio.h>

int main()
{
    int s = 0; // s for sum of deviders, to check whether s equals i
    int a[100]; // a for array of deviders
    int k = 0; // k for position in a
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= i / 2; j++)
            if (i % j == 0)
            {
                s += j;
                a[k] = j;
                k++;
            }
        k--;
        if (s == i)
        {
            printf("%d, which has its factors:",i);
            for (int j = 0; j <= k; j++)
                printf(" %d",a[j]);
            printf("\n");
        }
        k = s = 0;
    } 
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15

void sort(int *, int);
void binary_search(int *, int, int);
int exist(const int *, int);

int main(void)
{
    srand(time(NULL));
    int a[N] = {0};
    int i = 0, random;
    // initialize the array, no duplicates
    while(i < N)
    {
        if (exist(a, random = rand() % 100))
            continue;
        else
            a[i++] = random;
    }
    printf("The original array:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    sort(a, N);
    printf("The sorted array:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    int x;
    printf("\nSearching for: ");
    scanf("%d", &x);
    binary_search(a, N, x);
    return 0;
}

void sort(int * a, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (*(a + j) > *(a + i))
            {
                temp = a[i];
                a[i]= a[j];
                a[j] = temp;
            }
}

void binary_search(int * a, int n, int x)
{
    int l = 0, r = n - 1, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (*(a + m) == x)
        {
            printf("Found %d at a[%d]\n", x, m);
            return;
        }
        else if (*(a + m) > x)
            l = m + 1;
        else
            r = m - 1;
    }
    printf("Not found\n");
}

int exist(const int * a, int x)
{
    int t;
    while (t = *a++)
        if (t == x)
            return 1;
    return 0;
}
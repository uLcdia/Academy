#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

void transpose(int (*)[N]);

int main(void)
{
    srand(time(NULL));
    int ar[N][N];
    for (int i = 0; i < N; i++) // initialize the world
        for (int j = 0; j < N; j++)
            ar[i][j] = rand() % 10;
    printf("Reality:\n"); // visualize the real world
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d",ar[i][j]);
        putchar('\n');
    }
    transpose(ar); // How would you know the difference between the dream world and the real world?
    printf("Morpheus:\n");
    for (int i = 0; i < N; i++) // visualize the dream world
    {
        for (int j = 0; j < N; j++)
            printf("%2d",ar[i][j]);
        putchar('\n');
    }
    return 0;
}

void transpose(int (*pt)[N])
{
    int temp;
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
        {
            temp = pt[i][j];
            pt[i][j] = pt[j][i];
            pt[j][i] = temp;
        }
}
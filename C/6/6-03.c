#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3 // only odd N

int main(void)
{
    srand(time(NULL));
    int l[N][N];
    printf("What is the Matrix?\n");

    for (int i = 0; i < N; i++) // initializing the Matrix 
        for (int j = 0; j < N; j++)
            l[i][j] = rand() % 10;

    for (int i = 0; i < N; i++) // visualizing the Matrix 
    {
        for (int j = 0; j < N; j++)
            printf("%2d ",l[i][j]);
        printf("\n");
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += l[i][N-1-i] + l[i][i];
    }
    sum -= l[N/2][N/2];

    printf("%d.\nThis is the Matrix.",sum);

    return 0;
}
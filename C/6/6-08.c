#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5 // only odd N
int matrix(int);

int main(void)
{
    srand(time(NULL));
    int i = rand() % 1000;
    while(matrix(i++) == 0)
        printf("No such spot\n");
    return 0;
}

int matrix(int i)
{
    srand(i);
    int l[N][N], max[N] = {0}, min[N] = {0};
    printf("What is the Matrix?\n");

    for (int i = 0; i < N; i++) // initializing the Matrix 
        for (int j = 0; j < N; j++)
            l[i][j] = rand() % 25;

    for (int i = 0; i < N; i++) // visualizing the Matrix 
    {
        for (int j = 0; j < N; j++)
            printf("%2d ",l[i][j]);
        printf("\n");
    }

    int mv;
    for (int i = 0; i < N; i++) // fing max
    {
        mv = l[i][0];
        for (int j = 0; j < N; j++)
        {
            if (l[i][j] > mv)
            {
                mv = l[i][j];
                max[i] = j;
            }
        }
    }
    mv = l[0][0];
    for (int i = 0; i < N; i++) // find min
    {
        mv = l[0][i];
        for (int j = 0; j < N; j++)
            if (l[j][i] < mv)
            {
                mv = l[j][i];
                min[i] = j;
            }
    }
    int flag = 0;
    for (int i = 0; i < N; i++) // find the spot
        if (i == min[max[i]])
        {
            printf("loc(%d,%d) = %d\n",i,max[i],l[max[i]][min[i]]);
            flag++;
        }
    return flag;
}
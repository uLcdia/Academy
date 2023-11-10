#include <stdio.h>
#define n 3 // odd only; haven't figured out how to solve for even n

int main(void)
{
    int l[n][n] = {0}; // order l[y][x]
    int x = n - 1, y = n / 2; // init 1 position
    l[y][x] = 1; // write 1
    for (int i = 2; i <= n * n; i++) // loop for each number (2,n^2)
    {
        if (l[(y + n - 1) % n][(x + 1) % n] != 0) // the upper-right is occupied
            x--; // move to left 
        else
        {
            x = (x + 1) % n; // right
            y = (y + n - 1) % n; // upper
        }
        l[y][x] = i; // write i
    }
    for (int i = 0; i < n; i++) // print
    {    
        for (int j = 0; j < n; j++)
            printf("%3d",l[i][j]);
        printf("\n");
    }
    return 0;
}

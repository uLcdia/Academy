#include <stdio.h>

int main(void)
{
    int l[11] = {0,1,2,3,4,5,6,7,8,9}, n;
    printf("The array: ");
    for (int i = 0; i < 10; i++)
        printf("%d ",l[i]);
    printf("\nNow input, integer only: ");
    scanf("%d",&n); 
    int p;
    for (p = 0; p < 10; p++)
        if (l[p] > n)
            break;
    for (int i = 10; i > p; i--)
        l[i] = l[i-1];
    l[p] = n;
    printf("Revised Array: ");
    for (int i = 0; i < 11; i++)
        printf("%d ",l[i]);
    return 0;
}
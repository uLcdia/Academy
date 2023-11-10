#include <stdio.h>

int main(void)
{
    int l[20], length = 0, temp;
    printf("Now input the array, q to quit: ");
    while (scanf("%d ",&l[length]) == 1) // get array
        length++;
    for (int i = 0; i < length/2; i++) // reverse gravity
    {
        temp = l[i];
        l[i] = l[length - 1 - i];
        l[length - 1 - i] = temp;
    }
    printf("Revised array:");
    for (int i = 0; i < length; i++) // print array
        printf(" %d",l[i]);
    printf(".");
    return 0;
}
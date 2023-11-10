#include <stdio.h>

int main()
{
    int x[32], max;
    int l = 0;
    printf("Enter a number:        ");
    while (scanf("%d",&x[l++]) == 1)
    {
        printf("q to quit. New number: ");
    } // now I have the numbers
    l--; // the last digit is junk
    printf("I shall get max from ");
    for (int i = 0; i < l; i++)
    {
        printf("%d ",x[i]);
    }
    printf("for you.\n"); // show user the number used
    max = x[0];
    for (int i = 1; i < l; i++)
    {
        if (max < x[i])
            max = x[i];
    }
    printf("I now have max which is %d",max);
    return 0;
}
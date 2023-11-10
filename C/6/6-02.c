#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int l[10];
    printf("Original:"); // generate random num list
    for (int i = 0; i < 10; i++)
    {
        l[i] = rand() % 100;
        printf(" %d",l[i]);
    }
    printf(".\n");

    // now sorting

    int max = l[0], loc = 0, temp;
    for (int i = 0; i < 9; i++) // num to be replaced
    {
        for (int j = i; j < 10; j++) // get max
        {
            if (l[j] > max)
            {
                max = l[j];
                loc = j;
            }
        }
        temp = l[i];
        l[i] = l[loc];
        l[loc] = temp;
        loc = i + 1;
        max = l[i + 1];
    }

    // end sorting

    printf("Sorted:");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d",l[i]);
    }
    printf(".\nJob Completed.");

    return 0;
}
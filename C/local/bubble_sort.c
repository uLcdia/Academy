#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort_1(int * list, int N);
void bubble_sort_2(int * list, int N);

int main(void)
{
    int list[11] = {5,2,6,3,1,6,9,4,7,8,0};

    fputs("Unsorted: ", stdout);
    for (int i = 0; i < 11; i++)
        printf("%d ", list[i]);
    fputs("\n", stdout);

    int list1[11], list2[11];
    memcpy(list1, list, sizeof(list));
    memcpy(list2, list, sizeof(list));

    bubble_sort_1(list1, 11);
    fputs("Bubble_sort_1(): ", stdout);
    for (int i = 0; i < 11; i++)
        printf("%d ", list1[i]);
    fputs("\n", stdout);

    bubble_sort_2(list2, 11);
    fputs("Bubble_sort_2(): ", stdout);
    for (int i = 0; i < 11; i++)
        printf("%d ", list2[i]);
    fputs("\n", stdout);
    return 0;
}

void bubble_sort_1(int * list, int N)
{
    int swapped, temp;
    for (int i = 0; i < N - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < N - i - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            return;
    }
}

void bubble_sort_2(int * list, int N)
{
    int swapped, temp;
    for (int i = 0; i < N - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < N - i - 1; j++)
        {
            if (list[j] < list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            return;
    }
}
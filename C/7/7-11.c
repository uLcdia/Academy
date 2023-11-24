#include <stdio.h>

void bubble_sort_char(char *);

int main(void)
{
    char c[10] = "";
    for (int i = 0; i < 10; i++)
        c[i] = getchar();
    bubble_sort_char(c);
    for (int i = 0; i < 10; i++)
        printf("%c",c[i]);
    return 0;
}

void bubble_sort_char(char * c)
{
    char temp;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9 - i; j++)
            if (c[j] > c[j + 1])
            {
                temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
}
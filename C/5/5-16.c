#include <stdio.h>
#define LINES 7 

void print(char,int);

int main(void)
{
    for (int i = 0; i < LINES; i++)
    {
        print(' ',abs(LINES / 2 - i));
        print('*',7-abs((3-i))*2);
        printf("\n");
    }
    return 0;
}

void print(char c, int n)
{
    for (int i = 0; i < n; i++)
        putchar(c);
}
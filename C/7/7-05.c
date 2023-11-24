#include <stdio.h>

void reverse(char *, int);

int main(void)
{
    char c[50] = "";
    int i = 0;
    while ((c[i] = getchar()) != '\n') // fgets(c)
        i++;
    c[i] = '\0';
    reverse(c,--i);
    printf("%s",c);
    return 0;
}

void reverse(char *c, int n)
{
    char temp;
    for (int i = n; i > n / 2; i--)
    {
        temp = c[i];
        c[i] = c[n - i];
        c[n - i] = temp;
    }
}
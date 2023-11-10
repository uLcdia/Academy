#include <stdio.h>

int main(void)
{
    char c;
    int l,s,n,m; // l for letter, s for space, n for number, m for misc (including "\n")
    l = s = n = m = 0;
    while ((c = getchar()) != '\n')
    {
        if ((c > 'a' && c < 'z') || (c > 'A' && c < 'Z'))
            l++;
        else if (c == ' ')
            s++;
        else if (c > '0' && c < '9')
            n++;
        else
            m++;
    }
    printf("letter: %2d\nspace:  %2d\nnumber: %2d\nothers:  %2d\n",l,s,n,m);
    return 0;
}
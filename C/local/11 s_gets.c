#include <stdio.h>

void s_gets(char *st, int n);

int main(void)
{
    char str[10];
    s_gets(str, sizeof(str));
    fputs(str, stdout);
    puts(str);
    return 0;
}

void s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0'; // remove newline
        else // words[i] == '\0'
            while (getchar() != '\n') // clear buffer
                continue;
    }
}
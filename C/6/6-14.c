#include <stdio.h>

int strdiff(const char *, const char *);

int main(void)
{
    // This is your life and it's ending one minute at a time.
    const char line[2][50] = {"Memento","Mori"};
    printf("%d",strdiff(line[0],line[1]));
    return 0;
}

int strdiff(const char * line1, const char * line2)
{
    while ((*line1 != '\0') || (*line2 != '\0'))
    {
        if (*line1 != *line2)
            return *line1 - *line2;
        line1++;
        line2++;
    }
    // line1 and line2 are equal or we're at the end of one of them
    if (*line1 == '\0')
        return -1;
    else if (*line2 == '\0')
        return 1;
    else
        return 0;
}
#include <stdio.h>

void strcat(char *, const char*);

int main(void)
{
    char s[100] = "gonna make him an offer", d[] = " he can't refuse.";
    strcat(s,d);
    puts(s);
    return 0;
}

void strcat(char *s, const char *d)
{
    while (*(++s) != '\0') ;
    while (*(s++) = *(d++)) ;
}
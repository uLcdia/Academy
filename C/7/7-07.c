#include <stdio.h>

void extract_vowels(const char *, char *);

int main(void)
{
    char s[] = "They call it Royale with Cheese.", d[] = "";
    extract_vowels(s,d);
    printf("%s",d);
    return 0;
}

void extract_vowels(const char *s, char *d)
{
    while (*(s++) != '\0')
        if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u')
            *(d++) = *s;
    *d = '\0';
}
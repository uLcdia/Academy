#include <stdio.h>

void shin_strcpy(char *, const char *);

int main(void)
{
    char dest[100] = "Someday we will foresee obstacles\n";
    const char src[50] = "Through the blizzard\0, through the blizzard";
    shin_strcpy(dest, src);
    printf("%s",dest);
    return 0;
}

void shin_strcpy(char * dest, const char * src)
{
    dest = dest + strlen(dest);
    while (*src != '\0')
        *dest++ = *src++;
    *dest = '\0';
}
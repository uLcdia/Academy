#include <stdio.h>
#include <ctype.h>

void shin_strcpy(char *, const char *);
int count(const char *);
int shin_strcmp(const char *, const char *);

int count_list[5]; // 0: upper, 1: lower, 2: space, 3: digit, 4: other

int main(void)
{
    char dest[100] = "Someday we will foresee obstacles\n";
    const char src[50] = "Through the blizzard\0, through the blizzard";
    const char cmp[2][20] = {"Memento","Mori"};
    extern int count_list[5];
    shin_strcpy(dest, src);
    printf("%s\n",dest);
    printf("Count: %d\n", count(dest));
    printf("%5s %5s %5s %5s %5s\n", "Upper", "Lower", "Space", "Digit", "Other");
    printf("%5d %5d %5d %5d %5d\n", count_list[0], count_list[1], count_list[2], count_list[3], count_list[4]);
    printf("%s %s compared: %d\n", cmp[0], cmp[1], shin_strcmp(cmp[0], cmp[1]));
    return 0;
}

void shin_strcpy(char * dest, const char * src)
{
    dest = dest + strlen(dest);
    while (*src != '\0')
        *dest++ = *src++;
    *dest = '\0';
}

int count(const char * line)
{
    extern int count_list[5];
    int n = 0;
    while(*line != '\0')
    {
        if (isupper(*line))
            count_list[0]++;
        else if (islower(*line))
            count_list[1]++;
        else if (isspace(*line))
            count_list[2]++;
        else if (isdigit(*line))
            count_list[3]++;
        else
            count_list[4]++;
        line++;
        n++;
    }
    return n;
}

int shin_strcmp(const char * line1, const char * line2)
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
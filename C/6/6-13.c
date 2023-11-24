#include <stdio.h>

void strcat(char *, char *);

int main(void)
{
    // This is a chemical burn.
    char line[2][50] = {"Congratulations. ", "You're one step closer to hitting bottom."};
    printf("str:\n%s%s\n", line[0], line[1]);
    strcat(line[0], line[1]);
    printf("cat:\n%s\n", line[0]);
    return 0;
}

void strcat(char * line1, char * line2)
{
    line1 = line1 + strlen(line1);
    while (*line1++ = *line2++);
}
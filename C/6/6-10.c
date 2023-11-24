#include <stdio.h>
#include <ctype.h>

#define LINES 3
#define MAXLEN 80

void count(const char *);

int main(void)
{
    // quote from Blade Runner
    const char line1[80] = "I've seen things you people wouldn't believe... Attack ships on fire off the s-", line2[80] = "houlder of Orion... I watched C-beams glitter in the dark near the Tannhauser ", line3[80] = "Gate. All those moments will be lost in time, like tears in rain... Time to die";
    printf("%s\n%s\n%s\n", line1, line2, line3);

    // count the letters, digits, spaces and other characters
    count(line1);
    count(line2);
    count(line3);

    return 0;
}

void count(const char * line)
{
    putchar('\n');
    int letters = 0, digits = 0, spaces = 0, others = 0;
    while(*line != '\0')
    {
        putchar(*line);
        if (isdigit(*line))
            digits++;
        else if (isalpha(*line))
            letters++;
        else if (isspace(*line))
            spaces++;
        else
            others++;
        line++;
    }

    printf("\nLetters: %d Digits: %d Spaces: %d Others: %d\n", letters, digits, spaces, others);
}
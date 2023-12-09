#include <stdio.h>

void get_schtrlong(const char *, char *);

int main(void)
{
    //const char c[100] = "I tell you what now between me and you. There is no me and you. Not no more.";
    char word[25] = "";
    char c[100] = "";
    fgets(c,100,stdin);
    get_schtrlong(c, word);
    printf("%s",word);
    return 0;
}

void get_schtrlong(const char * c, char * word)
{
    int length = 0, longest = 0, i;
    char temp[25] = "";
    while (*c != '\0' && *c != '\n')
    {
        if (*c != ' ' || *c != '.' || *c != ',' || *c != '!' || *c != '?')
            temp[length++] = *c;
        else if (length > longest)
        {
            for (i = 0; i < length; i++)
                word[i] = temp[i];
            word[i+1] = '\0';
            longest = length;
            length = 0;
        }
        else
            length = 0;
        c++;
    }
}
#include <stdio.h>
#include <ctype.h>

void encode(char *, int);

int main(void)
{
    // Jules freaking line encoded
    char quote[] = "ZmwBlfDrooPmldNbMznvRhGsvOliwDsvmROzbNbEvmtvzmxvFklmGsvv";
    printf("Encoded:\n");
    printf("%s\n", quote);
    encode(quote, sizeof(quote) / sizeof(quote[0]));
    printf("Decoded:\n");
    printf("%s\n", quote);
    return 0;
}

void encode(char * quote, int n)
{
    for (int i = 0; i < n - 1; i++) // -1 to avoid the null terminator
        quote[i] = isupper(quote[i])?(char)(155 - quote[i]):(char)(219 - quote[i]);
}
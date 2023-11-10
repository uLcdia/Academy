#include <stdio.h>
#include <string.h>

int main(void)
{
    char c[20] = "China";
    for (int i = 0; i < strlen(c); i++)
    {
        printf("%c",c[i]+4);
    }
    printf("\n");
    for (int i = 0; i < strlen(c); i++)
    {
        putchar(c[i]+4);
    }
    return 0;
}

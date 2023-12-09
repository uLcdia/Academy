#include <stdio.h>
int main(void)
{
    char plain[100] = "If we are true to ourselves, we can not be false to anyone.";
    char cypher[100];
    int key = 2;
    for (int i = 0; plain[i] != '\0'; i++)
    {
        if (plain[i] >= 'a' && plain[i] <= 'z')
            cypher[i] = ((plain[i] - 'a') + key) % 26 + 'a';
        else if (plain[i] >= 'A' && plain[i] <= 'Z')
            cypher[i] = ((plain[i] - 'A') + key) % 26 + 'A';
        else
            cypher[i] = plain[i];
    }
    printf("Plain text: %s\n", plain);
    printf("Cypher text: %s\n", cypher);
    return 0;
}
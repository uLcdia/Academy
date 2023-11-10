#include <stdio.h>
void printlist(int xd[], int l);
void i_printlist(int xd[], int l); //inversed print list

int main()
{
    unsigned x, x_backup;
    int l = 1;
    int xd[10];
    scanf("%u",&x);
    x_backup = x;
    // get length
    while ((x /= 10) != 0)
        l++;
    printf("length: %d\n",l);
    x = x_backup;
    // get digit
    x_backup = x;
    for (int i = 0; i < l; i++)
    {
        xd[i] = x % 10;
        x = x / 10;
    }
    // print list
    printlist(xd,l);
    i_printlist(xd,l);
    return 0;
}

void i_printlist(int xd[], int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("%d",xd[i]);
    }
    printf("\n");
}

void printlist(int xd[], int l)
{
    for (int i = l - 1; i >= 0; i--)
    {
        printf("%d",xd[i]);
    }
    printf("\n");
}


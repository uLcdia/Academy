#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv)
{
    if (argc != 3)
        exit(EXIT_FAILURE);
    FILE * ip, * op;
    if ((ip = fopen(argv[1],"r")) == NULL)
        exit(EXIT_FAILURE);
    if ((op = fopen(argv[2],"w")) == NULL)
        exit(EXIT_FAILURE);
    register char buffer;
    while ((buffer = getc(ip)) != EOF)
        putc(buffer,op);
    fclose(ip);
    fclose(op);
    return 0;
}
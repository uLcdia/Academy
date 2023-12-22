#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find(FILE * restrict fp, const char C);
void finds(FILE * restrict fp, const char * S);

int main(int argc, char *argv[])
{
    if (argc != 3) 
        exit(EXIT_FAILURE);
    FILE * fp;
    fp = fopen(argv[2],"rb");
    if (strlen(argv[1]) == 1)
        find(fp,argv[1][0]);
    else
        finds(fp,argv[1]);
    fclose(fp);
    return 0;
}

void find(FILE * restrict fp, const char C)
{
    register long offset = 0;
    char cur;
    while ((cur = fgetc(fp)) != EOF)
    {
        offset++;
        if (cur == C)
        {
            fseek(fp,-offset,SEEK_CUR);
            while ((cur = fgetc(fp)) != '\n')
                fputc(cur,stdout);
            putc('\n',stdout);
            offset = 0;
        }
        else if (cur == '\n')
            offset = 0;
    }
}

void finds(FILE * restrict fp, const char * S)
{
    char line[256];
    while (fgets(line,256,fp))
        if (strstr(line,S))
            fputs(line,stdout);
}
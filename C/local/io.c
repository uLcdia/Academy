#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    FILE * in;
    char buffer;
    in = fopen("io","r+");
    if (in != NULL) while ((buffer = fgetc(in)) != EOF) fputc(buffer,stdout);
    fputs("123",in);
    fseek(in,-1,SEEK_END);
    fputs("123",in);
    fseek(in,-1,SEEK_END);
    printf("%ld",ftell(in));
    fseek(in,-1,SEEK_CUR);
    fputs("123",in);
    fclose(in);
    return 0;
}
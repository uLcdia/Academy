#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float sum = 0.0;
    char buffer[20];
    char * ptr;
    while (fgets(buffer,20,stdin))
        sum += strtof(buffer,&ptr);
    if (argc == 1)
        fprintf(stdout,"%f",sum);
    else
    {
        FILE * fp;
        fp = fopen(argv[1],"w");
        fprintf(fp,"%f",sum);
        fclose(fp);
    }
    return 0;
}
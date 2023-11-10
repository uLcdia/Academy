#include <stdio.h>

int main(void)
{
    int match[3] = {0,0,0};
    int list[3][2] = {{1,2},{0,2},{0,1}};
    char c[3] = {'X','Y','Z'};
    for (int i = 0; i < 3; i++) // A matching
    {
        match[0] = i;
        for (int j = 0; j < 2; j++) // B matching alongside with C
        {
            match[1] = list[i][j];
            match[2] = list[i][1-j];
            printf("A - %c; B - %c; C - %c | ",c[match[0]],c[match[1]],c[match[2]]);
            if (match[0] == 0)
                printf("NEGATIVE A\n");
            else if (match[2] == 0 && match[2] == 2)
                printf("NEGATIVE C\n");
            else
            {
                printf("AFFIRMATIVE");
                goto end;
            }
            
        }
    }
    end:
    return 0;
}
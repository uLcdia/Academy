#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int * roll(int, int, int);

int main(void)
{
    srand(time(NULL));
    int sets,sides,dices;
    int * results;
    while(1)
    {
        printf("Enter the number of sets; enter q to stop: ");
        while (scanf("%d",&sets) != 1 && sets > 0)
            if (getchar() == 'q')
                exit(EXIT_SUCCESS);
            else
                while (getchar() != '\n') ;
        while (getchar() != '\n') ;
        printf("How many sides and how many dices? ");
        while (scanf("%d %d",&sides,&dices) != 2 && sides > 1 && dices > 0)
            if (getchar() == 'q')
                exit(EXIT_SUCCESS);
            else
                while (getchar() != '\n') ;
        while (getchar() != '\n') ;
        results = roll(sets,sides,dices);
        printf("Here are %d sets of %d %d-sided throws.\n",sets,dices,sides);
        for(int i = 0; i < sets; i++)
            printf("%3d",results[i]);
        fputs("\n",stdout);
        free(results);
    }
    return 0;
}

int * roll(int sets, int sides, int dices)
{
    int * results = (int *)calloc(sets, sizeof(int));
    for(int i = 0; i < sets; i++)
        for(int j = 0; j < dices; j++)
            results[i] += rand() % sides;
    return results;
}
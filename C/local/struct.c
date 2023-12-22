#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pace
{
    int start;
    int stop;
};

struct king
{
    char name[32];
    char hand[32];
};

struct dead_king
{
    struct king info;
    struct pace reign;
    char hail[129];
};

struct dead_king * die(struct king *, struct pace);

int main(void)
{
    struct king kings[2] = {{"Robert Baratheon", "Eddard Stark"}, {"Joffrey Baratheon", "Tyrion Lannister"}};
    struct dead_king * dead_kings[2];
    dead_kings[0] = die(&kings[0], (struct pace){283, 298}); // reign is compound literal
    dead_kings[1] = die(&kings[1], (struct pace){298, 300});
    for (int i = 0; i < 2; i++)
    {
        puts(dead_kings[i]->hail);
        free(dead_kings[i]);
    }
    return 0;
}

struct dead_king * die(struct king * ptr, struct pace l) // deliver king as pointer, pace as struct
{
    struct dead_king * king = malloc(sizeof(struct dead_king));
    king->info = *ptr;
    king->reign = l;
    snprintf(king->hail, 128, "King %s, Hand %s, reign (%d, %d), duration %d years. \nThe king is dead, long live the king!\n", king->info.name, king->info.hand, king->reign.start, king->reign.stop, king->reign.stop - king->reign.start);
    return king;
}
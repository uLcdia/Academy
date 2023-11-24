#include <stdio.h>

#define N 10

void get_employee(int *, char (*name)[25]);
void sort_employee(int *, char (*name)[25]);
void search_employee(int *, char (*name)[25], int);

int main(void)
{
    int id[N];
    char name[N][25];
    int x; // search id

    get_employee(id,name);

    sort_employee(id,name);

    // print sorted id and name
    printf("    %-2s %-25s\n","ID","Name");
    for (int i = 0; i < N; i++)
    {
        printf("%02d: ",i);
        printf("%d %s\n", *(id + i), *(name + i));
    }

    // binary search
    while (1)
    {
        printf("Looking for ID: ");
        scanf("%d",&x);
        search_employee(id,name,x);
    }

    return 0;
}

void get_employee(int * id, char (*name)[25])
{
    printf("    %-2s %-25s\n","ID","Name");
    for (int i = 0; i < N; i++)
    {
        printf("%02d: ",i);
        scanf("%d %s", id + i, name + i);
    }
}

void sort_employee(int * id, char (*name)[25])
{
    int temp_id;
    char temp_name[25];
    // bubble sort
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - 1 - i; j++)
            if (id[j] > id[j + 1])
            {
                temp_id = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp_id;

                strcpy(temp_name, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], temp_name);
            }
}

void search_employee(int * id, char (*name)[25], int x)
{
    int l = 0, r = N - 1, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (id[m] < x)
            l = m + 1;
        else if (id[m] > x)
            r = m - 1;
        else
        {
            printf("%d %s\n", *(id + m), *(name + m));
            return;
        }
    }
    printf("Not found.\n");
}
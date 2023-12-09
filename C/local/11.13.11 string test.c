#include <stdio.h>
#include <string.h>

#define SIZE 5

char get_choice(void);
void print_names(const char * names[], int * order);
void sort_alphabetical(const char * names[], int * order);
void sort_length(const char * names[], int * order);
void sort_length_first_name(const char * names[], int * order);

int main(void)
{
    const char *NAMES[SIZE] = {"Max Caulfield", "Chloe Price", "Kate Marsh", "Rachel Amber", "Warren Graham"};
    int original_order[SIZE] = {0, 1, 2, 3, 4};
    int alphabet_order[SIZE] = {0, 1, 2, 3, 4};
    int length_order[SIZE] = {0, 1, 2, 3, 4};
    int length_first_name_order[SIZE] = {0, 1, 2, 3, 4};
    char choice = get_choice();
    while (choice != 'Q')
    {
        switch (choice)
        {
            case 'O':
                printf("Original Order:\n");
                print_names(NAMES, original_order);
                printf("\n");
                break;
            case 'A':
                sort_alphabetical(NAMES, alphabet_order);
                printf("Alphabetical Order:\n");
                print_names(NAMES, alphabet_order);
                printf("\n");
                break;
            case 'L':
                sort_length(NAMES, length_order);
                printf("Length Order:\n");
                print_names(NAMES, length_order);
                printf("\n");
                break;
            case 'F':
                sort_length_first_name(NAMES, length_first_name_order);
                printf("Length of First Name Order:\n");
                print_names(NAMES, length_first_name_order);
                printf("\n");
                break;
        }
        choice = get_choice();
    }
    return 0;
}

char get_choice()
{
    char choice;
    printf("Please choose one of the following:\n");
    printf("%-40s %-40s\n%-40s %-40s\n%-40s\n",
        "O. Print names in original order","A. Print names in alphabetical order",
        "L. Print names in length order","F. Print names in length of first name order",
        "Q. Quit");
    do
    {
        printf("Please enter choice: ");
        choice = getchar();
        while (getchar() != '\n') // clear buffer
            continue;
        choice = toupper(choice);
    } while(strchr("OALFQ", choice) == NULL); // invalid input
    printf("\n");
    return choice;
}

void print_names(const char * names[], int * order)
{
    for (int i = 0; i < SIZE; i++)
        printf("%s\n", names[order[i]]);
}

void sort_alphabetical(const char * names[], int * order)
{
    int min, temp;
    for (int i = 0; i < SIZE - 1; i++) // selection sort
    {
        min = i;
        for (int j = i + 1; j < SIZE; j++)
            if (strcmp(names[order[j]], names[order[min]]) < 0) // names[order[j]] < names[order[min]]
                min = j;
        temp = order[i];
        order[i] = order[min];
        order[min] = temp;
    }
}

void sort_length(const char * names[], int * order)
{
    int min, temp;
    for (int i = 0; i < SIZE - 1; i++) // selection sort
    {
        min = i;
        for (int j = i + 1; j < SIZE; j++)
            if (strlen(names[order[j]]) < strlen(names[order[min]]))
                min = j;
        temp = order[i];
        order[i] = order[min];
        order[min] = temp;
    }
}

void sort_length_first_name(const char * names[], int * order)
{
    int min, temp;
    int length_first_names[SIZE] = {0};
    for (int i = 0; i < SIZE; i++) // find length of first name
        for (const char * p = names[i]; *p != ' '; p++)
            length_first_names[i]++;
    for (int i = 0; i < SIZE - 1; i++) // selection sort
    {
        min = i;
        for (int j = i + 1; j < SIZE; j++)
            if (length_first_names[order[j]] < length_first_names[order[min]])
                min = j;
        temp = order[i];
        order[i] = order[min];
        order[min] = temp;
    }
}
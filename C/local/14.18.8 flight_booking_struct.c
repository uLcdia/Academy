#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> // Sleep()
// #include <unistd.h>

// interface colors
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_GRAY    "\x1b[90m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define ALERT(X) puts(ANSI_COLOR_RED "The plane is " X "." ANSI_COLOR_RESET)

typedef struct {
    char serial[8];
    int isBooked;
    char bookerFirstName[32];
    char bookerLastName[32];
} seat;

void printMenu(const int N);
int getChoice(const int N);
int countEmptySeats(const int N, const seat ** flight);
void showEmptySeats(const int N, const seat ** flight);
void showAlphabeticalSeats(const int N, const seat ** flight);
void assignSeat(const int N, seat ** flight);
void deleteAssignment(const int N, seat ** flight);

int available;

int main(void)
{
    extern available;
    const int N = 6;
    seat flight[6] = {
        {
            "BJ9891",
            1,
            "Kotone",
            "Shiomi"
        },
        {
            "GB2023",
            1,
            "Max",
            "Caulfield"
        },
        {
            .serial = "AT0001",
            .isBooked = 0
        },
        {
            .serial = "US2001",
            .isBooked = 0
        },
        {
            .serial = "JP2009",
            .isBooked = 0
        },
        {
            .serial = "HL2024",
            .isBooked = 0
        }
    };
    seat * flightPointer[6];
    for (int i = 0; i < N; i++)
        flightPointer[i] = &flight[i];
    available = countEmptySeats(N, flightPointer);

    int choice;
    while ((choice = getChoice(N)) != 0)
    {
        switch (choice)
        {
            case 1:
                printf(ANSI_COLOR_BLUE "There are " ANSI_COLOR_GREEN "%d" ANSI_COLOR_BLUE " empty seats.\n" ANSI_COLOR_RESET, countEmptySeats(N, flightPointer));
                Sleep(1000);
                break;
            case 2:
                showEmptySeats(N, flightPointer);
                Sleep(1000);
                break;
            case 3:
                showAlphabeticalSeats(N, flightPointer);
                Sleep(1000);
                break;
            case 4:
                if (available) 
                    assignSeat(N, flightPointer);
                else
                    ALERT("full");
                    //printf(ANSI_COLOR_RED "The flight is full.\n" ANSI_COLOR_RESET);
                Sleep(1000);
                break;
            case 5:
                if (available != N)
                    deleteAssignment(N, flightPointer);
                else
                    ALERT("empty");
                    //printf(ANSI_COLOR_RED "The flight is empty.\n" ANSI_COLOR_RESET);
                Sleep(1000);
                break;
        }
        available = countEmptySeats(N, flightPointer);
    }
    puts(ANSI_COLOR_BLUE "Thank you for using Pathfinder Airline booking service." ANSI_COLOR_RESET);
    return 0;
}

void printMenu(const int N)
{
    extern available;
    if (available == N) // empty
        printf(ANSI_COLOR_YELLOW "PATHFINDER AIRLINE" ANSI_COLOR_RESET " | " ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "/" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET " | " ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET " available\n" ANSI_COLOR_MAGENTA
        "1)" ANSI_COLOR_RESET " Show number of empty seats\n" ANSI_COLOR_MAGENTA
        "2)" ANSI_COLOR_RESET " Show list of empty seats\n" ANSI_COLOR_MAGENTA
        "3)" ANSI_COLOR_RESET " Show alphabetical list of seats\n" ANSI_COLOR_MAGENTA
        "4)" ANSI_COLOR_RESET " Assign a customer to a seat assignment\n" ANSI_COLOR_GRAY
        "5)" ANSI_COLOR_GRAY " Delete a seat assignment\n" ANSI_COLOR_MAGENTA // disabled
        "q)" ANSI_COLOR_RESET " Quit\n" ANSI_COLOR_RESET, N - available, N, available);
    else if (!available) // full
        printf(ANSI_COLOR_YELLOW "PATHFINDER AIRLINE" ANSI_COLOR_RESET " | " ANSI_COLOR_RED "%d" ANSI_COLOR_RESET "/" ANSI_COLOR_RED "%d" ANSI_COLOR_RESET " | " ANSI_COLOR_RED "Full\n" ANSI_COLOR_MAGENTA
        "1)" ANSI_COLOR_RESET " Show number of empty seats\n" ANSI_COLOR_MAGENTA
        "2)" ANSI_COLOR_RESET " Show list of empty seats\n" ANSI_COLOR_MAGENTA
        "3)" ANSI_COLOR_RESET " Show alphabetical list of seats\n" ANSI_COLOR_GRAY
        "4)" ANSI_COLOR_GRAY " Assign a customer to a seat assignment\n" ANSI_COLOR_MAGENTA // disabled
        "5)" ANSI_COLOR_RESET " Delete a seat assignment\n" ANSI_COLOR_MAGENTA
        "q)" ANSI_COLOR_RESET " Quit\n" ANSI_COLOR_RESET, N - available, N, available);
    else // normal
        printf(ANSI_COLOR_YELLOW "PATHFINDER AIRLINE" ANSI_COLOR_RESET " | " ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "/" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET " | " ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET " available\n" ANSI_COLOR_MAGENTA
        "1)" ANSI_COLOR_RESET " Show number of empty seats\n" ANSI_COLOR_MAGENTA
        "2)" ANSI_COLOR_RESET " Show list of empty seats\n" ANSI_COLOR_MAGENTA
        "3)" ANSI_COLOR_RESET " Show alphabetical list of seats\n" ANSI_COLOR_MAGENTA
        "4)" ANSI_COLOR_RESET " Assign a customer to a seat assignment\n" ANSI_COLOR_MAGENTA
        "5)" ANSI_COLOR_RESET " Delete a seat assignment\n" ANSI_COLOR_MAGENTA
        "q)" ANSI_COLOR_RESET " Quit\n" ANSI_COLOR_RESET, N - available, N, available);
}

int getChoice(const int N)
{
    extern available;
    printMenu(N);
    char choice = getchar();
    while (getchar() != '\n') ;
    while (! strchr("12345q",choice))
    {
        printf(ANSI_COLOR_RED "Invalid input. Try again.\n" ANSI_COLOR_RESET);
        Sleep(1000);
        printMenu(N);
        choice = getchar();
        while (getchar() != '\n') ;
    }
    switch (choice)
    {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case 'q':
            return 0;
        default:
            return 0;
    }
}

// return available seats
int countEmptySeats(const int N, const seat ** flight)
{
    int count = 0;
    for (int i = 0; i < N; i++)
        if (flight[i]->isBooked == 0)
            count++;
    return count;
}

// print available seat serials
void showEmptySeats(const int N, const seat ** flight)
{
    int * emptySeats = calloc(N,sizeof(int));
    int j = 0;
    for (int i = 0; i < N; i++)
        if (flight[i]->isBooked == 0)
            emptySeats[j++] = i;
    if (j == 0)
        ALERT("The flight is full.\n");
        //puts(ANSI_COLOR_RED "The flight is full.\n" ANSI_COLOR_RESET);
    else
    {
        printf(ANSI_COLOR_BLUE "Seat%s " ANSI_COLOR_CYAN, (j == 1)?"":"s");
        for (int i = 0; i < j; i++)
            printf("%s ",flight[emptySeats[i]]->serial);
        printf(ANSI_COLOR_BLUE "empty.\n" ANSI_COLOR_RESET);
    }
    free(emptySeats);
}

// print seat info in alphabet sequence
void showAlphabeticalSeats(const int N, const seat ** flight)
{
    int temp;
    int * order = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        order[i] = i;
    for (int i = 0; i < N - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < N - i - 1; j++)
            if (strcmp(flight[order[j]]->serial, flight[order[j + 1]]->serial) > 0)
            {
                temp = order[j];
                order[j] = order[j + 1];
                order[j + 1] = temp;
                swapped++;
            }
        if (!swapped)
            break;
    }
    for (int i = 0; i < N; i++)
    {
        printf(ANSI_COLOR_BLUE "Seat " ANSI_COLOR_CYAN "%s" ANSI_COLOR_BLUE " is ", flight[order[i]]->serial);
        if (flight[order[i]]->isBooked)
            printf("booked by " ANSI_COLOR_CYAN "%s %s" ANSI_COLOR_BLUE ".\n" ANSI_COLOR_RESET, flight[order[i]]->bookerFirstName, flight[order[i]]->bookerLastName);
        else
            printf("empty.\n" ANSI_COLOR_RESET);
    }
    free(order);
}

// book seat
void assignSeat(const int N, seat ** flight)
{
    char firstName[32], lastName[32];
    puts(ANSI_COLOR_BLUE "Please enter your first name (empty line to cancel): " ANSI_COLOR_RESET);
    if (gets_s(firstName, 31) == NULL || firstName[0] == '\0')
        return ;
    puts(ANSI_COLOR_BLUE "Please enter your last name (empty line to cancel): " ANSI_COLOR_RESET);
    if (gets_s(lastName, 31) == NULL || lastName[0] == '\0')
        return ;
    int i;
    for (i = 0; i < N; i++)
        if (!(flight[i]->isBooked))
        {
            strcpy(flight[i]->bookerFirstName, firstName);
            strcpy(flight[i]->bookerLastName, lastName);
            flight[i]->isBooked++;
            break;
        }
    printf(ANSI_COLOR_GREEN "Successfully booked seat " ANSI_COLOR_CYAN "%s" ANSI_COLOR_GREEN " for " ANSI_COLOR_CYAN "%s %s" ANSI_COLOR_BLUE ".\n" ANSI_COLOR_RESET, flight[i]->serial, firstName, lastName);
}

// cancel booking
void deleteAssignment(const int N, seat ** flight)
{
    showAlphabeticalSeats(N, flight);
    char serial[8];
    int i;
    puts(ANSI_COLOR_BLUE "Which seat would you like to unbook (empty line to cancel): " ANSI_COLOR_RESET);
    if (gets_s(serial, 31) == NULL || serial[0] == '\0')
        return ;
    for (i = 0; i < strlen(serial); i++)
        serial[i] = toupper(serial[i]);
    for (i = 0; i < N; i++)
        if (! strcmp(flight[i]->serial, serial))
            if (flight[i]->isBooked == 1)
            {
                flight[i]->isBooked--;
                printf(ANSI_COLOR_GREEN "Seat " ANSI_COLOR_CYAN "%s" ANSI_COLOR_GREEN " successfully unbooked.\n" ANSI_COLOR_RESET, flight[i]->serial);
                return ;
            }
            else
            {
                printf(ANSI_COLOR_RED "Seat " ANSI_COLOR_CYAN "%s" ANSI_COLOR_RED " is not booked.\n" ANSI_COLOR_RESET, flight[i]->serial);
                return ;
            }
    printf(ANSI_COLOR_RED "Couldn't find seat " ANSI_COLOR_CYAN "%s" ANSI_COLOR_RED ". Please check your input.\n" ANSI_COLOR_RESET, serial);
}
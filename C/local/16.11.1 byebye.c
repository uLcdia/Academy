#include <stdio.h>
#include <stdlib.h>
void sign_off(void);
void too_bad(void);

int main(void)
{
    int n;

    atexit(sign_off); // sign_off is a pointer to function, which is called when the program terminates normally
    puts("Enter an integer:");
    if (scanf("%d", &n) != 1)
    {
        puts("That's no integer!");
        atexit(too_bad); // too_bad is called before sign_off, the function is called in the reverse order of registration
        exit(EXIT_FAILURE);
    }
    printf("%d is %s.\n", n, (n % 2 == 0) ? "even" : "odd");

    return 0;
}

void sign_off(void)
{
    puts("Thus terminates another magnificent program from");
    puts("SeeSaw Software!");
}

void too_bad(void)
{
    puts("SeeSaw Software extends its heartfelt condolences");
    puts("to you upon the failure of your program.");
}
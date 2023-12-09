#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

long numbers[100] = {0};

void store_numbers(const char * str);

int main(void)
{
    char str[100] = "5120x2880@60Hz, 3840x2160@120Hz, 3840x2160@60Hz, 2560x1440@165Hz";
    store_numbers(str);
    for (int i = 0; i < 100; i++)
        if (numbers[i])
            printf("%02d: %ld\n", i, numbers[i]);
    return 0;
}

void store_numbers(const char * str)
{
    const char * p = str;
    char str_num[10] = {0};
    char * num_p = str_num;
    int i = 0;
    while (*p)
    {
        if (isdigit(*p))
            *num_p++ = *p;
        else
            if (num_p != str_num)
            {
                *num_p = '\0';
                numbers[i++] = strtol(str_num, NULL, 10);
                num_p = str_num;
            }
        p++;
    }
}
#include <stdio.h>
#include <stdlib.h>

int maxScore(const char * s);

int main(void)
{
    char s[501];
    gets_s(s,500);
    printf("%d",maxScore(s));
    return 0;
}

int maxScore(const char * s) {
    /*int zero = 0, one = 0;
    int max = 0;
    for (int i = 1, j; s[i] != '\0'; i++)
    {
        for (j = 0; j < i; j++)
            if (s[j] == '0')
                zero++;
        for (j = i; s[j] != '\0'; j++)
            if (s[j] == '1')
                one++;
        if (zero + one > max)
            max = zero + one;
        zero = 0;
        one = 0;
    }
    return max;*/
    int t = 0;
    int L = 0, R = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == '1')
            R++;
    for (int i = 0; s[i + 1] != '\0'; i++)
    { 
        if (s[i] == '0')
            L++;
        else
            R--;
        t = max(t,L + R);
    }
    return t;
}
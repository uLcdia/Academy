#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPalindrome(int x);
bool shin_isPalindrome(int x);

int main(void)
{
    int x;
    scanf("%d",&x);
    //printf("%s",isPalindrome(x)?"Yip Yip.":"Nah.");
    printf("%s",shin_isPalindrome(x)?"Yip Yip.":"Nah.");
    return 0;
}

bool isPalindrome(int x)
{
    // junk
    if (x < 0)
        return false;
    else if (x < 10)
        return true;
    int left = 0, right = 0, t = x, r = 0;
    int length = 0; // actual length = length + 1
    while (t /= 10)
        length++;
    t = 1;
    const int l = length;
    while (left == right && length > (l / 2))
    {
        left = x / pow(10,length);
        right = right * 10 + (x % (int)pow(10,t)) / pow(10,t-1);
        r = x % (int)pow(10,t);
        t++;
        x -= r;
        length--;
    }
    if (left == right)
        return true;
    else
        return false;
}

bool shin_isPalindrome(const int x)
{
    long x_regent = 0, x_parody = x;
    if (x < 0)
        return false;
    while (x_parody != 0)
    {
        x_regent = x_regent * 10 + x_parody % 10;
        x_parody /= 10;
    }
    if (x == x_regent)
        return true;
    else
        return false;
}
#include <stdio.h>
#define MIN 1e5
#define MAX 1e6
int main()
{
    long p; // p for prize; o for obtained
    double o = 0.0;
    int job;
    scanf("%d",&p);
    job = (p / (long)1e5 >= 10)? -1 : (p / (long)1e5); // flag -1 for p >= 1e6
    switch (job) // sum up obtained from high to low
    {
        case -1:
        {
            o += (p - 1e6) * 0.01;
            p = (long)1e6;
        }
        case 9:
        case 8:
        case 7:
        case 6:
        {
            o += (p - 6e5) * 0.015;
            p = (long)6e5;
        }  
        case 5:
        case 4:
        {
            o += (p - 4e5) * 0.03;
            p = (long)4e5; 
        }
        case 3:
        case 2:
        {
            o += (p - 2e5) * 0.05;
            p = (long)2e5; 
        }
        case 1:
        {
            o += (p - 1e5) * 0.075;
            p = (long)1e5; 
        }
        case 0:
            o += p * 0.1;
    }
    printf("%.2f",o);
    return 0;
}
#include <stdio.h>

int refine(int,int);

int main()
{
    int a,n,result;
    scanf("%d %d",&a,&n);
    result = 0;
    for (int i = 1; i <= n; i++)
    {
        result += refine(a,i);
    }
    printf("%d",result);
    return 0;
}

int refine(a,n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = 10 * result + a;
    }
    return result;
}
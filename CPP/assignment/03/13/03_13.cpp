// get Fibonacci by iteration

#include <iostream>

int getFibonacci(int n)
{
    if (n != 1 && n != 2)
    {
        return (getFibonacci(n-1) + getFibonacci(n-2));
    }
    else
    {
        return 1;
    }
}

int main()
{
    std::cout << getFibonacci(10) << '\n';

    return 0;
}
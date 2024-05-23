#include <iostream>

// return sum = 1 + (1 + 2) + (1 + 2 + 3) + ... + (1 + 2 + 3 + ... + n)
int calculate(int n)
{
    int sum1 = n * (n + 1) / 2; // sum1 = 1 + 2 + 3 + ... + n
    int sum2 = n * (n + 1) * (2 * n + 1) / 6; // sum2 = 1^2 + 2^2 + 3^2 + ... + n^2

    return n * sum1 - sum2 + sum1;
}

int main()
{
    int n {};
    std::cin >> n; // get input, store number in n

    std::cout << calculate(n); // output calls calculate(n)

    return 0;
}
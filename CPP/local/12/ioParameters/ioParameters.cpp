// https://www.learncpp.com/cpp-tutorial/in-and-out-parameters/

// Avoid out-parameters (except in the rare case where no better options exist).

#include <iostream>

void division(const int& dividend, const int& divisor, int& quotientOut, int& remainderOut)
{
    quotientOut = dividend / divisor;
    remainderOut = dividend % divisor;
}

int main()
{
    constexpr int dividend {5};
    constexpr int divisor {2};

    int quotient {};
    int remainder {};

    division(dividend, divisor, quotient, remainder);

    std::cout << dividend << " / " << divisor << " = " << quotient << " * " << divisor << " + " << remainder << '\n';

    return 0;
}
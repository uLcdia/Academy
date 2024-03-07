// https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/

#include <iostream>

int main()
{
    [[maybe_unused]] static constexpr int constexprInt {3}; // static gives it static duration
    // [[maybe_unused]] constexpr int constexprInt {3}; // constexpr variable 'constexprIntRef' must be initialized by a constant expression
    [[maybe_unused]] constexpr const int& constexprIntRef {constexprInt}; // constexpr reference can only be bound with objects with static duration

    return 0;
}
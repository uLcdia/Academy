// https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/

#include <iostream>
#include <cassert>  // for assert()

// use assertion to debug, use error handling to apologize to users
// If the macro NDEBUG is defined, the assert macro gets disabled.

void sayHi(int tortoisStatus)
{
    // static_assert(0, "0 means bad boy");  // static assertion failed with "0 means bad boy"; fails at compile time
    // static_assert(tortoisStatus, "error");  // expression must have a constant value
    static_assert(1, "1 means go");
    assert(tortoisStatus == 1 && "cartel says hi"); // Assertion failed: tortoisStatus == 1

    std::cout << "Hola DEA!\n";
}

int main()
{
    constexpr int tortoisStatus {0};

    sayHi(tortoisStatus);

    return 0;
}
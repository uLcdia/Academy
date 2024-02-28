// https://www.learncpp.com/cpp-tutorial/constexpr-if-statements/

#include <iostream>

int main()
{
    constexpr int zero = 0;
    constexpr int one = 1;
    constexpr int number = zero;

    if constexpr (number == zero)
    {
        std::cout << "0\n";
    }
    else if constexpr (number == one)
    {
        std::cout << "1\0";
    }
    else
    {
        std::cout << "?\0";
    }

    /*
    std::cout << "0\n";
    */
   
    return 0;
}
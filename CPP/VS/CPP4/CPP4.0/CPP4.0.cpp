// https://www.learncpp.com/cpp-tutorial/object-sizes-and-the-sizeof-operator/
// The sizeof operator

#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <cstddef> // for std::size_t // without this incluce it still compiles, don't know why
#include <iostream>

int main()
{

    /*
    8 bit signed	-128 to 127
    16 bit signed	-32,768 to 32,767
    32 bit signed	-2,147,483,648 to 2,147,483,647
    64 bit signed	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
    */

    std::cout << std::left; // left justify output
    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    // https://learn.microsoft.com/en-us/cpp/c-language/type-int?view=msvc-170 // Type int
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n"; // 4 bytes, identical to long int. Use int in most circumstances.
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";
    // std::cout << std::setw(16) << "void:" << sizeof(void) << " bytes\n"; // 'void': illegal sizeof operand

    std::cout << std::setw(16) << "std::size_t:" << sizeof(std::size_t) << " bytes\n"; // 8 bytes 64-bit, 4 bytes 32-bit

    return 0;
}

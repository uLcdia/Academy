// https://www.learncpp.com/cpp-tutorial/internal-linkage/
// https://www.learncpp.com/cpp-tutorial/external-linkage-and-variable-forward-declarations/

#include <iostream>

[[maybe_unused]] constexpr int constFoo { 2 };
// [[maybe_unused]] int intFoo { 4 };
[[maybe_unused]] static int staticIntFoo { 6 };

extern int intX;                        // intX which has external linkage is defined in another file
// extern constexpr int constexprIntY;  // don't extern a constexpr, the constexpr value should be known by compiler not linker
extern const int constIntZ;

void sayHola();
// void megidolaon(); // linker: undefined reference to `megidolaon()'

int main()
{
    // don't put variable definition here to avoid variable shadowing

    std::cout << "foo.cpp\n";
    std::cout << constFoo << " | " << intX << " | " << staticIntFoo << constIntZ << "\n";

    sayHola();
    // megidolaon();

    return 0;
}
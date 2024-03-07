// https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/

#include <iostream>

void addOne(int& x)
{
    std::cout << "x++\n";
    x++;
}

void printInt(const int& x)
{
    std::cout << x << '\n';
}

int main()
{
    std::cout << "int\n";
    int intX {1};
    printInt(intX);
    addOne(intX);
    printInt(intX);

    std::cout << "\nconst int\n";
    const int constIntX {5};
    printInt(constIntX);
    // addOne(constIntX);
    printInt(constIntX);

    std::cout << "\nint literal\n";
    printInt(10);   // can pass literal rvalue

    return 0;
}
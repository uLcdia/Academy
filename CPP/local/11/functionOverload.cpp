// https://www.learncpp.com/cpp-tutorial/function-overload-differentiation/

#include <iostream>

int add(int a, int b)
{
    return (a + b);
}

int add(int a, int b, int c)
{
    return (a + b + c);
}

double add(double a, double b)
{
    return (a + b);
}

// double add(int a, int b); // cannot overload functions distinguished by return type alone

void print(unsigned int)
{
}

void print(float)
{
}

void print(char) = delete;

int main()
{
    std::cout << add(1, 2) << '\n';
    std::cout << add(1, 2, 3) << '\n';
    std::cout << add(1.0, 2.0) << '\n';

    // std::cout << add(1.0L, 2.0L) << '\n'; // more than one instance of overloaded function "add" matches the argument list. error: call to 'add' is ambiguous

    // print(0); // int can be numerically converted to unsigned int or to float. more than one instance of overloaded function "print" matches the argument list
    // print(3.14159); // double can be numerically converted to unsigned int or to float. more than one instance of overloaded function "print" matches the argument list

    // print('a'); // function "print(char)" (declared at line 30) cannot be referenced -- it is a deleted function

    return 0;
}
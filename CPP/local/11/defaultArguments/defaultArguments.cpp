// https://www.learncpp.com/cpp-tutorial/default-arguments/

#include <iostream>
#include <random>
#include "defaultArguments.h"

namespace random
{
    std::random_device rd{};
    std::seed_seq ss {rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 mt {ss};
}

int rollDice(int faces) // with default arguments in declaration in header
{
    std::uniform_int_distribution dice {1, faces};

    return (dice(random::mt));
}

void print(int a, int b) // with default arguments in declaration in header
{
    std::cout << "a: " << a << '\t' << "b: " << b << '\n';
}

// void print(int a = 0);                       // print() and print(1): more than one instance of overloaded function "print" matches the argument list
// void print(double a = 0.0, double b = 1.0);  // print(): more than one instance of overloaded function "print" matches the argument list
// you can mix up default arguments and function overload, but beware of the possibility of getting errors of ambiguous function call

// void printAlt(int a = 0, int b); // error: missing default argument on parameter 'b'

int main()
{
    std::cout << "rollDice():   " << rollDice() << '\n';
    std::cout << "rollDice(6):  " << rollDice(6) << '\n';
    std::cout << "rollDice(20): " << rollDice(20) << '\n';

    print();
    print(1);
    print(1, 2);
    
    return 0;
}
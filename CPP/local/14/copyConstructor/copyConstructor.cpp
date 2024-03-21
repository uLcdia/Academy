// https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/

#include <iostream>

class Fraction
{
public:
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator {numerator} // if m_numerator = numerator: error: expected a '(' or a '{'. only direct initialization can be used in a constructor member initializer list
        , m_denominator {denominator}
    {}

    Fraction(const Fraction& fraction) // if const Fraction fraction: error: copy constructor must pass its first argument by reference
        : m_numerator {fraction.m_numerator}
        , m_denominator {fraction.m_denominator}
    // Access controls work on a per-class basis (not a per-object basis). This means the member functions of a class can access the private members of any class object of the same type (not just the implicit object).
    {
        std::cout << "COPY CONSTRUCTOR\n";
    }  // Copy constructors should have no side effects beyond copying. Generally there shouldn't be explicit copy constructor, this one is just for observational purpose

    void print() const {std::cout << "print(): Fraction(" << m_numerator << ", " << m_denominator << ")\n";}


private:
    int m_numerator {0};
    int m_denominator {1};
};

void printFraction(Fraction f) // f: Fraction(const Fraction& fraction); copy constructor
{
    f.print();
}

Fraction generateFraction(int numerator, int denominator)
{
    Fraction f {numerator, denominator};
    return f;
    // if not optimized: When generateFraction returns a Fraction back to main, the copy constructor is implicitly called again.
    // optimized: copy elision, the copy constructor is elided
}

int main()
{
    std::cout << "Fraction f1 {10, 20};\n";
    Fraction f1 {10, 20};

    std::cout << "printFraction(f1);\n";
    printFraction(f1);

    std::cout << "Fraction f2 {generateFraction(30, 40)};\n";
    Fraction f2 {generateFraction(30, 40)};

    std::cout << "printFraction(f2);\n";
    printFraction(f2);

    return 0;
}
// https://www.learncpp.com/cpp-tutorial/chapter-14-summary-and-quiz/

#include <iostream>

class Fraction
{
public:
    explicit Fraction(int numerator = 0, int denominator = 1)
        : m_numerator {numerator}
        , m_denominator {denominator}
    {}
    
    void getFraction() // better left as a non-member function
    {
        std::cout << "Enter a value for numerator: ";
        std::cin >> m_numerator;
        std::cout << "Enter a value for denominator: ";
        std::cin >> m_denominator;
        std::cout << '\n';
    }

    Fraction multiply(const Fraction& f) const // better left as a non-member function
    {
        return Fraction {getNumerator() * f.getNumerator(), getDenominator() * f.getDenominator() };
    }
    
    void printFraction() const // better left as a non-member function
    {
        std::cout << getNumerator() << '/' << getDenominator() << '\n';
    }

    int getNumerator() const {return m_numerator;}
    int getDenominator() const {return m_denominator;}

private:
    int m_numerator {0};
    int m_denominator {1};
};

int main()
{
    Fraction f1 {};
    f1.getFraction();
    Fraction f2 {};
    f2.getFraction();
        
    std::cout << "Your fractions multiplied together: ";

    f1.multiply(f2).printFraction();

    return 0;
}
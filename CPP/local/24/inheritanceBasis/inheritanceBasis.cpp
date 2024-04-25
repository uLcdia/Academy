// https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/

#include <iostream>

class A // no interitance
{
public:
    A(int a)
        : m_a {a}
    {
        std::cout << "Executing A constructor. " << std::endl;
    }
    int getA() const {return m_a;}
    ~A() {std::cout << "Executing A destructor." << std::endl;}
private:
    int m_a {};
};

class B: public A
{
public:
    B(int a, int b) // parameter for A constructor(a)
        : A {a}
        , m_b {b}
    {
        std::cout << "Executing B constructor. " << std::endl;
    }
    int getB() const {return m_b;}
    ~B() {std::cout << "Executing B destructor." << std::endl;}
private:
    int m_b {};
};


class C: public B
{
public:
    C(int a, int b, int c) // parameter for B constructor(a, b) (which includes parameter for A constructor(a))
        : B {a, b}
        , m_c {c}
    {
        std::cout << "Executing C constructor. " << std::endl;
    }
    int getC() const {return m_c;}
    ~C() {std::cout << "Executing C destructor." << std::endl;}
private:
    int m_c {};
};

int main()
{
    C c {0, 1, 2};
    std::cout << "a: " << c.getA() << ", b: " << c.getB() << ", c: " << c.getC() << std::endl;

    return 0;
}
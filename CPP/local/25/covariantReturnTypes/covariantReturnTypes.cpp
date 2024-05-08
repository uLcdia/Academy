// https://www.learncpp.com/cpp-tutorial/the-override-and-final-specifiers-and-covariant-return-types/

#include <iostream>

class A
{
public:
    void print()
    {
        std::cout << "A; ";
    }
    virtual void vprint()
    {
        std::cout << "A; ";
    }
};
class B : public A
{
public:
    void print()
    {
        std::cout << "B; ";
    }
    void vprint() override
    {
        std::cout << "B; ";
    }
};


class C
{
private:
    A m_a{};

public:
    virtual A& get()
    {
        std::cout << "C::get() -> ";
        return m_a;
    }
};

class D : public C
{
private:
    B m_b{};

public:
    B& get() override // covariant return type
    {
        std::cout << "B::get() -> ";
        return m_b;
    }
};

int main()
{
    // case 1
    D d {};
    d.get().print();
    d.get().vprint();
    std::cout << '\n';

    // case 2
    C c {};
    c.get().print();
    c.get().vprint();
    std::cout << '\n';

    // case 3
    C& ref{ d }; // ref is a C& referencing D object
    ref.get().print(); // ref.get() calls D::get() which returns an A& referencing a B object, A&.print() calls A::print() because print() is a non-virtual function of A
    ref.get().vprint(); // ref.get() calls D::get() which returns an A& referencing a B object, A&.print() calls B::print() because vprint() being a virtual function, causes virtual function resolution being used to find A& is referencing B, B::print() gets called
    std::cout << '\n';

    return 0;
}
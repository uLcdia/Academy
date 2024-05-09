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
    C& ref{ d }; // ref is a C& referencing a D object

    // ref.get() calls D::get() which returns an A& referencing a B object
    // A&.print() calls A::print() because print() is a non-virtual function of A

    // get() is a virtual function, calling it requires checking the virtual table
    // ref.__vPtr: *__vPtr of d. ref.get() resolves to d.__vPtr->d.get()
    // d.get() returns a B object, ref.get() is an A& referencing a B object
    // print() is not a virtual function, calling it doesn't require checking the virtual table
    // A&.print() calls A::print()
    ref.get().print();

    // ref.get() calls D::get() which returns an A& referencing a B object
    // A&.print() calls B::print() because vprint() is a virtual function
    // causing virtual function resolution being used to find A& is referencing B, B::print() gets called

    
    // vprint() is a virtual function, calling it requires checking the virtual table
    // ref.get().__vPtr: *__vPtr of m_b. ref.get().vprint() resolves to m_b.__vPtr->m_b.vprint()
    ref.get().vprint(); 
    std::cout << '\n';

    return 0;
}
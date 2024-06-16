#include <iostream>

class Base
{
public:
    // https://www.stroustrup.com/bs_faq2.html#virtual-ctor
    // A virtual call is a mechanism to get work done given partial information. In particular, "virtual" allows us to call a function knowing only any interfaces and not the exact type of the object. To create an object you need complete information. In particular, you need to know the exact type of what you want to create. Consequently, a "call to a constructor" cannot be virtual.
    // virtual Base(); // no virtual constructor

    virtual void vprint() const
    {
        std::cout << "Base::vprint()\n";
    }

    void print() const
    {
        std::cout << "Base::print()\n";
    }

    virtual ~Base()
    {
        std::cout << "~Base()\n";
    }
};

class Derived1 : public Base
{
public:
    // virtual void vprint() const // warning: 'vprint' overrides a member function but is not marked 'override' [-Werror,-Winconsistent-missing-override]
    void vprint() const override
    {
        std::cout << "Derived1::vprint()\n";
    }

    void print() const
    {
        std::cout << "Derived1::print()\n";
    }

    // all derived overrides, even if not explicitly marked virtual or not, are implicitly virtual; but the best practice is to explicitly mark virtual

    // If a class (Base) has a virtual destructor, it ensures that when you delete an object of a derived class (Derived1) through a pointer to the base class, the derived class's destructor will be called, followed by the base class's destructor.
    ~Derived1() override // ~Derived1() is override of ~Base() though the different name // virtual ~Derived1() also works, the same as the others
    {
        std::cout << "~Derived1()\n";
    }
};

class Derived2 : public Base
{
public:
    // specifier: override, final
    // override makes sure that this function overrides a virtual function from the base class
    // final makes sure that this function cannot be overridden again in the derived class
    
    void vprint() const override // preferred over virtual in Derived1
    {
        std::cout << "Derived2::vprint()\n";
    }

    void print() const
    {
        std::cout << "Derived2::print()\n";
    }

    ~Derived2() override
    {
        std::cout << "~Derived2()\n";
    }
};


int main()
{
    Base base {};
    base.vprint();
    base.print();

    Derived1 derived1 {};
    derived1.vprint();
    derived1.print();

    Derived2 derived2 {};
    derived2.vprint();
    derived2.print();

    {
        std::cout << "Base*: \n";
        Base* basePtr {};

        Derived1 derived1Alt {}; // destructor ~Derived1() then ~Base()
        basePtr = &derived1Alt;
        basePtr->vprint();
        basePtr->print();

        Derived2 derived2Alt {}; // destructor ~Derived2() then ~Base()
        basePtr = &derived2Alt;
        basePtr->vprint();
        basePtr->print();

        // the latter created object is deleted first
    }

    std::cout << "fin.\n";

    // ~Derived2() + ~Base(), ~Derived1() + ~Base(), ~Base()

    return 0;
}
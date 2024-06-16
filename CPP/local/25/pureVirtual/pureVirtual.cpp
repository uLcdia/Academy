// https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/

#include <iostream>

class Base
{
public:
    void function1() const {std::cout << "Base::function1()\n";}
    virtual void function2() const = 0;
    void function3() const {std::cout << "Base::function3()\n";}
protected:
    Base(int base)
        : m_base{base}
    {}
    [[maybe_unused]] int m_base {};
};

class D1 : public Base
{
public:
    D1(int base, int d1)
        : Base {base} // initialize **Base class part** of D1 object
        , m_d1 {d1}
    {}

    void function2() const override {std::cout << "D1::function2()\n";}

    void function3() const {std::cout << "D1::function3()\n";}
private:
    [[maybe_unused]] int m_d1 {};
    // Base baseObj {0}; // error: object of abstract class type "Base" is not allowed; can not instantiate **Base class object** anywhere
};

int main()
{
    // Base baseObj {}; // error: object of abstract class type "Base" is not allowed

    D1 dObj {0, 1};

    dObj.function1();
    dObj.function2();
    dObj.function3();

    dObj.Base::function3();
    static_cast<Base&>(dObj).function3();

    static_cast<Base&>(dObj).function2();
    static_cast<Base*>(&dObj)->function2();
    // static_cast<Base>(dObj).function2(); // error: a cast to abstract class "Base" is not allowed

    return 0;
}
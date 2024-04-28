// BaseClass and DerivedClass, each has its own fn1() and fn2(), call fn1() and fn2()

#include <iostream>

class BaseClass
{
public:
    void fn1() const {std::cout << "BaseClass.fn1() " << std::endl;}
    void fn2() const {std::cout << "BaseClass.fn2() " << std::endl;}
private:
};

class DerivedClass : public BaseClass
{
public:
    void fn1() const {std::cout << "DerivedClass.fn1() " << std::endl;}
    void fn2() const {std::cout << "DerivedClass.fn2() " << std::endl;}
private:
};

int main()
{
    const DerivedClass foo {};
    foo.fn1();
    foo.fn2();
    static_cast<const BaseClass&>(foo).fn1();
    static_cast<const BaseClass&>(foo).fn2();

    const DerivedClass* pFoo {&foo};
    pFoo->fn1();
    pFoo->fn2();
    const BaseClass* pBar {static_cast<const BaseClass*>(pFoo)};
    pBar->fn1();
    pBar->fn2();

    return 0;
}
#include <iostream>

class Foo
{
public:
    Foo(int value)
        : publicValue {value}, protectedValue {2 * value}, privateValue {4 * value}
    {}


    [[maybe_unused]] int publicValue {};
    void publicPrint() const
    {
        std::cout << "Foo::publicPrint()\n";
    }

protected:
    [[maybe_unused]] int protectedValue {};

private:
    [[maybe_unused]] int privateValue {};
};

class Goo
{
public:
    Goo(int value)
        : publicValue {value}
    {}

    [[maybe_unused]] int publicValue {};
    void publicPrint() const
    {
        std::cout << "Goo::publicPrint()\n";
    }
};

class Bar : public Foo, public Goo
{
public:
    // order: Base Classes' Constructors; Member Initializers: Derived Class Constructor.
    // Base constructor is called before Derived constructor; Derived constructor is called in the order of the inheritance list in class definition
    // Foo(); Goo(); Bar(). Bar() initializer list order doesn't matter, the same goes for member initializer, whose order depends on order of member variables' definition
    Bar(int value1, int value2)
        // : Goo {value2}, Foo {value1} // warning: base class 'Goo' will be initialized after base 'Foo' [-Werror,-Wreorder-ctor]
        : Foo {value1}, Goo {value2}
    {}

    Bar()
        : Bar {10, 10}
    {}
    void publicPrint() const
    {
        std::cout << "Bar::publicPrint()\n";
    }

private:
    void changeValue()
    {
        protectedValue = 10;
        // privateValue = 20; // member "Foo::privateValue" is inaccessible
        // Foo::privateValue = 20; // member "Foo::privateValue" is inaccessible
    }
};

class Tar : protected Foo
{
public:
    Tar(int value = 0)
        : Foo {value}
    {}

    void changeValue()
    {
        publicValue = 20; // publicValue becomes protected, can be touched by derived classes of Tar
    }
};

class Tar2 : public Tar
{
public:
    Tar2(int value = 0)
        : Tar {value}
    {}
};

class Gar : private Foo
{
public:
    Gar(int value = 0)
        : Foo {value}
    {}

    void changeValue()
    {
        publicValue = 30; // publicValue becomes private, can not be touched by derived classes of Gar
    }
};

class Gar2 : public Gar
{
public:
    Gar2(int value = 0)
        : Gar {value}
    {}
/* 
    void changeValue()
    {
        publicValue = 30; // error: member "Foo::publicValue" is inaccessible
    }
 */
};

int main()
{
    Bar bar {};
    bar.publicPrint(); // if Bar::publicPrint() is not defined: error: "Bar::publicPrint" is ambiguous
    bar.Foo::publicPrint();
    bar.Goo::publicPrint();
    // bar.publicValue = 5; // error: "Bar::publicValue" is ambiguousC/C++(266)
    bar.Goo::publicValue = 5;

    Tar tar {};
    // tar.publicValue = 2

    Tar2 tar2 {};
    tar2.changeValue();

    Gar2 gar2 {};
    gar2.changeValue(); // when gar2::changeValue() is commented out, gar2.Gar::changeValue() is called which has access to the Gar part

    return 0;
}
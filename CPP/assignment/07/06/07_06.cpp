// class Mammal as base, class Dog as derived

#include <iostream>

class Mammal
{
public:
    explicit Mammal(int foo) : m_foo {foo} {std::cout << "constructing Mammal." << std::endl;}
    virtual ~Mammal() {std::cout << "destructing Mammal." << std::endl;}
private:
    [[maybe_unused]]int m_foo {};
};

class Dog : public Mammal
{
public:
    Dog(int foo, int bar) : Mammal {foo}, m_bar {bar} {std::cout << "constructing Dog." << std::endl;}
    ~Dog() override {std::cout << "destructing Dog." << std::endl;}
private:
    [[maybe_unused]] int m_bar {};
};

int main()
{
    Dog wolfie {0, 1};

    return 0;
}
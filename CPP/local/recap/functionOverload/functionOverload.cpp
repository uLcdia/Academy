#include <iostream>

class Class1
{
public:
    void print(int value) const;
    void print(double value) const;
};

void Class1::print(int value) const
{
    std::cout << value << std::endl;
}

void Class1::print(double value) const
{
    std::cout << value << std::endl;
}

template <typename T>
class Class2
{
public:
    Class2(T value)
        : m_value {value}
    {}

    template <typename U>
    void print(U value) const
    {
        std::cout << value << std::endl;
    }
private:
    T m_value {};
};

int main()
{
    Class1 foo1 {};
    foo1.print(1);
    foo1.print(1.5);

    Class2 foo2 {2.5};
    foo2.print(2);
    foo2.print(2.5);

    return 0;
}
// https://www.learncpp.com/cpp-tutorial/introduction-to-destructors/

#include <iostream>

class Foo
{
public:
    Foo(int foo = 1)
        : m_foo{foo}
    {}
    ~Foo()
    {
        std::cout << "destructor " << m_foo << '\n';
    }
private:
    int m_foo {};
};

int main()
{
    Foo foo1 {1};
    Foo foo2 {2};
    /* {
        Foo foo3 {3};
        // exit(EXIT_SUCCESS); // will call no destructor
        return 0; // destructor 3, 2, 1
    } */

    return 0; // destructor 2, 1
}
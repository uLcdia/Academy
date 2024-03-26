// https://www.learncpp.com/cpp-tutorial/static-member-variables/

#include <iostream>

class Foo
{
public:
    // Best practice: Make your static members inline or constexpr so they can be initialized inside the class definition.
    // static member variables are shared between all objects of the class

    static inline int s_idGenerator {1};
    Foo()
        : m_id {s_idGenerator++}
    {}
    static constexpr double s_PI {3.1415927}; // constexpr members are implicitly inline
    // static double s_e {}; // error: a member with an in-class initializer must be const
    static double s_e;

    int getID() const {return m_id;}
private:
    int m_id {};
};

double Foo::s_e {2.718};

int main()
{
    std::cout << Foo::s_idGenerator << " " << Foo::s_PI << " " << Foo::s_e << '\n';

    Foo foo1 {};
    Foo foo2 {};

    std::cout << Foo::s_idGenerator << " " << Foo::s_PI << " " << Foo::s_e << '\n';
    std::cout << foo1.getID() << ' ' << foo2.getID() << '\n';

    return 0;
}
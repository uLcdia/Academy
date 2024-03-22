// https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/

// Make any constructor that accepts a single argument explicit by default. This includes constructors with multiple parameters where most or all of them have default values.

#include <iostream>

class Dollars
{
public:
    explicit Dollars(int d) // explicit, no converting constructors now
        : m_dollars {d}
    {}

    int getDollars() const {return m_dollars;}

private:
    int m_dollars {};
};

void print(Dollars d)
{
    std::cout << "$" << d.getDollars() << '\n';
}

int main()
{
    // print(5); // no suitable constructor exists to convert from "int" to "Dollars"

    // print({5}); // copy-list-initialization cannot use a constructor marked 'explicit'

    print(Dollars {5});

    return 0;
}
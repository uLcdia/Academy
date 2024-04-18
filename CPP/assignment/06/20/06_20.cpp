// class SimpleCircle, make its member itsRadius point to a int which stores the radius, make functions

#include <iostream>

namespace Circle
{
    constexpr double PI {3.1415927};
}

class SimpleCircle
{
public:
    SimpleCircle(int radius)
        : m_radius {radius}
    {}

    int * pointerRadius {&m_radius};
    void printArea() const
    {
        std::cout << "Area: " << m_radius * m_radius * Circle::PI << '\n';
    }
    void printCircumference() const
    {
        std::cout << "Circumference: " << 2 * m_radius * Circle::PI << '\n';
    }
private:
    int m_radius {};
};

int main()
{
    SimpleCircle foo {1};

    foo.printArea();
    foo.printCircumference();

    *foo.pointerRadius = 2;
    foo.printArea();
    foo.printCircumference();

    return 0;
}
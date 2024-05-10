// Base class Shape, derived Rectangle and Circle, which both have getArea(), use Rectangle as base to create derived Square.

#include <iostream>

class Shape
{
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape
{
public:
    explicit Circle(double radius)
        : m_radius {radius}
    {}

    double getArea() const override
    {
        return PI * m_radius * m_radius;
    }

private:
    double m_radius {};
    static constexpr double PI {3.1415927};
};

class Rectangle : public Shape
{
public:
    Rectangle(double width, double height)
        : m_width {width}, m_height {height}
    {}

    double getArea() const override
    {
        return m_width * m_height;
    }

private:
    double m_width {};
    double m_height {};
};

class Square : public Rectangle
{
public:
    explicit Square(double side)
        : Rectangle {side, side}
    {}
};

int main()
{
    Square foo {2};
    std::cout << foo.getArea() << std::endl;

    return 0;
}
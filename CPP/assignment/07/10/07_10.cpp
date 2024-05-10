// Base class Object with member variable weight and corresponding functions. Derived class Box with member variables height and width and their functions. Define a Box, observe the execution order of constructors and destructors.

#include <iostream>

class Object
{
public:
    explicit Object(double weight)
        : m_weight {weight}
    {
        std::cout << "Constructing Object..." << std::endl;
    }

    ~Object()
    {
        std::cout << "Destructing Object..." << std::endl;
    }

    double getWeight() const
    {
        return m_weight;
    }

    void setWeight(double weight)
    {
        m_weight = weight;
    }

protected:
    double m_weight {};
};

class Box : public Object
{
public:
    Box(double weight, double height, double width)
        : Object {weight}, m_height {height}, m_width {width}
    {
        std::cout << "Constructing Box..." << std::endl;
    }

    ~Box()
    {
        std::cout << "Destructing Box..." << std::endl;
    }

    double getHeight() const
    {
        return m_height;
    }

    void setHeight(double height)
    {
        m_height = height;
    }
    
    double getWidth() const
    {
        return m_width;
    }

    void setWidth(double width)
    {
        m_width = width;
    }

private:
    double m_height {};
    double m_width {};
};

void printBox(const Box& box)
{
    std::cout << "Weight: " << box.getWeight() << std::endl
              << "Height: " << box.getHeight() << std::endl
              << "Width: "  << box.getWidth()  << std::endl;
}

int main()
{
    Box foo {100.0, 20.0, 20.0};

    printBox(foo);

    Box* bar {new Box {500.0, 10.0, 10.0}};
    delete bar;

    return 0;
}
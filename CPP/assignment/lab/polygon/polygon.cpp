// base class Polygon, derived classes Triangle Rectangle Trapezoid
// member function: perimeter(), area(), display()

#include <iostream>
#include <array>
#include <cmath>
#include <numeric>
#include <exception>

// Define base class Polygon
class Polygon
{
public:
    // Declare pure virtual functions, for displaying info
    virtual void display() = 0;

    // Getter for perimeter
    double getPerimeter() const
    {   
        return m_perimeter;
    }

    // Getter for area
    double getArea() const
    {
        return m_area;
    }
protected:
    // Declare pure virtual functions, for calculating perimeter and calculating area
    virtual void calculatePerimeter() = 0;
    virtual void calculateArea() = 0;

    double m_perimeter {};
    double m_area {};
};

// Define derived class Triangle from Polygon
class Triangle : public Polygon
{
public:
    // Define number of sides in a triangle
    static constexpr int NUM_SIDES {3};

    // Constructor, takes a array of side lengths
    explicit Triangle(const std::array<double, NUM_SIDES>& sides)
        : m_sides {sides}
    {
        if (!isValidTriangle())
        {
            throw std::invalid_argument("Invalid triangle sides");
        }
        calculatePerimeter();
        calculateArea();
    }

    // Override display, showing shape, perimeter, area info
    void display() override
    {
        std::cout << "Triangle: " << '\n'
                  << "perimeter: " << getPerimeter() << '\n'
                  << "area:      " << getArea() << '\n';
    }
private:
    // Store side lengths
    std::array<double, NUM_SIDES> m_sides {};

    // Override calculatePerimeter, to calculate perimeter of the triangle
    void calculatePerimeter() override
    {
        m_perimeter = std::accumulate(m_sides.begin(), m_sides.end(), 0.0);
    }

    // Override calculateArea, to calculate area of the triangle
    void calculateArea() override
    {
        double s = m_perimeter / 2;
        m_area = std::sqrt(s * (s - m_sides[0]) * (s - m_sides[1]) * (s - m_sides[2]));
    }

    // Validate if sum of 2 sides is grater than the other side
    bool isValidTriangle()
    {
        return (m_sides[0] + m_sides[1] > m_sides[2]) && (m_sides[0] + m_sides[2] > m_sides[1]) && (m_sides[1] + m_sides[2] > m_sides[0]);
    }
};

// Define derived class Rectangle from Polygon
class Rectangle : public Polygon
{
public:
    // Define number of sides in a rectangle
    static constexpr int NUM_SIDES {4};

    // Constructor, takes a array of side lengths. Starting from top, clockwise
    explicit Rectangle(const std::array<double, NUM_SIDES>& sides)
        : m_sides {sides}
    {
        if (!isValidRectangle())
        {
            throw std::invalid_argument("Invalid rectangle sides");
        }
        calculatePerimeter();
        calculateArea();
    }

    // Override display, showing shape, perimeter, area info
    void display() override
    {
        std::cout << "Rectangle: " << '\n'
                  << "perimeter: " << getPerimeter() << '\n'
                  << "area:      " << getArea() << '\n';
    }
private:
    // Store side lengths
    std::array<double, NUM_SIDES> m_sides {};

    // Override calculatePerimeter, to calculate perimeter of the rectangle
    void calculatePerimeter() override
    {
        m_perimeter = std::accumulate(m_sides.begin(), m_sides.end(), 0.0);
    }

    // Override calculateArea, to calculate area of the rectangle
    void calculateArea() override
    {
        m_area = m_sides[0] * m_sides[1];
    }
    
    // Validate if parallel sides are equal
    bool isValidRectangle()
    {
        return (m_sides[0] == m_sides[2]) && (m_sides[1] == m_sides[3]);
    }
};

// Define derived class Trapezoid from Polygon
class Trapezoid : public Polygon
{
public:
    // Define number of sides in a trapezoid
    static constexpr int NUM_SIDES {4};

    // Constructor, takes a array of side lengths. Starting from top parallel side, clockwise
    explicit Trapezoid(const std::array<double, NUM_SIDES>& sides)
        : m_sides {sides}
    {
        calculatePerimeter();
        calculateArea();
    }

    // Override display, showing shape, perimeter, area info
    void display() override
    {
        std::cout << "Trapezoid: " << '\n'
                  << "perimeter: " << getPerimeter() << '\n'
                  << "area:      " << getArea() << '\n';
    }
private:
    // Store side lengths
    std::array<double, NUM_SIDES> m_sides {};

    // Override calculatePerimeter, to calculate perimeter of the trapezoid
    void calculatePerimeter() override
    {
        m_perimeter = std::accumulate(m_sides.begin(), m_sides.end(), 0.0);
    }

    // Override calculateArea, to calculate area of the trapezoid
    void calculateArea() override
    {
        // https://math.stackexchange.com/questions/2637690
        m_area = (m_sides[0] + m_sides[2]) / 2 * m_sides[1] * 
                 std::sqrt(1 - std::pow(((std::pow((m_sides[3] - m_sides[1]), 2) + std::pow(m_sides[1], 2) - std::pow(m_sides[3], 2)) / (2 * m_sides[1] * (m_sides[2] - m_sides[0]))), 2));
    }
};

int main()
{
    Triangle triangle {{3.0, 4.0, 5.0}};
    triangle.display();

    Rectangle rectangle {{1.0, 2.0, 1.0, 2.0}};
    rectangle.display();

    Trapezoid trapezoid {{1.0, 2.0, 3.0, 2.0}};
    trapezoid.display();

    try
    {
        Triangle invalidTriangle {{3.0, 4.0, 50.0}};
        invalidTriangle.display();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Rectangle invalidRectangle {{1.0, 2.0, 3.0, 4.0}};
        invalidRectangle.display();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

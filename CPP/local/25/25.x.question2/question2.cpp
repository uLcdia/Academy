// https://www.learncpp.com/cpp-tutorial/chapter-25-summary-and-quiz/

#include <iostream>
#include <vector>

class Point
{
private:
	int m_x{};
	int m_y{};

public:
	Point(int x = 0, int y = 0)
		: m_x{ x }, m_y{ y }
    {}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};

class Shape
{
public:
    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Shape& shape)
    {
        return shape.print(out);
    }

    virtual ~Shape() = default;
};

class Circle : public Shape
{
public:
    Circle(const Point& origin, const int radius)
        : m_origin {origin}, m_radius {radius}
    {}

    std::ostream& print(std::ostream& out) const override
    {
        out << "Circle(" << m_origin << ", radius " << m_radius << ")"; 
        return out;
    }

    int getRadius() const {return m_radius;}

private:
    Point m_origin {};
    int m_radius {};
};

class Triangle : public Shape
{
public:
    Triangle(const Point& pointA, const Point& pointB, const Point& pointC)
        : m_pointA {pointA}, m_pointB {pointB}, m_pointC {pointC}
    {}

    std::ostream& print(std::ostream& out) const override
    {
        out << "Triangle(" << m_pointA << ", " << m_pointB << ", " << m_pointC << ")";
        return out;
    }

private:
    Point m_pointA {};
    Point m_pointB {};
    Point m_pointC {};
};

int getLargestRadius(const std::vector<Shape*>& vector)
{
    int largestRadius {0};

    for (const Shape* vp : vector)
    {
        if (auto* circlePointer {dynamic_cast<const Circle*>(vp)})
        {
            largestRadius = std::max(largestRadius, circlePointer->getRadius());
        }
    }

    return largestRadius;
}

int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

	// print each shape in vector v on its own line here
    for (const Shape* vp : v)
    {
        std::cout << *vp << std::endl;
    }

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here
	/* 
    delete dynamic_cast<Circle*>(v[0]);
	delete dynamic_cast<Triangle*>(v[1]);
	delete dynamic_cast<Circle*>(v[2]);
    */
    for (const auto* vp : v)
    {
        delete vp;
    }

	return 0;
}
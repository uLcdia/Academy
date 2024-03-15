// https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/

#include <iostream>

class Point3d
{
private:
    int m_x {};
    int m_y {};
    int m_z {};
    bool initialized {};

public:
    void setValues(const int x, const int y, const int z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
        initialized = true;
    }

    int print() const
    {
        if (!initialized)
        {
            return 1;
        }
        else
        {
            std::cout << '<' << m_x << ", " << m_y << ", " << m_z << ">\n";
            return 0;
        }
    }

    bool isEqual(const Point3d& comparand) const
    {
        return ((m_x == comparand.m_x) && (m_y == comparand.m_y) && (m_z == comparand.m_z));
    }
};

int main()
{
    Point3d point1;
    point1.setValues(1, 2, 3);

    /*
    if (point1.print())
    {
        std::cerr << "Assign values first.";
    }
    */

	Point3d point2{};
	point2.setValues(1, 2, 3);

	std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

	Point3d point3{};
	point3.setValues(3, 4, 5);

	std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";


    return 0;
}
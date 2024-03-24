#ifndef CALC_H
#define CALC_H

class Calc
{
public:
    Calc(double radius = 1.0) : m_radius{radius} {};

    // if declaration and definition not identical, e.g. remove const specifier: declaration is incompatible with "void Calc::print()"

    double getArea() const;
    double getVolume() const;
    void print() const;

    double getRadius() const {return m_radius;}
    void setRadius(double radius) {m_radius = radius;}

private:
    const double PI {3.14159};
    double m_radius {1.0};
};

#endif
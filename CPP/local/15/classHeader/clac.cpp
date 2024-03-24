#include "calc.h"
#include <iostream>
#include <cmath>

double Calc::getArea() const
{
    return (Calc::PI * std::pow(Calc::getRadius(), 2.0));
}

double Calc::getVolume() const
{
    return (4.0 / 3.0 * Calc::PI * std::pow(Calc::getRadius(), 3.0));
}

void Calc::print() const
{
    std::cout << "r: " << Calc::getRadius() << "\n"
                 "S: " << Calc::getArea() << "\n"
                 "V: " << Calc::getVolume() << "\n";
}
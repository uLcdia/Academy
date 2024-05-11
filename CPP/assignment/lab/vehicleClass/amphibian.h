#ifndef AMPHIBIAN_H
#define AMPHIBIAN_H

#include "car.h"
#include "ship.h"

class Amphibian : public Car, public Ship
{
public:
    enum class Flag {ROAD, WATER};

    Amphibian(int weight, int numOfPassenger)
        : Vehicle {weight, numOfPassenger}
        , Car {weight, numOfPassenger}
        , Ship {weight, numOfPassenger}      
    {}
    
    ~Amphibian() = default;

    void drive() const override
    {
        if (m_flag == Flag::ROAD)
            Car::drive();
        else // m_flag == Flag::WATER
            Ship::drive();
    }

    void setFlag(Flag flag)
    {
        m_flag = flag;
    }

private:
    Flag m_flag {Flag::ROAD}; // 0: road, 1: water
};

#endif
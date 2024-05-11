#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class Vehicle
{
public:
    Vehicle(int weight, int numOfPassenger)
        : m_weight {weight}, m_numOfPassenger {numOfPassenger}
    {}

    ~Vehicle() = default;

    virtual void drive() const= 0;

    int getWeight() const
    {
        return m_weight;
    }
    void setWeight(int weight)
    {
        m_weight = weight;
    }
    int getNum() const
    {
        return m_numOfPassenger;
    }
    void setNum(int numOfPassenger)
    {
        m_numOfPassenger = numOfPassenger;
    }

protected:
    int m_weight {}; // unit: ton
    int m_numOfPassenger {};
};

#endif
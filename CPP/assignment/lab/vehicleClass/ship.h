#ifndef SHIP_H
#define SHIP_H

#include "vehicle.h"

class Ship : virtual public Vehicle
{
public:
    Ship(int weight, int numOfPassenger)
        : Vehicle {weight, numOfPassenger}
    {}
    
    ~Ship() = default;

    void drive() const override
    {
        std::cout << "Ship sails on the water.\n";
    }

};

#endif
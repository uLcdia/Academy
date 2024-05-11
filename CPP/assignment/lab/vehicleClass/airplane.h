#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "vehicle.h"

class Airplane : public Vehicle
{
public:
    Airplane(int weight, int numOfPassenger)
        : Vehicle {weight, numOfPassenger}
    {}
    
    ~Airplane() = default;

    void drive() const override
    {
        std::cout << "Airplane flies in the air.\n";
    }
};

#endif
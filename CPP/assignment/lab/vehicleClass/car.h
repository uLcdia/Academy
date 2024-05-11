#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class Car : virtual public Vehicle
{
public:
    Car(int weight, int numOfPassenger)
        : Vehicle {weight, numOfPassenger}
    {}
    
    ~Car() = default;

    void drive() const override
    {
        std::cout << "Car drives on the road.\n";
    }
};

#endif
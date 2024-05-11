// Base class Vehicle, derived classes Car, Ship, Airplane, Amphibian
// Vehicle: weight, numOfPassenger; setWeight(), setNum(); virtual drive
// Car: drive() on road; Ship: drive() on water; Airplane: drive() in air; 
// Amphibian: setFlag() to determine road or water, call different drive()s

#include <iostream>

#include "airplane.h"   // for Airplane class
#include "amphibian.h"  // for Amphibian class
#include "car.h"        // for Car class
#include "ship.h"       // for Ship class
#include "vehicle.h"    // for Vehicle class (which is an abstract class)

int main()
{
    // Vehicle vehicleObj {1, 2}; // error: object of abstract class type "Vehicle" is not allowed

    Car car {2, 5};
    std::cout << "Subaru WRX STI: ";
    car.drive();

    Ship ship {52310, 2200};
    // simulating a shipwreck
    ship.setWeight(65535);
    ship.setNum(705);
    std::cout << "Titanic: ";
    ship.drive();

    Airplane airplane {42, 220};
    std::cout << "Wayfarer 515: ";
    airplane.drive();

    Amphibian amphibian {1, 4}; // default flag = Amphibian::Flag::ROAD
    std::cout << "Amphicar: ";
    amphibian.drive();
    amphibian.setFlag(Amphibian::Flag::WATER);
    std::cout << "Amphicar: ";
    amphibian.drive();

    return 0;
}
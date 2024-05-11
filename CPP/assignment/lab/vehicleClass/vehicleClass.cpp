// Base class Vehicle, derived classes Car, Ship, Airplane, Amphibian
// Vehicle: weight, numOfPassenger; setWeight(), setNum(); virtual drive
// Car: drive() on road; Ship: drive() on water; Airplane: drive() in air; 
// Amphibian: setFlag() to determine road or water, call different drive()s

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

int main()
{
    // Vehicle vehicleObj {1, 2}; // error: object of abstract class type "Vehicle" is not allowed

    Car subaruWrxSti {2, 5};
    std::cout << "Subaru WRX STI: ";
    subaruWrxSti.drive();

    Ship titanic {52310, 2200};
    titanic.setWeight(65535);
    titanic.setNum(705);
    std::cout << "Titanic: ";
    titanic.drive();

    Airplane wayfarer515 {42, 220};
    std::cout << "Boeing 737-900: ";
    wayfarer515.drive();

    Amphibian amphicar {1, 4};
    std::cout << "Amphicar: ";
    amphicar.drive();
    amphicar.setFlag(Amphibian::Flag::WATER);
    std::cout << "Amphicar: ";
    amphicar.drive();

    return 0;
}
// https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/

#include <iostream>

class IHouse // an interface class
{
public:
    virtual void printHouse() const = 0;
    virtual void printSeat() const = 0;
};

void IHouse::printSeat() const // it's possible to define a pure virtual function
{
    std::cout << "No seat\n";
}

class Lannister : public IHouse
{
public:
    void printHouse() const override {std::cout << "House Lannister\n";}
    void printSeat() const override {std::cout << "Casterly Rock\n";}
};

class Stark : public IHouse
{
public:
    void printHouse() const override {std::cout << "House Stark\n";}
    void printSeat() const override {std::cout << "Winterfell\n";}
};

class Trump : public IHouse
{
public:
    void printHouse() const override {std::cout << "House Trump\n";}
    void printSeat() const override {IHouse::printSeat();}
};

void print(const IHouse& house)
{
    house.printHouse();
    house.printSeat();
}

int main()
{
    Lannister tyrion {};
    print(tyrion);

    Stark sansa {};
    print(sansa);

    Trump donald {};
    print(donald);

    return 0;
}
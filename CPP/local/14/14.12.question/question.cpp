// https://www.learncpp.com/cpp-tutorial/delegating-constructors/

#include <iostream>
#include <string>

class Car
{
public:
    Car() = default;

    Car(std::string model, int horsepower = 949)
        : m_model {model}
        , m_horsepower {horsepower}
    {}

    Car(int horsepower)
        : Car{"Subaru WRX STI", horsepower}
    {}
    
    const std::string& getModel() const {return (m_model);}
    int getHorsepower() const {return m_horsepower;}

private:
    std::string m_model {"Mercedes AMG One"};
    int m_horsepower {1049};
};

void printCar(Car& source)
{
    std::cout << source.getModel() << ": " << source.getHorsepower() << "hp.\n";
}

void printCarValue(Car source)
{
    std::cout << source.getModel() << ": " << source.getHorsepower() << "hp.\n";
}

Car getMustang()
{
    return {"Ford Mustang Shelby GT500 1967", 355};
}

int main()
{
    Car mercedes {};                            // {"Mercedes AMG One", 1049}
    Car subaru {310};                           // {"Subaru WRX STI", 310}
    Car ferarri {"Ferrari LaFerrari"};          // {"Ferrari LaFerrari", 949}
    Car porsche {"Porsche 911 GT3 RS", 518};    // {"Porsche 911 GT3 RS", 518}

    printCar(mercedes);
    printCar(subaru);
    printCar(ferarri);
    printCar(porsche);

    // temporary class objects
    // this passes a rvalue expression which can not be used as reference; printCar() error: initial value of reference to non-const must be an lvalue
    printCarValue(Car {"Mitsubishi Lancer Evolution X", 291});
    printCarValue({"Mazda MX-5 Miata 1990", 116});

    Car ford {getMustang()};
    printCar(ford);
    printCarValue(getMustang());

    return 0;
}
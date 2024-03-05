// https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/

#include "games.h"
#include "../multipleFiles/multipleFilesFoo.h"
#include "realMath.h"
#include <iostream>

int main()
{
    // realMath.h
    std::cout << "realMath.h" << std::endl;
    constexpr double pi { RealMath::pi };
    constexpr int one { RealMath::one };
    std::cout << "pi: " << pi << " one: " << one << std::endl;
    
    // ../multipleFiles/multipleFilesFoo.h
    // multipleFilesFoo.cpp is not compiled with this main.cpp, so functions declared in multipleFilesFoo.h have no definition thus they won't work
    std::cout << std::endl << "../multipleFiles/multipleFilesFoo.h" << std::endl;
    std::cout << "testvalue = " << Foo::testValue << std::endl;

    // games.h
    std::cout << std::endl << "games.h" << std::endl;

    // Persona
    std::cout << "Persona namespace" << std::endl;
    Persona::summon();
    std::cout << "Persona::testFunction(Persona::makoto, Persona::yu) = " << Persona::testFunction(Persona::makoto, Persona::yu) << std::endl;
    std::cout << "testValue = " << Persona::testValue << std::endl;

    // Witcher
    std::cout << std::endl << "Witcher namespace" << std::endl;
    std::cout << "Witcher::testFunction(Persona::makoto, Witcher::geralt) = " << Witcher::testFunction(Persona::makoto, Witcher::geralt) << std::endl;
    std::cout << "testValue = " << Witcher::testValue << std::endl;

    // Witcher::WitcherIII
    std::cout << std::endl << "Witcher::WitcherIII namespace" << std::endl;
    std::cout << "Witcher::WitcherIII::testFunction(Persona::makoto, Witcher::WitcherIII:testValue) = " << Witcher::WitcherIII::testFunction(Persona::makoto, Witcher::WitcherIII::testValue) << std::endl;

    return 0;
}

// global namespace
// this function is called by Persona::summon() in persona.cpp, defined in games.h
void print()
{
    std::cout << "Orpheus!" << std::endl;
}
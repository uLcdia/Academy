#include "colors.h"
#include <iostream>

void games(Color source)
{
    using enum Color;   // otherwise use Color::xxx
    switch (source)
    {
        case red:
            std::cout << "Red Dead Redemption is red.\n";
            break;
        case green:
            std::cout << "Grand Theft Auto V is green.\n";
            break;
        case blue:
            std::cout << "Persona 3 is blue.\n";
            break;
        default:
            break;
    }
}
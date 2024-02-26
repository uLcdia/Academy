#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants
{
    // OPTION_1
    inline constexpr double gravity { 9.8 };   // inline constexpr: 1.avoids both ODR violations and the downside of duplicated variables 2. compile-time const which helps with optimization;

    /*  // OPTION_2
    // extern definition in cpp, so each #include won't bring another definition, const instantiated only once
    // why even #include this header: consider there's many cpp and you don't have to forward declare every single one varaibles and functions, you can just #include this header
    extern const double gravity;    // defined in physics.cpp
    */
}

double timeToFall(double height, double gravity);

#endif
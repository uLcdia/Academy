// https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/

#include <iostream>

void foo()
{
    // Distance oregon {0.0};  // you can't use type alias Distance which is defined in main(), out of scope here
    return;
}

int main()
{
    using Distance = double;        // name type aliases starting with a capital letter and no suffix (suffix = _t, _type ...)
    // typedef double Distance      // typedef: the old way, prefer type aliases over typedefs
    Distance california {11364.0};  // name variables and functions starting with a lower case letter

    using FlightDurationHour = double;  // you can create multiple aliases for the same type
    FlightDurationHour californiaFlight {12.67};

    // california = californiaFlight;  // you can also do this, although meaningless

    std::cout << california << " " << californiaFlight << '\n';

    return 0;
}
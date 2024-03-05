// https://www.learncpp.com/cpp-tutorial/why-non-const-global-variables-are-evil/
// https://www.learncpp.com/cpp-tutorial/sharing-global-constants-across-multiple-files-using-inline-variables/

#include <iostream>
#include "physics.h"

int main()
{
    std::cout << timeToFall(20.0, constants::gravity) << "\0";
    return 0;
}
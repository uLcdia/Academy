// https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
// Forward declaration of content in namespaces

#include <iostream>
#include "multipleFilesFoo.h"

int main()
{
    std::cout << Foo::add(1,1);
    return 0;
}
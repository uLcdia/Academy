// https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators/

#include <iostream>
#include <vector>
#include <cassert>

namespace Students
{
    enum Names // even though Names enum is placed in Students namespace, it's still called an unscoped enum, for it's polluting Students namespace
    {
        stan,
        cartman,
        kyle,
        kenny,
        max_students
    };
}

enum class StudentNames : std::size_t // we specify StudentNames enum to use std::size_t as its underlying type, which doesn't change how the compiler will react
{
    stan,
    cartman,
    kyle,
    kenny,
    max_students
};

int main()
{
    std::vector testScores {90, 0, 80, 70};
    assert(testScores.size() == Students::max_students);
    std::cout << testScores[Students::stan] << '\n';
    
    // assert(std::ssize(testScores) == StudentNames::max_students);
    // std::cout << testScores[StudentNames::cartman] << '\n'; 
    // error: invalid operands to binary expression ('common_type_t<ptrdiff_t, make_signed_t<decltype(__cont.size())>>' (aka 'long long') and 'StudentNames')
    // Even though StudentNames has std::size_t as its underlying type, it's still a distinct type from std::size_t. C++ is a strongly typed language, and it doesn't automatically convert enum class types to their underlying types. This is one of the features of enum class that helps prevent bugs.
    assert(testScores.size() == static_cast<std::size_t>(StudentNames::max_students));
    std::cout << testScores[static_cast<int>(StudentNames::cartman)];
    
    return 0;
}
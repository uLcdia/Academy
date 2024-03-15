// https://www.learncpp.com/cpp-tutorial/const-class-objects-and-const-member-functions/

#include <iostream>
#include <string_view>

struct Name
{
    std::string_view firstName {};
    std::string_view lastName {};

    // A member function that does not (and will not ever) modify the state of the object should be made const, so that it can be called on both const and non-const objects.
    void printName() const
    {
        std::cout << "His name is " << firstName << ' ' << lastName << '\n';
    }

    void printNameNonConst()
    {
        std::cout << "His name is " << firstName << ' ' << lastName << '\n';
    }
};

void hailSir(const Name& source)
{
    source.printName();
    // source.printNameNonConst();  // the object has type qualifiers that are not compatible with the member function "Name::printNameNonConst"
}

int main()
{
    using namespace std::string_view_literals;
    const Name theOne {"Robert"sv, "Paulson"sv};

    hailSir(theOne);

    return 0;
}
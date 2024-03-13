// https://www.learncpp.com/cpp-tutorial/class-templates/

#include <iostream>
#include <string>

using namespace std::string_literals;

template <typename T = int> // set default type
struct Foo
{
    struct Twin
    {
        T a {};
        T b {};
    };              // Twin is a struct type (program-defined type)
    Twin twin {};   // twin is a Twin
    /*              // another way to create twin, not recommended though
    struct
    {
        T a {};
        T b {};
    } twin;
    */
    std::string dialogue {"Let me guess, someone stole your sweet roll?"};  // always std::string
};

template <typename T>
constexpr T max(const Foo<T>& source)
{
    return (source.twin.a < source.twin.b ? source.twin.b : source.twin.a); // you access source.twin but not source.Twin
}

int main()
{
    Foo<int> intTwin {{10, 20}};
    Foo intFoo {{100, 200}}; // if no default type set in template above: clang: cannot deduce class template arguments; Class template argument deduction (CTAD) C++17
    std::cout << "intTwin: " << intTwin.twin.a << ' ' << intTwin.twin.b << " max: " << max(intTwin);  // can max<int>(intTwin);
    
    using Loc = Foo<int>;

    Loc locFoo {{60, 120}, "No lollygagging."};

    return 0;
}
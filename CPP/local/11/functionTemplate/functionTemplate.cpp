// https://www.learncpp.com/cpp-tutorial/function-template-instantiation/

#include <iostream>

template <typename TValue>
void print(TValue x)
{
    std::cout << x << '\n';
}

template <>
void print(bool) = delete;   // you can also delete a template function // function "print(bool x)" (declared at line 10) cannot be referenced -- it is a deleted function

template <typename TNum>
TNum increment(TNum x)
{
    return (x + 1);
}

template <typename TNum>
TNum add(TNum x, TNum y)
{
    print("Using add<TNum>(TNum x, TNum y): ");
    return (x + y);
}

/*
template <typename TNum>
double add(TNum x, double y)    // you can mix type template and non-template parameters
{
    print("Using add<TNum>(TNum x, double y): ");
    return (static_cast<double>(x) + y);
}
*/

/*
template <typename T, typename U>
auto add(T x, U y)
{
    print("Using add(T x, U y): ");
    return (x + y);
}
*/

// Abbreviated function templates
auto add(auto x, auto y)
{
    print("Using add(auto x, auto y): ");
    return (x + y);
}

void print(bool x)
{
    std::cout << std::boolalpha << x << '\n';
}

int main()
{
    print(add<int>(1, 2));
    print(add<>(3, 4));
    print(add(5, 6));    // prefer add(5, 6)

    print(add(1, 0));
    print(add(1.0, 0));
    print(add(1, 1.0));
    
    // first 1.0: (TNum -> double); (second 1.0: (double) / (TNum -> double)): (double == double)
    // print(add(1.0, 1.0));   // error: call to 'add' is ambiguous: argument types are: (double, double)

    using namespace std::string_literals;
    print(add("Orpheus"s, "Telos"s));

    print(increment(1));
    // print(increment("Persona"s));   // invalid operands to binary expression ('std::basic_string<char>' and 'int')

    print(1.0);     // use print<double>(double x)
    print(true);    // use print(bool x)

    return 0;
}
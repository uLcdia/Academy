// https://www.learncpp.com/cpp-tutorial/introduction-to-containers-and-arrays/
// https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/
// https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem/
// https://www.learncpp.com/cpp-tutorial/passing-stdvector/
// https://www.learncpp.com/cpp-tutorial/returning-stdvector-and-an-introduction-to-move-semantics/

#include <iostream>
#include <vector>
#include <cassert>

class FooVector // initialization in class
{
public:
private:
    // std::vector m_v1 {1, 2, 3}; // error: use of class template 'vector' requires template arguments; argument deduction not allowed in non-static class member
    std::vector<int> m_v2 {1, 2, 3};
    //std::vector<int> m_v3(5); // error: expected parameter declarator; direct initialization not allowed for member default initializers
    std::vector<int> m_v4 {std::vector<int>(5)}; // creates an anonymous std::vector, then copy initialize m_v4

    // static constexpr std::vector<int> s_v1 {0, 1, 2}; // error: constexpr variable 's_v' must be initialized by a constant expression
    // static const std::vector s_v2 {0, 1, 2}; // error: a member of type "const std::vector<int, std::allocator<int>>" cannot have an in-class initializer
    // static std::vector s_v3; // error: declaration of variable 's_v' with deduced type 'std::vector' requires an initializer
    // static constexpr std::vector<int> s_v4 {0, 1, 2};
    static inline std::vector<int> s_v5 {0, 1, 2};
};
// std::vector FooVector::s_v3 {0, 1, 2};

auto foo(const auto& source, std::size_t index) // argument source passed by const reference, return value passed by value (using move semantic)
{
    assert((index < source.size()) && "Index out of bound.");
    std::cout << source[index] << '\n';
    return source;
}

auto calculateAverage(const auto& source, std::size_t num)
{
    assert((num == source.size()) && "num doesn't match.");

    double average {};
    for(std::size_t i = 0; i < num; i++)
    {
        average += source[i];
    }

    return (average / num);
}


int main()
{
    // creation and initialization
    // std::vector empty {}; // no instance of constructor "std::vector" matches the argument list
    std::vector<int> empty {};
    std::vector v1 {1, 2, 3, 4, 5};
    std::vector<int> v2(5); // creates v2 {0, 0, 0, 0, 0}


    // size
    std::cout << "size: \n";
    std::cout << "v1.size(): " << v1.size() << '\n';
    std::cout << "std::size(v1): " << std::size(v1) << '\n';
    std::cout << "std::ssize(v1): " << std::ssize(v1) << '\n';
    auto ss {std::ssize(v1)};
    std::cout << "auto ss {std::ssize(v1)}: " << ss << '\n';
    std::cout << "sizeof(ss): " << sizeof(ss) << '\n';


    // passing
    std::cout << "passing: \n";
    std::vector v3 {foo(v1, 0)};
    std::vector<int> v4 {foo(v1, 0)};
    // std::vector<double> v5 {foo(v1, 0)}; // error: no matching constructor for initialization of 'std::vector<double>'
    auto v6 {foo(v1, 0)};
    // foo(v6, 5); // Assertion failed: (index < source.size()) && "Index out of bound."

    // loop
    std::vector v7 {0, 1, 2, 3, 4};
    std::cout << "loop: ";
    std::cout << "calculateAverage(v7, 5) = " << calculateAverage(v7, 5) << '\n';

    return 0;
}
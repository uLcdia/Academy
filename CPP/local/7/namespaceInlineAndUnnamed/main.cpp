// https://www.learncpp.com/cpp-tutorial/unnamed-and-inline-namespaces/

#include <iostream>

namespace NamespaceRegular
{
    void persona()
    {
        std::cout << "Orpheus!\n";
    }
}

inline namespace NamespaceInline    // external linkage, but can be accessed without NamespaceInline:: prefix
{
    void persona()
    {
        std::cout << "Messiah!\n";
    }
}

/*
namespace   // unnamed (anonymous) namespace    // internal linkage, no namespace:: prefix
{
    void persona()
    {
        std::cout << "Orpheus Telos!\n";
    }
}
*/

void callPersona(); // from anotherFile.cpp

int main()
{
    std::cout << "regular: ";
    NamespaceRegular::persona();

    std::cout << "inline: ";
    NamespaceInline::persona();

    std::cout << "w/o namespace: ";
    persona(); // more than one instance of overloaded function "persona" matches the argument list // functions from both inline namespace and unnamed namespace can be called without namespace:: prefix

    std::cout << "call function within inline namespace from another file: ";
    callPersona();

    return 0;
}
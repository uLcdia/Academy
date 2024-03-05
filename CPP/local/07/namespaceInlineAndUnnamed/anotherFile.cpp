#include <iostream>

inline namespace NamespaceInline    // external linkage, but can be accessed without NamespaceInline:: prefix
{
    void persona(); // defined in the same namespace in main.cpp
}

void callPersona()
{
    persona();  // can be used without NamespaceInline:: prefix
}
#include <iostream>

[[maybe_unused]] constexpr int constexprIntFoo { 1 };       // constexpr internal by default
[[maybe_unused]] const int constIntFoo { 3 };               // const internal by default
[[maybe_unused]] static int staticIntFoo { 5 };             // int is extern by default, static makes its linkage internal

int intX { 7 };                                             // don't write extern, it's extern by default
// extern constexpr int constexprIntY { 9 };                // don't extern a constexpr, the constexpr value should be known by compiler not linker
extern const int constIntZ { 11 };                          // internal linkage by default, extern to make it external

void sayHola()
{
    std::cout << "Hola DEA\n";
}

[[maybe_unused]] static void megidolaon()
{
    std::cout << "Megidolaon\n";
}
// https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/
// Literals for std::string

#include <iostream>
#include <string>

int main()
{
    // https://learn.microsoft.com/en-us/cpp/cpp/string-and-character-literals-cpp?view=msvc-170
    using namespace std::string_literals; // using namespace std::literals::string_literals;
    using namespace std::string_view_literals; // using namespace std::literals::string_view_literals;


    std::string string1 { "Megido" };
    std::string string2 { "Megidola"s };
    std::string string3 { static_cast<std::string>("Megidolaon") };
    
    char charArray[15] { "Kotone" };

    std::cout << string1 << " " << string1.length() << std::endl;
    std::cout << string2 << " " << string2.length() << std::endl;
    std::cout << string3 << " " << string3.length() << std::endl;

    std::cout << charArray << " " << sizeof(charArray) / sizeof(charArray[0]) << std::endl;

    return 0;
}
#include <iostream>
#include <string>

void stringToUpper(std::string& string)
{
    for (auto& ch : string)
    {
        if (std::islower(ch))
        {
            ch = ch + 'A' - 'a';
        }
    }
}

int main()
{
    std::string string {};
    std::cin >> string;

    stringToUpper(string);

    std::cout << string;

    return 0;
}
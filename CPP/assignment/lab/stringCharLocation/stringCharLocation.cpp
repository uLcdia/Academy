// input: str (with length < 30), ch; use pointer to find location and count occurance

#include <iostream>
#include <string>

int main()
{
    std::string input;
    char ch;
    std::getline(std::cin, input, ' ');
    std::cin >> ch;

    bool found = false;
    for (size_t i = 0; i < input.size(); ++i)
    {
        if (*(input.data() + i) == ch)
        {
            std::cout << i << ' ';
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "NULL";
    }

    return 0;
}
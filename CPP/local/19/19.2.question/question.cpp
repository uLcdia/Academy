// https://www.learncpp.com/cpp-tutorial/dynamically-allocating-arrays/

#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::cout << "How many names would you like to enter? ";
    size_t length {};
    std::cin >> length;
    std::string* array {new (std::nothrow) std::string[length] {}};
    if (!array)
    {
        std::cerr << "Could not allocate memory." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    for (size_t i {0}; i < length; i++)
    {
        std::cout << "Enter name #" << i << ": ";
        std::getline(std::cin >> std::ws, array[i]);
    }

    std::sort(array, array + length);
    std::cout << "Here is your sorted list: " << std::endl;
    for (size_t i {0}; i < length; i++)
    {
        std::cout << "Name #" << i << ": " << array[i] << '\n';
    }

    delete[] array;
    array = nullptr;

    return 0;
}
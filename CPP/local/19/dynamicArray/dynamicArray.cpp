// https://www.learncpp.com/cpp-tutorial/dynamically-allocating-arrays/

#include <iostream>

int main()
{
    size_t length {};
    std::cin >> length;

    [[maybe_unused]] int* array {new int [length] {}};

    system("pause");

    delete[] array;
    array = nullptr;

    return 0;
}
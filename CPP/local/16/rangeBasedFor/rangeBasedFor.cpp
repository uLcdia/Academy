// https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each/

#include <iostream>
#include <vector>
#include <ranges> // for std::views

void printIntArray(const std::vector<int>& source)
{
    for (int num : source)
    {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

template <typename T>
void printTArray(const std::vector<T>& source)
{
    for (T num : source)
    {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

void printAutoArray(const auto& source)
{
    for (auto num : source) // num copies source[N] in every Nth loops, same goes above
    {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

void printArray(const auto& source)
{
    for (const auto& num : source) // prefered way; makes num a reference, keeps code tidy
    {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

void printArrayReversed(const auto& source)
{
    for (const auto& num : std::views::reverse(source)) // prints source in reversed order, using std::views::reverse from ranges library in c++20
    {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::vector array {0, 1, 2, 3, 4};

    printIntArray(array);
    printTArray(array);
    printAutoArray(array);
    printArray(array);
    printArrayReversed(array);

    return 0;
}
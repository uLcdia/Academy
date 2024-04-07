// https://www.learncpp.com/cpp-tutorial/stdvector-resizing-and-capacity/

#include <iostream>
#include <vector>

void printSize(const auto& source)
{
    std::cout << "Size: " << source.size() << "  Capacity: " << source.capacity() << '\n'; // size and length both mean the number of elements in the vector or array. 
    // The official term used in the C++ Standard Library is "size". The term "length" is used in some other programming languages and in some contexts in C++ (like std::string::length()), but when talking about a std::vector or array in C++, the correct term is "size".
}

void printArray(const auto& source)
{
    for (const auto& item : source)
    {
        std::cout << item << ' ';
    }
    std::cout << '\n';
}

void resizeArray(auto& source, size_t size)
{
    size_t originalSize {source.size()};
    source.resize(size); // Change size
    std::cout << "resizeArray(source, " << size << ") ";
    std::cout << "from " << originalSize << " to " << source.size() << '\n';
}

int main()
{
    std::vector v1 {0, 1, 2};

    printSize(v1);
    printArray(v1); // 0 1 2

    resizeArray(v1, 5);
    printSize(v1); // Size: 3  Capacity: 6 // GCC and Clang doubles the current capacity. VS multiplies the current capacity by 1.5.
    printArray(v1); // 0 1 2 0 0

    resizeArray(v1, 2);
    printSize(v1);
    printArray(v1); // 0 1

    resizeArray(v1, 3);
    printSize(v1);
    printArray(v1); // 0 1 0

    std::cout << "v1.shrink_to_fit()\n";
    v1.shrink_to_fit();
    printSize(v1);
    printArray(v1); // 0 1 0

    std::cout << "v1.reserve(5)\n";
    // std::vector::reserve // Request a change in capacity // Requests that the vector capacity be at least enough to contain n elements.
    // If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).
    // In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.
    // This function has no effect on the vector size and cannot alter its elements.
    v1.reserve(5); // Size: 3  Capacity: 5 // reallocation
    printSize(v1);
    printArray(v1);

    v1.reserve(4); // Size: 3  Capacity: 5 // no reallocation
    printSize(v1);
    printArray(v1);

    return 0;
}

// Reallocation is typically expensive. Avoid unnecessary reallocations.
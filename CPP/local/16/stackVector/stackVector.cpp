// https://www.learncpp.com/cpp-tutorial/stdvector-and-stack-behavior/

#include <iostream>
#include <vector>

void printStack(const auto& source)
{
    if (source.empty()) // = source.size() == 0
    {
        std::cout << "empty";
    }
    else
    {
        for (const auto& item : source)
        {
            std::cout << item << ' ';
        }
    }

    std::cout << "\tSize: " << source.size() << "  Capacity: " << source.capacity() << '\n';
}

int main()
{
    std::vector<int> stackVector {3}; // creates a empty stack based on vector

    stackVector.pop_back(); // Delete last element; No return value // no reallocation // capacity: 1
    printStack(stackVector);

//     stackVector.pop_back(); // can not delete last element of an empty vector, undefined results
//     printStack(stackVector); // outputs a bunch of bizarre numbers.

    stackVector.push_back(0); // Add element 0 at the end           // no reallocation // capacity: 1
    printStack(stackVector);
    stackVector.push_back(1); // Add element 1 at the end           // reallocation    // capacity: 1 -> 2
    printStack(stackVector);
    stackVector.push_back(2); // Add element 2 at the end           // reallocation    // capacity: 2 -> 4
    printStack(stackVector);  // 0 1 2   Size: 3  Capacity: 4

    stackVector.push_back(3); // Add element 2 at the end           // no reallocation // capacity: 4 // Size: 4  Capacity: 4 full

    // use std::vector::reserve properly to avoid unnecessary reallocation
    stackVector.reserve(6);   // Requests that the vector capacity be at least enough to contain 6 elements. // reallocation // capacity: 4 -> 6
    stackVector.push_back(4); // Add element 4 at the end           // no reallocation // capacity: 6 

    stackVector.emplace_back(5); // Construct and insert element at the end
    // Best practice // https://abseil.io/tips/112
    // Prefer emplace_back() when creating a new temporary object to add to the container, or when you need to access an explicit constructor.
    // Prefer push_back() otherwise.
    // https://stackoverflow.com/questions/4303513/push-back-vs-emplace-back
    // https://stackoverflow.com/questions/10890653/why-would-i-ever-use-push-back-instead-of-emplace-back

    std::cout << stackVector.front() << ' '; // Access first element
    std::cout << stackVector.back() << '\n'; // Access last element

    return 0;
}
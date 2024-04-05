// https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/

#include <iostream>
#include <vector>

/*
 * Using an unsigned loop variable
 * Many developers believe that since the standard library array types were designed to use unsigned indices, 
 * then we should use unsigned indices! This is a completely reasonable position. 
 * We just need to be extra careful that we do not run into signed/unsigned mismatches when doing so. 
 * If possible, avoid using the index loop variable for anything but indexing.
 */

template <typename T>
void printUnsignedTemplate(const T& source) // alternative approach: replace all T with std::vector<T>
{
    for (typename T::size_type index {0}; index < source.size(); index++)
    {
        std::cout << source[index] << ' ';
    }
    std::cout << '\n';
}

void printIntUnsigned(const std::vector<int>& source)
{
    for (size_t index {0}; index < source.size(); index++)
    {
        std::cout << source[index] << ' ';
    }
    std::cout << '\n';
}

/*
 * Using a signed loop variable
 * Although it makes working with the standard library container types a bit more difficult, 
 * using a signed loop variable is consistent with the best practices employed in the rest of our code (to favor signed values for quantities). 
 * And the more we can consistently apply our best practices, the fewer errors we will have overall.
 */

void printIntSigned(const std::vector<int>& source) // with a very large array, use std::ptrdiff_t instead of int
{
    // int length = static_cast<int>(source.size()); // before c++20
    for (int index {0}; index < std::ssize(source); index++) // index < length before c++20
    {
        std::cout << source[static_cast<std::size_t>(index)] << ' '; // strangely source[index] doesn't give me any warning
    }
    std::cout << '\n';
}


int main()
{
    std::vector v1 {0, 1, 2, 3, 4};

    printIntUnsigned(v1);
    printUnsignedTemplate(v1);

    printIntSigned(v1);

    return 0;
}

/* 
The only sane choice: avoid indexing altogether!
If you’re only using the index variable to traverse the array, then prefer a method that does not use indices.
Best practice
Avoid array indexing with integral values whenever possible.
 */
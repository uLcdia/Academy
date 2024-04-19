// https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

void find()
{
    constexpr std::array a {1, 9, 2, 8, 0};
    auto find {2};
    auto found {std::ranges::find(a, find)}; // Return iterator to the first element satisfying the condition or iterator equal to last if no such element is found. 
    if (found == std::end(a))
    {
        std::cout << find << " not found. " << std::endl;
    }
    else
    {
        auto index {std::distance(std::begin(a), found)}; // return std::ptrdiff_t
        std::cout << "found " << find << " at index " << index << ' ' << std::endl;
    }
}

bool isEven(int x)
{
    return x % 2 == 0;
}

void findIf()
{
    constexpr std::array a {1, 9, 2, 8, 0};
    auto found {std::ranges::find_if(a, isEven)};
    if (found == a.end())
    {
        std::cout << "even number not found. " << std::endl;
    }
    else
    {
        std::cout << "found " << *found << " at index " << (std::distance(a.begin(), found)) << ". " << std::endl;
    }
    found = std::find_if_not(a.begin(), a.end(), isEven);
    if (found == a.end())
    {
        std::cout << "odd number not found. " << std::endl;
    }
    else
    {
        std::cout << "found " << *found << " at index " << (std::distance(a.begin(), found)) << ". " << std::endl;
    }
}

void printEach(int source)
{
    std::cout << source << ' ';
}

template <typename T>
void print(std::vector<T> source)
{
    std::ranges::for_each(source, printEach);
    std::cout << std::endl;
}

template <typename T>
int replace(std::vector<T> vector, T before, T after)
{
    std::cout << "before: ";
    print(vector);
    int count = std::ranges::count(vector, before);
    if (count != 0)
    {
        std::ranges::replace(vector, before, after);
    }
    std::cout << "after:  ";
    print(vector);
    return count;
}

bool isBigger(int a, int b)
{
    return (a > b);
}

void sort()
{
    std::vector v {1, 9, 2, 8, 0};
    std::cout << "original: ";
    print(v);
    std::ranges::sort(v);
    std::cout << "ascending:  ";
    print(v);
    std::ranges::sort(v, isBigger);
    std::cout << "descending:  ";
    print(v);
}

// according to ChatGPT, many algorithms operate with a sequential execution policy (std::execution::seq) by default if no execution policy is specified explicitly. Check https://en.cppreference.com/w/cpp/algorithm/execution_policy_tag_t
// ChatGPT: It's generally safe to assume that algorithms with a sequential execution policy (std::execution::seq) will operate sequentially. However, it's essential to understand the semantics of the algorithms you're using and ensure that your assumptions are valid.
// learncpp: most algorithms provide some kind of performance guarantee, fewer have order of execution guarantees. For such algorithms, we need to be careful not to make assumptions about the order in which elements will be accessed or processed.
// CHECK REFERENCE BEFORE USING ALGORITHMS

int main()
{
    sort();

    return 0;
}
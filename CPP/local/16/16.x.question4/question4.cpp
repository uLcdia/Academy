// https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz/

#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
class Array
{
public:
    void getVector()
    {
        std::cout << "Begin input: \n";
        T item {};
        while (item != -1)
        {
            std::cin >> item;
            array_m.emplace_back(item);
        }
        array_m.pop_back();
        assert(std::ssize(array_m) > 1 && "Array too small.");
    }

    void print() const
    {
        printArray();
        printMin();
        printMax();
    }

private:
    std::vector<T> array_m {};
    
    int getMin() const
    {
        int minIndex {0};
        for (int i {1}; i < std::ssize(array_m); i++)
        {
            if (array_m[minIndex] > array_m[i])
            {
                minIndex = i;
            }
        }
        return minIndex;
    }
    int getMax() const
    {
        int maxIndex {0};
        for (int i {1}; i < std::ssize(array_m); i++)
        {
            if (array_m[maxIndex] < array_m[i])
            {
                maxIndex = i;
            }
        }
        return maxIndex;
    }
    void printArray() const
    {
        std::cout << "With array ( " << array_m[0];
        for (int i {1}; i < std::ssize(array_m); i++)
        {
            std::cout << ", " << array_m[i];
        }
        std::cout << " ): \n";
    }
    void printMin() const
    {
        int minIndex {getMin()};
        std::cout << "The min element has index " << minIndex << " and value " << array_m[minIndex] << '\n';
    }
    void printMax() const
    {
        int maxIndex {getMax()};
        std::cout << "The max element has index " << maxIndex << " and value " << array_m[maxIndex] << '\n';
    }
};


int main()
{
    Array<int> array {};

    array.getVector();
    array.print();

    return 0;
}
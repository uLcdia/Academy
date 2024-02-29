// https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/

#include <iostream>
#include <random>

int * generateUniformRandomInt(int * numberList, int listSize);
int * generateNormalRandomInt(int * numberList, int listSize);
void outputInt(int * numberList, int listSize, int newlineCount);

int main()
{
    constexpr int listSize {60};
    constexpr int newlineCount {15};

    int uniformRandomInt[listSize] {};
    generateUniformRandomInt(uniformRandomInt, listSize);

    int normalRandomInt[listSize] {};
    generateNormalRandomInt(normalRandomInt, listSize);

    std::cout << "with uniform_int_distribution: \n";
    outputInt(uniformRandomInt, listSize, newlineCount);

    std::cout << "\nwithout uniform_int_distribution: \n";
    outputInt(normalRandomInt, listSize, newlineCount);

    return 0;
}

int * generateUniformRandomInt(int * numberList, int listSize)
{
    std::mt19937 mt {};
    std::uniform_int_distribution uniformRandomInt {0,9};

    for (int i = 0; i < listSize; i++)
    {
        numberList[i] = uniformRandomInt(mt);
    }

    return (numberList);
}

int * generateNormalRandomInt(int * numberList, int listSize)
{
    std::mt19937 mt {};
    // std::uniform_int_distribution uniformRandomInt {0,9};

    for (int i = 0; i < listSize; i++)
    {
        numberList[i] = mt() % 10;
    }

    return (numberList);
}

void outputInt(int * numberList, int listSize, int newlineCount)
{
    for (int i = 0, count = 1; i < listSize; i++, count++)
    {
        std::cout << numberList[i] << " ";
        
        if (count % newlineCount == 0)
        {
            std::cout << '\n';
        }
    }
}
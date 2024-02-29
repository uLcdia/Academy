// https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/

#include <iostream>
#include <random>
#include <chrono>   // for std::chrono

int * mt19937GetNormal(int * numberList, int listSize, std::mt19937 mt);
int * mt19937GetAlternative(int * numberList, int listSize, std::mt19937 mt);
int * randGet(int * numberList, int listSize);
void outputInt(int * numberList, int listSize, int newlineCount);

int main()
{
    constexpr int listSize {100000};
    [[maybe_unused]] constexpr int newlineCount {15};
    
    // Only seed a PRNG once
    // std::mt19937 mt {static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())};  // set seed using time. steady_clock has a more granular tick than time()
    std::mt19937 mt {std::random_device{}()}; // ask the OS for a random number. caution: std::random_device**{}**(), both curly braces and parentheses. 
    // Q: What does std::random_device{}() mean? // std::random_device{} creates a value-initialized temporary object of type std::random_device. The () then calls operator() on that temporary object, which returns a randomized value

    // testing random num generator executing duration (testing chrono, seems fun)

    int uniformRandomInt[listSize] {};
    mt19937GetNormal(uniformRandomInt, listSize, mt);       // 1,236,600ns  slowest, interesting

    int normalRandomInt[listSize] {};
    mt19937GetAlternative(normalRandomInt, listSize, mt);   // 440,400ns

    int randRandomInt[listSize] {};
    randGet(randRandomInt, listSize);                   // 1,021,200ns

/*
    std::cout << "with uniform_int_distribution: \n";
    outputInt(uniformRandomInt, listSize, newlineCount);

    std::cout << "\nwithout uniform_int_distribution: \n";
    outputInt(normalRandomInt, listSize, newlineCount);
*/

    return 0;
}

int * mt19937GetNormal(int * numberList, int listSize, std::mt19937 mt)
{
    const auto timeStart {std::chrono::steady_clock::now()};    // weird return type, use auto here. // https://en.cppreference.com/w/cpp/chrono/time_point

    std::uniform_int_distribution uniformRandomInt {0,9};

    for (int i = 0; i < listSize; i++)
    {
        numberList[i] = uniformRandomInt(mt);
    }

    const auto timeEnd {std::chrono::steady_clock::now()};

    std::cout << "Duration of mt19937_normal " << listSize << " numbers: " << (timeEnd - timeStart) << '\n';

    return (numberList);
}

int * mt19937GetAlternative(int * numberList, int listSize, std::mt19937 mt)
{
    const auto timeStart {std::chrono::steady_clock::now()};    // weird return type, use auto here. // https://en.cppreference.com/w/cpp/chrono/time_point

    // std::uniform_int_distribution uniformRandomInt {0,9};

    for (int i = 0; i < listSize; i++)
    {
        numberList[i] = mt() % 10;
    }

    const auto timeEnd {std::chrono::steady_clock::now()};

    std::cout << "Duration of mt19937_alt " << listSize << " numbers: " << (timeEnd - timeStart) << '\n';

    return (numberList);
}

int * randGet(int * numberList, int listSize)   // rand() is typically used in C
{
    const auto timeStart {std::chrono::steady_clock::now()};    // weird return type, use auto here. // https://en.cppreference.com/w/cpp/chrono/time_point

    std::srand(std::random_device{}());
    // std::uniform_int_distribution uniformRandomInt {0,9};

    for (int i = 0; i < listSize; i++)
    {
        numberList[i] = std::rand() % 10;
    }

    const auto timeEnd {std::chrono::steady_clock::now()};

    std::cout << "Duration of rand " << listSize << " numbers: " << (timeEnd - timeStart) << '\n';

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
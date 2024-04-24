// https://www.learncpp.com/cpp-tutorial/timing-your-code/

#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <numeric>
#include <string>

void sortAlgorithm()
{
    std::vector<int> v (30000);
    // std::iota() Fills the range [first, last) with sequentially increasing values, starting with value and repetitively evaluating ++value. 
    std::iota(v.rbegin(), v.rend(), 1); // rbegin() Returns a reverse iterator to the first element of the reversed array. rend() Returns a reverse iterator to the element following the last element of the reversed array.
    std::ranges::sort(v);
}

void sortBubble()
{
    std::vector<int> v (30000);
    // std::iota() Fills the range [first, last) with sequentially increasing values, starting with value and repetitively evaluating ++value. 
    std::iota(v.rbegin(), v.rend(), 1); // rbegin() Returns a reverse iterator to the first element of the reversed array. rend() Returns a reverse iterator to the element following the last element of the reversed array.

    bool isChanged {false};
    for (auto i {0}; i < std::ssize(v) - 1; i++)
    {
        isChanged = false;
        for (int j {0}; j < std::ssize(v) - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                std::swap(v[j], v[j + 1]);
                isChanged = true;
            }
        }
        if (!isChanged)
            break;
    }
}

class Timer
{
public:
    void reset() { m_begin = Clock::now(); }
    void printElapsed() const { std::cout << std::chrono::duration_cast<Second>(Clock::now() - m_begin) << std::endl; }
private:
    using Clock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1>>;
    std::chrono::time_point<Clock, Second> m_begin {Clock::now()};
};

void printString(std::string string)
{
    std::cout << string << std::endl;
}
void printStringView(std::string_view string)
{
    std::cout << string << std::endl;
}

int main()
{
    Timer t {};
    sortAlgorithm();
    t.printElapsed();

    t.reset();
    sortBubble();
    t.printElapsed();

    std::string s {"I've seen things you people wouldn't believe... Attack ships on fire off the shoulder of Orion... I watched C-beams glitter in the dark near the Tannhäuser Gate. All those moments will be lost in time, like tears in rain... Time to die."};

    t.reset();
    printString(s);
    t.printElapsed();

    t.reset();
    printStringView(s);
    t.printElapsed();

    return 0;
}
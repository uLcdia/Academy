// https://www.learncpp.com/cpp-tutorial/chapter-21-summary-and-quiz/

#include <iostream>
#include <cstdint>

class Average
{
public:
    Average& operator+= (int value)
    {
        m_sum += value;
        ++m_count;
        return *this;
    }
    friend std::ostream& operator<< (std::ostream& out, const Average& source);
private:
    std::int32_t m_sum {};
    std::int8_t m_count {};
};

std::ostream& operator<< (std::ostream& out, const Average& source)
{
    out << (static_cast<double>(source.m_sum) / static_cast<double>(source.m_count));
    return out;
}

int main()
{
	Average avg{};

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}
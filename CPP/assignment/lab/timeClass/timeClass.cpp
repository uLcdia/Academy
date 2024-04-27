// define class Time, including 3 member variables (hour, minute, second)
// input, output Time with << / >>
// add and subtract Time object with += / -=
// increment and decrement 1 second with ++ / --

#include <iostream>
#include <iomanip>

class Time
{
public:
    Time(int h = 0, int m = 0, int s = 0)
        : m_hour {h}, m_minute {m}, m_second {s}
    {
        amend();
    }

    friend std::ostream& operator<<(std::ostream& out, const Time& source);
    friend std::istream& operator>>(std::istream& in, Time& source);

    Time& operator+=(const Time& source);
    Time& operator-=(const Time& source);
    Time& operator++();
    Time& operator--();
    Time operator++(int);
    Time operator--(int);

private:
    int m_hour {};
    int m_minute {};
    int m_second {};

    static constexpr int s_secondsInMinute {60};
    static constexpr int s_minutesInHour {60};
    static constexpr int s_hoursInDay {24};
    
    void amend();
};
void normalize(int& larger, int& smaller, int unitsInLarger)
{
    larger += smaller / unitsInLarger;
    smaller %= unitsInLarger;
    if (smaller < 0)
    {
        smaller += unitsInLarger;
        --larger;
    }
}
void Time::amend()
{
    normalize(m_minute, m_second, s_secondsInMinute);
    normalize(m_hour, m_minute, s_minutesInHour);
    m_hour %= s_hoursInDay;
    if (m_hour < 0)
    {
        m_hour += s_hoursInDay;
    }
}
std::ostream& operator<<(std::ostream& out, const Time& source)
{
    out << std::setw(2) << std::setfill('0') <<  source.m_hour << ':'
        << std::setw(2) << std::setfill('0') <<  source.m_minute << ':'
        << std::setw(2) << std::setfill('0') <<  source.m_second;
    return out;
}
std::istream& operator>>(std::istream& in, Time& source)
{
    in >> source.m_hour >> source.m_minute >>  source.m_second;
    return in;
}
Time& Time::operator+=(const Time& source)
{
    m_hour += source.m_hour;
    m_minute += source.m_minute;
    m_second += source.m_second;
    amend();
    return *this;
}
Time& Time::operator-=(const Time& source)
{
    m_hour -= source.m_hour;
    m_minute -= source.m_minute;
    m_second -= source.m_second;
    amend();
    return *this;
}
Time& Time::operator++() // prefix ++time
{
    m_second++;
    amend();
    return *this;
}
Time Time::operator++(int) // postfix time++
{
    Time timeTemp = *this;
    ++(*this);
    return timeTemp;
}
Time& Time::operator--() // prefix --time
{
    m_second--;
    amend();
    return *this;
}
Time Time::operator--(int) // postfix time--
{
    Time timeTemp = *this;
    --(*this);
    return timeTemp;
}

int main()
{
    Time time1;
    Time time2;

    std::cin >> time1;
    std::cin >> time2;

    std::cout << (time1 += (time2++)) << std::endl;
    std::cout << (time1 -= time2) << std::endl;
    std::cout << (++time2) << std::endl;
    std::cout << (time2 += (time1--)) << std::endl;
    std::cout << (--time1) << std::endl;
    std::cout << (time2 -= time1) << std::endl;

    return 0;
}
// https://www.learncpp.com/cpp-tutorial/overloading-the-parenthesis-operator/

#include <iostream>
#include <string>
#include <cassert>

class CustomString
{
public:
    CustomString(std::string_view string) : m_string {string} {}

    friend std::ostream& operator<< (std::ostream& out, CustomString string);
    std::string_view operator() (size_t start, size_t length);
private:
    std::string m_string {};
};
std::ostream& operator<< (std::ostream& out, CustomString string)
{
    out << string.m_string;
    return out;
}
std::string_view CustomString::operator() (size_t start, size_t length)
{
    assert((start + length) <= m_string.size());
    return std::string_view(m_string).substr(start, length);
}

int main()
{
    CustomString kotone {"Kotone Shiomi"};
    
    std::cout << kotone(0, 6) << std::endl;

    return 0;
}
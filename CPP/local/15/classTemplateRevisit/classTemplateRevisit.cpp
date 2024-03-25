// https://www.learncpp.com/cpp-tutorial/class-templates-with-member-functions/

#include <iostream>

template <typename T>
class Pair
{
public:
    Pair(const T& first, const T& second)
        : m_first {first}, m_second{second}
    {}
    
    const T& getFirst() const {return m_first;}
    const T& getSecond() const {return m_second;}

    const T& getMax() const;
    bool isEqual(const Pair<T>& rival) const;
private:
    T m_first {};
    T m_second {};
};

// use const T&, we don't know whether T is expensive to copy or not, and we don't want to change it
// use Pair<T>& and Pair<T>::*, Pair<T> need to be specified, Pair doesn't make sense solely

// either define member function templates inside the class definition or define them just below the class definition (in the same file)
// functions implicitly instantiated from templates are implicitly inline

template <typename T>
const T& Pair<T>::getMax() const
{
    return ((m_first < m_second) ? m_second : m_first);
}

template <typename T>
const T& getMin(const Pair<T>& source)
{
    return ((source.getFirst() < source.getSecond()) ? source.getFirst() : source.getSecond());
}

template <typename T>
bool Pair<T>::isEqual(const Pair<T>& rival) const
{
    return ((m_first == rival.m_first) && (m_second == rival.m_second)); // can use rival.m_*, access control applies on class types not objects
}

int main()
{
    Pair pair {10, 20}; // Pair deduced to Pair<int>

    std::cout << pair.getMax() << '\n';
    std::cout << std::boolalpha;
    std::cout << pair.isEqual({50, 100}) << '\n';

    return 0;
}
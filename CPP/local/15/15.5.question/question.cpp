// https://www.learncpp.com/cpp-tutorial/class-templates-with-member-functions/

#include <iostream>
#include <string>

using namespace std::string_literals;

template <typename A, typename B, typename C>
class Triad
{
public:
    Triad(A a, B b, C c)
        : m_a {a}
        , m_b {b}
        , m_c {c}
    {}

    const A& first() const {return m_a;}
    const B& second() const {return m_b;}
    const C& third() const {return m_c;}

    void print() const;
private:
    A m_a {};
    B m_b {};
    C m_c {};
};

template <typename A, typename B, typename C>
void Triad<A, B, C>::print() const
{
    std::cout << "[" << m_a << ", " << m_b << ", " << m_c << "]\n";
}

int main()
{
    Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
	std::cout << t1.first() << '\n';

	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';

    return 0;
}
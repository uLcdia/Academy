// https://www.learncpp.com/cpp-tutorial/chapter-21-summary-and-quiz/

#include <iostream>
#include <cstdint>
#include <cmath>
#include <cassert>

class FixedPoint2
{
public:
    FixedPoint2(std::int16_t base, std::int8_t decimal)
        : m_base {base}
        , m_decimal {decimal}
    {
        if (m_base < 0 || m_decimal < 0)
        {
			if (m_base > 0)
				m_base = -m_base;
			if (m_decimal > 0)
				m_decimal = -m_decimal;
        }

        m_base += m_decimal / 100;
        m_decimal %= 100;
    }

    FixedPoint2(double number)
        : m_base {static_cast<std::int16_t>(number)}
        , m_decimal {static_cast<std::int8_t>(std::round(number * 100) - m_base * 100)}
    {}

    explicit operator double() const {return (m_base + m_decimal * 0.01);} // explicit disables implicit conversions
    
    FixedPoint2 operator- () const;

private:
    std::int16_t m_base {};
    std::int8_t m_decimal {};
};

std::ostream& operator<< (std::ostream& out, const FixedPoint2& source)
{
    out << static_cast<double>(source);
    return out;
}

std::istream& operator>> (std::istream& in, FixedPoint2& target)
{
    double temp {};
    in >> temp;
    target = FixedPoint2{temp};
    return in;
}

bool operator== (const FixedPoint2& lhs, const FixedPoint2& rhs)
{
    return static_cast<double>(lhs) == static_cast<double>(rhs);
}

FixedPoint2 FixedPoint2::operator- () const
{
    return FixedPoint2{static_cast<std::int16_t>(-m_base), static_cast<std::int8_t>(-m_decimal)}; // '-' promotes int type smaller than int (like std::int16_t or std::int8_t) to int
}

FixedPoint2 operator+ (const FixedPoint2& lhs, const FixedPoint2& rhs)
{
    return FixedPoint2{static_cast<double>(lhs) + static_cast<double>(rhs)};
}

int main()
{
	assert(FixedPoint2{ 0.75 } == FixedPoint2{ 0.75 });    // Test equality true
	assert(!(FixedPoint2{ 0.75 } == FixedPoint2{ 0.76 })); // Test equality false

	// Test additional cases -- h/t to reader Sharjeel Safdar for these test cases
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 });    // both positive, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 });    // both positive, with decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }); // both negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }); // both negative, with decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 });  // second negative, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 });  // second negative, possible decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 });   // first negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 });   // first negative, possible decimal overflow

	FixedPoint2 a{ -0.48 };
	assert(static_cast<double>(a) == -0.48);
	assert(static_cast<double>(-a) == 0.48);

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	std::cout << "You entered: " << a << '\n';
	assert(static_cast<double>(a) == 5.68);

	return 0;
}
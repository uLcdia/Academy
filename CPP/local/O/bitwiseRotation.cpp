// https://www.learncpp.com/cpp-tutorial/bitwise-operators/
// Question #2 & Question #3

#include <bitset>
#include <iostream>

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits, size_t digits)
{
    digits %= 4; // allow rotating over 1 round
    const std::bitset<4> bitsRev { bits >> size_t { 4 - digits } }; // getting rotating leftover bits
    return ((bits << digits) | bitsRev);
}

int main()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1, 1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2, 6) << '\n';

	return 0;
}

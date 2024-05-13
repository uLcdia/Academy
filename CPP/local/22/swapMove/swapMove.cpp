// https://www.learncpp.com/cpp-tutorial/stdmove/

#include <iostream>
#include <string>
#include <utility>

// In particular, std::move produces an xvalue expression that identifies its argument t. It is exactly equivalent to a static_cast to an rvalue reference type. 

template <typename T>
void swapMove(T& a, T& b)
{
    T temp {std::move(a)};
    // a is in a valid but unspecified state

    // std::cout << "a: " << a << '\n'; // do not try to access the current value of a

    a = std::move(b);
    // a is determined again
    // b is in a valid but unspecified state

    // std::cout << "b: " << b << '\n'; // do not try to access the current value of b

    b = std::move(temp);
    // b is determined again
}

int main()
{
	std::string x{ "abc" };
	std::string y{ "de" };

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	swapMove(x, y);

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	return 0;
}
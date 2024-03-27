// https://www.learncpp.com/cpp-tutorial/static-member-functions/

#include <chrono>
#include <random>
#include <iostream>

class Random
{
public:
    static int get(int min, int max)
    {
        return std::uniform_int_distribution{min, max}(s_mt);
    }

private:
    static std::mt19937 generate()
    {
        std::random_device rd{};

        // Create seed_seq with high-res clock and 7 random numbers from std::random_device
        std::seed_seq ss{
            static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
                rd(), rd(), rd(), rd(), rd(), rd(), rd() };

        return std::mt19937{ ss };
    }

    static inline std::mt19937 s_mt {generate()};
};


int main()
{
    // Print a bunch of random numbers
	for (int count{ 1 }; count <= 10; ++count)
		std::cout << Random::get(1, 6) << '\t';

	std::cout << '\n';

    return 0;
}
#include "random.h"

int Random::get(int min, int max)
{
    return std::uniform_int_distribution{min, max}(s_mt);
}

int Random::get(int num)
{
    return std::uniform_int_distribution{0, num - 1}(s_mt);
}

std::mt19937 Random::generate()
{
    std::random_device rd{};

    // Create seed_seq with high-res clock and 7 random numbers from std::random_device
    std::seed_seq ss{
        static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
            rd(), rd(), rd(), rd(), rd(), rd(), rd() };

    return std::mt19937{ ss };
}
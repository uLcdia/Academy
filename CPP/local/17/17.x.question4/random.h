#ifndef RANDOM_H
#define RANDOM_H

#include <chrono>
#include <random>

class Random
{
public:
    static int get(int min, int max);
    static int get(int num);
private:
    static std::mt19937 generate();
public:
    static inline std::mt19937 s_mt {generate()};
};

#endif
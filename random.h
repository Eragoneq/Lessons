#ifndef RANDOM
#define RANDOM
#include <iostream>
#include <random>

unsigned long long rdtsc() {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return (unsigned long long) hi << 32 | lo;
}

std::mt19937 rng(rdtsc()); // NOLINT(cert-err58-cpp)

int randInt(int min, int max) {
    std::uniform_int_distribution<int> uni(min, max);
    return uni(rng);
}

float randFloat(float min, float max) {
    std::uniform_real_distribution<float> uni(min, max);
    return uni(rng);
}

#endif
#include "../include/Calculator.h"

#include <random>

int Calculator::GenerateRandomIntInRange(int min, int max) {
    // REFERENCE: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution.html
    // Cppreference.com (n.d.)
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(generator);
}

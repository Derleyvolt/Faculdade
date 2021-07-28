#pragma once

#include <time.h>
#include <random>

std::mt19937 gen(time(NULL));

int rng(int min, int max) {
    std::uniform_int_distribution<int> generator(min, max);
    return generator(gen);
}

// c-style rand
// int rng(int min, int max) {
//     static bool seed;
//     if(!seed)
//         srand(time(NULL)), seed = 1;
//     return min + (rand() % (max-min+1));
// }

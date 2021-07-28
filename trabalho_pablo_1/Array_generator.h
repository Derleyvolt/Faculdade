#pragma once

#include "RandomG.h"

#define increasing 1
#define decreasing 0

template<typename T> 
bool generate_worst_case(T arr[], int n) {
    T magic_number = rng(1, (T)(1e9 + 7));

    for(int i = 0; i < n; i++) {
        arr[i] = magic_number;
    }

    return 0;
}

template<typename T>
void generate_random_array(T arr[], int n, int min = 0, int max = (int)1e9) {
    for(int i = 0; i < n; i++) {
        arr[i] = rng(min, max);
    }
}

template<typename T>
void generate_monotonic_array(T arr[], int n, bool type = increasing) {
    T aux = (T)rng(n, n+19937);

    if(type) {
        for(int i = 0; i < n; i++) {
            arr[i] = aux + i;
        }
    } else {
        for(int i = n-1; i >= 0; i--) {
            arr[i] = aux - i;
        }
    }
}
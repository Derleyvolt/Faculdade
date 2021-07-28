#pragma once

#include "Quick_sort.h"

#define INSERTION       1
#define NO_INSERTION    0

// [i, j]
template<typename T>
void intro_sort(T arr[], int i, int j, int h, bool opt = INSERTION) {
    // caso base
    if(j-i+1 <= 1)
        return;

    // GNU usa insertion sort em partições menores que 16.

    // short-circuit evita que a checagem extra de opt
    // interfira no tempo de execução do algoritmo
    if(j-i+1 < 16 && opt) {
        return insertion_sort(arr+i, j-i+1);
    }

    // call stack cresceu muito..
    if(h <= 0) {
        return heap_sort(arr+i, j-i+1);
    }

    int pv = partition(arr, i, j, pivot(i, j));
    intro_sort(arr, i, pv-1, h-1);
    intro_sort(arr, pv+1, j, h-1);
}
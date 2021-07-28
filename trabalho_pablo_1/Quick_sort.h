#pragma once

#include "RandomG.h"

#define DETERMINISTIC_PIVOT   1
#define RANDOM_PIVOT          0

template<typename T>
void no_stl_swap(T& a, T& b) {
    T aux = a;
    a = b;
    b = aux;
}

int pivot(int low, int high, bool type = DETERMINISTIC_PIVOT) {
    return type ? (low+high)/2 : rng(low, high);
}

template<typename T>
T partition(T arr[], int l, int r, int pivot) {
    no_stl_swap(arr[pivot], arr[l]);

    int idx = r;
    pivot   = l;

    for(int i=r; i > l; i--) {
        if(arr[i] > arr[pivot]) {
            no_stl_swap(arr[i], arr[idx]);
            idx--;
        }
    }

    no_stl_swap(arr[pivot], arr[idx]);
    return idx;
}

void quick_sort(int arr[], int l, int r, bool type = DETERMINISTIC_PIVOT) {
    if (l < r) {
        int idx = partition(arr, l, r, pivot(l, r, type));

        quick_sort(arr, l, idx-1, type);
        quick_sort(arr, idx+1, r, type);
    }
}
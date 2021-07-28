#pragma once

#include "Quick_sort.h"

using namespace std;

template<typename T>
void heap_down(T arr[], int n, int i) {
    int l = i*2+1;
    int r = i*2+2;

    int temp = i; 

    if(r < n && arr[temp] < arr[r])
        temp = r;
    if(l < n && arr[temp] < arr[l])
        temp = l;

    if(temp != i) {
        no_stl_swap(arr[temp], arr[i]);
        heap_down(arr, n, temp);
    }
}

template<typename T>
void heap_sort(T arr[], int n) {
    for(int i = n/2; i >= 0; i--)
        heap_down(arr, n, i);

    for(int i = n-1; i >= 0; i--) {
        no_stl_swap(arr[0], arr[i]);
        heap_down(arr, i, 0);
    }
}
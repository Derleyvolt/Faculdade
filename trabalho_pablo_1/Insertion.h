#pragma once

template<typename T>
void insertion_sort(T arr[], int n) {
    int i;
    T aux;
    for (int j = 1; j < n; j++) {
        aux = arr[j];
        i = j-1;
        while ((i >= 0) && (arr[i] > aux)) {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = aux;
    }
}
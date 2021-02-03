#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_sequence(int *arr1, int *arr2, int *arr3, int *arr4, int n) {
    for(int i = 0; i < n; i++) {
    	int a = rand() % n * 100;
        arr1[i] = a;
        arr2[i] = a;
        arr3[i] = a;
        arr4[i] = a;
    }
}

long double bubble_sort(int *arr, int n) {
    int aux;
    time_t start, end;
    long double total;

    start = clock();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
             if (arr[j] > arr[j+1]) {
                aux    = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
             }
        }
    }

    end   = clock();
    total = (long double)(end - start) / CLOCKS_PER_SEC;
    return total;
}

long double insertion_sort(int *arr, int n) {
    int aux, i;
    time_t start, end;
    long double total;

    start = clock();
    for (int j = 1; j <= n; j++) {
        aux = arr[j];
        i = j-1;
        while ((i >= 0) && (arr[i] > aux)) {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = aux;
    }
    end = clock();
    total = (long double)(end - start) / CLOCKS_PER_SEC;
    return total;
}

long double selection_sort(int *arr, int n) {
    int i, j, aux;
    time_t start, end;
    long double total;

    start = clock();
    for (i = 0; i < n; i++) {
        aux = arr[i];
        for (j = (i+1); j < (n-1); j++) {
            if (arr[j] < aux) {
                aux = arr[j];
                arr[j] = arr[i];
            }
        }
        arr[i] = aux;
    }
    end = clock();
    total = (long double)(end - start) / CLOCKS_PER_SEC;
    return total;
}

long double comb_sort(int *arr, int n) {
    time_t start, end;
    long double total; 

    int gap = n; 
    int swapped = 1;

    start = clock();
    while (gap != 1 || swapped == 1) {
        gap = gap * 10 / 13;

        if(gap < 1)
            gap = 1;

        swapped = 0; 

        for (int i=0; i<n-gap; i++) { 
            if (arr[i] > arr[i+gap]) {
                int temp = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap] = temp; 
                swapped = 1; 
            } 
        } 
    } 
    end = clock();
    total = (long double)(end - start) / CLOCKS_PER_SEC;
    return total;
}

int main() {
    int n = 22000, k = 1000;
    long double time_bubble = 0.0, time_insertion = 0.0, time_selection = 0.0, time_comb = 0.0;
    int a[n], b[n], c[n], d[n];

    srand(time(NULL));

    printf("n: %d\n", n);
    printf("k: %d\n", k);

    while(k--) {
        generate_random_sequence(a, b, c, d, n);

        time_bubble     += bubble_sort(a, n);
        time_insertion  += insertion_sort(b, n);
        time_selection  += selection_sort(c, n);
        time_comb       += comb_sort(d, n);
    }
    printf("Bubble:     %Lf segundos\n", time_bubble);
    printf("Insertion:  %Lf segundos\n", time_insertion);
    printf("Selection:  %Lf segundos\n", time_selection);
    printf("Comb:       %Lf segundos\n", time_comb);
    return 0;
}

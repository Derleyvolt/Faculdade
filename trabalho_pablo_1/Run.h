#include "Heap.h"
#include "Timer.h"
#include "Insertion.h"
#include "Quick_sort.h"
#include "Intro_sort.h"
#include "Array_generator.h"
#include <iomanip>

template<typename T>
int my_log2(T n) {
    int lg = 0;
    while(n>1)
        n = n >> 2, lg++;
    return lg;
}

template<typename T>
void copy_array(T source[], T dest[], int n) {
    for(int i = 0; i < n; i++)
        dest[i] = source[i];
}

template<typename T>
void copy_arrays(T source[], T A[], T B[], T C[], T D[], int n) {
    copy_array(source, A, n);
    copy_array(source, B, n);
    copy_array(source, C, n);
    copy_array(source, D, n);
}

template<typename T>
void generate_arrays_instance(T A[], T B[], T C[], T D[], T E[], int n, char instance) {
    if(instance == 'A') {
        generate_random_array<T>(A, n);
    } else if(instance == 'C') {
        generate_monotonic_array<T>(A, n, increasing);
    } else if(instance == 'D') {
        generate_monotonic_array<T>(A, n, decreasing);
    } else if(instance == 'P') {
        generate_worst_case(A, n);
    }

    copy_arrays<T>(A, B, C, D, E, n);
}

template<typename T>
void is_ordered(T arr[], int n, const char algorithm_name[]) {
    for(int i = 0; i < n-1; i++) {
        if(arr[i] > arr[i+1]) {
            cout << algorithm_name << " nao ordenou o vetor." << endl;
            return;
        }
    }
}

template<typename T> 
void run_algorithms(int n, int n_cases, char instance) {
    T *arr_heap, *arr_quick, *arr_optimized_intro, *arr_intro, *arr_random_quick;

    arr_heap             = new T[n];
    arr_quick            = new T[n];
    arr_intro            = new T[n];
    arr_random_quick     = new T[n];
    arr_optimized_intro  = new T[n];

    double heap_time            = 0.f, quick_time = 0.f, 
           random_quick_time    = 0.f, intro_time = 0.f,
           optimized_intro_time = 0.f;

    while(n_cases--) {
        generate_arrays_instance<T>(arr_heap, arr_quick, arr_optimized_intro, 
                                    arr_intro, arr_random_quick, n, instance);

        Timer();
        quick_sort(arr_quick, 0, n-1, DETERMINISTIC_PIVOT);
        quick_time += Timer();
        is_ordered(arr_quick, n, "QuickSort com pivo fixo");


        Timer();
        quick_sort(arr_random_quick, 0, n-1, RANDOM_PIVOT);
        random_quick_time += Timer();
        is_ordered(arr_random_quick, n, "QuickSort com pivo aleatorio");


        Timer();
        heap_sort(arr_heap, n);
        heap_time += Timer();
        is_ordered(arr_heap, n, "Heapsort");


        Timer();
        intro_sort(arr_intro, 0, n-1, 2*my_log2(n), INSERTION);
        intro_time += Timer();
        is_ordered(arr_intro, n, "IntroSort com InsertionSort");


        Timer();
        intro_sort(arr_optimized_intro, 0, n-1, 2*my_log2(n), NO_INSERTION);
        optimized_intro_time += Timer();
        is_ordered(arr_optimized_intro, n, "IntroSort sem InsertionSort");
    }

    cout << endl << endl;

    cout << fixed << "HeapSort:                     " << heap_time             << " Segundos" << endl;
    cout << fixed << "QuickSort com pivo fixo:      " << quick_time            << " Segundos" << endl;
    cout << fixed << "QuickSort com pivo aleatorio: " << random_quick_time     << " Segundos" << endl;
    cout << fixed << "IntroSort com InsertionSort:  " << intro_time            << " Segundos" << endl;
    cout << fixed << "IntroSort sem InsertionSort:  " << optimized_intro_time  << " Segundos" << endl;

    delete[] arr_heap;
    delete[] arr_quick;
    delete[] arr_intro;
    delete[] arr_random_quick;
    delete[] arr_optimized_intro;
}

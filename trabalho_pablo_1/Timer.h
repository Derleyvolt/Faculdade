#pragma once

#include <iostream>
#include <chrono>

double Timer() {
    static chrono::steady_clock::time_point start;
    static bool                             elapsed;

    double aux = 0.f;

    if(!elapsed) {
        start = chrono::steady_clock::now();
    }
    else {
        aux = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count()/1000.f;
    }

    elapsed ^= 1;
    return aux;
}
#include <chrono>
#include <iomanip>
#include "run.h"
#include "instancias_Reais_Trabalho_2.hpp"

using namespace std;

double Timer() {
    static chrono::steady_clock::time_point  start;
    static bool                              elapsed;

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

bool compare(int* ocur_a, int* ocur_b, int len) {
    for(int i = 0; i < len; i++) {
        if(ocur_a[i] != ocur_b[i]) {
            return false;
        } else if(ocur_a[i] == -1) {
            return true;
        }
    }

    return false;
}

void throw_error() {
    puts("Erro ao alocar memoria");
    exit(0);
}

void run_real(int l, int r) {
    if(l > 35129 || r > 35129 || l > r) {
        puts("Os valores de x ou y estao incorretos.");
        return;
    }

    int text_len = strlen(Texto_Livros);

    int *ocurrences_KMP    = new int[strlen(Texto_Livros)+1];
    int *ocurrences_BRUTE  = new int[strlen(Texto_Livros)+1];

    double KMP_elapsed_time    = 0.f;
    double BRUTE_elapsed_time  = 0.f;

    for(int i = l; i <= r; i++) {

        // Knuth-Morris-Pratt String Matching
        Timer();

            if(KMP(Padroes_Palavras[i], Texto_Livros, ocurrences_KMP) == false)
                throw_error();

        KMP_elapsed_time += Timer();



        // Brute Force String Matching
        Timer();

            if(brute_force(Padroes_Palavras[i], Texto_Livros, ocurrences_BRUTE) == false)
                throw_error();

        BRUTE_elapsed_time += Timer();

        if(!compare(ocurrences_BRUTE, ocurrences_KMP, text_len+1)) {
            puts("As saidas sao diferentes!");
            return;
        }
    }

    cout << fixed << endl;

    cout << "Knuth-Morris-Pratt:  " << KMP_elapsed_time   << " segundos" << endl;
    cout << "Brute Force:         " << BRUTE_elapsed_time << " segundos" << endl;

    // limpando o heap
    delete[] ocurrences_BRUTE;
    delete[] ocurrences_KMP;
}

void run_random(char bound, int pattern_len, int text_len, int instance_len) {
    char *pattern  = new char[pattern_len+1];
    char *text     = new char[text_len+1];

    int *ocurrences_KMP    = new int[text_len+1];
    int *ocurrences_BRUTE  = new int[text_len+1];

    double KMP_elapsed_time    = 0.f;
    double BRUTE_elapsed_time  = 0.f;

    for(int i = 0; i < instance_len; i++) {
        generate_random_text(pattern_len, bound, pattern);
        generate_random_text(text_len, bound, text);


        // Knuth-Morris-Pratt String Matching
        Timer();

            if(KMP(pattern, text, ocurrences_KMP) == false)
                throw_error();

        KMP_elapsed_time += Timer();


        
        // Brute Force String Matching
        Timer();

            if(brute_force(pattern, text, ocurrences_BRUTE) == false)
                throw_error();

        BRUTE_elapsed_time += Timer();

        if(!compare(ocurrences_BRUTE, ocurrences_KMP, text_len+1)) {
            puts("As saidas sao diferentes!");
            return;
        }
    }
    
    cout << fixed << endl;

    cout << "KMP:         " << KMP_elapsed_time   << " segundos" << endl;
    cout << "Brute Force: " << BRUTE_elapsed_time << " segundos" << endl;

    // limpando o heap
    delete[] pattern;
    delete[] text;
    delete[] ocurrences_BRUTE;
    delete[] ocurrences_KMP;
}
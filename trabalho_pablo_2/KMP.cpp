#include "KMP.h"

void zero_mem(int *buf, int len) {
    for(int i = 0; i < len; i++) {
        buf[i] = 0;
    }
}

void prefix_function(const char *pattern, int *pi) {
    int len = strlen(pattern);
    zero_mem(pi, len);

    for(int i = 1; i < len; i++) {
        int j = pi[i-1];
        while(j > 0 && pattern[j] != pattern[i]) {
            j = pi[j-1];
        }

        if(pattern[j] == pattern[i]) {
            pi[i] = j + 1;
        }
    }
}

bool KMP(const char *P, const char *T, int *o) {
    int pattern_len = strlen(P);
    int text_len    = strlen(T);

    int* pi = new int[pattern_len];

    if(pi == nullptr)
        return false;

    prefix_function(P, pi);

    int index = 0, ocurrences_index = 0;

    for(int i = 0; i < text_len; i++) {
        if(P[index] == T[i]) {
            index++;
            if(index == pattern_len) {
                o[ocurrences_index] = i-pattern_len+1;
                ocurrences_index++;
                index = pi[index-1];
            }
        } else if(index) {
            index = pi[index-1];
            i--;
        }
    }

    delete[] pi;

    o[ocurrences_index] = -1;

    return true;
}
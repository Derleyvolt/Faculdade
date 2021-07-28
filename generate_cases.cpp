#include "generate_cases.h"

// gera um numero aleatório entre char[min, max].
char rng_char(char min, char max) {
    static int init;
    if(init == 0)
        srand(time(NULL)), init = 1;
    return min + rand() % (max-min+1);
}

void generate_random_text(int length, char max_char, char* buf) {
    buf[length] = 0;
    for(int i = 0; i < length; i++) {
        buf[i] = rng_char('a', max_char);
    }
}
#include <iostream>
#include "run.h"

// 00:53 - 26/07/2021

int main(int argc, char *argv[]) {
    if(argc > 1) {
        char type = argv[1][0];

        if(type == 'A') {
            int  bound           = argv[2][0];
            int  pattern_len     = std::stoi(argv[3]);
            int  text_len        = std::stoi(argv[4]);
            int  instances_count = std::stoi(argv[5]);
            run_random(bound, pattern_len, text_len, instances_count);

        } else if(type == 'R') {
            int l_bound = std::stoi(argv[2]);
            int u_bound = std::stoi(argv[3]);
            run_real(l_bound, u_bound);
        }
    } else {
        puts("O programa nao foi inicializado corretamente");
    }
    return 0;
}

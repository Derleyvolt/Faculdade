#include <iostream>
#include <string>
#include "Run.h"

int main(int argc, char *argv[]) {
    if(argc == 4) {
        run_algorithms<int>(stoi(argv[2]), stoi(argv[3]), argv[1][0]);
    } else {
        cout << "Poucos argumentos foram passados.." << endl;
    }

    return 0;
}
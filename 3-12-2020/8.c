// Online C compiler to run C program online
#include <stdio.h>

void fib_(int n) {
    int f1 = 0, f2 = 0, it = 1;
    while(it < n) {
        printf("%d\n", it);
        f2 = f1;
        f1 = it;
        it = f1 + f2;
    }
}


int main() {
    int n;
    scanf("%d", &n);
    fib_(n);
    return 0;
}

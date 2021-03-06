#include <stdio.h>

int is_prime(int n) {
    if(n == 2)
        return 1;
    if(n <= 1 || n % 2 == 0)
        return 0;
    int root = sqrt(n);
    for(int i = 3; i <= root; i++) {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n; scanf("%d", &n);
    int it = 0;
    int counter = 0;
    while(counter < n) {
        if(is_prime(it)) {
            printf("%d\n", it);
            counter++;
        }
        it++;
    }
    return 0;
}

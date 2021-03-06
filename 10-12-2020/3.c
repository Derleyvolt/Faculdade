#include <stdio.h>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    printf("%d", gcd(a, gcd(b, c)));
}

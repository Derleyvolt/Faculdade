#include <stdio.h>

#define ll long long

// (2n)! / n!

double factorial(ll n) {
    if(n == 1)
        return 1;
    return n * factorial(n-1);
}

int main() {
	int n; scanf("%d", &n);
    printf("%f", factorial(2 * n) / factorial(n));
	return 0;
}
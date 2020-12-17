#include <stdio.h>

#define ll long long

ll pot(ll b, ll e) {
    if(e == 1)
        return b;
    return b * pot(b, e-1);
}

ll hyper_factorial(ll n) {
    if(n == 1)
        return 1;
    return pot(n, n) * hyper_factorial(n-1);
}

int main() {
	int n; scanf("%d", &n);
    printf("%ld", hyper_factorial(n));
	return 0;
}
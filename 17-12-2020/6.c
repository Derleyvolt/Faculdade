#include <stdio.h>

#define ll long long

ll pot(ll b, ll e) {
    if(e == 1)
        return b;
    return b * pot(b, e-1);
}

ll factorial_exp(ll n) {
    if(n == 1)
        return 1;
    return pow(n, factorial_exp(n-1));
}

int main() {
	int n; scanf("%d", &n);
    printf("%ld", factorial_exp(n));
	return 0;
}
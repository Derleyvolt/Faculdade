#include <stdio.h>

#define ll long long

ll factorial(ll n) {
    if(n == 1)
        return 1;
    return n * factorial(n-1);
}

ll super_factorial(ll n) {
    if(n == 1)
        return 1;
    return factorial(n) * super_factorial(n-1);
}

int main() {
	int n; scanf("%d", &n);
    printf("%ld", super_factorial(n));
	return 0;
}
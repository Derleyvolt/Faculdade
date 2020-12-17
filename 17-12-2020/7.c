#include <stdio.h>

#define ll long long

ll tetranacci(ll n) {
    if(n < 4)
        return 0;
    if(n == 4)
        return 1;
    return tetranacci(n-1) + tetranacci(n-2) + tetranacci(n-3) + tetranacci(n-4);
}

int main() {
	int n; scanf("%d", &n);
    printf("%ld", tetranacci(n));
	return 0;
}
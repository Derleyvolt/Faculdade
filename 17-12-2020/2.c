#include <stdio.h>

#define ll long long

ll double_factorial(ll n) {
    if(n == 1)
        return 1;
    return n * double_factorial(n-2);
}

int main(void) {
	int n; scanf("%d", &n);
    if(n % 2 != 0)
        printf("%d", double_factorial(n));
	return 0;
}
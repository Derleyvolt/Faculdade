// Online C compiler to run C program online
#include <stdio.h>

void reverse(long long n) {
	long long ans = 0;
	while(n) {
		int r = n % 10;
		n = n / 10;
		ans = ans * 10 + r;
	}
	printf("%lld", ans);
}

int main() {
	long long n;
	scanf("%lld", &n);
	reverse(n);
}
#include <stdio.h>

#define ll long long

// sem usar vetor
bool is_palindrome_ex(ll n) {
    ll reverse = 0, num = n;
    while(n) {
        int r = n % 10;
	n = n / 10;
	reverse = reverse * 10 + r;    
    }	
    return reverse == num;	
}

// com vetor
bool is_palindrome(ll n) {
	int arr[10];
	int it = 0;
	while (n) {
		ll r = n % 10;
		arr[it] = r;
		n = n / 10;
		it++;
	}

	int l = 0, r = it - 1;
	while (l < r) {
		if (arr[l++] != arr[r--])
			return 0;
	}
	return 1;
}

int main(void) {
	ll n; scanf("%lld", &n);
	if (is_palindrome(n))
		printf("e um palindromo");
	else
		printf("nao e um palindromo");
}

#include <bits/stdc++.h>

using namespace std; 

int is_prime(int n) {
    if(n == 1)
        return 1;
    if(n == 2)
        return 1;
    for(int i = 2; i < n / i; i++) {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n; scanf("%d", n);
    int it = 0;
    while(it < n) {
        if(is_prime(it))
	    printf("%d\n", it);
        it++;
    }
    return 0;
}

// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>

int is_prime(int n) {
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    int root = sqrt(n);
    for(int i = 2; i <= root; i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	int it  = 0;
	int ans = 0;
	
	if(n < ans)
		printf("nao ha primos menores que esse numero");
	
	while(it < n) {
		ans = is_prime(it) == 1 ? it : ans;
		it++;
	}
	
	printf("%d", ans);
}
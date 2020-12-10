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
    int it = 1;
    while(n) {
    	n = n - (is_prime(it) && printf("%d\n", it));
        it++;
    }
    return 0;
}
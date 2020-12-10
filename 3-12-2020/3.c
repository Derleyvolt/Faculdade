// Online C compiler to run C program online
#include <stdio.h>

int min(int a, int b) {
    if(a > b)
        return b;
    return a;
}

int max(int a, int b) {
    if(a < b)
        return b;
    return a;
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    int cateto_a = min(a, min(b, c));
    int cateto_b = 0;
    
    if(cateto_a == a)
        cateto_b = min(b, c);
    else if(cateto_a == b)
        cateto_b = min(a, c);
    else
        cateto_b = min(a, b);
    
    if (a + b > c && a + c > b && b + c > a) {
        int hyp = max(a, max(b, c));
        if(cateto_a * cateto_a + cateto_b * cateto_b == hyp * hyp)
            printf("E um triangulo retangulo");
        else
            printf("Nao e um triangulo retangulo");
    }
    else
        printf("Nao e um triangulo");
    return 0;
}
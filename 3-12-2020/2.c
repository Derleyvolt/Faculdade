// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if(b != 0) {
        printf("%i", a / b);
        printf("%i", a % b);
    } else
        printf("Divisao por zero");
    return 0;
}
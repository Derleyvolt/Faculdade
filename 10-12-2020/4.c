#include <stdio.h>
#include <math.h>

#define pi 3.14

int main() {
    int r; scanf("%d", r);
    printf("%f volume", 4.0/3.0 * pi * pow(r, 3));
    printf("%f area", 4.0 * pi * pow(r, 2));
}

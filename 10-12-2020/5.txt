#include <stdio.h>

double pot(double x, int k) {
    if (k == 0)
        return 1;
    return x * pot(x, k - 1);
}

int main() {
    double b; int e; scanf("%lf%d", &b, &e);
    printf("%lf", pot(b, e));
}

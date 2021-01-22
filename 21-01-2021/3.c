#include <stdio.h>

void simetric(int x, int y, double a, double b, double c) {
	double m = -a / b; // coeficiente angular da primeira reta
	double k = -1 / m; // coeficiente angular da segunda reta

	double n = y - k * x; // coeficiente linear da segunda reta

	double p = -1;
	double ya = (k * c - a * n) / (a * p - k * b);
	double xa = (-b * ya - c) / a;

	double yr = 2 * ya - y;
	double xr = 2 * xa - x;

	printf("x: %.02f y: %.02f", xr, yr);
}

int main(void) {
	simetric(5, 7, 4, -1, 3);
	return 0;
}

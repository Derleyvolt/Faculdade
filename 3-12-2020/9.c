// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>

int main() {
	int counter = 0;
	int ans = 0;
	while(counter != 1000) {
		if(ans % 2 != 0 && ans % 3 != 0 && ans % 7 != 0) {
			printf("%d\n", ans);
			counter++;
		}
		ans++;
	}
}
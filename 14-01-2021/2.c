#include <stdio.h>

int main(void) {
	int arr[1000];
	int n; scanf("%d", &n);
	
	for(int i =0; i < n; i++) scanf("%d", &arr[i]);
	
	int r;
	
	if(n >= 2)
		r = arr[1] / arr[0];
		
	for(int i = 0; i < n - 1; i++) {
		if(arr[i+1] / arr[i] != r) {
			printf("a sequencia nao e uma progressão geometrica");
			return 0;
		}
	}
	
	printf("A razao da progressao geometrica e = %d", r);
}

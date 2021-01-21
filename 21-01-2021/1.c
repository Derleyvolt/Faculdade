#include <stdio.h>

void bubble_sort(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int aux = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aux;
			}
		}
	}
}

int main(void) {
	int arr[] = { 1, 4, 2, 1, 3, 5, 1, 11, 51, 47, 12, 32, 14, 155 };
	bubble_sort(arr, sizeof(arr) / 4);
	for (int i = 0; i < sizeof(arr) / 4; i++)
		printf("%d\n", arr[i]);
	return 0;
}

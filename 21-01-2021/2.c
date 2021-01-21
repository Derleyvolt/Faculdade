#include <stdio.h>

void selection_sort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_element = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_element])
				min_element = j;
		}

		int aux          = arr[i];
		arr[i]           = arr[min_element];
		arr[min_element] = aux;
	}
}

int main(void) {
	int arr[] = { 1, 4, 2, 1, 3, 5, 1, 11, 51, 47, 12, 32, 14, 155 };
	selection_sort(arr, sizeof(arr) / 4);
	for (int i = 0; i < sizeof(arr) / 4; i++)
		printf("%d\n", arr[i]);
	return 0;
}

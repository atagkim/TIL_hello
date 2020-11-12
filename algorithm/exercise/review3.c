#include <stdio.h>

int table[10000010];
int temp[10000010];

void init(int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d", &table[i]);
	}
}

void merge(int start,int middle, int end) {

	int left = start, right = middle + 1, idx = start;

	while (left <= middle && right <= end) {

		if (table[left] < table[right]) {
			temp[idx++] = table[left++];
		}
		else
			temp[idx++] = table[right++];
	}

	while (left <= middle) {
		temp[idx++] = table[left++];
	}
	while (right <= end) {
		temp[idx++] = table[right++];
	}

	for (int i = start; i <= end; i++) {
		table[i] = temp[i];
	}
}


void mergeSort(int start, int end) {

	if (start < end) {
		int middle = (start + end) / 2;
		mergeSort(start, middle);
		mergeSort(middle + 1, end);
		merge(start, middle, end);
	}
}

int main() {

	int n;
	scanf("%d", &n);

	init(n);

	mergeSort(0, n-1);

	for (int i = 0; i < n; i++) {
		printf("%d\n", table[i]);
	}

}
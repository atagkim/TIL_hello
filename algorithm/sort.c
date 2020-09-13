#include <stdio.h>

int inputTable[1010];
int tempBuf[1010];

void init(int n) {

	for (int i = 0; i < n; i++) {
		scanf("%d", &inputTable[i]);
	}
}

void solution(int* inputTable, int n);

int main() {

	int n;
	scanf("%d", &n);

	init(n);

	solution(inputTable, n);

}

void merge(int* inputTable, int left, int mid, int right) {

	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {

		if (inputTable[i] < inputTable[j])
			tempBuf[k++] = inputTable[i++];
		else
			tempBuf[k++] = inputTable[j++];
	}

	while (i <= mid)
		tempBuf[k++] = inputTable[i++];
	while (j <= right)
		tempBuf[k++] = inputTable[j++];

	for (int a = left; a <= right; a++)
		inputTable[a] = tempBuf[a];
}

void mergeSort(int* inputTable, int left, int right) {

	int mid = (left + right) / 2;

	if (left < right) {
		mergeSort(inputTable, left, mid);
		mergeSort(inputTable, mid + 1, right);
		merge(inputTable, left, mid, right);
	}
	
}


void solution(int* inputTable, int n) {


	mergeSort(inputTable, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d\n", inputTable[i]);
	}
}

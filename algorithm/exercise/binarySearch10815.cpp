#include <stdio.h>

int inputTable[500010];
int tempTable[500010];
int idxTable[500010];
int tempidxTable[500010];
int tempSolution;

void init(int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d", &inputTable[i]);
		inputTable[i] += 10000000;
		
		idxTable[i] = i;
	}
}

void merge(int* currentTable, int* currentidxTable, int start, int middle, int end) {

	int left = start, right = middle + 1, idx = start;

	while (left <= middle && right <= end) {
		if (currentTable[left] < currentTable[right]) {
			tempTable[idx] = currentTable[left];
			tempidxTable[idx++] = currentidxTable[left++];
		}
		else {
			tempTable[idx] = currentTable[right];
			tempidxTable[idx++] = currentidxTable[right++];
		}
	}

	while (left <= middle) {
		tempTable[idx] = currentTable[left];
		tempidxTable[idx++] = currentidxTable[left++];
	}
	while (right <= end) {
		tempTable[idx] = currentTable[right];
		tempidxTable[idx++] = currentidxTable[right++];
	}

	for (int i = start; i <= end; i++) {
		currentTable[i] = tempTable[i];
		currentidxTable[i] = tempidxTable[i];
	}
}

void mergeSort(int* currentTable, int* currentidxTable, int start, int end) {

	if (start < end) {
		int middle = (start + end) / 2;

		mergeSort(currentTable, currentidxTable, start, middle);
		mergeSort(currentTable, currentidxTable, middle + 1, end);

		merge(currentTable, currentidxTable, start, middle ,end);
	}
}

void binarySearch(int* currentTable, int* currentidxTable, int start, int end, int input) {

	int middle = (start + end) / 2;

	if (currentTable[middle] == input) {
		tempSolution = 1;
		return;
	}
	else if (start >= end) {
		return;
	}
	else if (currentTable[middle] < input) {
		binarySearch(currentTable, currentidxTable, middle + 1, end, input);
	}
	else {
		binarySearch(currentTable, currentidxTable, start, middle - 1, input);
	}
}


int main() {

	int n;
	scanf("%d", &n);

	init(n);

	mergeSort(inputTable, idxTable, 0, n - 1);

	int m;
	scanf("%d", &m);

	int input;
	while (m--) {
		scanf("%d", &input);
		input += 10000000;

		tempSolution = 0;
		binarySearch(inputTable, idxTable, 0, n-1, input);
		
		printf("%d ", tempSolution);
	}
}
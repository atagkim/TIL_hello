#include <stdio.h>

int aTable[55];
int bTable[55];
int originalTable[55], tempTable[55];
int idxTable[55], idxTempTable[55];

void init(int n) {

	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1)
				scanf("%d", &aTable[j]);
			else
				scanf("%d", &bTable[j]);
		}
	}

}

void initMerge(int n, int* table) {

	for (int i = 1; i <= n; i++) {
		originalTable[i] = table[i];
		idxTable[i] = i;
	}
}

void merge(int n, int start, int middle, int end, int order) {

	int left = start, right = middle + 1;

	int idx = start;
	while (left <= middle && right <= end) {

		if (order == 1) {
			if (originalTable[left] < originalTable[right]) {
				tempTable[idx] = originalTable[left];
				idxTempTable[idx++] = idxTable[left++];
			}
			else {
				tempTable[idx] = originalTable[right];
				idxTempTable[idx++] = idxTable[right++];
			}
		}
		else {

			if (originalTable[left] > originalTable[right]) {
				tempTable[idx] = originalTable[left];
				idxTempTable[idx++] = idxTable[left++];
			}
			else {
				tempTable[idx] = originalTable[right];
				idxTempTable[idx++] = idxTable[right++];
			}
		}
	}

	while (left <= middle) {
		tempTable[idx] = originalTable[left];
		idxTempTable[idx++] = idxTable[left++];
	}
	while (right <= end) {
		tempTable[idx] = originalTable[right];
		idxTempTable[idx++] = idxTable[right++];
	}

	idx = start;
	while (idx <= end){
		originalTable[idx] = tempTable[idx];
		idxTable[idx] = idxTempTable[idx];
		idx++;
	}

}

void mergeSort(int n, int start, int end, int order) {

	if (end - start == 0) {
		return;
	}
	else {

		int middle = (start + end) / 2;

		mergeSort(n, start, middle, order);
		mergeSort(n, middle + 1, end, order);

		merge(n, start, middle, end, order);
	}

}


int main() {

	int n; 
	scanf("%d", &n);

	init(n);

	initMerge(n, bTable);
	mergeSort(n, 1, n, -1);

	int currentIdxTable[55];
	for (int i = 1; i <= n; i++)
		currentIdxTable[i] = idxTable[i];
	
	initMerge(n, aTable);
	mergeSort(n, 1, n, 1);

	long long solution = 0;
	for (int i = 1; i <= n; i++) {
		solution += bTable[currentIdxTable[i]] * originalTable[i];
	}
	printf("%lld", solution);

}
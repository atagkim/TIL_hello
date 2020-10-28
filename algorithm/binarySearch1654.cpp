#include <stdio.h>

int inputTable[10010];
int solution;

void binarySearch(int start, int end, int n, int k) {

	if (start <= end) {
		int middle = (start + end) / 2;

		int count = 0;
		for (int i = 0; i < n; i++) {
			count += inputTable[i] / middle;
			if (count >= k)
				break;
		}

		if (count >= k) {
			solution = middle;
			binarySearch(middle + 1, end, n, k);
		}
		else
			binarySearch(start, middle - 1, n, k);

	}

}

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	int max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &inputTable[i]);
		if (max < inputTable[i])
			max = inputTable[i];
	}
	solution = max;

	int start = 1, end = max;

	binarySearch(start, end, n, k);
	printf("%d", solution);
}
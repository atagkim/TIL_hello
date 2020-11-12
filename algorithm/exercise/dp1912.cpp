#include <stdio.h>

int inputTable[100100];
int dpTable[100100][2];

void init(int n) {
	for (int i = 1; i <= n; i++) {
		scanf("%d", &inputTable[i]);
	}
}

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {

	int n;
	scanf("%d", &n);

	init(n);

	for (int i = 1; i <= n; i++) {
		dpTable[i][0] = 0;
		dpTable[i][1] = max(dpTable[i - 1][1] + inputTable[i], dpTable[i - 1][0] + inputTable[i] );
	}

	int max = -987654321;
	for (int i = 1; i <= n; i++) {
		if (max < dpTable[i][1]) {
			max = dpTable[i][1];
		}
	}
	printf("%d", max);
}
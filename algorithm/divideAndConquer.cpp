#include <stdio.h>

struct matrixUnit {
	int n;
	int a[6][6];
};

matrixUnit baseMatrix;


void init(int n, int b) {

	baseMatrix.n = n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &baseMatrix.a[i][j]);
		}
	}

}

matrixUnit matrixMultiplication(matrixUnit a, matrixUnit b) {

	int n = a.n;
	matrixUnit result;
	result.n = n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			
			result.a[i][j] = 0;

			for (int k = 1; k <= n; k++) {
				result.a[i][j] += a.a[i][k] * b.a[k][j];
			}
			
			result.a[i][j] %= 1000;
		}
	}

	return result;
	
}

matrixUnit calculate(int n, int start, int end) {

	if (end - start >= 2) {
		return matrixMultiplication( calculate(n, start, (start + end) / 2), calculate(n, (start + end) / 2 + 1, end) );
	}
	else if(end - start == 1){
		
		return matrixMultiplication(baseMatrix, baseMatrix);
	}
	else {
		return baseMatrix;
	}

}


int main() {

	int n, b;
	scanf("%d %d", &n, &b);

	init(n, b);

	matrixUnit solution = calculate(n, 1, b);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", solution.a[i][j]);
		}
		printf("\n");
	}

}



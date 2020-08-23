#include <stdio.h>

struct matrixUnit {
	int n;
	int a[6][6];
};

matrixUnit baseMatrix;
matrixUnit current;
matrixUnit solution;

void init(int n, long long b) {

	baseMatrix.n = n;
	solution.n = n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &baseMatrix.a[i][j]);
		}
		solution.a[i][i] = 1;
	}

	current = baseMatrix;
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

void calculate(int n, int start, long long end) {

	if (end == start) {
		solution = matrixMultiplication(solution, current);
	}
	else if (end < (long long)(start * 2)) {
		solution = matrixMultiplication(solution, current);
		
		current = baseMatrix;
		calculate(n, 1, end - (long long)start);
	}
	else {
		current = matrixMultiplication(current, current);

		calculate(n, start * 2, end);
	}

}


int main() {

	int n;
	long long b;
	scanf("%d %lld", &n, &b);

	init(n, b);

	calculate(n, 1, b);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", solution.a[i][j]);
		}
		printf("\n");
	}

}



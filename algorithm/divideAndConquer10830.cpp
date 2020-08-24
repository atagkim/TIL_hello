//
//#include <stdio.h>
//
//struct matrixUnit {
//	int n;
//	int a[6][6];
//};
//
//matrixUnit baseMatrix;
//matrixUnit current;
//matrixUnit solution;
//
//void init(int n, long long b) {
//
//	baseMatrix.n = n;
//	solution.n = n;
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			scanf("%d", &baseMatrix.a[i][j]);
//		}
//		solution.a[i][i] = 1;
//	}
//
//	current = baseMatrix;
//}
//
//void matrixMultiplication(matrixUnit* a, matrixUnit* b) {
//
//	int n = a->n;
//
//	matrixUnit result;
//	result.n = n;
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//
//			result.a[i][j] = 0;
//
//			for (int k = 1; k <= n; k++) {
//				result.a[i][j] += a->a[i][k] * b->a[k][j];
//				result.a[i][j] %= 1000;
//			}
//
//		}
//	}
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			a->a[i][j] = result.a[i][j];
//		}
//	}
//
//
//}
//
//void calculate(int n, int start, long long end) {
//
//	while (end > 0) {
//
//		if (end % 2 == 1) {
//			matrixMultiplication(&solution, &current);
//		}
//		
//		end /= 2;
//		matrixMultiplication(&current, &current);
//	
//	}
//
//}
//
//
//int main() {
//
//
//	int n;
//	long long b;
//	scanf("%d %lld", &n, &b);
//
//	init(n, b);
//
//	calculate(n, 1, b);
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			printf("%d ", solution.a[i][j]);
//		}
//		printf("\n");
//	}
//
//}





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

void matrixMultiplication(matrixUnit* a, matrixUnit* b) {

	int n = a->n;

	matrixUnit result;
	result.n = n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			
			result.a[i][j] = 0;

			for (int k = 1; k <= n; k++) {
				result.a[i][j] += a->a[i][k] * b->a[k][j];
				result.a[i][j] %= 1000;
			}
			
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a->a[i][j] = result.a[i][j];
		}
	}


}

void calculate(int n, long long start, long long end) {


	while (end > start) {

		if (end < start * 2) {
			
			end = end - start;
			start = 1;

			matrixMultiplication(&solution, &current);
			
			current = baseMatrix;
		
		}
		else {

			start = start * 2;

			matrixMultiplication(&current, &current);

		}

	}
	
	matrixMultiplication(&solution, &current);

	return;

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

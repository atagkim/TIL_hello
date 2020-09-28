#include <stdio.h>

int inputOutdegree[550][550];
int indegree[550];
int inputTime[550];
int inputSize[550];
int solution[550];

int stack[550];
int stackTop;

void check(int n) {

	stackTop = 0;
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			indegree[i] = -1;
			stack[stackTop++] = i;
		}
	}
}

void scan(int n) {

	int row = 0, flag = 0;
	while (n - row) {
		int input;
		scanf("%d", &input);

		if (flag == 0) {
			inputTime[row] = input;
			flag = 1;
		}
		else {
			if (input == -1) {
				row++;
				flag = 0;
			}
			else {
				inputOutdegree[input - 1][inputSize[input - 1]++] = row;
				indegree[row]++;
			}
		}
	}

}

int main() {

	int n;
	scanf("%d", &n);

	scan(n);

	while (1) {

		check(n);
		if (stackTop == 0)
			break;

		int idx = 0;
		while (idx < stackTop) {
			int current = stack[idx++];
			solution[ current ] += inputTime[ current ];

			for (int j = 0; j < inputSize[current]; j++) {
				int next = inputOutdegree[current][j];
				solution[next] = solution[next] > solution[current] ? solution[next] : solution[current];
				indegree[next]--;
			}
		}

	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", solution[i]);
	}

}
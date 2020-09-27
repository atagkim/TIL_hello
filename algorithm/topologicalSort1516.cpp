#include <stdio.h>

int inputTable[550][550];
int indegree[550];
int solution[550];

int queue[550];
int front, real;

void check(int n) {

	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			indegree[i] = -1;

		}
	}

}

int main() {

	int n;
	scanf("%d", &n);

	int row = 0, col = 1, flag = 0;
	while (n - row) {
		int input;
		scanf("%d", &input);
	
		if (flag == 0) {
			inputTable[row][0] = input;
			flag = 1;
		}
		else {
			inputTable[row][col++] = input;
			if (input == -1) {
				indegree[row] = col - 2;

				row++;
				col = 1;
				flag = 0;
			}
		}
	}

	while (1) {

		int current = check(n);
		if (current == -1)
			break;

		solution[current] += inputTable[current][0];

		for (int i = 1; inputTable[current][i] != -1; i++) {
			solution[inputTable[current][i]] += inputTable[current][0];

			indegree[inputTable[current][i]]--;
		}

	}

}
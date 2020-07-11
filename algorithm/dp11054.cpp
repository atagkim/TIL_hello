#include <stdio.h>

int inputTable[1010];
int dpTable[1010][4];
int currentTable[1010];
int top, maxLength, maxLengthLastNum, upAndDown;

void init(int num) {

	for (int i = 1; i <= num; i++) {
		scanf("%d", &inputTable[i]);
	}

}

void dp(int num) {

	for (int i = 1; i <= num; i++) {
		int current = inputTable[i];

		dpTable[current][0] = 0;
		dpTable[current][1] = 1;
		dpTable[current][2] = 2000;
		dpTable[current][3] = 1;

		for (int j = 0; j < top; j++) {
			
			int before = currentTable[j];

			if (before < current) {
				
				if (dpTable[current][1] < dpTable[before][1] + 1) {
					dpTable[current][0] = before;
					dpTable[current][1] = dpTable[before][1] + 1;
				}
			}
			else if (before > current) {
			
				if (dpTable[current][3] < dpTable[before][3] + 1) {
					dpTable[current][2] = before;
					dpTable[current][3] = dpTable[before][3] + 1;
				}
				if (dpTable[current][3] < dpTable[before][1] + 1) {
					dpTable[current][2] = before;
					dpTable[current][3] = dpTable[before][1] + 1;
				}

			}
		}


		if (maxLength < dpTable[current][1]) {
			maxLength = dpTable[current][1];
			maxLengthLastNum = current;
			upAndDown = 0;
		}

		if (maxLength < dpTable[current][3]) {
			maxLength = dpTable[current][3];
			maxLengthLastNum = current;
			upAndDown = 1;
		}

		currentTable[top++] = current;
	}

}

int main() {

	int num;
	scanf("%d", &num);

	init(num);

	dp(num);

	printf("%d", maxLength);

}
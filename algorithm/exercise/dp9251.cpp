#include <stdio.h>
#include <string.h>

struct unit {
	int length;
};

unit dpTable[1010][1010];

char input[3][1010];
int inputLen[3];

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {

	scanf("%s %s", input[1], input[2]);
	inputLen[1] = strlen(input[1]);
	inputLen[2] = strlen(input[2]);

	for (int i = 1; i <= inputLen[1]; i++) {
		
		char current = input[1][i - 1];

		for (int j = 1; j <= inputLen[2]; j++) {

			char current2 = input[2][j - 1];
			
			if (current == current2) {
				int max = 0, idx = 0;
				for (int k = j - 1; k >= 1; k--) {
					if (max < dpTable[i - 1][k].length) {
						max = dpTable[i - 1][k].length;
					}
				}
				if (max == 0) {
					dpTable[i][j].length = 1;
				}
				else {
					dpTable[i][j].length = max + 1;
				}
			}
			else {
				dpTable[i][j] = dpTable[i - 1][j];
			}
		}

	}

	int max = 0;
	for (int i = 1; i <= inputLen[2]; i++) {
		if (max < dpTable[inputLen[1]][i].length) {
			max = dpTable[inputLen[1]][i].length;
		}
	}
	printf("%d", max);

}


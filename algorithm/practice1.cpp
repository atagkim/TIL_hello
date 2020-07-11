#include <stdio.h>

int hambuck[5];
int drink[5];

int main() {

	int min = 987654321;

	for (int i = 0; i < 3; i++) {
		scanf("%d", &hambuck[i]);
	}
	for (int i = 0; i < 2; i++) {
		scanf("%d", &drink[i]);
		for (int j = 0; j < 3; j++) {
			int sum = hambuck[j] + drink[i] - 50;
			if (min > sum) {
				min = sum;
			}
		}
	}

	printf("%d", min);

}

//bj 5543
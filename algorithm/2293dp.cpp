#include <stdio.h>

int dpTable[10100];
int coinTable[110];

int countPossible(int value, int n) {

	for (int i = 1; i < value; i++) {

		int current = dpTable[i];


		int idx = n, sum = 0;
		while (1) {
			
			

		}

	}

}

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &coinTable[i]);
	}

	
	for (int i = 1; i <= k; i++) {

		dpTable[i] = countPossible(i, n);
	}

}
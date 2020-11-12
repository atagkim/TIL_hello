#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct unit {
	int weight;
	int value;
};

vector<unit> itemTable;

int dpTable[110][100100];

void init(int n, int k) {

	unit zero;
	itemTable.push_back(zero);

	for (int i = 1; i <= n; i++) {
	
		unit input;
		scanf("%d %d", &input.weight, &input.value);

		itemTable.push_back(input);
	}
	
}

int max(int a, int b) {
	return a > b ? a : b;
}

void dp(int n, int k) {

	for (int i = 1; i <= n; i++) {
		unit current = itemTable[i];

		for (int j = 0; j <= k; j++) {
			if (j - current.weight >= 0) {
				dpTable[i][j] = max(dpTable[i - 1][j], dpTable[i - 1][j - current.weight] + current.value);
			}
			else {
				dpTable[i][j] = dpTable[i - 1][j];
			}
		}

	}

	printf("%d", dpTable[n][k]);

}


int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	init(n, k);

	dp(n, k);

}
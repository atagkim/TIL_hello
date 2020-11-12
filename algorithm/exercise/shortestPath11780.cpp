#include <stdio.h>
#include <vector>

using namespace std;

int distTable[110][110];
int betweenTable[110][110];
int inf = 987654321;

vector<int> orderTable[110][110];

void init(int n, int m) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				distTable[i][j] = 0;
			else
				distTable[i][j] = 987654321;

		}
	}


	for (int i = 1; i <= m; i++) {
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);

		if (distTable[start][end] > cost)
			distTable[start][end] = cost;
	}

}

void findLength(int i, int j, int* count) {
	
	if (betweenTable[i][j] != 0) {
		findLength(i, betweenTable[i][j], count);
		(*count)++;
		findLength(betweenTable[i][j], j, count);
	}
}

void findPath(int i, int j) {

	if (betweenTable[i][j] != 0) {

		findPath(i, betweenTable[i][j]);
		printf("%d ", betweenTable[i][j]);
		findPath(betweenTable[i][j], j);
	}

}

void floyd(int n, int m) {

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				if (distTable[i][k] != inf && distTable[k][j] != inf
					&& distTable[i][j] > distTable[i][k] + distTable[k][j]) {

					distTable[i][j] = distTable[i][k] + distTable[k][j];
				
					betweenTable[i][j] = k;
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (distTable[i][j] == inf || distTable[i][j] == 0)
				printf("0 ");
			else
				printf("%d ", distTable[i][j]);
		}
		printf("\n");
	}

	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (distTable[i][j] == inf || distTable[i][j] == 0)
				printf("0\n");
			else {
				int count = 2;

				findLength(i, j, &count);

				printf("%d %d ", count, i);
				findPath(i, j);
				printf("%d\n", j);
				
			}
		}
	}

}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	init(n, m);

	floyd(n, m);

}
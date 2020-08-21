#include <stdio.h>
#include <queue>

using namespace std;

struct inputUnit {
	int end;
	int cost;
};
vector<inputUnit> inputTable[410];

int distTable[410][410];

int inf = 987654321;

void init(int v, int e) {

	for (int j = 1; j <= v; j++) {
		for (int i = 1; i <= v; i++) {
			distTable[j][i] = inf;
		}
	}

	for (int i = 1; i <= e; i++) {
		int start, end, cost;
		
		scanf("%d %d %d", &start, &end, &cost);
		
		distTable[start][end] = cost;
	}

	return;
}


void floyd(int v, int e) {


	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {

				if (distTable[i][k] != inf && distTable[k][j] != inf
					&& distTable[i][j] > distTable[i][k] + distTable[k][j])

					distTable[i][j] = distTable[i][k] + distTable[k][j];
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			printf("%d ", distTable[i][j]);
		}
		printf("\n");
	}

	int min = 987654321;
	for (int i = 1; i <= v; i++) {
		if (min > distTable[i][i]) {
			min = distTable[i][i];
		}
	}
	printf("%d", min);

}


int main() {

	int v, e;
	scanf("%d %d", &v, &e);

	init(v, e);

	floyd(v, e);

}
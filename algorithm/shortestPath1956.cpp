#include <stdio.h>
#include <queue>

using namespace std;


struct inputUnit {
	int end;
	int cost;
};
vector<inputUnit> inputTable[410];

int shortestTable[4][410][410];

void init(int v, int e) {

	for (int i = 1; i <= e; i++) {
		int start, temp;
		inputUnit input;

		scanf("%d %d %d", &start, &input.end, &input.cost);

		inputTable[start].push_back(input);
	}

	for (int j = 1; j <= 2; j++) {
		for (int i = 1; i <= v; i++) {
			for (int k = 1; k <= v; k++) {
				shortestTable[j][i][k] = 987654321;
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if(i == j)
				shortestTable[1][i][j] = 0;
		}
	}

	return;
}

void free(int v, int e) {

	for (int i = 1; i <= v; i++) {
		inputTable[i].clear();
	}
	return;
}

void bellman(int v, int e) {

	for (int i = 1; i <= 2 * v - 2; i++) {
		for (int j = 1; j <= v; j++) {
			for (int k = 0; k < inputTable[j].size(); k++) {
				
				for (int l = 1; l <= v; l++) {
					if (shortestTable[1][l][j] != 987654321
						&& shortestTable[1][l][j] + inputTable[j][k].cost < shortestTable[1][l][inputTable[j][k].end]) {
						shortestTable[1][l][inputTable[j][k].end] = shortestTable[1][l][j] + inputTable[j][k].cost;
						if (shortestTable[2][l][inputTable[j][k].end] > shortestTable[1][l][j] + inputTable[j][k].cost) {
							shortestTable[2][l][inputTable[j][k].end] = shortestTable[1][l][j] + inputTable[j][k].cost;
						}
					}
					if (shortestTable[2][l][j] != 987654321
						&& shortestTable[2][l][j] + inputTable[j][k].cost < shortestTable[2][l][inputTable[j][k].end]) {
						shortestTable[2][l][inputTable[j][k].end] = shortestTable[2][l][j] + inputTable[j][k].cost;
					}
				}
			}
		}
	}

	int min = 987654321;
	for (int i = 1; i <= v; i++) {
		if (shortestTable[2][i][i] != 987654321 && shortestTable[2][i][i] < min)
			min = shortestTable[2][i][i];
	}
	if (min != 987654321)
		printf("%d\n", min);
	else
		printf("-1\n");

}


int main() {

	int v, e;
	scanf("%d %d", &v, &e);

	init(v, e);

	bellman(v, e);

	free(v, e);
}
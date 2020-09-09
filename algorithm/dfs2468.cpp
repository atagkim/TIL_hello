#include <stdio.h>
#include <queue>

using namespace std;

struct unit {
	int x;
	int y;
};

queue<unit> qqu;

int checkTable[110][110];
int inputTable[110][110];

int xAdded[10] = { 0,0,0,1,-1 };
int yAdded[10] = { 0,1,-1,0,0 };

int solution, realSolution;

void init(int n, int* min, int* max) {

	int input;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			scanf("%d", &input);

			if (input > *max)
				*max = input;
			if (input < *min)
				*min = input;

			inputTable[i][j] = input;
		}
	}
}


void bfs(int n, int x, int y, int k) {

	unit fire;
	fire.x = x;
	fire.y = y;

	if (x > 0 && y > 0 && x <= n && y <= n && checkTable[x][y] == 0 && inputTable[x][y] > k) {
		qqu.push(fire);
		
		checkTable[x][y] = 1;
		
		solution++;
	}

	while (!qqu.empty()) {

		unit current = qqu.front();
		qqu.pop();

		for (int i = 1; i <= 4; i++) {
			unit next;
			next.x = current.x + xAdded[i];
			next.y = current.y + yAdded[i];

			if (next.x < 1 || next.y < 1 || next.x > n || next.y > n)
				continue;

			if (checkTable[next.x][next.y] == 0 && inputTable[next.x][next.y] > k) {
				checkTable[next.x][next.y] = 1;

				qqu.push(next);
			}
		}
	}

}


int main() {

	int n;
	scanf("%d", &n);

	int min = 987654321, max = 0;
	init(n, &min, &max);

	for (int k = min; k < max; k++) {

		solution = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				checkTable[i][j] = 0;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				bfs(n, i, j, k);
			}
		}

		if (realSolution < solution)
			realSolution = solution;
	}
	
	printf("%d", realSolution);

}


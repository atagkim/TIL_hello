#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int inputTable[110][110];
int checkTable[110][110];

int xAdded[5] = { 0,1,-1,0,0 };
int yAdded[5] = { 0,0,0,1,-1 };

int solutionNum;
vector<int> solutionValue;

struct unit {
	int x;
	int y;
};

queue<unit> qqu;

void init(int n, int m, int k) {

	int x1, y1, x2, y2;
	for (int i = 1; i <= k; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		x1++;
		y1++;

		for (int j = x1; j <= x2; j++) {
			for (int l = y1; l <= y2; l++) {
				inputTable[j][l] = 1;
			}
		}

	}

}

void initCheck(int n, int m) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			checkTable[i][j] = 0;
		}
	}
}

void bfs(int n, int m, int x, int y) {
	
	unit fire;
	fire.x = x;
	fire.y = y;

	int area = 0;

	if (x >= 1 && y >= 1 && x <= n && y <= m) {
		if (inputTable[x][y] == 0 && checkTable[x][y] == 0) {
			qqu.push(fire);

			checkTable[x][y] = 1;

			solutionNum++;
			area = 1;
		}
	}

	while (!qqu.empty()) {

		unit current = qqu.front();
		qqu.pop();

		for (int i = 1; i <= 4; i++) {
			unit next;
			next.x = current.x + xAdded[i];
			next.y = current.y + yAdded[i];

			if (next.x > 0 && next.y > 0 && next.x <= n && next.y <= m) {
				if (inputTable[next.x][next.y] == 0 && checkTable[next.x][next.y] == 0) {
					qqu.push(next);

					checkTable[next.x][next.y] = 1;
					area++;
				}
			}

		}
	}

	if (area != 0) {
		solutionValue.push_back(area);
	}
	
}



int main() {

	int n, m, k;
	scanf("%d %d %d", &m, &n, &k);

	init(n, m, k);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			bfs(n, m, i, j);
		}
	}

	sort(solutionValue.begin(), solutionValue.end());

	printf("%d\n", solutionNum);
	for (int i = 0; i < solutionValue.size(); i++) {
		printf("%d ", solutionValue[i]);
	}
}
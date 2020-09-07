#include <stdio.h>
#include <queue>

using namespace std;

struct unit {
	int x;
	int y;
};

queue<unit> qqu;

int inputTable[100][100];
int visitTable[100][100];

int solution;

int xAdded[10] = { 0, 1, 1, 1, 0, 0, -1, -1, -1 };
int yAdded[10] = { 0, 1, 0, -1, 1, -1, 1, 0, -1 };


void init(int h, int w) {
	
	while (!qqu.empty())
		qqu.pop();

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf("%d", &inputTable[i][j]);
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			visitTable[i][j] = 0;
		}
	}

	solution = 0;
}

void bfs(int h, int w, int x, int y) {

	unit fire;

	fire.x = x;
	fire.y = y;

	if (x >= 1 && y >= 1 && x <= h && y <= w && inputTable[x][y] == 1 && visitTable[x][y] == 0) {
		qqu.push(fire);
		solution++;
	}
		
	while (!qqu.empty()) {

		unit current = qqu.front();
		qqu.pop();

		if (current.x >= 1 && current.y >= 1 && current.x <= h && current.y <= w)
			visitTable[current.x][current.y] = 1;
		else
			continue;

		for (int i = 1; i <= 8; i++) {
			int nextX = current.x + xAdded[i];
			int nextY = current.y + yAdded[i];

			if (nextX >= 1 && nextY >= 1 && nextX <= h && nextY <= w) {

				if (visitTable[nextX][nextY] == 0 && inputTable[nextX][nextY] == 1) {

					unit next;

					next.x = nextX;
					next.y = nextY;

					visitTable[nextX][nextY] = 1;

					qqu.push(next);

				}

			}

		}

	}

}

int main() {

	while (1) {
		
		int w, h;
		scanf("%d %d", &w, &h);

		if (w == 0 && h == 0)
			break;

		init(h, w);


		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				bfs(h, w, i, j);
			}
		}

		printf("%d\n", solution);

	}

}
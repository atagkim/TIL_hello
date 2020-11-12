#include <iostream>
#include <queue>
using namespace std;

struct unit {
	int x;
	int y;
	int count;
};
queue<struct unit> qqu;

int solution;

int xadded[10] = {-2, -1, 1, 2, 2, 1, -1, -2};
int yadded[10] = {1, 2, 2, 1, -1, -2, -2, -1};
// x,yadded 0start

int visitTable[310][310];

void bfs(int startx, int starty, int endx, int endy, int n) {

	struct unit fire;
	fire.x = startx;
	fire.y = starty;
	fire.count = 0;
	qqu.push(fire);

	while (!qqu.empty()) {

		struct unit current = qqu.front();
		qqu.pop();

		if (visitTable[current.x][current.y] == 1)
			continue;
		visitTable[current.x][current.y] = 1;

		if (current.x == endx && current.y == endy) {
			solution = current.count;
			break;
		}

		for (int i = 0; i < 8; i++) {

			int nextx = current.x + xadded[i];
			int nexty = current.y + yadded[i];

			if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n) {

				struct unit nextfire;
				nextfire.x = nextx;
				nextfire.y = nexty;
				nextfire.count = current.count + 1;

				qqu.push(nextfire);
			}

		}		
	}

	while (!qqu.empty()) {
		qqu.pop();
	}
}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);
		
		int startx, starty, endx, endy;
		scanf("%d %d %d %d", &startx, &starty, &endx, &endy);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visitTable[i][j] = 0;
			}
		}

		solution = 0;
		bfs(startx, starty, endx, endy, n);
		printf("%d\n", solution);
	}
}
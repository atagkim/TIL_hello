#include <iostream>
#include <queue>
using namespace std;

char table[15][15];
int solution = -1;
int visitTable[15][15][15][15];

struct unit {
	int rx;
	int ry;
	int bx;
	int by;
	int count;
	int status;
};

queue<struct unit> qqu;

int xadded[5] = { 0,1,0,-1 };
int yadded[5] = { 1,0,-1,0 };

// 0 오른쪽 1 아래족 2 왼쪽 3 위쪽
struct unit nextfinder(struct unit current, int order, int endx, int endy) {

	int rx = current.rx, ry = current.ry, bx = current.bx, by = current.by;

	while (1) {
		if (table[rx][ry] == 'O') {
			break;
		}
		else if (table[rx][ry] == '#') {
			rx -= xadded[order];
			ry -= yadded[order];
			break;
		}
		rx += xadded[order];
		ry += yadded[order];
	}
	
	while (1) {
		if (table[bx][by] == 'O') {
			break;
		}
		else if (table[bx][by] == '#') {
			bx -= xadded[order];
			by -= yadded[order];
			break;
		}
		bx += xadded[order];
		by += yadded[order];
	}

	struct unit next;
	next.count = current.count + 1;
	next.bx = bx;
	next.by = by;
	next.ry = ry;
	next.rx = rx;

	return next;
}

void bfs(int n, int m) {

	int bx = 0, by = 0, rx = 0, ry = 0, ox = 0, oy = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (table[i][j] == 'B') {
				bx = i;
				by = j;
			}
			else if (table[i][j] == 'R') {
				rx = i;
				ry = j;
			}
			else if (table[i][j] == 'O') {
				ox = i;
				oy = j;
			}
		}
	}

	struct unit fire;
	fire.rx = rx;
	fire.ry = ry;
	fire.bx = bx;
	fire.by = by;
	fire.count = 0;

	qqu.push(fire);
	while (!qqu.empty()) {

		struct unit current = qqu.front();
		qqu.pop();

		if (visitTable[current.rx][current.ry][current.bx][current.by] == 1)
			continue;
		visitTable[current.rx][current.ry][current.bx][current.by] = 1;

		if (current.count > 10)
			break;
		if (current.rx == ox && current.ry == oy) {
			solution = current.count;
			break;
		}

		struct unit next[5];
		for (int i = 0; i < 4; i++) {
			next[i] = nextfinder(current, i, ox, oy);

			if (next[i].bx == ox && next[i].by == oy)
				continue;
			
			if(next[i].bx == next[i].rx && next[i].by == next[i].ry) {
				if (i == 0) {
					current.by < current.ry ? next[i].by-- : next[i].ry--;
				}
				else if (i == 1) {
					current.bx < current.rx ? next[i].bx-- : next[i].rx--;
				}
				else if (i == 2) {
					current.by > current.ry ? next[i].by++ : next[i].ry++;
				}
				else {
					current.bx > current.rx ? next[i].bx++ : next[i].rx++;
				}
			}

			if (visitTable[next[i].rx][next[i].ry][next[i].bx][next[i].by] == 0)
				qqu.push(next[i]);

		}
	}
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", table[i]);
	}

	bfs(n, m);
	printf("%d", solution);

	while (!qqu.empty()) {
		qqu.pop();
	}
}
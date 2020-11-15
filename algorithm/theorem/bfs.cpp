#include <iostream>
#include <queue>
using namespace std;

struct unit {
	int x;
	int y;
	int dist;
};

queue<unit> qqu;

int xAdded[5] = { 0,0,1,-1 };
int yAdded[5] = { 1,-1,0,0 };

bool visitTable[10][10];
int table[10][10] = { 
	{2,1,1,0,1},
	{0,0,0,0,1},
	{1,1,1,0,1},
	{1,0,0,0,1},
	{3,0,1,0,1},
};
// 2 = start, 1 = wall, 0 = way, 3 = end
// answerDist = 10

int bfs(int startX, int startY, int n) {

	int revalue = 0;
	int nextX, nextY;
	unit current, next;

	unit fire;
	fire.x = startX;
	fire.y = startY;
	fire.dist = 0;

	visitTable[fire.x][fire.y] = 1;
	qqu.push(fire);

	while (!qqu.empty()) {

		current = qqu.front();
		qqu.pop();

		if (current.x < 0 || current.x >= n || current.y < 0 || current.y >= n)
			continue;

		if (table[current.x][current.y] == 3) {
			revalue = current.dist;
			break;
		}

		for (int i = 0; i < 4; i++) {
			nextX = current.x + xAdded[i];
			nextY = current.y + yAdded[i];

			if (nextX >= 0 && nextX < n && nextY < n && nextY >= 0) {
				if (table[nextX][nextY] != 1 && visitTable[nextX][nextY] == 0) {

					next.x = nextX;
					next.y = nextY;
					next.dist = current.dist + 1;

					visitTable[nextX][nextY] = 1;
					qqu.push(next);

				}
			}

		}
	}
	
	while (!qqu.empty()) {
		qqu.pop();
	}

	return revalue;

}


int main() {
	
	
	int answerDist = bfs(0, 0, 5);
	
	printf("¿Ãµø √— ∞≈∏Æ: %d", answerDist);

}
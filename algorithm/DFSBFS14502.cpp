#include <stdio.h>

struct unit {
	int x;
	int y;
};

int inputTable[10][10];
struct unit inputStart[105];
struct unit point[5];
struct unit queue[105];
int tempTable[10][10];
int visitTable[10][10];
int tempCnt, initCnt;
int solution;

int xAdded[5] = { 0,0,1,-1 };
int yAdded[5] = { 1,-1,0,0 };

void queueAdd(struct unit* queue, struct unit input) {
	struct unit* real = &queue[100];
	queue[(*real).y++] = input;
}

void queuePop(struct unit* queue) {
	struct unit* front = &queue[100];
	(*front).x++;
}

struct unit queueFront(struct unit* queue) {
	struct unit* front = &queue[100];
	return queue[(*front).x];
}

void queueClear(struct unit* queue) {
	queue[100].x = 0;
	queue[100].y = 0;
}

void init(int n, int m) {

	initCnt = n * m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &inputTable[i][j]);

			if (inputTable[i][j] != 0)
				initCnt--;

			if (inputTable[i][j] == 2) {
				struct unit input;
				input.x = i;
				input.y = j;
				queueAdd(inputStart, input);
			}
		}
	}
	solution = 0;
}

int check() {

	for (int i = 1; i <= 3; i++) {
		int currentX = point[i].x, currentY = point[i].y;

		if (inputTable[currentX][currentY] != 0)
			return 0;
	}
	return 1;
}

int queueEmpty(struct unit* queue) {
	return queue[100].x == queue[100].y ? 1 : 0;
}

void bfs(int n, int m) {

	tempCnt = initCnt - 3 + inputStart[100].y;

	for(int i=0;i<inputStart[100].y;i++)
		queueAdd(queue, inputStart[i]);

	/*for (int i = 0; i < queue[100].y; i++) {
		printf("virus: %d %d\n", queue[i].x, queue[i].y);
	}
	printf("wall: ");
	for (int i = 1; i <= 3; i++) {
		printf("%d %d  ", point[i].x, point[i].y);
	}
	printf("\n");

	printf("initCnt: %d\n", initCnt);*/
	
	while (!queueEmpty(queue)) {

		struct unit current = queueFront(queue);
		queuePop(queue);

		//printf("current: %d %d\n", current.x, current.y);

		tempCnt--;

		for (int i = 0; i < 4; i++) {
			int nextX = current.x + xAdded[i];
			int nextY = current.y + yAdded[i];
		
			if (nextX >= 1 && nextX <= n && nextY >= 1 && nextY <= m) {
				if (visitTable[nextX][nextY] == 0 && tempTable[nextX][nextY] == 0) {
					visitTable[nextX][nextY] = 1;

					struct unit next;
					next.x = nextX;
					next.y = nextY;

					queueAdd(queue, next);
				}
			}
		}
	}

	//printf("end...\ntempCnt: %d\n", tempCnt);

}

void initBfs(int n, int m) {

	queueClear(queue);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visitTable[i][j] = 0;
			tempTable[i][j] = inputTable[i][j];
		}
	}
	for (int i = 1; i <= 3; i++) {
		tempTable[point[i].x][point[i].y] = 1;
	}

}

void dfs(int idx, int x, int y, int n, int m) {

	if (idx == 4) {

		if (check()) {

			initBfs(n, m);
			bfs(n, m);
			if (solution < tempCnt)
				solution = tempCnt;

		}
			
		return;
	}

	for (int j = y; j <= m; j++) {
		point[idx].x = x;
		point[idx].y = j;

		if (x == n && j == m) {
			if (idx == 3)
				dfs(idx + 1, 0, 0, n, m);
			else
				return;
		}
		else if (j == m)
			dfs(idx + 1, x + 1, 1, n, m);
		else
			dfs(idx + 1, x, j + 1, n, m);
	}
	for (int i = x + 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			point[idx].x = i;
			point[idx].y = j;

			if (i == n && j == m) {
				if (idx == 3)
					dfs(idx + 1, 0, 0, n, m);
				else
					return;
			}
			else if (j == m)
				dfs(idx + 1, i + 1, 1, n, m);
			else
				dfs(idx + 1, i, j + 1, n, m);
		}
	}

}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	init(n, m);

	dfs(1, 1, 1, n, m);
		
	printf("%d", solution);
}
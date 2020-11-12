#include <stdio.h>

int inputTable[100][100];
int dpTable[100][100];

struct unit {
	int x;
	int y;
	int weight;
};

struct unit queue[10100];
int front, real;

int solution;

int empty() {
	if (front >= real)
		return 1;
	return 0;
}

void push(struct unit input) {
	queue[real++] = input;
}

struct unit frontFunc() {
	return queue[front];
}

void pop() {
	front++;
}


void init(int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &inputTable[i][j]);
		}
	}
}

int xAdded[5] = { 1,0,-1,0 };
int yAdded[5] = { 0,1,0,-1 };


void bfs(int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", inputTable[i][j]);
		}printf("\n");
	}

	struct unit fire;
	fire.x = 0;
	fire.y = 0;
	fire.weight = 13 - inputTable[fire.x][fire.y];
	dpTable[fire.x][fire.y] = fire.weight - inputTable[fire.x][fire.y];

	push(fire);

	while (!empty()) {

		struct unit current = frontFunc();
		pop();


		if (current.x == n - 1 && current.y == m - 1) {
			if (solution < current.weight)
				solution = current.weight;
			continue;
		}

		if (dpTable[current.x][current.y] > current.weight) {
			printf("dupple\n");
			continue;
		}
			
		for (int i = 0; i < 4; i++) {
			struct unit next;
			next.x = current.x + xAdded[i];
			next.y = current.y + yAdded[i];

			if (next.x >= 0 && next.y >= 0 && next.x < n && next.y < m) {
	
				next.weight = current.weight - inputTable[next.x][next.y];
				printf("current %d %d %d\n", current.x, current.y, current.weight);
				printf("next[%d] %d %d %d\n", i, next.x, next.y, next.weight);

				if (dpTable[next.x][next.y] < next.weight) {
					printf("next[%d] %d %d %d pushed...\n", i, next.x, next.y, next.weight);
					push(next);
					dpTable[next.x][next.y] = next.weight;
				}
			}

		}

	}

}


int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	init(n, m);

	bfs(n, m);

	printf("%d", solution);
}
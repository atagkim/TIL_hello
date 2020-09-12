#include <stdio.h>
#include <stdlib.h>

char* inputTable[110];
char inputTableReal[110][110];

void init(int n) {

	for (int i = 0; i < n; i++) {
		inputTable[i] = inputTableReal[i];
		scanf("%s", &inputTableReal[i]);
	}
}

int* solution(char** v, int n);

int main() {

	int n;
	scanf("%d", &n);

	init(n);

	int* answer = solution(&inputTable, n);

	printf("%d %d", answer[0], answer[1]);
}




struct unit {
	int x;
	int y;
};

struct unit qqu[10000];
int front, real;

int count;

int visitTable[110][110];

int xAdded[5] = { 0,0,1,-1 };
int yAdded[5] = { 1,-1,0,0 };

void initQueue() {
	front = 0;
	real = 0;
}

void initVisit(int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visitTable[i][j] = 0;
		}
	}
}


struct unit frontFunc() {
	return qqu[front];
}

void pop() {
	front++;
}

void push(struct unit input) {
	qqu[real++] = input;
}

int empty() {
	if (front >= real)
		return 1;
	return 0;
}


void bfs(char** v, int n, int x, int y) {

	struct unit fire;
	fire.x = x;
	fire.y = y;
	char pivot = v[fire.x][fire.y];

	if (fire.x >= 0 && fire.x < n && fire.y >= 0 && fire.y < n && visitTable[fire.x][fire.y] == 0) {

		visitTable[fire.x][fire.y] = 1;
		
		push(fire);

		count++;
	}

	while (!empty()) {

		struct unit current = frontFunc();
		pop();

		for (int i = 0; i < 4; i++) {
			struct unit next;
			next.x = current.x + xAdded[i];
			next.y = current.y + yAdded[i];

			if (next.x >= 0 && next.y >= 0 && next.x < n && next.y < n ) {
				if (visitTable[next.x][next.y] == 0 && v[next.x][next.y] == pivot) {
					visitTable[next.x][next.y] = 1;

					push(next);
				}
			}
		}

	}

}



void bfs2(char** v, int n, int x, int y) {

	struct unit fire;
	fire.x = x;
	fire.y = y;
	char pivot = v[fire.x][fire.y];

	if (fire.x >= 0 && fire.x < n && fire.y >= 0 && fire.y < n && visitTable[fire.x][fire.y] == 0) {

		visitTable[fire.x][fire.y] = 1;

		push(fire);

		count++;
	}

	while (!empty()) {

		struct unit current = frontFunc();
		pop();

		for (int i = 0; i < 4; i++) {
			struct unit next;
			next.x = current.x + xAdded[i];
			next.y = current.y + yAdded[i];

			if (next.x >= 0 && next.y >= 0 && next.x < n && next.y < n) {
				if (visitTable[next.x][next.y] == 0) {
					
					if ( (v[next.x][next.y] == pivot)
						|| (v[next.x][next.y] == 'R' && pivot == 'G')
						|| (v[next.x][next.y] == 'G' && pivot == 'R') ) {
						visitTable[next.x][next.y] = 1;
						push(next);
					}
				}
			}
		}

	}

}


int* solution(char** v, int n) {

	int* answer = (int*)malloc(sizeof(int) * 2);

	count = 0;
	initVisit(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			initQueue();
			bfs(v, n, i, j);
		}
	}
	answer[0] = count;

	count = 0;
	initVisit(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			initQueue();
			bfs2(v, n, i, j);
		}
	}
	answer[1] = count;

	return answer;
}



#include <stdio.h>

char table[30][30];
int visitTable[30];
int max;

int xAdded[5] = { 0, 1, 0, -1 };
int yAdded[5] = { 1, 0, -1, 0 };

void init(int r, int c) {

	for (int i = 0; i < r; i++) {
		scanf("%s", table[i]);
	}
}

void dfs(int r, int c, int x, int y, int length) {

	int idx = table[x][y] - 'A';
	visitTable[idx] = 1;

	if (max < length)
		max = length;

	for (int i = 0; i < 4; i++) {
		int nextX = x + xAdded[i];
		int nextY = y + yAdded[i];

		if(nextX >= 0 && nextX < r && nextY < c && nextY >= 0){
			int nextIdx = table[nextX][nextY] - 'A';
			if (visitTable[nextIdx] == 0) {
				dfs(r, c, nextX, nextY, length + 1);
				visitTable[nextIdx] = 0;
			}
		}
	}
}

int main() {

	int r, c;
	scanf("%d %d", &r, &c);

	init(r, c);

	dfs(r, c, 0, 0, 1);
	
	printf("%d", max);
}
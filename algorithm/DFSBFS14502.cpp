#include <stdio.h>

int inputTable[10][10];
int solution;
int point[5][3];

void init(int n, int m) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &inputTable[i][j]);
		}
	}
	solution = 0;


}

int check() {

}

void bfs() {


	
}

void dfs(int idx, int x, int y, int n, int m) {

	if (idx == 4) {

		check();


		bfs();


		return;
	}

	for (int j = y; j <= m; j++) {
		point[idx][0] = x;
		point[idx][1] = j;

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
			point[idx][0] = i;
			point[idx][1] = j;

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
		
	printf("%d", cnt);
}
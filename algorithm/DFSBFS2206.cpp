#include <stdio.h>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

typedef struct stt {
	int row;
	int colum;
	int status;
	int length;
};

queue<stt> qqu;

int visited[1010][1010][2];
char table[1010][1010];
int nextRow[5] = {0, 0, 1, 0, -1 };
int nextColum[5] = {0, 1, 0, -1, 0 };

void init(int n, int m) {

	char inputBuf[1010];

	for (int i = 1; i <= n; i++) {
		scanf("%s", inputBuf);
		for (int j = 1; j <= m; j++) {
			table[i][j] = inputBuf[j - 1];
		}
	}
}

void bfs(int n, int m) {

	while (!qqu.empty()) {

		stt current = qqu.front();
		qqu.pop();
	
		printf("%d %d %d\n", current.row, current.colum, current.status);

		if (current.row < 1 || current.colum < 1 || current.row > n || current.colum > m) continue;
		visited[current.row][current.colum][current.status] = 1;

		if (current.row == n && current.colum == m) {
			printf("%d", current.length);
			return;
		}

		for (int i = 1; i <= 4; i++) {
			stt next;
			next.row = current.row + nextRow[i];
			next.colum = current.colum + nextColum[i];
			next.length = current.length + 1;
			next.status = current.status;
			
			if (next.row >= 1 && next.row <= n && next.colum >= 1 && next.colum <= m) {
				if (current.status == 1 
					&& visited[next.row][next.colum][0] == 0 
					&& visited[next.row][next.colum][1] == 0 
					&& table[next.row][next.colum] == '0') {
					visited[next.row][next.colum][1] = 1;
					
					qqu.push(next);
				}
				else if(current.status == 0) {
					if (table[next.row][next.colum] == '0'
						&& visited[next.row][next.colum][0] == 0) {
						visited[next.row][next.colum][0] = 1;
						
						qqu.push(next);
					}
					else if(table[next.row][next.colum] == '1' 
						&& visited[next.row][next.colum][1] == 0
						&& visited[next.row][next.colum][0] == 0){
						visited[next.row][next.colum][1] = 1;
						
						next.status = 1;
						qqu.push(next);
					}
				}			
			}
		}

	}
	printf("-1");
	return;
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	init(n, m);

	stt start;
	start.row = 1;
	start.colum = 1;
	start.length = 1;
	start.status = 0;
	qqu.push(start);

	bfs(n, m);
}
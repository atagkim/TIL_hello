#include <stdio.h>

#define start 0
#define end 987654321


// 길 찾기 dfs로
int table[10][10] = { {start, 2, 3}, {3, 4, 2}, {3, 5, end} };
int maxlength;

int xadded[5] = { 0,0,1,-1 };
int yadded[5] = { 1,-1,0,0 };

int dptable[10][10];

void dfs(int x, int y, int length, int n) {

	int nextx, nexty;

	if (table[x][y] == end) {
		if (maxlength < length)
			maxlength = length;

		return;
	}

	for (int i = 0; i < 4; i++) {
		nextx = x + xadded[i];
		nexty = y + yadded[i];

		if(0 <= nextx && nextx < n && 0 <= nexty && nexty < n)
			if(table[nextx][nexty] > table[x][y])
				if (dptable[nextx][nexty] < length + 1) {

					dptable[nextx][nexty] = length + 1;
					dfs(nextx, nexty, length + 1, n);
				}
	}

}

int main() {

	dptable[0][0] = 1;
	dfs(0, 0, 1, 3);

	printf("%d", maxlength);
}
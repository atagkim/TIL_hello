#include <stdio.h>

#define START 0
#define END 987654321
#define TABLESIZE 4

// s 1 2 1
// 2 3 3 4
// 3 7 6 5
// 4 8 9 e
int table[10][10] = { {START,1,2,1}, {2,3,3,4}, {3,7,6,5}, {4,8,9,END} };

// 더 큰수로만 갈 수 있음.

int dpTable[10][10];
int maxlength;
 
int xadded[5] = { 0,0,1,-1 };
int yadded[5] = { 1,-1,0,0 };

void dfs(int x, int y, int current, int length, int n) {

	int nextx, nexty;

	if (table[x][y] == END) {

		if (maxlength < length)
			maxlength = length;
		
		return;
	}

	for (int i = 0; i < 4; i++) {

		nextx = x + xadded[i];
		nexty = y + yadded[i];

		if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n) 
			if(table[nextx][nexty] > table[x][y])
				if (dpTable[nextx][nexty] < length + 1) {
					dpTable[nextx][nexty] = length + 1;

					dfs(nextx, nexty, table[nextx][nexty], length + 1, n);
				}
	}

}


int main() {

	dpTable[0][0] = 1;
	dfs(0,0,START,1, TABLESIZE);

	printf("%d", maxlength);

}
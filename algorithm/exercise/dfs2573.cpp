#include <stdio.h>

struct unit {
	int x;
	int y;
};

int inputTable[330][330];
int visitTable[330][330];
int checkFlag;
int iceCount, currentIceCount;

int xAdded[5] = { 1,-1,0,0 };
int yAdded[5] = { 0,0,1,-1 };

void initVisit(int n, int m) {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visitTable[i][j] = 0;
		}
	}

}

unit findStart(int n, int m) {
	
	unit revalue;
	revalue.x = 0;
	revalue.y = 0;

	iceCount = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (inputTable[i][j] != 0) {
				revalue.x = i;
				revalue.y = i;
				iceCount++;
			}
		}
	}
	return revalue;
}

void checkIceberg(int n, int m, int x, int y) {

	visitTable[x][y] = 1;
	currentIceCount++;

	for (int i = 0; i < 4; i++) {
		int nextX = x + xAdded[i];
		int nextY = y + yAdded[i];

		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
			if (visitTable[nextX][nextY] == 0 && inputTable[nextX][nextY] != 0) {
				checkIceberg(n, m, nextX, nextY);
			}
		}
	}

}

void removeIceberg(int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (inputTable[i][j] != 0)
				visitTable[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (inputTable[i][j] == 0 && visitTable[i][j] == 0) {
				for (int k = 0; k < 4; k++) {
					int nextX = i + xAdded[k];
					int nextY = j + yAdded[k];

					if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
					
						if (visitTable[nextX][nextY] == 1 && inputTable[nextX][nextY] > 0) {

							inputTable[nextX][nextY]--;
						}
					}
				}
			}
		}
	}

}


int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &inputTable[i][j]);
		}
	}

	unit start;
	int solution = -1;
	checkFlag = 0;

	while (!checkFlag) {

		solution++;

		start = findStart(n, m);

		if (start.x == 0)
			break;

		initVisit(n, m);
		currentIceCount = 0;
		checkIceberg(n, m, start.x, start.y);
		if (currentIceCount != iceCount) {
			checkFlag = 1;
			break;
		}

		initVisit(n, m);
		removeIceberg(n, m);
	}

	if (checkFlag == 0)
		printf("0");
	else
		printf("%d", solution);
	
}
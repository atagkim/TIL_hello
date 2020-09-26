#include <stdio.h>
#include <stdlib.h>

int topoTable[15];
int tempTopo[15];
int maxTopo, tempMaxTopo;
int maxTopoTable[15];
int maxTopoTop;
char inputTable[30];
int visitTable[15];
char tempSolution[15];
int maxSolution, minSolution = 987654321;

void initTopo(int k) {

	for (int i = 0; i <= k; i++) {

		int left = i - 1;
		int right = i;

		while (1) {
			if (left < 0)
				break;
			else if (inputTable[left] != '<')
				break;

			topoTable[i]++;
			left--;
		}
		
		while (1) {
			if (right >= k)
				break;
			else if (inputTable[right] != '>')
				break;

			topoTable[i]++;
			right++;
		}
	}

	for (int i = 0; i <= k; i++) {
		if (topoTable[i] > maxTopo)
			maxTopo = topoTable[i];
	}

	for (int i = 0; i <= k; i++) {
		if (topoTable[i] == maxTopo)
			maxTopoTable[maxTopoTop++] = i;
	}
}

void pasteTopo(int k) {

	for (int i = 0; i <= k; i++) {
		tempTopo[i] = topoTable[i];
	}
}

void initVisit(int k) {

	for (int i = 0; i <= k; i++) {
		visitTable[i] = 0;
	}

}


void dfs(int current, int k, int v) {

	visitTable[current] = 1;
	tempSolution[current] = '0' + v;

	tempMaxTopo = -1;
	for (int i = 0; i <= k; i++) {
		if (tempTopo[i] > tempMaxTopo && visitTable[i] == 0)
			tempMaxTopo = tempTopo[i];
	}

	if (tempMaxTopo == -1) {
		tempSolution[k + 1] = 0;
		int currentSolution = atoi(tempSolution);

		if (currentSolution > maxSolution)
			maxSolution = currentSolution;

		if (currentSolution < minSolution)
			minSolution = currentSolution;

		return;
	}

	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < v; j++) {
			if (tempTopo[i] == tempMaxTopo && visitTable[i] == 0 ) {
			
				dfs(i, k, j);
				visitTable[i] = 0;

			}
		}
	}



}


int main() {

	int k;
	scanf("%d", &k);

	for (int i = 0; i < k * 2; i++) {
		char input;
		scanf("%c", &input);

		if (i % 2 == 1)
			inputTable[i / 2] = input;
	}

	initTopo(k);
	pasteTopo(k);

	for (int i = 0; i < maxTopoTop; i++) {
		for (int j = 0; j <= 9; j++) {

			initVisit(k);

			dfs(i, k, j);

		}		
	}

	printf("%d\n%d", minSolution, maxSolution);

}

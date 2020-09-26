#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int topoTable[15];
int maxTopo;
int maxTopoTable[15];
int maxTopoTop;
char inputTable[30];
int visitTable[15];
char tempSolution[15];
int maxSolution, minSolution = 987654321;
char maxPrint[15], minPrint[15];

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


void initVisit(int k) {

	for (int i = 0; i <= k; i++) {
		visitTable[i] = 0;
	}

}

int findMaxTopo(int k) {

	int revalue = -1;
	for (int i = 0; i <= k; i++) {
		if (topoTable[i] > revalue && visitTable[i] == 0)
			revalue = topoTable[i];
	}
	return revalue;
}


void dfs(int current, int v, int k) {

	visitTable[current] = 1;
	tempSolution[current] = '0' + v;

	int tempMaxTopo = findMaxTopo(k);

	if (tempMaxTopo == -1) {
		tempSolution[k + 1] = 0;
		int currentSolution = atoi(tempSolution);

		if (currentSolution > maxSolution) {
			maxSolution = currentSolution;
			strcpy(maxPrint, tempSolution);
		}

		if (currentSolution < minSolution) {
			minSolution = currentSolution;
			strcpy(minPrint, tempSolution);
		}

		return;
	}

	for (int i = 0; i <= k; i++) {
		for (int j = v - 1; j >= 0; j--) {
			if (topoTable[i] == tempMaxTopo && visitTable[i] == 0 ) {
			
				dfs(i, j, k);
				visitTable[i] = 0;

			}
		}
	}

}

void scan(int k) {

	for (int i = 0; i < k * 2; i++) {
		char input;
		scanf("%c", &input);

		if (i % 2 == 1)
			inputTable[i / 2] = input;
	}

}


int main() {

	int k;
	scanf("%d", &k);
	scan(k);

	initTopo(k);
	
	for (int i = 0; i < maxTopoTop; i++) {
		for (int v = 9; v >= 0; v--) {

			initVisit(k);

			dfs(maxTopoTable[i], v, k);
		}		
	}

	printf("%s\n%s", maxPrint, minPrint);

}

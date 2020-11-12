#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inputTable[15][5];
int flag;
int checkNum[15];
char tempSolution[15];
char max[15], min[15];
int indegree[15], indegree2[15];
int outdegree[15][15], outdegree2[15][15];
int outdegreeSize[15], outdegreeSize2[15];
int maxindegree;

void init(int n) {

	char input[10];
	for (int i = 0; i < n; i++) {
		scanf("%s", inputTable[i]);
	}

	for (int i = 0; i <= n; i++) {
		int left = i - 1, right = i + 1;
	
		while (left >= 0) {
			if (inputTable[left][0] == '>') {
				indegree[i]++;
				outdegree[left][outdegreeSize[left]++] = i;

				left--;
			}
			else
				break;
		} 

		left = i - 1;
		while (left >= 0) {
			if (inputTable[left][0] == '<') {
				indegree2[i]++;
				outdegree2[left][outdegreeSize2[left]++] = i;

				left--;
			}
			else
				break;
		}
		while (right <= n) {
			if (inputTable[right - 1][0] == '<') {
				indegree[i]++;
				outdegree[right][outdegreeSize[right]++] = i;

				right++;
			}
			else
				break;
		}

		right = i + 1;
		while (right <= n) {
			if (inputTable[right - 1][0] == '>') {
				indegree2[i]++;
				outdegree2[right][outdegreeSize2[right]++] = i;

				right++;
			}
			else
				break;
		}
	}
}

int findZero(int n) {
	for (int i = 0; i <= n; i++) {
		if (indegree[i] == 0) {
			indegree[i] = -1;
			return i;
		}
	}
	return -1;
}
int findZero2(int n) {
	for (int i = 0; i <= n; i++) {
		if (indegree2[i] == 0) {
			indegree2[i] = -1;
			return i;
		}
	}
	return -1;
}


void findMax(int n) {

	for (int i = 9; i >= 0; i--) {
		
		int currentIdx = findZero(n);
		if (currentIdx == -1)
			break;

		tempSolution[currentIdx] = i + '0';

		for (int j = 0; j < outdegreeSize[currentIdx]; j++) {
			indegree[outdegree[currentIdx][j]]--;
		}
	}
	tempSolution[n + 1] = 0;
	printf("%s\n", tempSolution);
}

void findMin(int n) {

	for (int i = 0; i <= 9; i++) {

		int currentIdx = findZero2(n);
		if (currentIdx == -1)
			break;

		tempSolution[currentIdx] = i + '0';

		for (int j = 0; j < outdegreeSize2[currentIdx]; j++) {
			indegree2[outdegree2[currentIdx][j]]--;
		}
	}
	tempSolution[n + 1] = 0;
	printf("%s\n", tempSolution);
}

int main() {

	int n;
	scanf("%d", &n);

	init(n);

	findMax(n);

	findMin(n);
}
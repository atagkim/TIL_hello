#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inputTable[15][5];
int flag;
int checkNum[15];
char tempSolution[15];
char max[15], min[15];

void init(int n) {

	char input[10];
	for (int i = 0; i < n; i++) {
		scanf("%s", inputTable[i]);
	}
}

int checkPossible(int next, int idx, int n) {

	if (idx - 1 >= 0) {
		if(inputTable[idx - 1][0] == '>'){
			if (tempSolution[idx - 1] > '0' + next)
				return 1;
			return 0;
		}
		else {
			if (tempSolution[idx - 1] < '0' + next)
				return 1;
			return 0;
		}
	}

}

void dfs(int current, int idx, int n, int swich) {

	checkNum[current] = 1;
	tempSolution[idx] = '0' + current;

	if (idx == n) {
		
		tempSolution[n + 1] = 0;
	
		if (swich == 1)
			strcpy(max, tempSolution);
		else
			strcpy(min, tempSolution);

		flag = 1;
		return;
	}

	if (swich == 1) {
		for (int i = 9; i >= 0; i--) {
			if (checkNum[i] == 0) {
				if (checkPossible(i, idx + 1, n)) {

					dfs(i, idx + 1, n, swich);

						checkNum[i] = 0;

						if (flag == 1)
							return;
				}
			}
		}
	}

	else {
		for (int i = 0; i < 10; i++) {
			if (checkNum[i] == 0 && checkPossible(i, idx + 1, n)) {

				dfs(i, idx + 1, n, swich);

				checkNum[i] = 0;

				if (flag == 1)
					return;
			}
		}
	}

}


void findMax(int n) {

	for (int i = 9; i >= 0; i--) {
		dfs(i, 0, n, 1);

		checkNum[i] = 0;

		if (flag == 1)
			break;
	}
	printf("%s\n", max);
}

void findMin(int n) {

	for (int i = 0; i < 10; i++) {
		dfs(i, 0, n, 0);

		checkNum[i] = 0;

		if (flag == 1)
			break;
	}
	printf("%s\n", min);

}

void initForDfs() {
	
	flag = 0;

	for (int i = 0; i < 10; i++) {
		checkNum[i] = 0;
	}
}

int main() {

	int n;
	scanf("%d", &n);

	init(n);

	findMax(n);

	initForDfs();
	findMin(n);

}
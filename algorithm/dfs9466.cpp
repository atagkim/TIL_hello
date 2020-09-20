#include <stdio.h>

int inputTable[100100];
int visitTable[100100];
int checkFlag, grouped;

void init(int n) {
	for (int i = 1; i <= n; i++) {
		scanf("%d", &inputTable[i]);
	}
}

void initVisit(int n) {
	for (int i = 1; i <= n; i++) {
		visitTable[i] = 0;
	}
}

void dfs(int goal, int current, int n) {

	visitTable[current] = 1;

	if (goal == inputTable[current]) {
		checkFlag = 1;		
		grouped++;

		return;
	}

	if (visitTable[inputTable[current]] == 0) {
		dfs(goal, inputTable[current], n);
		if (checkFlag == 1) {
			grouped++;
		}
		else
			visitTable[current] = 0;
	}
	else {
		visitTable[current] = 0;
	}
}

int main() {

	int t;
	scanf("%d", &t);
	while (t--) {

		int n;
		scanf("%d", &n);
		
		init(n);
		initVisit(n);
		grouped = 0;
		
		for (int i = 1; i <= n; i++) {	
			checkFlag = 0;
			
			dfs(i, i, n);
		}
		printf("%d\n", n - grouped);
	}
}
#include <stdio.h>

char inputTable[15][5];
int indegree[15], visit[15], visitFlag;
int outdegree[15][15];
int outdegreeSize[15];

int stack[15];
int top;

int tempSolution[15];
int solution[15];

void scan(int n) {

	for (int i = 0; i < n; i++) {
		scanf("%s", inputTable[i]);
	}
}

void initDegree(int n) {
	for (int i = 0; i <= n; i++) {
		int left = i - 1, right = i + 1;

		while (left >= 0) {
			if (inputTable[left][0] == '<')
				break;
			
			indegree[i]++;
			outdegree[left][outdegreeSize[left]++] = i;
			
			left--;
		}

		while (right <= n) {
			if (inputTable[right - 1][0] == '>')
				break;

			indegree[i]++;
			outdegree[right][outdegreeSize[right]++] = i;

			right++;
		}
	}

}

void checkZero(int n) {
	
	top = 0;
	for (int i = 0; i <= n; i++) {
		if (indegree[i] == 0) {
			indegree[i] = -1;
			stack[top++] = i;
		}
	}

}

int checkPossible(int n, int current, int what) {
	
	int revalue = 1;

	if (current - 1 >= 0) {
		if(visit[current-1] == 1){
			if (inputTable[current - 1][0] == '>') {
				if (tempSolution[current - 1] <= what)
					revalue = 0;
			}
			else {
				if (tempSolution[current - 1] >= what)
					revalue = 0;
			}
		}
	}
	if (current + 1 <= n) {
		if (visit[current + 1] == 1) {
			if (inputTable[current][0] == '>') {
				if (what <= tempSolution[current + 1])
					revalue = 0;
			}
			else {
				if (what >= tempSolution[current + 1])
					revalue = 0;
			}
		}
	}
	return revalue;
}

void dfs(int n) {

	if (visitFlag == 1) {
		return;
	}

	checkZero(n);

	int idx = 0;
	while (idx < top) {
		int current = stack[idx++];

		for (int i = 9; i >= 0; i--) {

			int possible = checkPossible(n, current, i);

			if (possible == 1) {
				tempSolution[current] = i;
				dfs()
			}
		}

	}

}

int main() {
	
	int n;
	scanf("%d", &n);

	scan(n);

	initDegree(n);

	dfs(n);

}


#include <stdio.h>
#include <vector>
#pragma warning(disable:4996)

using namespace std;


struct unit {
	int start;
	int end;
	int weight;
};
vector<vector<unit>> busTable;
int shortestTable[6010];
int tempSolution[6010];


void init(int n, int m) {

	vector<unit> deleteZero;
	busTable.push_back(deleteZero);

	for (int i = 1; i <= n; i++) {
		vector<unit> buf;
		busTable.push_back(buf);
	}

	int start, end, weight;
	for (int i = 1; i <= m; i++) {
		
		scanf("%d %d %d", &start, &end, &weight);
		unit input;
		input.start = start;
		input.end = end;
		input.weight = weight;

		busTable[start].push_back(input);
	}
	
	for (int i = 2; i <= n; i++) {
		shortestTable[i] = 987654321;
	}
}

void solution(int n, int m) {
	
	for (int k = 1; k <= n - 1; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < busTable[i].size(); j++) {
				if (busTable[i][j].weight + shortestTable[i] < shortestTable[busTable[i][j].end]) {
					shortestTable[busTable[i][j].end] = busTable[i][j].weight + shortestTable[i];
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		tempSolution[i] = shortestTable[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < busTable[i].size(); j++) {
			if (busTable[i][j].weight + shortestTable[i] < shortestTable[busTable[i][j].end]) {
				shortestTable[busTable[i][j].end] = busTable[i][j].weight + shortestTable[i];
			}
		}
	}

	bool flag = 0;
	for (int i = 1; i <= n; i++) {
		if (tempSolution[i] != shortestTable[i]) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) {
		printf("-1\n");
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (shortestTable[i] == 987654321) printf("-1\n");
			else printf("%d\n", shortestTable[i]);
		}
	}

}


int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	
	init(n, m);

	solution(n, m);
}
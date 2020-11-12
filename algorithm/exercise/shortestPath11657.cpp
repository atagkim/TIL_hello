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
long long shortestTable[6010];
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
	
	shortestTable[1] = 0;
	for (int i = 2; i <= n; i++) {
		shortestTable[i] = 987654321;
	}
}

// 벨만 포드
void solution(int n, int m) {
	
	bool flag = false;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < busTable[i].size(); j++) {
				if ( shortestTable[i] != 987654321 && busTable[i][j].weight + shortestTable[i] < shortestTable[busTable[i][j].end]) {
					shortestTable[busTable[i][j].end] = busTable[i][j].weight + shortestTable[i];

					if (k == n) flag = true;
				}
			}
		}
	}
	
	if (flag == true) {
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
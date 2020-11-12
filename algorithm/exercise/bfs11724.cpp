#include <stdio.h>
#include <queue>

using namespace std;


vector<int> inputTable[1010];
int visitTable[1010];

queue<int> qqu;

void init(int n, int m) {

	int start, end;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &start, &end);
	
		inputTable[start].push_back(end);
		inputTable[end].push_back(start);
	
	}

}


void bfs(int fire, int* solution) {

	while (!qqu.empty())
		qqu.pop();

	qqu.push(fire);

	if (visitTable[fire] == 0) 
		(*solution)++;
		
	while (!qqu.empty()) {

		int current = qqu.front();
		qqu.pop();

		if (visitTable[current] == 1)
			continue;

		visitTable[current] = 1;

		for (int i = 0; i < inputTable[current].size(); i++) {

			int next = inputTable[current][i];

			if (visitTable[next] == 0)
				qqu.push(next);

		}

	}


}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	init(n, m);

	int solution = 0;

	for (int i = 1; i <= n; i++) {
		bfs(i, &solution);
	}

	printf("%d", solution);
}
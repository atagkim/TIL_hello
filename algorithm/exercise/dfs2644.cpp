#include <stdio.h>
#include <vector>

using namespace std;

vector<int> inputTable[110];
int visitTable[110];
int solution;

void dfs(int n, int m, int x, int y, int current, int length) {

	if (current == y) {
		solution = length;
		return;
	}

	visitTable[current] = 1;

	for (int i = 0; i < inputTable[current].size(); i++) {
		int next = inputTable[current][i];

		if (visitTable[next] == 0) {
			dfs(n, m, x, y, next, length + 1);
			visitTable[next] = 0;
		}

	}

}

int main() {

	int n,m,x,y;
	scanf("%d", &n);
	scanf("%d %d", &x, &y);
	scanf("%d", &m);
	
	int parent, child;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &parent, &child);

		inputTable[parent].push_back(child);
		inputTable[child].push_back(parent);
	}

	dfs(n, m, x, y, x, 0);

	if (solution == 0)
		printf("-1");
	else
		printf("%d", solution);
}


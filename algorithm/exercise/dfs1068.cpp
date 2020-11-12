#include <stdio.h>
#include <queue>
using namespace std;

vector<int> downEdge[60];
vector<int> upEdge[60];
int solution;

queue<int> temp;

void dfs(int current, int* solution) {

	if (downEdge[current].size() == 0) {
		(*solution)++;
		return;
	}

	for (int i = 0; i < downEdge[current].size(); i++) {
		int next = downEdge[current][i];
		dfs(next, solution);
	}
}

int main() {

	
	int n;
	scanf("%d", &n);

	int input, root = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		
		if (input == -1) {
			root = i;

			upEdge[i].push_back(input);
			continue;
		}

		upEdge[i].push_back(input);
		downEdge[input].push_back(i);
	}

	int k;
	scanf("%d", &k);

	int parent = upEdge[k][0];
	if (parent == -1) {
		printf("0");
	}
	else {

		for (int i = 0; i < downEdge[parent].size(); i++) {
			if (downEdge[parent][i] == k)
				continue;
			temp.push(downEdge[parent][i]);
		}

		downEdge[parent].clear();

		while (!temp.empty()) {
			int current = temp.front();
			temp.pop();

			downEdge[parent].push_back(current);
		}

		dfs(root, &solution);

		printf("%d", solution);

	}
}
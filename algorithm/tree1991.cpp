#include <iostream>
#include <vector>
using namespace std;

int nodeTable[30][3];

// node 1น๘บฮลอ
// left 0 right 1

void dfs(int current, int order) {

	if (current == -18) {
		return;
	}

	int left = nodeTable[current][0];
	int right = nodeTable[current][1];

	if (order == 1) {
		printf("%c", 'A' + current - 1);
		dfs(left, order);
		dfs(right, order);
	}
	else if (order == 2) {
		dfs(left, order);
		printf("%c", 'A' + current - 1);
		dfs(right, order);
	}
	else {
		dfs(left, order);
		dfs(right, order);
		printf("%c", 'A' + current - 1);
	}
}

int main() {

	int n;
	scanf("%d", &n);

	char node[10], left[10], right[10];
	for (int i = 1; i <= n; i++) {
		scanf("%s %s %s", node, left, right);
	
		int idx = node[0] - 'A' + 1;
		nodeTable[idx][0] = left[0] - 'A' + 1;
		nodeTable[idx][1] = right[0] - 'A' + 1;
	}

	dfs(1, 1);
	printf("\n");
	dfs(1, 2);
	printf("\n");
	dfs(1, 3);
	printf("\n");
}
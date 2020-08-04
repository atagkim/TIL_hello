#include <stdio.h>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

struct edgeUnit {
	int start;
	int end;
	int cost;
	int dist;
};

struct pqUnit {
	int node;
	int dist;
	int cost;
};

struct cmp {

	bool operator()(pqUnit a, pqUnit b) {
		return a.dist > b.dist;
	}
};

priority_queue<pqUnit, vector<pqUnit>, cmp> pq;

vector<vector<edgeUnit>> edgeTable;

bool checkList[110][10010];
int distPerCostTable[110][10010];

void init(int n, int m, int k) {

	vector<edgeUnit> buf;
	for (int i = 0; i <= n; i++) {
		edgeTable.push_back(buf);
	}

	edgeUnit input;
	for (int i = 1; i <= k; i++) {
		scanf("%d %d %d %d", &input.start, &input.end, &input.cost, &input.dist);

		edgeTable[input.start].push_back(input);
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			checkList[i][j] = 0;
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 10000; j++) {
			distPerCostTable[i][j] = 987654321;
		}
	}
	
}


void free(int n, int m, int k) {

	for (int i = 0; i <= n; i++) {
		edgeTable[i].clear();
	}
	edgeTable.clear();

	while (!pq.empty()) {
		pq.pop();
	}

}

void findPath(int n, int totalCost, int destination) {

	pqUnit start;
	start.node = 1;
	start.cost = 0;
	start.dist = 0;
	
	pq.push(start);

	while (!pq.empty()) {

		pqUnit current = pq.top();
		pq.pop();

		if (checkList[current.node][current.cost] == 1) continue;
		checkList[current.node][current.cost] = 1;

		for (int i = 0; i < edgeTable[current.node].size(); i++) {
			edgeUnit currentEdge = edgeTable[current.node][i];

			if (currentEdge.cost + current.cost > totalCost) continue;

			if (current.dist + currentEdge.dist < distPerCostTable[currentEdge.end][current.cost + currentEdge.cost]) {
				distPerCostTable[currentEdge.end][current.cost + currentEdge.cost] = current.dist + currentEdge.dist;

				pqUnit next;
				next.node = currentEdge.end;
				next.dist = current.dist + currentEdge.dist;
				next.cost = current.cost + currentEdge.cost;

				pq.push(next);
			}

		}

	}

	for (int i = 1; i <= totalCost; i++) {
		if (distPerCostTable[destination][i] != 987654321) {
			printf("%d\n", distPerCostTable[destination][i]);
			break;
		}

		if (i == totalCost) printf("Poor KCM\n");
	}

}


int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);

		init(n, m, k);

		findPath(n, m, k);

		free(n, m, k);

	}
}
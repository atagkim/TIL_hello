#include <stdio.h>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

struct unit {
	int start;
	int end;
	int cost;
	int value;
};

struct pqUnit {
	int start;
	int cost;
	int value;
};

struct cmp {
	bool operator()(pqUnit A, pqUnit B) {
		if (A.value == B.value) {
			return A.cost > B.cost;
		}
		else return A.value > B.value;
	}
};


priority_queue<pqUnit, vector<pqUnit>, cmp> pq;

vector<vector<unit>> edgeTable;

int solution;

void init(int vertex, int totalCost, int edge) {

	solution = 987654321;

	vector<unit> basis;
	for (int i = 0; i <= vertex; i++) {
		edgeTable.push_back(basis);
	}

	int start, end, cost, value;
	for (int i = 1; i <= edge; i++) {
		scanf("%d %d %d %d", &start, &end, &cost, &value);
		
		unit input;
		input.start = start;
		input.end = end;
		input.cost = cost;
		input.value = value;

		edgeTable[start].push_back(input);
	}

}

void findPath(int start, int end, int totalCost, int currentCost, int currentValue) {

	if (start == end) {
		if (currentValue < solution) {
			solution = currentValue;
		}
		return;
	}

	for (int i = 0; i < edgeTable[start].size(); i++) {

		if (edgeTable[start][i].cost + currentCost <= totalCost) {
			findPath(edgeTable[start][i].end, end, totalCost,
				edgeTable[start][i].cost + currentCost, edgeTable[start][i].value + currentValue);
		}
	}
}

void free(int vertex) {

	for (int i = 0; i <= vertex; i++) {
		edgeTable[i].clear();
	}


}


int main() {

	int t;
	scanf("%d", &t);

	while (t--) {
		
		int vertex, totalCost, edge;
		scanf("%d %d %d", &vertex, &totalCost, &edge);

		init(vertex, totalCost, edge);

		findPath(1, vertex, totalCost, 0, 0);

		if (solution == 987654321) {
			printf("Poor KCM\n");
		}
		else {
			printf("%d\n", solution);
		}

		free(vertex);
	}

}